// writed by xiaojl 1999/11/20 ���ִ���
// rewrited by Lonely 2003/11/21 
// sos.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

#define SOS_NUM       99

mapping *notes;

string query_save_file() { return DATA_DIR + "sos"; }

int help(object me);

void prompt_user(object me)
{
        int num;
        int total;
        mapping *notes;
        int last_read_time;

        if (! wizardp(me)) return;
        
        last_read_time = me->query("board_last_read/sos");
        
        if (! last_read_time)
        {
                tell_object(me, HIG "��ӭ������" + LOCAL_MUD_NAME() +
                                HIG "�������ʹ��" HIY " sos " HIG
                                "���������ҵ������Ϣ��\n" NOR);
                me->set("board_last_read/sos", time());
                return;
        }
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        total = 0;
        while (num--)
                if (notes[num]["time"] > last_read_time)
                        total++;
                else
                        break;

        if (! total)
                tell_object(me, "��Ŀǰû��δ���Ķ�������������Ϣ��\n");
        else
                tell_object(me, sprintf(WHT "��Ŀǰһ���� " HIY "%d" NOR
                                        WHT " ����������Ϣ��û���Ķ�����ʹ�� "
                                        HIY "sos" NOR WHT " �����Ķ���\n" NOR, total));
}

void done_post(object me, mapping note, string text)
{
        int i; 
        string *lines;

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "��������ж̾�̫���ˣ������һ���Ա������Ķ���\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "����������Щ��̫���ˣ�������Ա������Ķ���\n");
                        return;
                }
        }
                                    
        note["msg"] = text;

        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        set("notes", notes);
        tell_object(me, HIM "�����ϡ������Ϣ�Ѿ����ӵ���ʦ֪ͨ�����\n");
        tell_object(me, HIM "��ʦ���ڴ���������ң���ȴ���\n");
        tell_object(me, HIM "�������æ���Լ������飬��һ��ʱ��������" NOR + 
                        HIR "SOS LIST|READ" NOR + HIM "�鿴�Ƿ񱻽����\n" NOR);        
        save();
        return;
}

void done_re(object me, mapping report, int project, string text)
{
        int i;
        mapping *reports;
        string *lines;  

        if (! stringp(text))
                return;
                
        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "��������ж̾�̫���ˣ������һ���Ա������Ķ���\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "����������Щ��̫���ˣ�������Ա������Ķ���\n");
                        return;
                }
        }

        report["msg"] = text;

        reports = notes[project]["re"];
        
        if (! arrayp(reports))  
                reports = ({ report });
        else 
                reports += ({ report });

        notes[project]["re"] = reports;
        notes[project]["time"] = time();

        set("notes", notes);
        tell_object(me, HIW "�ظ���ϡ�\n" NOR);

        save();
        return;
}

int do_list() 
{
        int i, last_time_read;
        string msg;
        object me = this_player();      

        if (! pointerp(notes) || ! sizeof(notes)) 
        {
                write("û���˷�������źš�\n");
                return 0;
        }
                
        msg = sprintf("%s�Ѿ�����������ź��б����£�" 
                HIW "\n----------------------------------------------------------------------------------\n" NOR, 
                      wizardp(me) ? "���" : "��");
        
        last_time_read = me->query("board_last_read/sos");
        
        for (i = 0; i < sizeof(notes); i++) 
        {
                if (wizardp(me) || ! strcmp(me->query("id"), notes[i]["author"]))
                        msg += sprintf("%s[%2d]" NOR "  %-50s %-6s (%s)\n", 
                                       (notes[i]["time"] > last_time_read ? HIY : ""),
                                       i + 1, notes[i]["title"], 
                                       notes[i]["solve"] == "" ? "�����" 
                                                               : "�ѽ��",  
                                       ctime(notes[i]["time"])[0..15]);
        }
        msg += HIW "----------------------------------------------------------------------------------\n" NOR;
        me->start_more(msg);
        return 1;
}

