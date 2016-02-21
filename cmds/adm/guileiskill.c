// guileiskill.c
// by Smallfish

#include <ansi.h>
#include <armor.h>

inherit F_CLEAN_UP;

int guilei_dir(object me, string dir, int continueable, int *total);
int guilei_file(object me, string file);
nosave int all_num;	//�ж϶����ļ�������
nosave mapping famskill;
nosave string *valid_types = ({
        "axe",
        "force",
        "dodge",
        "unarmed",
        "cuff",
        "strike",
        "finger",
        "hand",
        "claw",
        "sword",
        "blade",
        "staff",
	"hammer",
        "club",
        "whip",
        "dagger",
        "throwing",
        "parry",
        "magic",
	"medical",
        "poison",
        "chuixiao-jifa",
        "tanqin-jifa",
        "guzheng-jifa",
        "array",
});

int main(object me, string arg)
{
        string dir,type,type_name;
        int continueable,i,j;
        int *total = ({0});
        string *fams,*famskills;

             if (! SECURITY_D->valid_grant(me, "(admin)")) 
                  return 0; 

        seteuid(geteuid(me));

        continueable = 1;

 	if (!arg) 
                return notify_fail("��ʽ��guileiskill <·����> \n");

       	dir = resolve_path(me->query("cwd"), arg);

	if (file_size(dir) == -1) return notify_fail("Ŀ¼"+ dir + "�����ڣ�\n");

	if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/') dir += "/";

        famskill = ([]);
        
	message_system("�������" + type_name + "�����У����Ժ�...");
        if (! guilei_dir(me, dir, continueable, total))
        {
                write(HIR "��������������ֹ��\n" NOR);
        }
        
        fams = keys(famskill);
        log_file("static/guilei/famskills","mapping famskill = ([\n");
        
        for (i = 0;i < sizeof(fams);i++)
        {
                log_file("static/guilei/famskills",sprintf("        \"%s\": ({\n",fams[i]));
                famskills = famskill[fams[i]];
                for (j = 0;j < sizeof(famskills);j++)
                        log_file("static/guilei/famskills",sprintf("                        \"%s\",\n",famskills[j]));
                log_file("static/guilei/famskills","                 }),\n");
        }
        log_file("static/guilei/famskills","]);");        
                
        if (total[0] > 0)
        {
                write(HIC "�ܹ���" + HIW + total[0] + HIC "���������ɹ����࣡\n" NOR);
                write(HIC "������Ϣ�����" + HIW + "/log/static/" + type + HIC "֮�У�\n" NOR);
        } else
                write(HIC "û�й����κε�����\n" NOR);

        return 1;
}

int guilei_dir(object me, string dir, int continueable, int *total)
{
	int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;

        if (! is_root(previous_object()))
                return 0;

	file = get_dir(dir, -1);
	if (! sizeof(file))
	{
                if (file_size(dir) == -2)
                        write(dir + "���Ŀ¼�ǿյġ�\n");
		else
		        write("û��" + dir + "���Ŀ¼��\n");
                return 1;
	}

        write (HIY "��ʼ���Ŀ¼" + dir + "����������ļ���\n" NOR);
	i = sizeof(file);
        compcount = 0;
        filecount = 0;
        all_num = 0;
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;

                        if (! guilei_file(me, dir + filename) &&
                            ! continueable)
                                return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
	}
        write(HIC "\n������Ŀ¼" + dir + "�µ�" + HIW + filecount + HIC +
              "���ļ�\n�����������" + HIW + compcount + HIC + 
              "��������\n������������" + HIW + all_num + HIC + "��������\n" + NOR );

	i = sizeof(file);
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! guilei_dir(me, dir + file[i][0], continueable, total) &&
                            ! continueable)
                                return 0;
                }
        }
	return 1;
}

int guilei_file(object me, string file)
{
        mapping fam,allskill;
        string fam_name,*skillkey,*famskills;
        int i,j;
        object obj;

        if (file == "/cmds/adm/guilei.c")
                // �����Ҷ���ָ���ļ�
                return 1;

        write (".");
        
        catch(obj = new(file));
        if (!obj) return 0;
        if (!obj->is_character())
        {
                destruct(obj);
                return 0;
        }
        if (!mapp(fam = obj->query("family")))
        {
                destruct(obj);
                return 0;
        }
        
        fam_name = fam["family_name"];
        
        if (!mapp(allskill = obj->query_skills()))
        {
                destruct(obj);
                return 0;
        }

        all_num++;
        skillkey = keys(allskill);
        
        for (i = 0;i < sizeof(skillkey); i++)
        {
                for (j = 0; j < sizeof(valid_types);j++)
                {
                	if (SKILL_D(skillkey[i])->valid_enable(valid_types[j]))
                        {
                                if (undefinedp(famskill[fam_name]))
                                {
                                        famskills = ({});
                                        famskills += ({ skillkey[i] });
                                        famskill[fam_name] = famskills;
                                } else
                                {
                                        famskills = famskill[fam_name];
                                        famskills -= ({ skillkey[i] });
                                        famskills += ({ skillkey[i] });
                                        famskill[fam_name] = famskills;
                                }
                                break;
                        }
                }
        }
        
        destruct(obj);                

        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: guilei <·��|�ļ���> <room|npc|obj>
 
���ָ������ָ����һ���ļ�����һ��Ŀ¼�µķ��䡢�����Ʒ��
���Խ��й��ࡣ
room������ʾ���෿���ļ�����Ϣ�����ļ����������������������
Ʒ�ļ�������Ʒ����������ƷӢ������
npc ������ʾ���������ļ�����Ϣ�����ļ�������������Ӣ��������
��ID��������������������Ʒ���ļ�������ƷID����Ʒ������������
�ĸ���HP���ԡ��������ҪSCORE���ԣ�
obj ������ʾ������Ʒ�ļ�����Ϣ�����ļ�������ƷID����Ʒ��������
��Ʒ�ļ�ֵ�ȵȣ�

������Ϣ�����/log/staticĿ¼�¡�
����ĩ�գ�smallfish

HELP );
        return 1;
}
