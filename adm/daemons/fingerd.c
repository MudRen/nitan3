// fingerd.c

#include <net/dns.h>
#include <net/messaged.h>
#include <ansi.h>

#include <mudlib.h>
#include "/adm/etc/database.h"

int sort_by_ip(object ob1, object ob2);

void create() { seteuid( getuid() ); }

int sort_by_ip(object ob1, object ob2)
{
        string ip1, ip2;

        if (! wizardp(ob1) && wizardp(ob2))
                return -1;

        if (wizardp(ob1) && ! wizardp(ob2))
                return 1;

        if (interactive(ob1) && ! interactive(ob2))
                return -1;

        if (! interactive(ob1) && interactive(ob2))
                return 1;

        if (interactive(ob1) && interactive(ob2))
        {
                ip1 = query_ip_number(ob1);
                ip2 = query_ip_number(ob2);
                if (ip1 != ip2)
                        return strcmp(ip1, ip2);
        }

        return strcmp(getuid(ob1), getuid(ob2));
}

string age_string(int time)
{
        int month, day, hour, min, sec;

        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "m":"") + (day?day + "d":"") + 
        (hour?hour + "h":"") + min + "m";
}

string user_list(object *ob, int flag)
{
        object me;
        string msg;
        string ipname;
        int admin;
        int i;

        if (! ob || ! sizeof(ob))
                return "û���κη�����������ҡ�\n";
        me = this_player();
        admin = me->is_admin() || (SECURITY_D->query_site_privilege("finger") == "enable");
        msg = "������������������������������������������������"
              "������������������\n" +
              BBLU WHT "����          �ʺ�          ����          ����   ����             \n" NOR +
              "������������������������������������������������"
              "������������������\n";
        for(i = 0; i < sizeof(ob); i++)
        {
                if (me && ! me->visible(ob[i])) continue;
                //ipname = query_ip_name(ob[i]);
                ipname = admin ? query_ip_number(ob[i]) : "--------";
                msg = sprintf("%s%s%-14s%s%-14s%-14s%s%-7s" NOR "%s\n",
                        msg, (ob[i]->name() != ob[i]->name(flag) ? HIM : NOR),
                        ob[i]->name(flag), NOR, ob[i]->query("id"),
                        age_string( (int)ob[i]->query("mud_age")), 
                        (interactive(ob[i]) ? ((query_idle(ob[i]) >= 120) ? HIG : NOR) : ob[i]->query("doing") == "closed" ? HIY : HIR),
                        (interactive(ob[i]) ? (query_idle(ob[i]) + "s") : ob[i]->query("doing") == "closed" ? "�չ�" : "����"), ipname);
        }

        msg += "������������������������������������������������"
               "������������������\n";
        return msg;
}

varargs string finger_all(int idle)
{
        object *ob,*login_ob;
        //string msg, fip;
        string msg;
        int i;
        int admin;
        object me;

        me = this_player();
        ob = users();
        msg = "";
        admin = me->is_admin() || (SECURITY_D->query_site_privilege("finger") == "enable");
        if (wiz_level(me) < 2)  // player finger
        {
                for (i = 0; i < sizeof(ob); i++)
                {
                        if (me && ! me->visible(ob[i])) continue;
                        msg = sprintf("%s%-14s%-14s%-14s\n",
                                msg, ob[i]->query("name"), ob[i]->query("id"),
                                (interactive(ob[i]) ? (query_idle(ob[i]) + "s") : HIR "������" NOR));
                }
                return "�� " + MUD_NAME + "\n" +
                       "������������������������������������\n"
                       + "����          �ʺ�          ����\n" +
                       "������������������������������������\n"
                       + msg +
                       "������������������������������������\n";
        } else         // wizard finger
        {
                string *counter;
                string ipname;
                int pcnt;
                int lcnt;

                pcnt = 0;
                lcnt = 0;
                counter = ({ });
                if (idle)
                        ob = filter_array(ob, (: interactive($1) && !query_idle($1) :) );
                if (admin) 
                        ob = sort_array(ob, (: sort_by_ip :));
                for(i = 0; i < sizeof(ob); i++)
                {
                        if (me && ! me->visible(ob[i])) continue;
                        //ipname = query_ip_name(ob[i]);
                        ipname = query_ip_number(ob[i]);
                        if (environment(ob[i]))
                        {
                                pcnt++;
                                if (interactive(ob[i]) &&
                                    member_array(ipname, counter) == -1 )
                                        counter += ({ ipname });
                        } 
                }

                login_ob = children("/clone/user/login");
                login_ob = filter_array(login_ob, (: query_ip_number($1) :) );
                lcnt = sizeof(login_ob);

                msg = WHT "�� " + MUD_NAME + "\n" NOR + user_list(ob, 1) +
                      sprintf("%d�������������%d����ͬ�ĵص㣬"
                              "%s��ҽ�����Ϸ�С�\n\n",
                              pcnt, sizeof(counter),
                              lcnt ? (string) lcnt + "��" : "Ŀǰû��");
                return msg;
        }
}

