// dboard.c

#include <ansi.h>
#include <board.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;

// �Ƿ����۰壿
int is_board()  { return 1; }

// create() ʱ���ã���Ҫ���ڸ������ݿ��ڱ�������Ϣ����
// ����ĳ�������
void setup()
{
        string loc;
        string my_long, my_id;

        if (stringp(loc = query("location")))
                move(loc);
        /*
        my_long = BOARD_D->query_forum_info(this_object(),
                                            "forum_desc");
        */
        my_long = query("long");
        my_id = query("board_id");

        set("no_get", 1);
        set("long", my_long + "\n");
        set("id", my_id);
        set("location", loc);
}

void init()
{
        add_action("do_post", "post");
        add_action("do_read", "read");
        add_action("do_discard", "delete");        
        add_action("do_discard", "discard");
}

// ����Ķ�������Ҫ����δ��������/��������
string short()
{
        mapping *notes;
        int i, unread, last_read_time;
        object me;
        int mode;
        int time;
        int max;
        object ob;
        string str;

        if (! objectp(me = this_player()))
                return ::short();

        ob = this_object();
        mode = is_bbs_mode(me);
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();        
        notes = (mode ? BOARD_D->query_all_posts(ob)
                      : BOARD_D->query_all_topics(ob));
        time = (mode ? POST_TIME : TOPIC_TIME);

        str = mode ? "����" : "����";

        if (! arrayp(notes) || ! sizeof(notes))
                return ::short() + " [ û���κ�" + str + " ]";

        last_read_time = me->query("board_last_read/" + query("board_id"));
        max = sizeof(notes) - 1;

        for (unread = 0, i = max; i >= 0; i--, unread++)
                if (notes[i][time] <= last_read_time) break;

        max++;
        if (unread)
                return sprintf(HIC + "%s" + NOR + " [ %d ƪ%s��" + HIY + "%d" + NOR + " ƪ" +
                               HIR + "δ��" + NOR + "]", ::short(), max, str, unread);
        else
                return sprintf("%s [ " WHT "%d" NOR " ƪ%s ]", ::short(), max, str);
}

// ����ĳ�������������������/������б�
string long()
{
        mixed *notes;
        mixed *pinfo, *tinfo;
        int i, last_time_read;
        string msg, title;
        object me;

        me = this_player();
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
        // bbs ģʽ
        if (is_bbs_mode(me))
        {
                notes = BOARD_D->query_all_posts(this_object());
                msg = sprintf("�� " HIW "%s" NOR " ��(" WHT "%s" NOR ")\n%s"
                              "\n" WHT "Ŀǰ���е������У�\n" NOR
                              "������������������������������������������������"
                              "��������������������������\n", query("name"), 
                              sprintf(FORUM_URL, query("forum_id")),
                              query("long"));
                if (! arrayp(notes) || ! sizeof(notes)) return query("long");

                last_time_read = me->query("board_last_read/" + query("board_id"));
                i = sizeof(notes) - 200;
                if (i < 0) i = 0;
                for (; i < sizeof(notes); i++)
                {
                        // ���� 1 �����򲻷��� msg
                        pinfo = BOARD_D->query_post_info(notes[i][POST_ID], 1);
                        if (pinfo[POST_SUBJECT] == "")
                        {
                                tinfo = BOARD_D->query_topic_info(notes[i][TOPIC_ID]);
                                title = (sizeof(tinfo) ? ("Re: " + tinfo[TOPIC_TITLE])
                                                       : pinfo[POST_SUBJECT]);
                        }
                        else title = pinfo[POST_SUBJECT];

                        msg += sprintf(WHT "%s[%2d]" NOR "  %-40s " WHT "%s " NOR "(%s)\n",
                                       (notes[i][POST_TIME] > last_time_read ? HIY : WHT),
                                       i + 1, title, 
                                       BOARD_D->query_user_name(notes[i][POSTER_ID]), 
                                       ctime(notes[i][POST_TIME])[0..15]);
                }
                msg += "��������������������������������������������������������"
                       "������[ " WHT "BBS ģʽ" NOR " ]\n\n";
        } else
        {
                // ���� 1 �����򲻷��غ�����
                notes = BOARD_D->query_all_topics(this_object(), 1);
                msg = sprintf("�� " HIW "%s" NOR " ��(" WHT "%s" NOR ")\n%s"
                              "\n" WHT "Ŀǰ���е������У�\n" NOR
                              "������������������������������������������������"
                              "��������������������������\n", query("name"), 
                              sprintf(FORUM_URL, query("forum_id")),
                              query("long"));

                if (! arrayp(notes) || ! sizeof(notes)) return query("long");
                
                last_time_read = me->query("board_last_read/" + query("board_id"));
                i = sizeof(notes) - 200;
                if (i < 0) i = 0;
                for (; i < sizeof(notes); i++)
                {
                        msg += sprintf(WHT "%s[%2d]" NOR "  %-40s " WHT "%s " NOR "(%s)\n",
                                       (notes[i][TOPIC_TIME] > last_time_read ? HIY : WHT),
                                       i + 1, notes[i][TOPIC_TITLE], 
                                       BOARD_D->query_user_name(notes[i][TOPIC_POSTER]), 
                                       ctime(notes[i][TOPIC_TIME])[0..15]);
                }
                msg += "��������������������������������������������������������"
                       "������[ " WHT "Web ģʽ" NOR " ]\n\n";
        }
        return msg;
}

