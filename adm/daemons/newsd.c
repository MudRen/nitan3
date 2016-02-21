// newsd.c

#include <ansi.h>
#include <getconfig.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

#include "/adm/etc/database.h"

// ���ݵ�����˳��
#define TITLE   0       // ����
#define TIME    1       // ʱ��
#define AUTHOR  2       // ����
#define MSG     3       // ����
#define VIEW    4       // ���

// ���һǧ������
#define MAX_NEWS_CAPACITY       1000

// ���ɸ������ȼ�
int     last_update_day = 0;
mapping family_priority = ([ ]);

nosave mixed *snotes = ({ });

// ��ѯ���е�����
#ifdef DB_SAVE
mixed *query_notes()
{
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
         
        snotes = DATABASE_D->db_all_query(sprintf("SELECT * from %s", NEWS_TABLE));
                
        if (! pointerp(snotes) || ! sizeof(snotes))
        {
                tell_object(this_player(), "�����������⣬�������ݿ��ٶ���Щ�ٻ��������²鿴���š�\n");
                return ({});
        }   
                          
        return sort_array(snotes, (: $1[1] - $2[1] :));
}
#endif

void create()
{
        seteuid(getuid());
        restore();
        set_heart_beat(300);
}

// ����������ÿ�������������ɵĸ������ȼ�
void heart_beat()
{
       // int time;
        string fam;

        if (time() / 86400 != last_update_day)
        {
                // �������ɸ�������˳������
                last_update_day = time() / 86400;

                if (! mapp(family_priority))
                        family_priority = ([ ]);

                foreach (fam in keys(FAMILY_D->query_all_family_name()))
                        if (undefinedp(family_priority[fam]))
                                family_priority[fam] = 10;
                        else
                                family_priority[fam] += 10;

                save();
        }
}

mapping query_family_priority()
{
        return family_priority;
}

void remove()
{
        save();
}

void mud_shutdown()
{
        save();
}

// ������ŵĵ�� / �Ķ�����
#ifdef DB_SAVE
void add_view_time(mixed* news, int i)
{
        string sql;

        sql = sprintf("UPDATE %s SET view = view + %d WHERE time = %d",
                      NEWS_TABLE, i, news[TIME]);
        // tell_object(this_player(), WHT + sql + "\n" NOR);
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();           
        DATABASE_D->db_query(sql);
}
#endif 

// ��ʾ�û�
void prompt_user(object me)
{
        int num;
        int total;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {
                tell_object(me, WHT "\n��ӭ������" + LOCAL_MUD_NAME() +
                                WHT "�������ʹ��" HIY " news " NOR WHT
                                "������ķ�����������Ϣ��\n" NOR);
                me->set("last_read_news", time());
                return;
        }
#ifdef DB_SAVE
    	notes = query_notes();
#else
        notes = query("notes");
#endif
        if (! arrayp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        total = 0;
        while (num--)
        {
#ifdef DB_SAVE
       		if (notes[num][TIME] > last_read_time)
#else
                if (notes[num]["time"] > last_read_time)
#endif
                        total++;
                else
                        break;
	}
        if (! total)
                tell_object(me, "\n��Ŀǰû��δ���Ķ��������š�\n");
        else
                tell_object(me, sprintf(WHT "\n��Ŀǰһ���� " HIY "%d" NOR
                                        WHT " �����Ż�û���Ķ�����ʹ��("
                                        HIY "news" NOR WHT ")�����Ķ���\n" NOR, total));

        // ��ʼ��ʱ֪ͨ
        if (previous_object() == find_object(LOGIN_D))
                me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me),
                                        10 + random(10));
}