// convert ip number into the type which database
// can understand
string resolve_ip_number(string ip_number)
{
        string part, *parts;
        string full;

        parts = explode(ip_number, ".");
        full = "";
        foreach (part in parts)
                full += replace_string(sprintf("%3s", part), " ", "0");
        return full;
}

varargs string finger_user(string name, mixed me)
{
        object ob, body;
       // string msg, mud, where;
        string msg,mud;
        int public_flag;
        string cname;
        //string email, *ret;
        string email;
        //string sql, ip_number;        
        //string info;
        //string *res;  
       // int flag;
        int admin;
        object *uob;
        int same;
        //int i;

        if (! me) me = this_player();
        if (sscanf(name, "%s@%s", name, mud) == 2)
                if (msg = GFINGER_Q->send_gfinger_q(mud, name, me))
                        return msg;

        admin = me->is_admin() || (SECURITY_D->query_site_privilege("finger") == "enable");
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if (! ob->restore())
        {
                destruct(ob);
                return "û�������ҡ�\n";
        }

        if (objectp(body = find_player(name)) && getuid(body) == name)
        {
                public_flag = body->query("env/public") ? 1 : 0;
                cname = body->query("name");
                email = body->query("email");
        } else
        {
                body = LOGIN_D->make_body(ob);
                if (! body->restore())
                {
                        destruct(ob);
                        destruct(body);
                        return "û�������ҡ�\n";
                }
                public_flag = body->query("env/public") ? 1 : 0;
                cname = body->query("name");
                email = body->query("email");
                destruct(body);
        }

        if (objectp(me) && me->query("id") == name ||
            stringp(me) && me == name)
                public_flag = 1;

        if (wiz_level(me) < 2)  // player finger
        {
                msg =  sprintf("Ӣ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
                        "�����ʼ���ַ��\t%s\n�ϴ����ߣ�\t%s\n",
                        ob->query("id"),
                        cname,
                        SECURITY_D->get_status(name),
                        (public_flag) ? email : "��������",
                        ctime(ob->query("last_on")));

                if (objectp(body = find_player(name)) &&
                    getuid(body) == name &&
                    MESSAGE_D->visible(me, body))
                {
                        if (interactive(body))
				msg += sprintf("\n%sĿǰ���������С�\n", cname);
                        else
                                msg += sprintf("\n%sĿǰ�����С�\n", cname);
                }
        } else          // wizard finger
        {
                msg =  sprintf("Ӣ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
                        "�����ʼ���ַ��\t%s\n�ϴ����ߵ�ַ��\t%s( %s )\n",
                        ob->query("id"),
                        cname,
                        SECURITY_D->get_status(name),
                        email,
                        ob->query("last_from"),
                        ctime(ob->query("last_on"))
                );

                if (objectp(body = find_player(name)) &&
                    getuid(body) == name &&
                    MESSAGE_D->visible(me, body))
                {
                        if (interactive(body))
                        {
                                if (admin)
                                {
                                        uob = filter_array(all_interactive(),
                                                (: query_ip_number($1) == $(query_ip_number(body)) :));
                                        same = sizeof(uob);
#ifdef DB_SAVE
                                        string *ret;
                                        string where,sql,ip_number; 
                                        ip_number = resolve_ip_number(query_ip_number(body));
                                        sql = sprintf("SELECT place FROM %s WHERE start <= \"%s\" AND"
                                                      " end >= \"%s\" ORDER BY end LIMIT 1", IP_TABLE,
                                                      ip_number, ip_number);
                                        if (sizeof(ret = DATABASE_D->db_fetch_row(sql)))
                                        {
                                                where = ret[0];
        				        msg += sprintf("\n%sĿǰ���ڴ� %s (%s) ������", cname,
        				                       query_ip_number(body), where);
                                        } else 
#endif
                                                msg += sprintf("\n%sĿǰ���ڴ� %s ������", cname,
        				                       query_ip_number(body));
                                        if (same > 1)
                                        {
                                                msg += sprintf("���õ�ַһ���� %d λʹ���ߡ�\n", same);
                                                if (previous_object() != find_object(MESSAGE_D))
                                                        // I won't return the list if this is
                                                        // called from a chat user
                                                        msg += user_list(uob, 1);
                                        } else
                                                msg += "��\n";
                                } else
                                        msg += sprintf("\n%sĿǰ���������С�\n", cname);
                        } else
                                msg += sprintf("\n%sĿǰ�����С�\n", cname);
                                
                        if (body->name() != body->name(1))
                                msg += sprintf("�����Ŀǰ��%s����ж���\n", body->name());
                }
        }       

        if (! objectp(body) &&
            MESSAGE_D->query_connection(name) &&
            MESSAGE_D->visible(me, name))
        {
                msg += "\n" + cname + "Ŀǰ���������С�\n";
        }

#ifdef DB_SAVE
        //string info;
        string *res;  
        int flag;
                        
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();  

        res = DATABASE_D->do_sql("select online, last_station from users where id = '" + name + "'");
        flag = arrayp(res);
        if (flag && MESSAGE_D->visible(me, name))
        {
                if ((int)res[0] == 3)
                        msg += sprintf("%s������Ŀǰ���������С���\n", cname);
                else
                {
                        where = res[1];
                        if (stringp(where) && where != LOCAL_STATION)
                        {
                                if ((int)res[0] == 2)
                                        msg += sprintf("\n%sĿǰ����%sվ��չ��С�\n",
			                               cname, ! undefinedp(stations[where]) ? stations[where] : "����",
			                               ! undefinedp(stations[where]) ? stations[where] : "����");
			        else
			        if ((int)res[0] == 1)
			                msg += sprintf("\n%sĿǰ����%sվ�������С�\n",
			                               cname, ! undefinedp(stations[where]) ? stations[where] : "����",
			                               ! undefinedp(stations[where]) ? stations[where] : "����"); 
			        else
			        if ((int)res[0] == 0) 
			                msg += sprintf("\n%sĿǰ����%sվ�㣬��û�����߽�����Ϸ��\n",
			                               cname, ! undefinedp(stations[where]) ? stations[where] : "����",
			                               ! undefinedp(stations[where]) ? stations[where] : "����");
                        } 
                }
        }
#endif
        destruct(ob);
        return msg;
}