// �⽫���������е� F_EDIT ����
void done_post(object me, string title, string text)
{
        int i;
        mapping *notes;
        string *lines;
        int topic_id;
        int mode;
        int num;
        object ob;

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

        // ���������ʽ����
        text = replace_string(text, "  ", "��");
        ob = this_object();
        mode = is_bbs_mode(me);
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
        if (title == "re last") topic_id = BOARD_D->query_number_topic(ob, -1, mode);
        if (sscanf(title, "re last %d", num)) topic_id = BOARD_D->query_number_topic(ob, -num, mode);
        if (sscanf(title, "re %d", num)) topic_id = BOARD_D->query_number_topic(ob, (num - 1), mode);

        // �ظ������⣿
        if (topic_id)
        {
                if (! BOARD_D->reply_topic(ob, topic_id, 
                                           me->query("id"), text,
                                           query_ip_number(me)))
                        tell_object(me, "�ظ�ʧ�ܣ�������ʦ��ѯԭ��\n");
                else
                        tell_object(me, "�ظ���ϡ�\n");
                return;
        }

        // ���������⣿
        if (! BOARD_D->post_new_topic(ob, title, 
                                      me->query("id"), text,
                                      query_ip_number(me)))
        {
                tell_object(me, "����ʧ�ܣ�������ʦ��ѯԭ��\n");
                return;
        }

        tell_object(me, "������ϡ�\n");
        return;
}

int do_post(string arg, int n)
{
        object me;

        if (! arg)
                return notify_fail("����������ָ��һ�����⡣\n");

        me = this_player();
        if (wiz_level(me) < 1)
        {
                if (me->query("mud_age") < 1800)
                        return notify_fail("����������ע����ʮ�����Ժ����ʹ�����۰棬���"
                                           "ʱ���������Ķ����˵����ԡ�\n");

                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã���Ϣһ�����˵�ɡ�\n");

                me->receive_damage("jing", 50);
        }

        if (replace_string(arg, " ", "") == "")
                arg = "�ޱ���";

        me->edit((: done_post, me, arg :));
        return 1;
}