// ��ʾ���е����ű���
// raw = 1: ����ʾδ������
void show_news(object me, int raw)
{
        mixed *notes;
        int i, last_time_read;
        string msg;

#ifdef DB_SAVE 
  	notes = query_notes();
#else
        notes = query("notes");
#endif
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }

        msg = "Ŀǰ��̶�е�������Ϣ���¡�\n"
              HIC "��" HIY "������������������������������������������������������������������������������" HIC "��\n" NOR;
        last_time_read = me->query("last_read_news");
        i = sizeof(notes);
        while (i--)
        {
#ifdef DB_SAVE

     	if (raw && (notes[i][TIME] <= last_time_read))
             	break;

                msg += sprintf("%s[%3d]" NOR " %-" + (40 + color_len(notes[i][TITLE])) +
                               "s %s (%s) [%3d]\n",
                               (notes[i][TIME] > last_time_read ? HIY : ""),
                               i + 1, notes[i][TITLE],
                               // notes[i][AUTHOR], ctime(notes[i][TIME])[0..15], notes[i][VIEW]);
                               "NITAN3", ctime(notes[i][TIME])[0..15], notes[i][VIEW]);
#else
	if (raw && (notes[i]["time"] <= last_time_read))
        	break;

       	msg += sprintf("%s[%3d]" NOR " %-" + (40 + color_len(notes[i]["title"])) +
                               "s %16s (%s)\n",
                               (notes[i]["time"] > last_time_read ? HIY : ""),
                               i + 1, notes[i]["title"],
                               // notes[i]["author"], ctime(notes[i]["time"])[0..15]);
                               "NITAN3", ctime(notes[i]["time"])[0..15]);
#endif
        }

        if (i == sizeof(notes) - 1)
        {
                tell_object(me, "Ŀǰû���κ�δ���������š�\n");
                return;
        }

        msg += HIC "��" HIY "������������������������������������������������������������������������������" HIC "��\n" NOR;

        me->start_more(msg);
}

// �˺�������Ҵ� F_EDIT �б༭��ɺ����
#ifdef DB_SAVE
void done_post(object me, mixed *note, int n, string text)
#else
void done_post(object me, mapping note, int n, string text)
#endif
{
        int i;
        int pl;
        string sign;
        string pure;
        mapping *notes;
#ifdef DB_SAVE   
        int t;     
        string sql;
#endif
        
        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // �Զ�ѡ���һ���ǿ�ǩ��
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        }

        text = color_filter(text) + NOR;
#ifdef DB_SAVE
        note[MSG] = text;
        t = sizeof(note);
        sql = "";

        for (i = 0; i < t; i++)
        {
                if (stringp(note[i]))
                        sql += sprintf("\"%s\"", note[i]);
                else if (intp(note[i]))
                        sql += sprintf("%d", note[i]);
                else sql += sprintf("%O", note[i]);
                
                if (i != t - 1)
                        sql += ",";
        }
        // write(sql);
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();           
        DATABASE_D->db_query(sprintf("INSERT INTO %s VALUES (%s)",
                                     NEWS_TABLE, sql));
#else
        note["msg"] = text;
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        // Truncate the notes if maximum capacity exceeded.
        if (sizeof(notes) > MAX_NEWS_CAPACITY)
                notes = notes[MAX_NEWS_CAPACITY / 4 .. MAX_NEWS_CAPACITY];

        set("notes", notes);
#endif
        tell_object(me, "���ŷ�����ϡ�\n");
        message("system", BLINK HIW "\n�����ž��顿�����������ţ���λ������� news �鿴��\n\n" NOR,     
                users()); 
        save();
}

// ��������
void do_post(object me, string arg)
{
        int n;
#ifdef DB_SAVE
        mixed *note;
#else
        mapping note;
#endif
        /*
        if (! VERSION_D->is_release_server())
        {
                tell_object(me, "ֻ���ڰ汾������վ����ܷ������š�\n");
                return;
        }
        */

        if (! wizardp(me) || ! interactive(me))
        {
                tell_object(me, "ֻ����ʦ���ܷ������š�\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "����������ָ��һ�����⡣\n");
                return;
        }

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "�ޱ���";
        else
                arg = color_filter(arg) + NOR;
#ifdef DB_SAVE
        note = allocate(5);
        note[TITLE] = arg;
        note[AUTHOR] = me->name(1) + "-" + me->query("id");
        note[TIME] = time();
        note[VIEW] = 0;
#else
        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = me->name(1) + "-" + me->query("id");
        note["time"] = time();
#endif
        me->edit(bind((: call_other, __FILE__, "done_post", me, note, n :), me));
}

// �Ķ�����
void do_read(object me, string arg)
{
        int num;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
#ifdef DB_SAVE
        notes = query_notes();
#else
        notes = query("notes");
#endif
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "�������һ�����ţ�\n");
                return;
        }

        if (arg == "new" || arg == "next")
        {
                if (! last_read_time)
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
#ifdef DB_SAVE
                                if (notes[num - 1][TIME] > last_read_time)
#else
                                if (notes[num - 1]["time"] > last_read_time)
#endif
                                        break;
        } else
        if (! sscanf(arg, "%d", num))
        {
                tell_object(me, "��Ҫ���ڼ������ţ�\n");
                return;
        }

        if (num < 1 || num > sizeof(notes))
        {
                tell_object(me, "û���������š�\n");
                return;
        }
        num--;
