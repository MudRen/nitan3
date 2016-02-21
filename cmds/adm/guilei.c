// guilei.c
// by Smallfish

#include <ansi.h>
#include <armor.h>

inherit F_CLEAN_UP;

int guilei_dir(object me, string dir, string type, int continueable, int *total);
int guilei_file(object me, string file, string type);
nosave int all_num;	//�ж϶����ļ�������

int main(object me, string arg)
{
        string dir,type,type_name;
        int continueable;
        int *total = ({0});

           if (! SECURITY_D->valid_grant(me, "(admin)")) 
              return 0; 

        seteuid(geteuid(me));
        write("guilei ���� v1.0  \nС���(smallfish)��2002��1��8�ű�д��\n"+"��ҳ��http://www.jdmr.com\n�ʼ���cunsun@sina.com\n");

        continueable = 1;
 	if (!arg || !(sscanf(arg,"%s %s",dir,type) == 2)) 
                return notify_fail("��ʽ��guilei <·��> room|npc \n");

       	dir = resolve_path(me->query("cwd"), dir);

        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("û��" + dir + "���·����\n");

        //��������
        switch(type)
        {
                case "room":
                        type_name = "����";
                        break;
                case "npc":
                        type_name = "NPC";
                        break;
                case "obj":
                        type_name = "��Ʒ";
                        break;
                default:
                        return notify_fail("��ʽ��guilei <·��> room|npc \n");
        }

	me->set("cwd", dir);

	message_system("�������" + type_name + "�����У����Ժ�...");
        if (! guilei_dir(me, dir, type, continueable, total))
        {
                write(HIR "��������������ֹ��\n" NOR);
        }

        if (total[0] > 0)
        {
                write(HIC "�ܹ���" + HIW + total[0] + HIC "���������ɹ����࣡\n" NOR);
                write(HIC "������Ϣ�����" + HIW + "/log/static/" + type + HIC "֮�У�\n" NOR);
        } else
                write(HIC "û�й����κε�����\n" NOR);

        return 1;
}

int guilei_dir(object me, string dir, string type, int continueable, int *total)
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

                        if (! guilei_file(me, dir + filename, type) &&
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
                        if (! guilei_dir(me, dir + file[i][0], type, continueable, total) &&
                            ! continueable)
                                return 0;
                }
        }
	return 1;
}

