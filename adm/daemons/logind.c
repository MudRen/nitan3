// logind.c
// updated by Lonely for mysql and cruise

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <config.h>
#include <getconfig.h>
#include <mudlib.h>

#ifndef UNREG_IDLE
#define UNREG_IDLE      60
#endif
#define MUDLIST_CMD     "/cmds/usr/mudlist"
#define REBOOT_CMD      "/cmds/arch/reboot"
#define INVENTORY_CMD   "/cmds/usr/inventory"
#define MULTI_LOGIN     1
#define NO_FEE
#define NO_FEE_WARNING  "$$��ע�⡿Ϊ������Ա���棬����ǻ�Ա�� " + UNREG_IDLE + " ��֮��û���κλ��¼�����ｫ��ϵͳ�Զ������$$"
inherit F_DBASE;

#include "/adm/etc/database.h"

nosave int wiz_lock_level = 0;
nosave int cruise_lock_status = 0;

nosave mapping blocks = ([]);
nosave string *allows = ({});

string *banned_name = ({
        "��", "��", "��", "��", "��", "��",
        "��", "ү", "��", "��",
        "ʺ", "��", "��",
});

string *banned_id = ({
        "domain", "root", "mudlib", "quit",
        "arch", "wizard", "apprentice",
        "immortal", "player", "fuck", "doing", "admin",
        "all", "none", "cancel",
});

mapping day2num = ([
        "Mon"   : 1, "Tue"   : 2,
        "Wed"   : 3, "Thu"   : 4,
        "Fri"   : 5, "Sat"   : 6,
        "Sun"   : 7
]);

// �ڲ����õĺ���
protected void get_id(string arg, object ob);
protected void get_version(string arg, object ob);
protected void confirm_cruiseid(string yn, object ob);
protected void get_cruisepwd(string pass, object ob);
protected void get_passwd(string pass, object ob);
protected void get_ad_passwd(string pass, object ob);
protected void check_ok(object ob);
protected void confirm_id(string yn, object ob);
private   void init_new_player(object user);

protected void client_connect(object);
protected void client_check(string, object);

// ���Ա��ⲿ���õĺ���
object    make_body(object ob);
object    find_body(string name);
varargs   void enter_world(object ob, object user, int silent);
varargs   void reconnect(object ob, object user, int silent);
int       check_legal_id(string arg);
int       check_legal_name(string arg, int maxlen);
int       blocks_ip(string ip, int time, string reason);
int       remove_blocks(string ip);
int       remove_allows(string ip);
int       player_day, player_week, day;

void create() 
{
        seteuid(ROOT_UID);
        set("channel_id", "���߾���");
        if (intp(WIZ_LOCK_LEVEL))
                wiz_lock_level = WIZ_LOCK_LEVEL;
        else
                wiz_lock_level = 0;
}

void logon(object ob)
{
        //object *usr, *login_usr;
        object *usr;
        int i, ip_num, wiz_cnt, ppl_cnt, login_cnt;
        int iplimit;
       // int user_num;
        int now_time;
        //string msg;
       // mapping temp_time;
        string *counter = ({});
        string ipname;

        if (uptime() < 30)
        {
                write(sprintf("%s�������������У����Ժ�������\n", LOCAL_MUD_NAME()));
                destruct(ob);
                return;
        }
        
        now_time = time() & 0xFFFFFFFE;
        if (BAN_D->is_banned(query_ip_number(ob)) == 1)
        {
                write("��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��\n");
                destruct(ob);
                return;
        }

/*
        if (mapp(temp_time = blocks[query_ip_number(ob)]))
        {
                if (now_time - temp_time["time"] < temp_time["punish"])
                {
                        write(temp_time["reason"] + "���" + 
                              appromix_time(temp_time["time"] + temp_time["punish"] - now_time) + "�ٳ������ߡ�\n");
                        destruct(ob);
                        return;
                }
                remove_blocks(query_ip_number(ob));
        }
        
        login_usr = filter_array(children(LOGIN_OB), (: query_ip_number($1) == $2 :), query_ip_number(ob));

        if (sizeof(login_usr) > 20)
        {
                blocks_ip(query_ip_number(ob), 1800, "����IP�����˴����������ӣ�");

                for (i = 0; i < sizeof(login_usr); i ++)
                                destruct(login_usr[i]);

                return;
        }
*/
        
        write(ESC "[2J");
        write(color_filter(read_file(WELCOME))); 

        catch(MUDLIST_CMD->main());
        UPTIME_CMD->main();

        if (ob->query_temp("tomud"))
                write(ALERT("��������MUD��Ϸ��nt3����Ⱥ�š�44135826��������ϷΪ�����Ϸ��$$" +
                        "�뵽 http://www.mudbuilder.com �������Ϸ��ҳ����̳�����š�$$"+
                        "������κ����ʣ��뵽����Ϸ��̳ר�����ʣ�����ϵQQ 150867 ��ѯ��$$"));

        if (! VERSION_D->is_version_ok() && ! VERSION_D->query_temp("operator"))
                write(HIY "���ڱ�վ����ͬ���汾������㲻����ʦ�����Ժ��ٵ�¼��\n\n" NOR);
        else
        if (REBOOT_CMD->is_rebooting())
                write(HIY "���ڱ�վ����׼����������������㲻����ʦ�����Ժ��ٵ�¼��\n\n" NOR);

        usr = users() + filter(children(LOGIN_OB), (: interactive :));
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        iplimit = 0;       
        for (i = 0; i < sizeof(usr); i++)
        {
                ipname = query_ip_number(usr[i]);
                if (member_array(ipname, counter) == -1)
                        counter += ({ ipname });
                if (ipname == query_ip_number(ob)) 
                        iplimit++;
                if (base_name(usr[i]) == LOGIN_OB)
                        login_cnt++;
                else if (wizardp(usr[i]))
                {
                        if (! usr[i]->query("env/invisible")) wiz_cnt++;
                }
                else ppl_cnt++;
        }

        ip_num = atoi(read_file("/adm/etc/ips", 1));
        if (sizeof(counter) > ip_num)
                write_file("/adm/etc/ips", sprintf("%d", sizeof(counter)), 1);
        
#ifndef MULTI_LOGIN     
        if ((iplimit > 12 || (iplimit > 4 && ! BAN_D->is_netclub(query_ip_number(ob)))) && query_ip_number(ob) != "124.42.121.251")
        {
                write("�Բ���" + LOCAL_MUD_NAME() + "������ͬip���ص�¼��\n");
                destruct(ob);
                return;
        }
#endif
        if (file_size("/adm/etc/players") > 0)
        {
                sscanf(read_file("/adm/etc/players", 1, 1), "%d %d %d",
                       player_week, player_day, day);
                        
                ip_num = atoi(read_file("/adm/etc/ips", 1));
                
                write(sprintf ("�Կ�վ�����������IP��" CYN " %d " NOR 
                        "������������ " CYN "%d" NOR " �˴Σ��������� " CYN "%d" NOR " �˴Ρ�\n",
                        ip_num, player_day, player_week));
        }
  
        write(sprintf("Ŀǰ���� " CYN "%d" NOR " λ��ʦ��" CYN "%d" NOR " λ���"
                      "�����ϣ��Լ� "CYN "%d" NOR " λʹ"
                      "���߳��������С�\n", wiz_cnt, ppl_cnt, login_cnt));
               
        if (ob->query_temp("tomud"))
        {
                write(TMI("version"));
                input_to("get_version", ob);
        }
        if (! ob->query_temp("big5"))
                write("Select ������ GB or �j���X BIG5 (gb/big5)��\n");
        else
                write("����Ӣ������(����ҿ���ѡ��һϲ��������)��\n");
                
        input_to("get_id", ob);
}