#ifdef DB_SAVE
        me->start_more(sprintf(HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n"
        		       NOR "[%3d] %-" + (40 + color_len(notes[num][TITLE])) +
                               "s %s (%s)\n" HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n" NOR,
                               num + 1, notes[num][TITLE], notes[num][AUTHOR],
                               ctime(notes[num][TIME])[0..9]) + notes[num][MSG]);
        // ��ӵ�� / �Ķ�����
        add_view_time(notes[num], 1);
        // ��¼����ϴ��Ķ����ŵ�ʱ��
        if (notes[num][TIME] > (int)last_read_time)
                me->set("last_read_news", notes[num][TIME]);
#else
        me->start_more(sprintf(HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n"
                               NOR " [%3d] %-" + (40 + color_len(notes[num]["title"])) +
                               "s %15s (%s)\n" HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n\n" NOR,
                               // num + 1, notes[num]["title"], notes[num]["author"],
                               num + 1, notes[num]["title"], "NITAN3",
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
#endif
}

// ɾ������
void do_discard(object me, string arg)
{
        mixed *notes;
        int num;
        //string author, aid, sql;
        string author, aid;

        if (! arg || sscanf(arg, "%d", num) != 1)
        {
                tell_object(me, "����ȥ����һ�����ţ�\n");
                return;
        }
#ifdef DB_SAVE
        notes = query_notes();
#else
        notes = query("notes");
#endif
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
        {
                tell_object(me, "û���������š�\n");
                return;
        }

        num--;
#ifdef DB_SAVE
        string sql;
        if ((! stringp(author = notes[num][AUTHOR]) ||
             sscanf(author, "%*s-%s", aid) != 2 ||
             aid != me->query("id")) &&
            (string)SECURITY_D->get_status(me) != "(admin)")
        {
                tell_object(me, "ֻ���������ȥ�����˷��������š�\n");
                return;
        }
        sql = sprintf("DELETE FROM %s WHERE title = \"%s\" AND time = %d AND author = \"%s\" AND msg = \"%s\"",
                      NEWS_TABLE, notes[num][TITLE], notes[num][TIME], notes[num][AUTHOR], notes[num][MSG]);
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();                         
        DATABASE_D->db_query(sql);
#else
        if ((! stringp(author = notes[num]["author"]) ||
             sscanf(author, "%*s-%s", aid) != 2 ||
             aid != me->query("id")) &&
            (string)SECURITY_D->get_status(me) != "(admin)")
        {
                tell_object(me, "ֻ���������ȥ�����˷��������š�\n");
                return;
        }

        notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
        set("notes", notes);
        save();
#endif
        tell_object(me, "ɾ���� " + (num + 1) + " ������....Ok��\n");
}

// �Զ�֪ͨ���
void auto_notice(object me)
{
        int num;
        mixed *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
#ifdef DB_SAVE
        notes = query_notes();
#else
        notes = query("notes");
#endif

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
#ifdef DB_SAVE
        if (notes[num][TIME] <= last_read_time)
#else
        if (notes[num]["time"] <= last_read_time)
#endif
                return;

        // ����һЩ���Ŵ�������ʼ�µ� call_out
        me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
#ifdef DB_SAVE
                if (notes[num][TIME] <= last_read_time)
#else
                if (notes[num]["time"] <= last_read_time)
#endif
                {
                        num++;
                        break;
                }

                // ����������һ��
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "һ������������ž�������������ǰ������"
                      "����һ���������õ�ֽͷ����������������\n" NOR;
                break;
        case 1:
                msg = HIM "����ͻȻ����һ���ѷ죬ð��һ������������"
                      "�ž��飬��������ੲ��ݵ�����������\n" NOR;
                break;
        case 2:
                msg = HIM "���Ȼ�������˺��㣬���ͷһ����ԭ��������"
                      "������ͷ�󺹵����˹�����\n" NOR;
                break;
        case 3:
                msg = HIM "��մ���һ����Ƿ����Ȼǰ��ð��һ������ɢ"
                      "ȥ�Ժ�ֻ��һ�����ž���������Ŀ����㣬���������дʡ�\n" NOR;
                break;
        default:
                msg = HIM "��ž����һ�������ž����Ǳ�������ˤ�ڵ��ϣ�"
                      "����æ��������\n" NOR;
                break;
        }

        msg += HIG "���ž����������������������Ϣ��\n" NOR;
        tell_object(me, msg);
#ifdef DB_SAVE
        me->start_more(sprintf(HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n"
                               NOR "[%3d] %-" + (40 + color_len(notes[num][TITLE])) + "s %s (%s)\n"
        		       HIC "��" HIY "������������������������������������"
        		       "������������������������������������������" HIC "��\n" NOR,
                               // num + 1, notes[num][TITLE], notes[num][AUTHOR],
                               num + 1, notes[num][TITLE], "NITAN3",
                               ctime(notes[num][TIME])[0..9]) + notes[num][MSG]);
        // ��ӵ�� / �Ķ�����
        add_view_time(notes[num], 1);

        // ��¼����ϴ��Ķ����ŵ�ʱ��
        if (notes[num][TIME] > (int)last_read_time)
                me->set("last_read_news", notes[num][TIME]);
#else
        me->start_more(sprintf(HIC "��" HIY "������������������������������������"
                               "������������������������������������������" HIC "��\n"
                               NOR "[%3d] %-" + (40 + color_len(notes[num]["title"])) + "s %15s (%s)\n"
        		       HIC "��" HIY "������������������������������������"
        		       "������������������������������������������" HIC "��\n" NOR,
                               // num + 1, notes[num]["title"], notes[num]["author"],
                               num + 1, notes[num]["title"], "NITAN3",
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
#endif
        tell_object(me, HIM "���ž���˵�����ʧ��һ������֮�С�\n" NOR);
}

void do_search(object me, string arg)
{
        mixed *notes;
        int i, last_time_read, j;
        string msg, topic, theway;

#ifdef DB_SAVE
        notes = query_notes();;
#else
        notes = query("notes");
#endif        
        if (! arrayp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }
        
        if (! arg)
        {
                tell_object(me, "����������һ�����ţ�\n");
                return;
        }
        
        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");   
                return;
        } else
        {
                if (topic == "title") 
                        theway = "����";
                else
                if (topic == "author") 
                        theway = "����";
                else
                if (topic == "document") 
                        theway = "����";
                else
                {
                        tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");  
                        return;
                }
        }
                             
        last_time_read = me->query("last_read_news");       

        msg = sprintf("���� " HIY "%s" NOR " ���� " HIY "%s" NOR " �õ����·����������ţ�\n"           
                      HIC "��" HIY "������������������������������������������������������������������������������" HIC "��\n" NOR,
                      arg, theway);   
                      
        i = sizeof(notes);   
        j = 0;             
        while (i--)
        {
                if (topic == "document")
                {
#ifdef DB_SAVE   
                        if (strsrch(notes[i][MSG], arg) == -1)                        
#else
                        if (strsrch(notes[i]["msg"], arg) == -1)
#endif
                                continue;
                } else  
                { 
#ifdef DB_SAVE   
                        if (topic == "title")
                        {
                                if (strsrch(notes[i][TITLE], arg) == -1) 
                                        continue;
                        }  else
                        if (topic == "author")
                        {
                                if (strsrch(notes[i][AUTHOR], arg) == -1) 
                                        continue;
                        }                                            
#else                                             
                        if (strsrch(notes[i][topic], arg) == -1)
                                continue;
#endif
                }
                
                j++;
#ifdef DB_SAVE   
                msg += sprintf("%s[%3d]" NOR " %-" + (40 + color_len(notes[i][TITLE])) +
                               "s %s (%s)\n",
                               (notes[i][TIME] > last_time_read ? HIY : ""),
                               i + 1, notes[i][TITLE],
                               notes[i][AUTHOR], ctime(notes[i][TIME])[0..15]);  
#else                
                msg += sprintf("%s[%3d]" NOR " %-" + (40 + color_len(notes[i]["title"])) +
                               "s %s (%s)\n",
                               (notes[i]["time"] > last_time_read ? HIY : ""),
                               i + 1, notes[i]["title"],
                               notes[i]["author"], ctime(notes[i]["time"])[0..15]);  
#endif 
                if (j > 99)
                { 
                        msg += HIW "\n�����������Ľ��̫�࣬���ֻ��ʾһ�������ţ���ʹ�ø���ȷ�Ĺؼ���|�ʡ�\n" NOR;
                        break;
                }
        }  

        if (j == 0)
        {
                tell_object(me, "���� " HIY + arg + NOR " ���� " HIY + theway + NOR " û���ҵ�����Ҫ������š�\n");
                return;
        } 
        
        msg += HIC "��" HIY "������������������������������������������������������������������������������" HIC "��\n" NOR;

        me->start_more(msg);  
}      

string query_save_file() { return DATA_DIR "newsd"; }