int do_read(string arg)
{
        object me, ob;
        int num, t, mode, time, max;
        mapping last_read_time;
        mixed *notes, *replies, *reply;
        mixed *pinfo, *tinfo;
        string myid, msg, title;

        me = this_player();
        ob = this_object();
        last_read_time = me->query("board_last_read");
        myid = query("board_id");
        // �Ƿ�ʹ�� bbs ģʽ��
        mode = is_bbs_mode(me);

        if (! arg) return notify_fail("ָ���ʽ��read <���� / ������> | new | next\n");

        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
        // ��ñ�����������        
        notes = (mode ? BOARD_D->query_all_posts(ob)
                      : BOARD_D->query_all_topics(ob));
        time = (mode ? POST_TIME : TOPIC_TIME);

        if (! sizeof(notes)) return notify_fail("���۰���û���κ����¡�\n");

        if (arg == "new" || arg == "next")
        {
                if (! mapp(last_read_time) || undefinedp(last_read_time[myid]))
                        num = 1;
                else
                {
                        max = sizeof(notes);
                        for (num = 1; num <= max; num++)
                        {
                                if (notes[num - 1][time] > last_read_time[myid])
                                        break;
                        }
                }
        } else
        if (! sscanf(arg, "%d", num))
                return notify_fail("��Ҫ���ڼ�ƪ���£�\n");

        if (num < 1 || num > sizeof(notes))
                return notify_fail("û����ƪ���¡�\n");
        num--;

        // bbs ģʽ
        if (mode)
        {
                // ������ص�һЩ��Ϣ
                pinfo = BOARD_D->query_post_info(notes[num][POST_ID]);
                // ������ʱ��
                t = notes[num][POST_TIME];
                tinfo = BOARD_D->query_topic_info(notes[num][TOPIC_ID]);
                title = ((sizeof(tinfo) && pinfo[POST_SUBJECT] == "") ? ("Re: " + tinfo[TOPIC_TITLE]) :
                        pinfo[POST_SUBJECT]);

                msg = sprintf("[" WHT "%3d" NOR "]" WHT " %-40s " NOR "(%s) [ " WHT "%s" NOR " ]\n"
                              "����������������������������������������������������������"
                              "����������������\n" NOR "%s\n����������������������"
                              "����������������������������������������[ " WHT "BBS ģʽ" 
                              NOR " ]\n" NOR, num + 1,
                              title, ctime(t)[0..9], 
                              BOARD_D->query_mud_name(notes[num][POSTER_ID]), pinfo[POST_TEXT]);

                BOARD_D->add_topic_view(notes[num][TOPIC_ID], 1);

                // ��������ƪ����Ļظ���
                if (sizeof(tinfo))
                        msg += sprintf("���������� " WHT "%s" NOR " (%d) ��%s��\nWeb ��ַ�� " WHT "(%s)" NOR, 
                                       tinfo[TOPIC_TITLE], BOARD_D->query_topic_number(ob, tinfo[TOPIC_ID]),
                                       (tinfo[TOPIC_FIRST_ID] == notes[num][POST_ID] ? "����" : "�ظ�"),
                                       sprintf(TOPIC_URL, tinfo[TOPIC_ID]));
        } else
        {
                pinfo = BOARD_D->query_post_info(notes[num][TOPIC_FIRST_ID]);
                t = notes[num][TOPIC_TIME];

//              DEBUG_MSG(sprintf(HIC "notes[num] = " WHT "%O\n" NOR, notes[num]));
//              DEBUG_MSG(sprintf(HIC "pinfo = " WHT "%O\n" NOR, pinfo));

                msg = sprintf("[" WHT "%3d" NOR "]" WHT " %-40s " NOR "(%s) [ " WHT "%s" NOR " ]\n"
                              "����������������������������������������������������������"
                              "����������������\n" NOR "%s\n����������������������"
                              "����������������������������������������[ " WHT "Web ģʽ" 
                              NOR " ]\nWeb ��ַ��" WHT "(%s)" NOR, num + 1,
                              notes[num][TOPIC_TITLE], ctime(t)[0..9], 
                              BOARD_D->query_mud_name(notes[num][TOPIC_POSTER]), pinfo[POST_TEXT],
                              sprintf(TOPIC_URL, notes[num][TOPIC_ID]));

                BOARD_D->add_topic_view(notes[num][TOPIC_ID], 1);

                // �Ƿ��лظ��أ�
                if (notes[num][TOPIC_REPLIES])
                {
                        mode = me->query("env/reply_mode");

                        if (mode)
                        {
                                replies = BOARD_D->query_all_replies(notes[num][TOPIC_ID], 
                                                                     notes[num][TOPIC_FIRST_ID]);
                                switch (mode)
                                {
                                // ��ʾ���һƪ�ظ�
                                case 1 :
                                        reply = replies[sizeof(replies) - 1];
                                        pinfo = BOARD_D->query_post_info(reply[POST_ID]);
                                        t = reply[POST_TIME];

                                        msg += sprintf(WHT "\nRe: %-42s "
                                                       NOR "(%s) [ " WHT "%s" NOR " ]\n"
                                                       "��������������������������������"
                                                       "��������������������������������"
                                                       "����������\n" NOR "%s\n" NOR,
                                                       notes[num][TOPIC_TITLE], ctime(t)[0..9], 
                                                       BOARD_D->query_mud_name(reply[POSTER_ID]),
                                                       pinfo[POST_TEXT]);
                                        break;
                                // ��ʾ���лظ�
                                case 2 :
                                        foreach (reply in replies)
                                        {
                                                pinfo = BOARD_D->query_post_info(reply[POST_ID]);
                                                t = reply[POST_TIME];

                                                msg += sprintf(WHT "\nRe: %-42s "
                                                               NOR "(%s) [ " WHT "%s" NOR " ]\n"
                                                               "��������������������������������"
                                                               "��������������������������������"
                                                               "����������\n" NOR "%s\n" NOR,
                                                               notes[num][TOPIC_TITLE], ctime(t)[0..9], 
                                                               BOARD_D->query_mud_name(reply[POSTER_ID]),
                                                               pinfo[POST_TEXT]);
                                        }
                                        break;
                                }
                                msg += "����������������������������������������������������������"
                                       "����������������\n";
                        }
                        msg += "�����⹲�� " WHT + notes[num][TOPIC_REPLIES] + NOR " ƪ�ظ���\n";
                }
        }
        me->start_more(msg);

        // ��¼�ϴ��Ķ�������
        if (! mapp(last_read_time))
                me->set("board_last_read", ([ myid: t ]));
        else 
                if (undefinedp(last_read_time[myid]) || t > last_read_time[myid])
                        last_read_time[myid] = t;
        return 1;
}