int do_read(string arg) 
{
        int i, num, last_time_read;
        string msg;
        object me = this_player();    
              
        last_time_read = me->query("board_last_read/sos");    
          
        if (! pointerp(notes) || ! sizeof(notes))
        { 
                write("û�˷�������źš�\n");
                return 0;
        }
        
        if (arg == "new" || arg == "next")
        {
                if (! last_time_read)
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                        {
                                if (wizardp(me))
                                {
                                        if (notes[num - 1]["time"] > last_time_read)
                                                break;
                                } else
                                {
                                        if (notes[num - 1]["time"] > last_time_read &&
                                            ! strcmp(me->query("id"), notes[num - 1]["author"]))
                                                break;
                                }
                        }
        } else
        if (! sscanf(arg, "%d", num))
        {
                write("��Ҫ���ĵڼ�������źţ�\n");
                return 0;
        }
                                                    
        if (num < 1 || num > sizeof(notes))
        {
                write("û���������źš�\n");
                return 0;
        }
        num--;

        if (! wizardp(me) && strcmp(me->query("id"), notes[num]["author"]))
        {
                write("��������ź��㲻���Ķ���\n");
                return 0;
        }

        msg = sprintf("[" WHT "%2d" NOR "]" NOR 
                      "  %-50s %-12s (%s)\n����������������������������������������������������������������������������������\n%s\n"
                      "����������������������������������������������������������������������[" HIW " �� ƪ �� " NOR "]\n",
                      num + 1, notes[num]["title"], 
                      notes[num]["solve"] == "" ? "no solved   " : "by " + notes[num]["solve"],
                      ctime(notes[num]["time"])[0..9], notes[num]["msg"]);
                      
        for (i = 0; i < sizeof(notes[num]["re"]); i++) 
        {
                msg += sprintf(
                               "\n[ " HIW "�ظ���ţ�" NOR "%2d] [ " HIW "�ظ����⣺" NOR "%-52s ] \n"
                               "����������������������������������������������������������������������������������\n"
                               "%s\n����������������������������������������������������������������������������������\n[ " HIW "ʱ�䣺" NOR "%s ] [ "
                               HIW "�ظ��ߣ�" NOR " %35s]\n",
                               i + 1,
                               notes[num]["re"][i]["title"],
                               notes[num]["re"][i]["msg"],
                               ctime(notes[num]["re"][i]["time"]),
                               notes[num]["re"][i]["author"] + "(" +
                               notes[num]["re"][i]["owner"] + ")");
        }
                        
        me->start_more(msg);   
        
        if (notes[num]["time"] > last_time_read)
                me->set("board_last_read/sos",
                        notes[num]["time"]);
        return 1;
}

int do_solve(string arg)
{
        int num;
        object me = this_player();
        
        if (sscanf(arg, "%d", num) != 1) 
                return help(me);
                
        if (! pointerp(notes) || ! sizeof(notes) ||
            num < 1 || num > sizeof(notes)) 
        {
                write("�޴�����źű��!!\n");
                return 0;
        } 
        if (notes[num-1]["solve"] != "") 
        {
                write(notes[num-1]["solve"] + "�Ѿ���־��!\n");
                return 1;
        }
        notes[num-1]["solve"] = me->query("id");
        
        save();
        write("�������Ϣ�ѱ�־Ϊ�����\n");
        return 1;
}