string get_killer()
{
        int i;
        string msg;
        object *ob = users();

        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition("killer"))
                        msg += (ob[i]->short() + "\n");
        if (msg == "")
                return "�����ΰ����á�\n";
        else
                return "���ڱ������ڼ��������˷���\n\n" + msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
        object ob, body;
        string msg;
        //mapping conn;
        int public_flag;
        string cname, email;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if (! ob->restore())
        {
                destruct(ob);
                return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";
        }

        if (objectp(body = find_player(name)) && getuid(body) == name)
        {
                public_flag = body->query("env/public") ? 1 : 0;
                cname = body->query("name");
                email = body->query("email");
        } else
        {
                body = LOGIN_D->make_body(ob);
                if (! body->restore())
                {
                        destruct(ob);
                        destruct(body);
                        return "û�������ҡ�\n";
                }
                public_flag = body->query("env/public") ? 1 : 0;
                cname = body->query("name");
                email = body->query("email");
                destruct(body);
        }

        if (! public_flag)
                email = "��������";

        if (chinese_flag)
                msg = sprintf("Ӣ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
                              "�����ʼ���ַ��\t%s\n�ϴ����ߣ�\t%s\n",
                              ob->query("id"),
                              SECURITY_D->get_status(name),
                              cname, email,
                              ctime(ob->query("last_on")));
        else msg =  sprintf("Name\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s\n",
                            capitalize(ob->query("id")),
                            SECURITY_D->get_status(name),
                            email,
                            ctime(ob->query("last_on")));

        if (objectp(body = find_player(name)) &&
            ! body->query("env/invisible"))
        {
                if (chinese_flag)
                        msg += "\n" + cname + "Ŀǰ���������С�\n";
                else
                        msg += "\n" + capitalize(name) + " is currently connected.\n";
        }
        if (objectp(body = MESSAGE_D->query_connection(name)) &&
            ! body->query("env/invisible"))
        {
                if (chinese_flag)
                        msg += "\n" + cname + "Ŀǰ���������С�\n";
                else
                        msg += "\n" + capitalize(name) + " is connected to chat now.\n";
        }

        destruct(ob);
        return msg;
}

object acquire_login_ob(string id)
{
        object ob;

        if( ob = find_player(id) ) {
                // Check if the player is linkdead
                if( ob->query_temp("link_ob") )
                        return ob->query_temp("link_ob");
        }
        ob = new(LOGIN_OB);
        ob->set("id", id);
        return ob->restore() ? ob : 0;
}