protected void get_version(string arg, object ob)
{
        // CURRENT_CLIENT_VERSION
/*
        if (! arg || arg[0..3] != "2060")
        {
                write(HIY "������е�ַ����Tomud�ͻ���\n" NOR);
                write(HIG "    http://www.mudbuilder.com/down/tomudsetup.exe\n" NOR);
                write(HIY "��ʹ��Zmud�ͻ���ѡ��2000�˿��������ӡ�\n\n" NOR);
                destruct(ob);
                return;
        }
*/
        input_to("get_id", ob);
}

protected void get_id(string arg, object ob)
{
        object ppl, *usr;
        //string where;
       // string *res;  
        int    i, flag;
                      
        arg = lower_case(arg);

        if (arg == "big5")
        {
                ob->set_temp("big5", 1);
                logon(ob);
                return;
        }
        
        if (! check_legal_id(arg))
        {
                ob->add_temp("fake_id", 1);
                if (ob->query_temp("fake_id") > 20)
                {
                        blocks_ip(query_ip_number(ob), 300, "����IP������¼��ЧID��");
                        destruct(ob);
                        return;
                }
                
                write("����Ӣ������(����ҿ���ѡ��һϲ��������)��\n");
                input_to("get_id", ob);
                return;
        }

        // ��������������
        if (intp(MAX_USERS) && MAX_USERS > 0)
        {
                if ((string)SECURITY_D->get_status(arg) == "(player)" &&
                    sizeof(users()) >= MAX_USERS)
                {
                        ppl = find_body(arg);
                        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                        if (! ppl)
                        {
                                write("�Բ���" + LOCAL_MUD_NAME() +
                                      "��ʹ�����Ѿ�̫���ˣ������������\n");
                                destruct(ob);
                                return;
                        }
                }
        }

        if (wiz_level(arg) < 1)
        {
                if (! VERSION_D->is_version_ok() && ! VERSION_D->query_temp("operator"))
                {
                        write("���ڱ�վ����ͬ���汾�У���ʱ���ܵ�¼�����Ժ��ٳ��ԡ�\n");
                        destruct(ob);
                        return;
                } else
                if (REBOOT_CMD->is_rebooting() && ! find_player(arg))
                {
                        write("���ڱ�վ��׼��������������ʱ���ܵ�¼�����Ժ��ٳ��ԡ�\n");
                        destruct(ob);
                        return;
                }
        }

        if (wiz_level(arg) < wiz_lock_level)
        {
                write(sprintf("�Բ���%sĿǰ������ʦ�ȼ� %d ��"
                              "�ϵ��˲������ߡ�\n",
                              LOCAL_MUD_NAME(), wiz_lock_level));
                destruct(ob);
                return;
        }
        
        if (AHACK_D->query_block(arg))
        {
                write(HIY "����˺ű���ʱ�����ˣ����� guest ���������������ʦ��ϵ��\n" NOR);
                destruct(ob);
                return;
        }
        
        if ((string)ob->set("id", arg) != arg)
        {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if (arg == "guest")
        {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } 
        
#ifdef DB_SAVE
        res = DATABASE_D->do_sql("select online, on_time, fee_time,
                                  last_station from users where id = '" + arg + "'");
        flag = arrayp(res);
        if (flag)
        {
                if ((int)res[0] == 3)
                {
                        write(sprintf("[%s] ��� ID Ŀǰ���������У����Ժ��ٳ��Ե�½����\n", arg));
                        destruct(ob);
                        return;
                }

                where = res[3];
                if (wiz_level(arg) < 1 && stringp(where) && where != LOCAL_STATION)
                {
                        if (res[0] > 0)
                        {
                                if ((int)res[0] == 2)
                                        write(sprintf("[%s] ��� ID Ŀǰ����%s�չأ��������Σ����Ƚ��� ID ��%sվ�˳���\n",
                                                      arg, ! undefinedp(stations[where]) ? stations[where] : "����վ",
                                                      ! undefinedp(stations[where]) ? stations[where] : "����վ"));  
                                else
                                if ((int)res[0] == 1)
                                        write(sprintf("[%s] ��� ID Ŀǰ����%s���ߣ��������Σ����Ƚ��� ID ��%sվ�˳���\n",
                                                      arg, ! undefinedp(stations[where]) ? stations[where] : "����վ",
                                                      ! undefinedp(stations[where]) ? stations[where] : "����վ"));   
                                
                                destruct(ob);
                                return;
                        }
                        write(sprintf("[%s] ��� ID ����Ŀǰ��%s�����뽫�� ID �������ι���(y/n)����\n",
                                      arg, ! undefinedp(stations[where]) ? stations[where] : "����վ"));
                        write("����� ID ������ע��Ļ����㲻�����Σ�������(n/N)������ע����½���� ID��\n" NOR);
                                input_to("confirm_cruiseid", 1, ob);
                        return;
                }                       
                ob->set_temp("res", res);
        }
#else
        flag = (file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0);  
#endif              
        if (flag)
        {
                if (ob->restore())
                {
                        if ((string)SECURITY_D->get_status(ob->query("id")) != "(player)") 
                        {
                                if (ob->query("wizpwd")) 
                                {
                                        write("��������ʦר�����룺\n");
                                        input_to("get_wizpwd", 1, ob);
                                        return;
                                }
                                
                                write("\n���棡��û��������ʦר�����룡���½����" HIW " wizpwd " NOR "�������á�\n");
                                write("���������룺\n");
                                input_to("get_passwd", 1, ob);
                                return;
                        }                       
                        write("�����ɫ�Ѿ����ڣ�������ý�ɫ�����룺\n");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }
        
#ifdef DB_SAVE 
        if (! DATABASE_D->query_db_status())
        {
                write("�Բ����������Ӳ������ݿ����ڷ�������Ŀǰ" + MUD_NAME + "��ʱ�������������λ������ע�ᡣ\n"
                      "�������Ϸ��̳��http://www.mudbuilder.com �����ϸ��ѶϢ�������³������ӡ�\n");
                destruct(ob);
                return;
        } 
#endif

#ifdef REFUSE_NEW_PLAYER
        if (! VERSION_D->is_release_server())
        {
                write("�Բ���Ŀǰ" + MUD_NAME + "��ʱ�����������ע�ᡣ\n���½��վ(NITAN.NET 2000)ע�ᡣ\n");
                destruct(ob);
                return;
        }
#endif

        // ��ֹ�������ϵ������ͬһ�ʺ�
        usr = filter_array(children(LOGIN_OB), (: interactive :));
        i = sizeof(usr);
        while (i--)
                if (usr[i] != ob && usr[i]->query("id") == arg)
                        break;
        if (i >= 0)
        {
                write("�������������ʹ����� ID�����������롣\n");
                write("����Ӣ�����֣�\n");
                input_to("get_id", ob);
                return;
        }
        
        if (ob->query_temp("tomud"))
                write(ALERT(NO_FEE_WARNING)+"ʹ�� " + (string)ob->query("id") + 
                        " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        else
                write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��\n");               
        input_to("confirm_id", ob);
}

protected void get_wizpwd(string pass, object ob)
{
        string old_pass;
        
        write("\n");
        old_pass = ob->query("wizpwd");

        if (crypt(pass, old_pass) == old_pass) 
        {
                write(HIG "���ȷ����ɣ���ʦר��������֤ͨ����\n" NOR);
                write("���������룺\n");
                input_to("get_passwd", 1, ob);
                return;
        } else 
        { 
                write("�������\n");
                destruct(ob);
                return;
        }
}

protected void confirm_cruiseid(string yn, object ob)
{
        //int t;
        
        write("\n");
        if (upper_case(yn) == "Y")  
        {
                if (cruise_lock_status)
                {
                        write("�Բ���Ŀǰ��վ�ѱ���ʦ��ʱ����Ϊ��ֹ���Σ�����Ҫ���Σ������ʦ��ϵ��\n");
                        destruct(ob);
                        return;
                }

                write("������� ID �������룺\n");
                input_to("get_cruisepwd", 1, ob);
                return;  
        }    
        write("��ѡ������ע����½ ID�����������롣\n");         
        write("����Ӣ�����֣�\n");
        input_to("get_id", ob);
        return;
}

protected void get_cruisepwd(string pass, object ob)
{
	write("\n"); 
#ifdef DB_SAVE    
        string sites;
        string passwd;
        passwd = DATABASE_D->db_query_user(ob->query("id"), "ad_password");
        if (! stringp(passwd) || crypt(pass, passwd)[0..15] != passwd)
        {
                write("�������\n");
                destruct(ob);
                return;
        }
                                  
        write("�������ȷ����ɣ���ʼ����վ���������ȡ�����������Ϣ��\n");
        sites = DATABASE_D->db_query_user(ob->query("id"), "last_station");
        CRUISE_D->authenticate_user(ob, sites);

        destruct(ob);
        return;
#else
        write("�������\n");
        destruct(ob);
        return;
#endif
}

protected void get_passwd(string pass, object ob)
{
        string ad_pass;
        string my_pass;

        my_pass = ob->query("password");
        ad_pass = ob->query("ad_password");
        if (! stringp(my_pass) || crypt(pass, my_pass) != my_pass)
        {
                if (! stringp(ad_pass) || crypt(pass, ad_pass) != ad_pass)
                {
                        write("�������\n");
                        destruct(ob);
                        return;
                }

                write(HIR "\n������˹������������Ϸ��"
                      "����������޸������ͨ���롣\n" NOR);

                // ����ǣ���ʾĿǰ�������޸������֧��
                ob->set_temp("reset_password", 1);
                write("\n�������趨������ͨ���룺\n");
                input_to("new_password", 1, ob);
                return;
        }

        if (! stringp(ad_pass))
        {
                write(HIC "\n��ע�⣺���IDĿǰ��û�й������룬��������Ĺ������롣\n\n" NOR);
                write(HIW "������ͨ���붪ʧ������£�������������������룬���޸���ͨ\n"
                      "���룬������������һ���ɿ��Ĳ�������ͨ���벻ͬ�Ĺ������룬��\n"
                      "���������ID��ƽʱ��ʹ����ͨ�����½���������Ƶ����ʹ�ù���\n"
                      "�����Ե���Ǳ�ڵ�й©���ա�\n\n" NOR);
                write("��������Ĺ������룺\n");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        check_ok(ob);
}

protected void reset_ad_password(string pass, object ob)
{
        string my_pass;
        write("\n");

        if (strlen(pass) < 5)
        {
                write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺\n");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        my_pass = ob->query("password");
        if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
        {
                write(HIR "Ϊ�˰�ȫ�����ϵͳҪ�����������������ͨ���벻����ͬ��\n\n" NOR);
                write("������������Ĺ������룺\n");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set_temp("ad_password", crypt(pass, 0));
        write("��������һ�����Ĺ������룬��ȷ����û�Ǵ�\n");
        input_to("confirm_reset_ad_password", 1, ob);
}

protected void confirm_reset_ad_password(string pass, object ob)
{
        //mapping my;
        string old_pass;
        //string passwd;
        
        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write("����������Ĺ������벢��һ�����������趨һ�ι������룺\n");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);
        check_ok(ob);
}

protected void check_ok(object ob)
{
        object user;
        //string *res, str, str1, str2;
        //int    on, fee, i, rec = 0;
        int rec=0;
        
        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (! objectp(user)) 
                user = make_body(ob);
        else
                rec = 1;

        if (! objectp(user)) 
        {
                write(HIR "�޷���������ң�����Գ������µ�¼���Ǻ���ʦ��ϵ��\n" NOR);
                return ;
        }

        if (rec != 1 && ! user->restore()) // ����Ҫ�ж�rec��ֵ��������������ݷ��ص�ǰһ�δ洢������
        {
                write(HIR "�޷���ȡ��������ݣ�����Գ������µ�¼���Ǻ���ʦ��ϵ��\n" + rec + NOR);
                return ;
        }

#ifdef NO_FEE
        if (ob->query_temp("tomud"))
                write(ALERT("����MUD��Ϸ��nt2��������������ѿ��ţ�����������໥ת�棡\n"));
#else
        string *res, str, str1, str2;
        int    on, fee, i;
        // ������·��û�������Ҫ���жϵ����ˡ�
        if (user->query("monfee") < time() && arrayp(res = ob->query_temp("res")))
        {
                str1 = res[1] + "0"; 
                str2 = res[2] + "0";
                if (sscanf(str1, "%d", on) == 1 && sscanf(str2, "%d", fee) == 1)
                {
                        on /= 10;
                        fee /= 10;
                        i = onl / 3600;
                        str = "���ܹ�������Ϸʱ�䣺 " + fee + " ��Сʱ$$" +
                              "���Ѿ�����Ϸ�н����ˣ�" + i + "Сʱ" + ((on % 3600) / 60) + "����$$";
                        if (i >= fee)
                                str += "�㹺�����Ϸʱ���Ѿ�ʹ�����ˣ�����ϵ��nt2��С�����������Ϸʱ�䣡$$��Ϸ��ҳ�� http://www.mudbuilder.com $$";
                        else if ((fee - i) < 18)
                                str+="�㹺�����Ϸʱ���Ѿ�ֻ�� " + (fee - i - 1) + " Сʱ��һ����$$��Ͽ�ȥ http://www.mudbuilder.com ������ʺ����Ѱ�$$";
                        else if (fee == i)
                                str += "�㹺���ʱ���Ѿ�����һ��Сʱ�ˣ��뾡��ȥ http://www.mudbuilder.com ������ʺ�����$$";
                        if (fee == 18)
                                str += NO_FEE_WARNING;
                        write(ALERT(str) + ((fee > 18) ? TMI("regur good") : "") + TMI("dlurl 123.12586.com/images/face32/"));
                        if (i >= fee)
                        {
                                destruct(ob);
                                destruct(user);
                                return;
                        }
                        // write(ALERT("a"));
                }
                // else
                //         write(ALERT("b"));
        }
        // else
        //      write(ALERT("c") + "FLAG : " + user->query("monfee") + " " + time() + " " + arrayp(res = ob->query_temp("res")));

        // Check if we are already playing.
        // user = find_body(ob->query("id"));
        // if (user)
        // {
#endif
                        
        if (rec)
        {
                if (user->is_net_dead())
                {
                        reconnect(ob, user);
                        return;
                }
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)\n");
                input_to("confirm_relogin", ob, user);
                return;
        }
        /*
        user = MESSAGE_D->find_chatter(ob->query("id"));
        if (objectp(user))
        {
                write("������������ID���˳�ȥ��\n");
                MESSAGE_D->user_logout(user, user->name(1) + "��" +
                                       query_ip_number(ob) + "���߽������磬"
                                       "�������˳�ȥ��\n");
        }

        if (objectp(user = make_body(ob)))
        {
                if (user->restore())
                */
                else
                {
                        mixed err;
                        string msg;

                        log_file("usage", sprintf("%s(%s) loggined from %s (%s)\n",
                                 user->query("name"), user->query("id"),
                                 query_ip_number(ob), ctime(time()) ) );

                        if (ob->query("last_on") < time() &&
                            ob->query("last_on") > time() - 30 &&
                            ! wiz_level(user))
                        {
                                write("�����һ���˳�ʱ��ֻ��" + chinese_number(time() - ob->query("last_on")) +
                                      "���ӣ����Ժ��ٵ�¼��\n");
                                destruct(user);
                                destruct(ob);
                                return;
                        }

                        user->set_temp("logon_time", time());
                        user->set("last_save", time());
                        if (err = catch(enter_world(ob, user)))
                        {
                                user->set_temp("error", err);
                                msg = HIR "\n���޷�����������磬������ĵ�"
                                      "������һЩ���⣬��Ҫ����ʦ��ϵ��\n\n" NOR;
                                if (mapp(err))
                                        msg += MASTER_OB->standard_trace(err, 1);
                                user->set_temp("error_message", msg);
                                tell_object(user, msg);
                        }
                        return;
                } 
                /*
                else
                {
                        destruct(user);
                        write(HIR "\n�޷���ȡ������ݵ���������Ҫ����ʦ��ϵ��\n" NOR);
                        if (CONFIG_D->query_int("ask_recreate"))
                        {
                                write(WHT "�����ѡ�����´������(y/n)��\n" NOR);
                                input_to("create_new_player", ob);
                        } else
                                destruct(ob);
                }
        } else
                write(HIR "�޷���������ң�����Գ������µ�¼���Ǻ���ʦ��ϵ��\n" NOR);
        */
}

protected void create_new_player(string yn, object ob)
{
        if (yn != "y" && yn != "Y")
        {
                write("\n�Ǻðɣ��������ӵ�¼ʧ���ˡ�\n");
                destruct(ob);
                return;
        }

        write(HIW "\n���ڿ�ʼ���´��� " HIY + ob->query("id") +
              HIW " �����ҡ�\n" NOR);
        confirm_id(yn, ob);
}

protected void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if (! yn || yn=="")
        {
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)\n");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if (yn[0]!='y' && yn[0]!='Y')
        {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        }

        if (user)
        {
                tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
                                + " )����ȡ���������Ƶ����\n");
                log_file("usage", sprintf("%s(%s) replaced by %s (%s)\n",
                         user->query("name"), user->query("id"),
                         query_ip_number(ob), ctime(time())));

                // Kick out tho old player.
                old_link = user->query_temp("link_ob");
                if (old_link)
                {
                        exec(old_link, user);
                        destruct(old_link);
                }
        } else
        {
                write("������ҶϿ������ӣ�����Ҫ���µ�½��\n");
                destruct(ob);
                return;
        }

        reconnect(ob, user);
}

protected void confirm_id(string yn, object ob)
{
        if (yn == "")
        {
                write("\nʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��\n");
                input_to("confirm_id", ob);
                return;
        }       

        if (yn[0] != 'y' && yn[0] != 'Y')
        {
                write("\n�ðɣ���ô��������������Ӣ�����֣�\n");
                input_to("get_id", ob);
                return;
        }
        write(@TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ���������벻Ҫѡ���ӹС˵��
��������������

���������������գ�����������ݵĽ�ɫ�������Ļ��������롰�š���
Ȼ����Ի�ѯ��������֣���ʱ�������롰���������������ݵĽ�ɫ
�����ֱȽϹ֣�����С��ϻ��������Բ������գ�ֱ���ûس��Թ�����
�ǽ����㻹������һ���Ƚ������ӵ�����������Щ�ȽϹֵĳƺſ�����
�ǳƴ��棬����ĳЩ�ط��ĳƺ����ܻ�ȽϹ֡������Ҫ�������ң���
ô��Ͳ����������ˣ���Ϊһ���������ҽ��Զ�ѡ��Ҵ����գ�������
�Լ������ġ�

TEXT
        );
        write("��������" HIG "����" NOR "(��Ҫ������������)��\n");
        input_to("get_surname", ob);
}

protected void get_surname(string arg, object ob)
{
        if (arg && strlen(arg) > 0)
        {
                if (ob->query_temp("big5")) 
#ifdef LONELY_IMPROVED
                        // arg = big5togb(arg);
                        arg = LANGUAGE_D->toGB(arg);
#else                   
                        arg = LANGUAGE_D->toGB(arg);
#endif                          
                if (! check_legal_name(arg, 4))
                {
                        write("��������" HIG "����" NOR "(��Ҫ������������)��\n");
                        input_to("get_surname", ob);
                        return;
                }
                ob->set("surname", arg);
        } else
        {
                write("��������" HIG "����" NOR "(������û������)��\n");
                input_to("get_surname", ob);
                return;
        }
        write("��������" HIY "����" NOR "(��Ҫ������������)��\n");
        input_to("get_name", ob);
}

protected void get_name(string arg, object ob)
{
        string fname;
        string result;

        if (ob->query_temp("big5")) 
#ifdef LONELY_IMPROVED
                // arg = big5togb(arg);
                arg = LANGUAGE_D->toGB(arg);
#else
                arg = LANGUAGE_D->toGB(arg);
#endif                
        if (! check_legal_name(arg, 4))
        {
                write("��������" HIY "����" NOR "(��Ҫ������������)��\n");
                input_to("get_name", ob);
                return;
        }
        ob->set("purename", arg);

        fname = ob->query("surname");
        if (! stringp(fname)) fname = "";
        fname += arg;

        if (strlen(fname) < 4)
        {
                write("�Բ�������������֣��պ�������ϣ�����Ҫ���������֡�\n");
                write("\n����������������" HIG "����" NOR "��\n");
                input_to("get_surname", ob);
                return;
        }

        if (stringp(result = NAME_D->invalid_new_name(fname)) ||
            stringp(result = NAME_D->invalid_new_name(arg)))
        {
                write("�Բ���" + result + "\n");
                write("\n����������������" HIG "����" NOR "��\n");
                input_to("get_surname", ob);
                return;
        }
        
#ifdef DB_SAVE
        if (DATABASE_D->db_find_user("name", fname) ||
            DATABASE_D->db_find_user("name", arg))
        {
                write("�Բ����������������վ��ҵ������ظ������ƣ�\n");
                write("\n����������������" HIG "����" NOR "��\n");
                input_to("get_surname", ob);
                return;
        }        
#endif       
                
        if (arg == ob->query("surname"))
        {
                write(HIW "\nϵͳ������������պ�������ͬ������������ֽ��ǣ���"
                      HIY + arg + arg + HIW "����\n"
                      "���Ƿ�����Ϊ���˽Ȿϵͳ����û����ϸ�Ķ�ǰ��İ��������������\n"
                      "���������������ǣ������������Ӳ�����������֣�������������һ\n"
                      "�����ȫ�����������ȷ��ʹ��������֡�\n\n" NOR);
                write("����������ȫ��(���պ����ֵ����)��\n");
                input_to("input_full_name", ob, arg + arg);
                return;
        }

        write(HIW "\nΪ�˱�֤�������İ�ȫ����ϷҪ���������������롣һ���ǹ�����\n"
              "�룬����������������ʧ����ͨ����ʱ��¼��Ϸ���������޸���ͨ\n"
              "���롣ƽʱ��ʹ����ͨ�����½���������Ƶ����ʹ�ù��������Ե�\n"
              "��Ǳ�ڵ�й©���ա�\n\n" NOR);
        write("���趨���Ĺ������룺\n");
        input_to("new_ad_password", 1, ob);
}

protected void input_full_name(string arg, object ob, string fname)
{
        if (arg != fname)
        {
                write(WHT "\n�������ȫ�����������պ����ֵĵ���ϣ�ϵͳ��Ϊ�㿪ʼû�������\n"
                      "�����ֵ�Ҫ��" HIR "������ϸ�Ķ�������ʾ�������Ҫ��������"
                      NOR WHT "��������\n"
                      "������Ϸ����������ϸ�Ķ����ְ����͹��棬������Ϊ����Ϊ�Ƕ���\n"
                      "���˷�ʱ��������ܲ���Ҫ����ʧ��\n" NOR);
                confirm_id("Yes", ob);
                return;
        }

        write("\n���趨���Ĺ������룺\n");
        input_to("new_ad_password", 1, ob);
}

protected void new_ad_password(string pass, object ob)
{
        write("\n");
        if (strlen(pass) < 5)
        {
                write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺\n");
                input_to("new_ad_password", 1, ob);
                return;
        }
        
#ifdef ENABLE_MD5_PASSWORD 
        ob->set_temp("ad_password", crypt(pass, sprintf("$1$%d", random(99999999)))); 
#else 
        ob->set_temp("ad_password", crypt(pass, 0));
#endif 

        write("��������һ�����Ĺ������룬��ȷ����û�Ǵ�\n");
        input_to("confirm_ad_password", 1, ob);
}

protected void confirm_ad_password(string pass, object ob)
{
        //mapping my;
        string old_pass;
        //string passwd;

        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write("����������Ĺ������벢��һ�����������趨һ�ι������룺\n");
                input_to("new_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);

        write(HIW "��ͨ��������ƽʱ��¼��Ϸʱʹ�õģ���Ϸ�п���ͨ�� PASSWD ����\n"
              "���޸�������롣\n\n" NOR);
        write("�����������ͨ���룺\n");
        input_to("new_password", 1, ob);
}

protected void new_password(string pass, object ob)
{
        string ad_pass;

        write("\n");
        if (strlen(pass) < 3)
        {
                write("����ĳ�������Ҫ������Ԫ���������������룺\n");
                input_to("new_password", 1, ob);
                return;
        }

        if (stringp(ad_pass = ob->query("ad_password")) &&
            crypt(pass, ad_pass) == ad_pass)
        {
                write(HIR "��ע�⣬Ϊ�˰�ȫ�����ϵͳҪ����Ĺ����������ͨ���벻����ͬ��\n\n" NOR);
                write("����������������ͨ���룺\n");
                input_to("new_password", 1, ob);
                return;
        }
        
#ifdef ENABLE_MD5_PASSWORD 
        ob->set_temp("password", crypt(pass, sprintf("$1$%d", random(99999999)))); 
#else 
        ob->set_temp("password", crypt(pass, 0));
#endif 

        write("��������һ���������룬��ȷ����û�Ǵ�\n");
        input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
       // mapping my;
        string old_pass;
        //string passwd;

        write("\n");
        old_pass = ob->query_temp("password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write("��������������벢��һ�����������趨һ�����룺\n");
                input_to("new_password", 1, ob);
                return;
        }

        ob->set("password", old_pass);
        if (ob->query_temp("reset_password"))
        {
                // �����û��޸��Լ��������֧���̣����Ǵ���
                // �û���֧�����ת�Ƶ� check_ok ��������ִ
                // �С�
                ob->save();
                check_ok(ob);
                return;
        }

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��\n");
        input_to("get_gender", ob);
}

protected void get_gender(string gender, object ob)
{
        object user;

        write("\n");
        if (gender == "")
        {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��\n");
                input_to("get_gender", ob, user);
                return;
        }

        if (gender[0]=='m' || gender[0]=='M')
                ob->set_temp("gender", "����");
        else if (gender[0]=='f' || gender[0]=='F')
                ob->set_temp("gender", "Ů��" );
        else
        {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��\n");
                input_to("get_gender", ob, user);
                return;
        }

        if (find_body(ob->query("id")))
        {
                write(HIR "�����������Ѿ���¼������������ˣ���"
                      "�˳��������ӡ�\n" NOR);
                destruct(ob);
                return;
        }
        
#ifdef DB_SAVE
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();   

        if (DATABASE_D->db_find_user("id", ob->query("id")))   
        {
                write(HIR "\n�����������Ѿ�������վע���ˣ����˳��������ӡ�\n" NOR);
                destruct(ob);
                return;
        }
#endif        
        ob->set("body", USER_OB);
        if (! objectp(user = make_body(ob)))
        {
                write(HIR "\n���޷���¼����µ����������ѡ��\n" NOR);
                destruct(ob);
                return;
        }
        user->set("str", 14);
        user->set("dex", 14);
        user->set("con", 14);
        user->set("int", 14);
        user->set("per", 20);
        user->set("kar", 20);
        user->set("gender", ob->query_temp("gender"));
        ob->set("registered", 0);
        user->set("registered", 0);
        log_file("usage", sprintf("%s(%s) was created from %s (%s)\n",
                          user->query("name"), user->query("id"),
                          query_ip_number(ob), ctime(time())));

        init_new_player(user);
        user->set_temp("newplayer", 1);
        enter_world(ob, user);
        write("\n");
}

object make_body(object ob)
{
        string err;
        object user;
        //int n;

        if (! is_root(previous_object()))
        {
                log_file("static/security",
                         sprintf("%s try to create player(%s) on %s.\n",
                                 (string)geteuid(previous_object()),
                                 (string)ob->query("id"),
                                 ctime(time())));
                write("��û��Ȩ�޴�����ҡ�\n");
                return 0;
        }

        seteuid(getuid());
        user = new(USER_OB);
        if (! user)
        {
                write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set("surname", ob->query("surname"));
        user->set("purename", ob->query("purename"));
        user->set_name(0, ({ ob->query("id")}));
        return user;
}

private void init_new_player(object user)
{
        // ��ʼ����Ҫ����
        user->set("title", "��ͨ����");
        user->set("birthday", time());
        user->set("combat_exp", "100");
        user->set("potential", 99);
        user->set("food", (user->query("str") + 10) * 10);
        user->set("water", (user->query("str") + 10) * 10);
        user->set("channels", ({ "chat", "rumor", "party",
                                 "bill", "sos", "family",
                                 "nt", "rultra" }));
        user->set("chann", (["sing" : 1, "chat" : 1, "bill" : 1 ])); // Ĭ����ʾ�������ڵ�Ƶ��

        // ��¼����
        NAME_D->map_name(user->query("name"), user->query("id"));

        // �����¶Ȼ�Ա
        user->set("monfee", time() + 8640000);
        // ���ñ�Ҫ�Ļ�������
        // user->set("env/prompt", "time");
        user->set("env/wimpy", 60);
        user->set("env/roomlist", 1);        
}
                
varargs void enter_world(object ob, object user, int silent)
{
        //object cloth, shoe, room, login_ob;
        object cloth,shoe,login_ob;
        string startroom;
        string ipname;
        mapping marry;
        object *users;

        if (! is_root(previous_object()))
                return;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        ob->set("registered", user->query("registered"));
        user->set_temp("time", time());
        user->set_temp("logon_time", time());
        user->set("env/show_reply", "all");
        if (ob->query_temp("big5")) 
                user->set_temp("big5", 1);
        if (ob->query_temp("tomud")) 
                user->set_temp("tomud", 1);
        if (interactive(ob)) exec(user, ob);

        write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");

        user->setup();
        if (user->query("age") == 14)
        {
                user->set("food", user->max_food_capacity());
                user->set("water", user->max_water_capacity());
        }

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        // �����ﴴ��һ�����ݿ��¼
#ifdef DB_SAVE
        if (user->query_temp("newplayer"))
        {
                if (! DATABASE_D->query_db_status())
                        DATABASE_D->connect_to_database();
                        
                DATABASE_D->db_new_player(ob, user);
        }
#endif
        user->save();
        user->set("last_save", time());
        ob->save();

        // check the user
        UPDATE_D->check_user(user);

        if (wizhood(user) == "(player)")
        {
                if (user->query("class") == "bonze")
                {
                        if (user->query("gender") == "Ů��")
                        {
                                cloth = new("/clone/cloth/ni-cloth.c");
                                shoe = new("/clone/cloth/ni-xie.c");
                        }
                        else
                        {
                                cloth = new("/clone/cloth/seng-cloth.c");
                                shoe = new("/clone/cloth/seng-xie.c");
                        }
                } else
                {
                        if (user->query("class") == "taoist")
                        {
                                if (user->query("gender") == "Ů��")
                                {
                                        cloth = new("/clone/cloth/daogu-cloth.c");
                                        shoe = new("/clone/cloth/dao-xie.c");
                                } else
                                {
                                        cloth = new("/clone/cloth/dao-cloth.c");
                                        shoe = new("/clone/cloth/dao-xie.c");
                                }
                        } else
                        {
                                if (user->query("gender") == "Ů��")
                                {
                                        shoe = new("/clone/cloth/female-shoe.c");
                                        cloth = new(sprintf("/clone/cloth/female%d-cloth.c", 1 + random(8)));
                                } else
                                {
                                        shoe = new("/clone/cloth/male-shoe.c");
                                        cloth = new(sprintf("/clone/cloth/male%d-cloth.c", 1 + random(8)));
                                }
                        }
                }

                cloth->move(user);
                catch(cloth->wear());
                shoe->move(user);
                catch(shoe->wear());
        } else
        {
                if (user->query("gender") == "Ů��")
                {
                        cloth = new("/clone/cloth/yunshang");
                        cloth->move(user);
                        cloth->wear();
                } else
                {
                        cloth = new("/clone/cloth/jinduan");
                        shoe  = new("/clone/cloth/xianlv");
                        cloth->move(user);
                        cloth->wear();
                        shoe->move(user);
                        shoe->wear();
                }
        }

        if (cloth && (! environment(cloth) || ! cloth->query("equipped")))
                destruct(cloth);

        if (shoe && (! environment(shoe) || ! shoe->query("equipped")))
                destruct(shoe);

        if (! silent)
        {
                if (! user->query("registered"))
                        write(color_filter(read_file(UNREG_MOTD))); 
                else
                        write(color_filter(read_file(MOTD))); 

                write("�����߽���" + LOCAL_MUD_NAME() + "��\n\n");

                if (! user->query("registered"))
                {
                        if (user->is_ghost())
                                user->reincarnate();
                        user->set("startroom", REGISTER_ROOM);
                } else
                if (! stringp(user->query("born")))
                {
                        if (user->is_ghost())
                                user->reincarnate();
                        user->set("startroom", BORN_ROOM);
                }
                
                if ((string)SECURITY_D->get_status(ob->query("id")) != "(player)") 
                        startroom = WIZARD_ROOM;
                
                else        
                if (user->is_in_prison())
                        startroom = user->query_prison();
                else
                if (user->is_ghost())
                        startroom = DEATH_ROOM;
                else
                if (! stringp(startroom = user->query("startroom")) ||
                    file_size(startroom + ".c") < 0)
                        startroom = START_ROOM;

                if (! catch(load_object(startroom)))
                        user->move(startroom);
                else
                {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") +
                          "���߽���������硣\n", ({user}));
        }

        login_ob = new(LOGIN_OB);
        login_ob->set("id", user->query("id"));
        login_ob->restore();
        if (login_ob->query("registered"))
        {
                if (! intp(login_ob->query("login_times")))
                {
                        write(NOR "\n���ǵ�һ�ι���" + LOCAL_MUD_NAME() + "��\n");
                        login_ob->set("login_times", 1);
                        // show rules
                } else
                {
                        login_ob->add("login_times", 1);
                        write("\n���ϴι���" + LOCAL_MUD_NAME() + "�� " + HIG +
                                ctime(login_ob->query("last_on")) + NOR + " �� " + HIR +
                                login_ob->query("last_from") + NOR + " ���ӵġ�\n");
                }
        }

        destruct(login_ob);

        if (!(wizardp(user)&&user->query("env/no_login_msg")))
        CHANNEL_D->do_channel(this_object(), "sys",
                sprintf("%s(%s)��%s���߽��롣",
                user->name(), user->query("id"),
                (ipname = query_ip_number(user)) ? ipname : "δ֪�ص�"));

#ifdef DB_SAVE
        DATABASE_D->db_set_player(user->query("id"), "online", 1);
        DATABASE_D->db_set_player(user->query("id"), "last_station", LOCAL_STATION);
#endif
        
#if INSTALL_EXAMINE
        EXAMINE_D->examine_player(user);
#endif

        if (day ==6 && day2num[ctime(time())[0..2]] == 7)
                player_week = 0;
        if (day != day2num[ctime(time())[0..2]]) 
        {
                player_day = 0;
                day = day2num[ctime(time())[0..2]];
        }
        write_file("/adm/etc/players", sprintf( "%d %d %d", player_week + 1, player_day + 1, day), 1);
          
        if (wizhood(user) != "(admin)" &&
            EXAMINE_D->query("log_by/" + user->query("id")))
                user->start_log();

        if (BAN_D->is_welcome(user->query("id")) && ! BAN_D->is_netclub(query_ip_number(user)))
                BAN_D->open_club_line(user);    // �Զ�������������

        // notice user the user of this mud
        NEWS_D->prompt_user(user);
        ANALECTA_D->prompt_user(user);
        TOPTEN_D->topten_checkplayer(user);
        if (mapp(marry = user->query("couple")) && ! undefinedp(marry["couple_id"]))
        {
                string tmpstr, tmpstr1;
                object couple_ob = find_player(marry["couple_id"]);
                if (couple_ob)
                {
                        if ((string)user->query("gender") != "����")
                        {
                                tmpstr1 = "���"; 
                                tmpstr = "����";
                        }
                        else
                        {
                                tmpstr1 = "����";
                                tmpstr = "���";
                        }
                        write(sprintf(WHT HIM "\n���%s%s�Ѿ����������þ��ˣ���ȥ��%s�ɡ�����\n" NOR,
                                      tmpstr1, couple_ob->name(), gender_pronoun(couple_ob->query("gender"))));
                        tell_object(couple_ob, sprintf(WHT HIM "\n���%s%s���Ʋ�ס�����˼����������������ȥ��%s����к��ɡ�����\n" NOR,
                                                       tmpstr,user->name(),gender_pronoun(user->query("gender"))));
                }
        }

        if ((user->query("qi") < 0 || user->query("jing") < 0) && living(user))
                user->unconcious();

        users = filter_array(users(), (: $1->query_temp("tomud") :));
        message("system", ADD2(user), users);
        if (user->query_temp("tomud"))
        {
                foreach (object player in users())
                        tell_object(user, ADD2(player));
                user->force_me("inventory");
                user->force_me("wear all");
                user->force_me("cmdbar");
        }
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        
        if (ob->query_temp("big5"))
                user->set_temp("big5", 1);
        else    
                user->delete_temp("big5");
                
        if (ob->query_temp("tomud"))
                user->set_temp("tomud", 1);
        else    
                user->delete_temp("tomud");

        exec(user, ob);

        user->reconnect();
        if (! silent && (! wizardp(user) || ! user->query("env/invisible"))) {
                tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
                ({user}));
        }

        if (user->query_temp("tomud"))
        {
                user->force_me("look");
                user->force_me("inventory");
                user->force_me("cmdbar");
        }
#ifdef DB_SAVE
        DATABASE_D->db_set_player(user->query("id"), "online", 1);
#endif
        
        if (! (wizardp(user) && user->query("env/no_login_msg"))) 
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s�������߽��롣", user->query("name"),
                        user->query("id"), query_ip_number(user)));
}

int check_legal_id(string id)
{
        int i;

        if (member_array(id, banned_id) != -1)
        {
                write("�Բ���" HIC"��" + id + "��" NOR"�����������"
                      "��ĺ��⣬��������Ӣ�����֡�\n");
                return 0;
        }

        i = strlen(id);

        if ((strlen(id) < 3) || (strlen(id) > 10))
        {
                write("Ӣ�����ֱ����� 3 �� 10 ��Ӣ����ĸ,��ע���ʽ��\n");
                return 0;
        }

        while (i--)
        {
                if (id[i] < 'a' || id[i] > 'z' )
                {
                        write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                        return 0;
                }
        }

        return 1;
}

int check_legal_name(string name, int maxlen)
{
        int i;

        i = strlen(name);
        
        if ((strlen(name) < 2) || (strlen(name) > maxlen))
        {
                write("�Բ������������������̫����̫�̡�\n");
                return 0;
        }

        if (! is_chinese(name))
        {
                write("�Բ��������á����ġ�ȡ���֡�\n");
                return 0;
        }

        if (member_array(name, banned_name) % 2 == 0)
        {
                write("�Բ���������������������˵����š�\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        return find_player(name);
}

int set_wizlock(int level)
{
        if (wiz_level(this_player(1)) <= level)
                return 0;

        if (geteuid(previous_object()) != ROOT_UID)
                return 0;

        wiz_lock_level = level;
        return 1;
}

int set_cruiselock(int level)
{
        if (wiz_level(this_player(1)) <= 4)
                return 0;

        cruise_lock_status = 1;
        return 1;
}

int can_login(int level)
{
        if (level < wiz_lock_level)
                return 0;

        return 1;
}

int blocks_ip(string ip, int time, string reason)
{
        mapping temp_ban = ([]);

        temp_ban["reason"] = reason;
        temp_ban["time"] = time();
        temp_ban["punish"] = time;
        map_delete(blocks, ip);
        blocks[ip] = temp_ban;

        return 1;
}

int remove_blocks(string ip)
{
        if (ip == "all")
                blocks = ([]);
        else
                map_delete(blocks, ip);

        return 1;
}

mapping query_blocks()
{
        return blocks;
}

int allows_id(string id)
{
        allows += ({ id });
        return 1;
}

int remove_allows(string id)
{
        if (id == "all")
                allows = ({});
        else
                allows -= ({ id });

        return 1;
}