int main(object me, string arg)
{
        mapping note;
        object where;
        string s, str, arg1, arg2; 
        int i, num;
        string title;
        int l;

        restore();
        
        notes = query("notes");
        
        if (! arg) 
        {
                if (! wizardp(me))
                {
                        if (sizeof(notes) > SOS_NUM)
                                return notify_fail("�Բ�������SOS�ϵ��ź�̫���ˣ���������ʦ���촦����ǰ��SOS�����źš�\n");
                                
                        if (base_name(environment(me)) == "/inherit/room/chatroom")
                                return notify_fail("���������޷����������źţ�\n");

                        tell_object(me, HIM "������ " HIY + LOCAL_MUD_NAME() + HIM " �������������ͣ�ͻȻ����һֻ����ĳ�������������\n" NOR);
                        tell_object(me, HIM "��Ͻ�����ʦ�Ƿ�����������źţ��ӣϣӣ�����\n" NOR);
                        where = environment(me);                        
                        if (! where) 
                                s = sprintf("%s(%s)���", (string)me->name(), (string)me->query("id"));
                        else
                                s = sprintf("%s(%s)��(%s)%s���",
                                            (string)me->name(),
                                            (string)me->query("id"),
                                            (string)file_name(where),
                                            filter_color((string)where->query("short")));
                                            
                        // ȷ����ʾ���ң�����������Ϊ��-50.50s�����ƣ���ʵ��Ȼ
                        // ��Ϊ��Ӣ�Ľ�ϵģ������޷���֤-50.50s����������
                        if (strlen(s) > 50)
                        {
                                l = strlen(s) - 50;
                                if (l % 2)
                                        s = s[0..48];  
                                else
                                        s = s[0..49];
                        }                                                 
                        note = allocate_mapping(5);
                        note["title"] = s;
                        note["author"] = me->query("id"); 
                        note["time"] = time();
                        note["solve"] = "";
                        me->edit( (: done_post, me, note :) );
                } else 
                {
                        do_list();
                }
                return 1;
        } 

        if (sscanf(arg, "%s %s", arg, arg2) == 2) 
        {
                if (arg == "re")
                {
                        if (sscanf(arg2, "%d.%s", num, title) < 1)
                                return notify_fail("ָ���ʽ��bsos re <���ӱ��>.<�ظ�����>\n");
                                
                        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                                return notify_fail("û�����������ӡ�\n");

                        if (strlen(title) > 50)
                                return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

                        if (! title) 
                                title = "R: " + notes[num - 1]["title"];
                
                        note = allocate_mapping(5);
                        note["title"] = title;
                        note["owner"] = me->query("id");
                        note["author"] = me->name(1);
                        note["time"] = time();
                        me->edit((: done_re, me, note, num - 1 :));
                        return 1;
                } else                        
                if (arg == "solve")
                {
                        if (! wizardp(me)) 
                                return help(me);
                        
                        if (arg2 == "all") 
                        {
                                if (! (i = sizeof(notes))) 
                                        return notify_fail("û���˷��� SOS ����źš�\n");
                                for ( ; i > 0; i-- ) 
                                        notes[i-1]["solve"] = me->query("id");
                                write("���е������Ϣ�Ѿ���־Ϊ����ˡ�\n");
                                save();
                                return 1;
                        } else
                        {
                                do_solve(arg2);
                                return 1;
                        }
                } else
                if (arg == "read")
                {
                        do_read(arg2);
                        return 1;       
                } else
                        return help(me);
        }
                                                                                                    
        if (sscanf(arg, "%s", arg1) == 1) 
        {
                switch(arg1)
                {
                case "list":
                        do_list();
                        break;
                
                case "pack":
                        if (! wiz_level(me)) 
                                return help(me);
                                
                        if (! (i = sizeof(notes))) 
                                return notify_fail("û���˷��� SOS ����źš�\n");
                                
                        for( ; i > 0; i-- ) 
                        if ("" != notes[i-1]["solve"]) 
                        {
                                printf("���(%s)�� SOS ����ѱ�ɾ����\n", notes[i-1]["author"]);
                                if (sizeof(notes) == 1) 
                                        notes = ({});
                                else 
                                if (i == 1) 
                                        notes = notes[1..sizeof(notes)-1];
                                else 
                                if (i == sizeof(notes)) 
                                        notes = notes[0..sizeof(notes)-2];
                                else 
                                        notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
                                        
                                set("notes", notes);
                        }
                        save();
                        break;
                case "new":
                case "next":
                        do_read(arg1);
                        break;                              
                default:
                        if (sscanf(arg1, "%d", num) == 1) 
                                do_read(arg1);
                                
                        else return help(me);
                        break;
                } 
                return 1;
                        
        } else 
                return help(me);
}

int help(object me)
{
        if (! wizardp(me))
        write(@HELP
ָ���ʽ :   
           SOS         
           SOS LIST
           SOS READ NEXT|NEW|<���ӱ��>
           SOS <���ӱ��>
           SOS RE <���ӱ��>.<�ظ�����>
���ָ�������ϵͳ���� SOS ʱ������ʦ������
����������ϵͳ����ʾ������� SOS �����������������Ӧ�ý� 
���ֵ������ϵͳ����ʾ������ϸ�ؽ���˵�����Ա���ʦ�޸ĸ� SOS��
������ SOS READ �Ķ��Լ�����������źš�
HELP
        );
        else 
write(@HELP
ָ���ʽ : SOS 
           SOS <���ӱ��>                       
           SOS READ NEXT|NEW|<���ӱ��>        
           SOS SOLVE <���ӱ��>                                        
           SOS RE <���ӱ��>.<�ظ�����> 
           SOS PACK   

���ָ����Ը�����ʦ�����������������Ϣ�б�SOS �� SOS LIST �Ĺ���һ����
���ǽ����е� SOS ��Ϣ�����б��������� SOS ������ݲ����Ĳ�ͬ������ʾ
��Ӧ������Ӧ��ҵ� SOS ����ϸ��Ϣ��SOS SOLVE ������־ĳ��SOS�Ѿ�������ˡ�
SOS PACK ��ɾ�������Ѿ���־Ϊ����˵� SOS��
HELP
        );
        return 1;
}