int do_discard(string arg)
{
        mixed *pdata;
        mixed *tinfo;
        int num;
        int mode;
        int topic_id;
        int post_id;
        object me;
        object ob;
        
        me = this_player();
        ob = this_object();

        if (! arg || sscanf(arg, "%d", num) != 1)
                return notify_fail("ָ���ʽ��discard <���Ա��>\n");

        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
                
        mode = is_bbs_mode(me);
        if (mode)
        {
                post_id = BOARD_D->query_number_post(ob, num - 1);
                if (! post_id)
                        return notify_fail("û����ƪ���¡�\n");

                pdata = BOARD_D->query_post_data(post_id);

                if (BOARD_D->query_user_name(pdata[POSTER_ID]) != me->query("id") &&
                    wiz_level(me) < wiz_level("(wizard)"))
                        return notify_fail("��ƪ���²�����д�ģ���Ҳû��ɾ�����µ�Ȩ�ޡ�\n");

                BOARD_D->delete_post(ob, post_id);
                write("ɾ���� " + num + " ƪ����....Ok��\n");
                return 1;
        } else
        {
                topic_id = BOARD_D->query_number_topic(ob, num - 1, mode);
                if (! topic_id)
                        return notify_fail("û����ƪ���¡�\n");

                tinfo = BOARD_D->query_topic_info(topic_id);

                if (BOARD_D->query_user_name(tinfo[TOPIC_POSTER]) != me->query("id") &&
                    wiz_level(me) < wiz_level("(wizard)"))
                        return notify_fail("��ƪ���²�����д�ģ���Ҳû��ɾ�����µ�Ȩ�ޡ�\n");

                BOARD_D->delete_topic(ob, topic_id);
                write("ɾ���� " + num + " ƪ����....Ok��\n");
                return 1;
        }
}