int guilei_file(object me, string file, string type)
{
        string document,err,logfile,armor_type;
        mapping all_obj,bookskill;
        string *ob_list,the_id,the_name,the_object,file_name;
        int i,is_ok,num;
        object obj,*inv;

        if (file == "/cmds/adm/guilei.c")
                // �����Ҷ���ָ���ļ�
                return 1;

        write (".");
        
        //���෿���ļ�
        if (type == "room"){
                document = read_file(file);
                if (!document) return 0;
                is_ok = strsrch(document,"inherit ROOM",1);
                
                if (is_ok > 0) {
                        all_num ++;
                        file_name = file->query("short");
                        all_obj = file->query("objects");
                        if (!mapp(all_obj)) return 0;
                        ob_list = keys(all_obj);
                        for (i = 0; i < sizeof(ob_list); i++) {
                                the_object = ob_list[i] + ".c";
                                the_name = the_object->name(1);
                                the_id = the_object->query("id");
                                log_file("static/room", sprintf("%s|%s|%s|%s|%s\n",
                                        file, 
                                        file_name, 
                                        the_object, 
                                        the_name, 
                                        the_id, 
                                ));
                        }
                }
        }

        //����NPC�ļ�
        if (type == "npc")
        {
                document = read_file(file);
                if (!document) return 0;
                is_ok = strsrch(document,"inherit NPC",1);
                
                if (is_ok > 0) 
                {
                        all_num ++;
                        obj = new(file);
                        if (!obj) return 0;
                        log_file("static/npc", sprintf("%s|%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%s|%s|%s\n",
                                file,
                                obj->query("id"),
                                obj->query("name"),
                                obj->query("combat_exp"),
                                obj->query("jing"),
                                obj->query("eff_jing"),
                                obj->query("qi"),
                                obj->query("eff_qi"),
                                obj->query("jingli"),
                                obj->query("max_jingli"),
                                obj->query("neili"),
                                obj->query("max_neili"),
                                obj->query("shen"),
                                obj->query("gender"),
                                obj->query("race"),
                                obj->query("family/family_name")
                        ));

                        inv = all_inventory(obj);
                        if (sizeof(inv)) {
                                for (i = 0; i < sizeof(inv); i++)
                                {
                                        log_file("static/npc_obj", sprintf("%s|%s.c|%s|%s\n",
                                                file, 
                                                base_name(inv[i]),
                                                inv[i]->query("id"),
                                                inv[i]->name(1)
                                        ));
                                }
                        }

                        all_obj = obj->query("vendor_goods");
                        if (!mapp(all_obj)) return 0;
                        ob_list = keys(all_obj);
                        for (i = 0; i < sizeof(ob_list); i++) {
                                the_object = ob_list[i] + ".c";
                                log_file("static/npc_obj", sprintf("%s|%s|%s|%s\n",
                                        file, 
                                        the_object,
                                        the_object->query("id"), 
                                        the_object->name(1)
                                ));
                        }
                        destruct(obj);
                }
        }

        //������Ʒ�ļ�
        if (type == "obj"){
            if (strsrch(file, "/d/wizard/") > 0) return 0;
            if (strsrch(file, "/d/room/") > 0) return 0;
            if (strsrch(file, "/d/pk/") > 0) return 0;
            if (strsrch(file, "/d/death/") > 0) return 0;
            err = catch(obj = new(file));
            if (err) return 0;
            if (!obj) return 0;
            if (stringp(obj->query_save_file()))
            {
                destruct(obj);
                return 0;
            }
            
            //����ARMOR����Ʒ
            if (mapp(obj->query("armor_prop")) && stringp(armor_type = obj->query("armor_type")) )
            {
                
                if (armor_type != "head" &&
                    armor_type != "neck" &&
                    armor_type != "cloth" &&
                    armor_type != "armor" &&
                    armor_type != "surcoat" &&
                    armor_type != "waist" &&
                    armor_type != "wrists" &&
                    armor_type != "shield" &&
                    armor_type != "hands"
                    ) {
                            destruct(obj);
                            return 0;
                    }

                switch(armor_type)
                {
                        case "head":
                                logfile = "head";
                                break;
                        case "neck":
                                logfile = "head";
                                break;
                        case "cloth":
                                logfile = "cloth";
                                break;
                        case "armor":
                                logfile = "armor";
                                break;
                        case "surcoat":
                                logfile = "armor";
                                break;
                        case "waist":
                                logfile = "armor";
                                break;
                        case "wrists":
                                logfile = "armor";
                                break;
                        case "shield":
                                logfile = "armor";
                                break;
                        case "hands":
                                logfile = "armor";
                                break;
                        default:
                                destruct(obj); 
                                return 0;
                }

                num = 0;
                inv = children(file);
                if (!inv) 
                    num = 0;
                else
                {
                    i = sizeof(inv);
                    if (i <= 0) 
                        num = 0;
                    else {
                        while(i--)
                                if (environment(inv[i])) num++;
                    }
                }
                
                
                log_file("static/guilei/"+logfile, sprintf("        \"%s\":,\n",
                        file,
                ));
                        
                all_num ++;
            }

            //�������
            if (mapp(obj->query("weapon_prop")) && stringp(armor_type = obj->query("skill_type")) )
            {
                
                if (armor_type != "blade" &&
                    armor_type != "club" &&
                    armor_type != "hammer" &&
                    armor_type != "staff" &&
                    armor_type != "sword" 
                    ) {
                            destruct(obj);
                            return 0;
                    }

                switch(armor_type)
                {
                        case "blade":
                                logfile = "blade";
                                break;
                        case "club":
                                logfile = "staff";
                                break;
                        case "hammer":
                                logfile = "hammer";
                                break;
                        case "staff":
                                logfile = "staff";
                                break;
                        case "sword":
                                logfile = "sword";
                                break;
                        default:
                                destruct(obj); 
                                return 0;
                }

                num = 0;
                inv = children(file);
                if (!inv) 
                    num = 0;
                else
                {
                    i = sizeof(inv);
                    if (i <= 0) 
                        num = 0;
                    else {
                        while(i--)
                                if (environment(inv[i])) num++;
                    }
                }

                log_file("static/guilei/"+logfile, sprintf("        \"%s\":,\n",
                        file,
                ));
                        
                all_num ++;
            }

            //�����鱾
            if ( mapp(bookskill = obj->query("skill")) )
            {
                if (undefinedp(bookskill["name"]) )
                {
                        destruct(obj);
                        return 0;
                }
                
                armor_type = obj->query("skill/name");
                if (file_size(SKILL_D(armor_type) + ".c") <= 0)
                {
                        destruct(obj);
                        return 0;
                }
                
                switch(SKILL_D(armor_type)->type())
                {
                        case "knowledge":
                                logfile = "knowledge";
                                break;
                        default:
                                logfile = "miji";
                                break;
                }

                num = 0;
                inv = children(file);
                if (!inv) 
                    num = 0;
                else
                {
                    i = sizeof(inv);
                    if (i <= 0) 
                        num = 0;
                    else {
                        while(i--)
                                if (environment(inv[i])) num++;
                    }
                }

                log_file("static/guilei/"+logfile, sprintf("        \"%s\":,\n",
                        file,
                ));
                        
                all_num ++;
            }
                destruct(obj);
        }
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
