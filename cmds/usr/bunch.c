// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bunch.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

#include "/adm/npc/npcneed.h"

void create() { seteuid(getuid()); }

int sort_bunch(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

int check_item(string item)
{
        int i;

        i = strlen(item);

        if( (strlen(item) < 4) || (strlen(item) > 16 ) ) {
                return 0;
        }
        while(i--) {
                if( item[i]<=' ' ) {
                        return 0;
                }
        if( i%2==0 && !is_chinese(item[i..<0]) ) {
                        return 0;
        }
        }
        return 1;
}

void delete_target(object npc, string name);
int check_bunch(string fame);
string show_ally(object me, string id);
int sort_hatred(string id1, string id2, mapping hatred);
int sort_member(string id1, string id2);
int show_bunch_info(object me, string arg);
int show_bunch_area(object me, string arg);
int show_bunch_member(object me, string arg);
int show_bunch_hatred(object me, string arg);
int show_bunch_all(object me, string arg);
int expell_bunch_member(object me, string arg);
int dismiss_bunch(object me, string arg);
int appoint_bunch_member(object me, string arg);
int inherit_bunch_master(object me, string arg);
int show_bunch_league(object me, string arg);
int bunch_arrest(object me, string arg);
int bunch_invite(object me, string arg);
int join_bunch(object me, string arg);
int bunch_color(object me, string arg);

mapping citys = ([ 
        "city"     : "����", 
        "changan"  : "����", 
]);

int main(object me, string arg)
{
        object *obs;
        string fname;
        string *args;

        if (! arg) arg = "all";
        args = explode(arg, " ");
        if (sizeof(args) > 1)
                arg = implode(args[1..<1], " ");
        else
                arg = 0;

        switch (args[0])
        {
        case "info":
                // ��ʾͬ�˵���Ϣ
                return show_bunch_info(me, arg);

        case "member":
                return show_bunch_member(me, arg);

        case "dismiss":
                return dismiss_bunch(me, arg);
        
        case "expell":        
        case "kaichu":        
                return expell_bunch_member(me, arg);

        case "top":
                return "/cmds/usr/top"->main(me, "bunch");

        case "area":
                return show_bunch_area(me, arg);
                
        case "hatred":
                // ��ʾͬ�˵ĳ���
                return show_bunch_hatred(me, arg);                
                
        case "all":
                return show_bunch_all(me, arg);
        
        case "appoint":
        case "renming":
                return appoint_bunch_member(me, arg);
                
        case "inherit":  
        case "rangwei":
                return inherit_bunch_master(me, arg);      
                
        case "ally":
        case "league":
                return show_bunch_league(me, arg);
        
        case "arrest":
        case "tongji":
        case "zhuisha":
                return bunch_arrest(me, arg);
                
        case "invite":
        case "yaoqing":
                return bunch_invite(me, arg);
         
        case "join":
        case "jiaru":
                return join_bunch(me, arg);
                
        case "color":
                return bunch_color(me, arg);

        case "out":
                if (! stringp(fname = me->query("bunch/bunch_name")))
                        return notify_fail("�����ڻ�û�м����κΰ����ء�\n");

                if (me->query_temp("pending/out_bunch"))
                {
                        // ͬ�˵������½�
                        BUNCH_D->add_bunch_fame(fname, -me->query("weiwang"));
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                "��˵" + me->name(1) + "(" + me->query("id") +
                                ")���޷��ˣ��Ѿ����롺" + fname + "����ȥ��");
                        me->delete_temp("pending/out_bunch");

                        // ������û���ͬ���е���Ϣ
                        UPDATE_D->clear_user_data(me->query("id"), "bunch");
                        return 1;
                }

                write("�������Ҫ��������������������ή��" + fname + "��������\n"
                      YEL "�����ȷ���ˣ���������һ�� bunch out ���\n" NOR);
                me->set_temp("pending/out_bunch", 1);
                return 1;
        }

        write("��Ч�Ĳ�����\n");
        return 1;
}

// ������ҺͲ���ѡ��ͬ�˵�����
mixed select_bunch(object me, string arg)
{
        string fam;
        object ob;

        if (! wizardp(me))
                // only wizard can show every league's list
                fam = 0;
        else
        if (stringp(arg) && arg != "")
        {
                if (! arrayp(BUNCH_D->query(arg + "/member")))
                        fam = 0;
                else
                        fam = arg;

                if (! stringp(fam) && objectp(ob = UPDATE_D->global_find_player(arg)))
                {
                        // û�� arg ���ͬ�ˣ��鿴�Ƿ��и����
                        fam = ob->query("bunch/bunch_name");
                        UPDATE_D->global_destruct_player(ob);
                        if (! stringp(fam))
                                return notify_fail("��������û�м����κΰ��ɡ�\n");
                }

                if (! stringp(fam))
                        return notify_fail("û�������ң����ܲ�����ص�ͬ�ˡ�\n");
        }

        if (! fam)
        {
                // select my league
                if (! stringp(fam = me->query("bunch/bunch_name")))
                        return notify_fail("�����ڻ�û�м����κΰ����ء�\n");
        }

        return fam;
}


// ��ʾͬ�˵ĳ���
int show_bunch_hatred(object me, string arg)
{
        mapping hatred;
        string fam;
        string *ids;
        mixed *data;
        string msg;
        string st;
        int count;
        int i;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        hatred = BUNCH_D->query_bunch_hatred(fam);
        if (! mapp(hatred) || ! sizeof(hatred))
        {
                write(fam + "����û��ʲô���ˡ�\n");
                return 1;
        }

        ids = keys(hatred) - ({ 0 });
        ids = sort_array(ids, (: sort_hatred :), hatred);

        count = 0;
        msg = WHT "Ŀǰ" + fam + "�ڽ����ϵĳ�ж���\n" NOR
              HIY "��������������������������������\n" NOR;
        for (i = 0; i < sizeof(ids) && count < 30; i++)
        {
                data = hatred[ids[i]];
                if (! arrayp(data) || sizeof(data) < 2 ||
                    ! stringp(data[0]) || ! intp(data[1]))
                        continue;

                st = sprintf("%s(%s%s%s)", data[0], YEL, ids[i], NOR);
                msg += sprintf("%2d. %-34s  %s%-9d%s\n",
                               ++count, st, HIR, data[1], NOR);
        }

        msg += HIY "��������������������������������\n" NOR;
        if (i < sizeof(ids))
                msg += WHT "�����ϵĵ���̫�࣬���Ծ�����\n" NOR;
        else
                msg += WHT "Ŀǰһ����" + chinese_number(i) +
                       "�ˡ�\n" NOR;
        write(msg);
        return 1;
}

// ��ʾĳһ��ͬ���е���Ա
int show_bunch_member(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
        {
                if (! stringp(arg = me->query("bunch/bunch_name")))
                        return notify_fail("�����ڻ�û�м����κ�һ�������ء�\n");
        }

        if (! arrayp(member = BUNCH_D->query_bunch_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")������ɡ�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = "";
        n = 0;
        foreach (id in member)
        {
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += user->short(1) + "\n";
                UPDATE_D->global_destruct_player(user);
        }

        if (msg == "")
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        write(arg + "Ŀǰ������" + chinese_number(n) + "�ˣ�\n" + msg);
        return 1;
}

int show_bunch_all(object me, string arg)
{
        mapping fame;
        string *fam;
        string id, bunch;
        object user;
        string msg;
        int n, area, player;

        if (! mapp(fame = BUNCH_D->query_bunch_fame()))
        {
                write("���ڽ�����û���κ������İ��ɡ�\n");
                return 1;
        }
        
        fam = keys(fame) - ({ 0 });

        if (sizeof(fam) < 1)
                return notify_fail("Ŀǰ������û��ʲô�����İ��ɡ�\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        fam = sort_array(fam, (: sort_bunch :), fame);
                
        msg = sprintf(WHT "%-12s%-20s%-10s%-10s%-12s%-10s\n" NOR,
                      "�������", "������", "�����", "������", "���˰���", "��̳");
        msg += HIY "����������������������������������������������������������������������\n" NOR;
        
        n = 0;
        foreach (bunch in fam)
        {
                id = BUNCH_D->query(bunch + "/master");
                area = sizeof(BUNCH_D->query_bunch_areas(bunch));
                player = sizeof(BUNCH_D->query_bunch_members(bunch));
                
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += sprintf(WHT "%-12s%-20s%-10s%-10s%-12s%-10s\n" NOR,
                               bunch, user->query("name") + "(" + user->query("id") + ")",
                               player + " ��", area + " ��", 
                               sizeof(BUNCH_D->query_bunch_league(bunch)) + " ��",
                               citys[BUNCH_D->query_bunch_info(bunch, "room_zone")]);
               
                UPDATE_D->global_destruct_player(user);
        }

        if (n < 1)
                return notify_fail("����û���κΰ�����Ϣ��\n");

        msg += "\nĿǰ��̶����" + HIM + chinese_number(n) + NOR + "�����ɡ�\n";
        msg += HIY "����������������������������������������������������������������������\n" NOR;

        write(msg);
        return 1;
}

// ��ʾͬ���е���Ϣ
int show_bunch_info(object me, string arg)
{
        string fam;
        object  ob;
        string  msg;
        string *member;
        string  id;
        int i;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        if (! arrayp(member = BUNCH_D->query_bunch_members(fam)))
        {
                write("���ڽ�����û��(" + fam + ")������ɡ�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(fam + "����û��һ��������ҡ�\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        /*
        msg = WHT "\n" + fam + "�İ�������б�\n" NOR;
        msg += HIY "������������������������������������������������������\n" NOR;
        member = sort_array(member, (: sort_member :));
        foreach (id in member)
        {
                reset_eval_cost(); 
                msg += sprintf(WHT "%-10s  ", id);
                if (objectp(ob = find_player(id)))
                        msg += sprintf(HIY "����    "        
                                       NOR WHT "ְλ��" HIM "%-20s "
                                       NOR WHT "�ȼ���" HIR "%-2d\n" NOR,
                                       ob->query("bunch/title"),
                                       ob->query("bunch/level"));                                       
                else
                        msg += HIR "������\n" NOR;
        }

        */
        msg = WHT "\n" + fam + "�İ������ϻ��ܱ�\n" NOR;
        msg += HIY "\n������������������������������������������������������\n" NOR;
        msg += WHT + fam + "�ϸ������뵥��\n" NOR;
        msg += HIY "������������������������������������������������������\n" NOR;
        i = (int)BUNCH_D->query(fam + "/last_area_money");
        if (! intp(i))   i = 0;
        msg += "�������룺" + MONEY_D->money_str(i) + "\n\n";
        i = (int)BUNCH_D->query(fam + "/last_npc_money");
        if (! intp(i))   i = 0;
        msg += "�������룺" + MONEY_D->money_str(i) + "\n\n";
        i = (int)BUNCH_D->query(fam + "/last_bangzhu_money");
        if (! intp(i))   i = 0;
        msg += "�������ã�" + MONEY_D->money_str(i) + "\n\n";
#ifdef LONELY_IMPROVED
        msg += "�����ʲ���" + count_div(BUNCH_D->query_bunch_info(fam, "money"), 10000) + " ���ƽ�\n\n";
#else
        msg += "�����ʲ���" + MONEY_D->money_str(BUNCH_D->query(fam + "/money")) + "\n\n";
#endif
        msg += HIY "������������������������������������������������������\n" NOR;
                	                                            
        msg += sprintf("����%s�ڽ����Ͼ��� %s%d%s ��������\n",
                       fam, HIY, BUNCH_D->query_bunch_fame(fam), NOR);
        write(msg);

        return 1;
}

int show_bunch_area(object me, string arg)
{
        string fam;
        string *member;
        string id;
        mapping area;
        string msg;
        int n;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        if (! arrayp(member = BUNCH_D->query_bunch_areas(fam)))
        {
                write("���ڰ���" + fam + "û���κε��̡�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(fam + "����û���κε��̡�\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = sprintf(HIC "\n%-18s%-28s%-8s%-8s%-18s\n" NOR,
                      "��������", "פ�ذ���", "������", "�ҳ϶�", "��������");
                      
        msg += HIY "����������������������������������������������������������������������\n" NOR;
                
        n = 0;
        foreach (id in member)
        {
                area = BUNCH_D->query_area_info(id, "dbase");
                
                if (! mapp(area)) continue;

                n++;
                msg += sprintf(HIC "%-18s%-28s%-8s%-8s%-18s\n" NOR, 
                               area["area_name"], area["npc_name"] + "(" + area["npc_id"] + ")",
                               area["kaifa"] + "%", 
                               area["zhongcheng"] + "%",
                               area["last_money"] / 100 + " ��"); 
        }

        if (n < 1)
                return notify_fail(arg + "����û���κε��̡�\n");

        msg += "\nĿǰ" + HIM + fam + NOR + "����" + HIM + chinese_number(n) + NOR + "�����̡�\n";
        msg += HIY "����������������������������������������������������������������������\n" NOR;
        // me->start_more(msg);
        write(msg);
        return 1;
}
        
// ��ʾĳһ��ͬ���е���Ա
int dismiss_bunch(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("���Ȩ�޲���������ǿ�н�ɢ���ɡ�\n");

        if (! arg)
                return notify_fail("��Ҫ��ɢ�ĸ����ɣ�\n");

        if (! arrayp(member = BUNCH_D->query_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")������ɡ�\n");
                return 1;
        }

        write("��ǿ�н�ɢ��" + arg + "��\n");
        BUNCH_D->dismiss_bunch(arg);
        return 1;
}

int expell_bunch_member(object me, string arg)
{
        string fname;
        object ob;
        
        if (! stringp(fname = me->query("bunch/bunch_name")))
        {
                write("�����ڻ�û�м����κΰ����ء�\n");
                return 1;
        }
        
        if (me->query("bunch/level") != 7 || 
            BUNCH_D->query_bunch_info(fname, "master") != me->query("id"))
        {
                write("ֻ�а�������Ȩ������ĳ�˳���ᣡ\n");
                return 1;
        }
        
        if (arg == me->query("id"))
        {
                write("�����Լ����㻹�����ɢ��İ��ɣ�\n");
                return 1;
        }
           
        if (! objectp(ob = find_player(arg)))
        {
                ob = UPDATE_D->global_find_player(arg);

                if (! objectp(ob))
                { 
                        write("û�������ҡ�\n");
                        return 1;
                } 
        
                if (ob->query("bunch/bunch_name") != fname)
                {
                        UPDATE_D->global_destruct_player(ob);                                                      
                        write("��������İ������ˣ�����Ȩ��������\n");    
                        return 1;                   
                        
                }
                UPDATE_D->global_destruct_player(ob);
                
        }
        
        BUNCH_D->add_bunch_fame(fname, -BUNCH_D->query_bunch_fame(fname) / 20);
       
        if (objectp(ob))
                CHANNEL_D->do_channel(this_object(), "rumor",
                        "��˵" + ob->query("name") + "(" + arg + ")" +
                        "�����ɡ�" + fname + "���������ˡ�");

        UPDATE_D->clear_user_data(arg, "bunch");
        
        return 1;
}

int appoint_bunch_member(object me, string arg)
{
        object ob;
        string name, item, zhiwei, id, n1, n2;
        string banghui;
        int lvl, flag;
        
        if (! (banghui = me->query("bunch/bunch_name")))
              return notify_fail("��û�вμ��κΰ�ᣬ�޷���������ְλ��\n");
        
        flag = 0;
        
        if (me->query("bunch/level") == 7   
        ||  (intp(me->query("bunch/level")) 
        &&  (int)me->query("bunch/level") > 2))
                flag = 1;               
        
        if (! arg)   
                return notify_fail("ָ���ʽ��bunch appoint <ĳ��> <ְ��> �� bunch appoint <ĳ��> <����> <ְ��>\n");
                
        if (! flag)
                return notify_fail("���ڰ���ְλ̫�ͣ���Ȩ��������ְλ��\n");
                
        if (sscanf(arg, "%s %s %s", id, item, zhiwei) == 3) 
        {
                ob = present(id, environment(me));
                
                if (! ob) return notify_fail("���û����ô���ˡ�\n");
                
                if (! ob->is_character())
                        return notify_fail("��������ǲ������ˣ�\n");
                                
                if (! playerp(ob))  
                        return notify_fail("��ֻ�Ա��������ʹ���������\n");
                        
                if (banghui != (string)ob->query("bunch/bunch_name"))
                        return notify_fail("��ֻ�Ա��������ʹ���������\n");
                        
                if ((int)me->query("bunch/level") < (int)ob->query("bunch/level"))
                        return notify_fail("�Է��ڰ��е�ְλ����ߣ�������������Ц��\n");

                if ((int)me->query("bunch/level") == (int)ob->query("bunch/level"))
                        return notify_fail("�Է��ڰ��е�ְλ����һ���ߣ�������������Ц��\n");
                        
                if (me->is_busy() || me->is_fighting())
                        return notify_fail("����æ���أ�\n");
                        
                if (ob->is_busy() || ob->is_fighting())
                        return notify_fail("�Է���æ���أ�\n");
                        
                if (ob == me)
                        return notify_fail("�Լ������Լ���\n");
                        
                if (! check_item(item))
                        return notify_fail("��������ְ����������ģ���Ϊ�������֣�\n");
                        
                if (zhiwei != "����" && zhiwei != "����" && zhiwei != "̳��" 
                &&  zhiwei != "����" && zhiwei != "����" && zhiwei != "����"
                &&  zhiwei != "����")
                        return notify_fail("������ְλ���϶���Ϊ������,����,̳��,����,����,����,���ڡ�\n");
                        
                switch (zhiwei)
                { 
                case "������": 
                        lvl = 6;
                        break;
                case "����":
                        lvl = 5;
                        break;
                case "����":
                        lvl = 4;
                        break;
                case "����":
                case "̳��":
                case "����":
                case "����":
                        lvl = 3;
                        break;
                case "����":
                        lvl = 2;
                        break;
                case "����":
                        lvl = 1;
                        break;
                }
                
                if ((int)me->query("bunch/level") <= lvl)
                        return notify_fail("��ְλ̫�ͣ���Ȩ�����������ְλ��\n");
                        
                else 
                {
                        ob->set("bunch/title", item + zhiwei);
                        ob->set("bunch/level", lvl);
                        message_vision("$N����$nΪ��" + banghui + "��" + item + zhiwei + "��\n", me, ob);
                        return 1;
                }
        }
     
               
        if (sscanf(arg, "%s %s", id, name) == 2) 
        {
                ob = present(id, environment(me));
                
                if (! ob) return notify_fail("���û����ô���ˡ�\n");
                
                if (! ob->is_character())
                        return notify_fail("��������ǲ������ˣ�\n");
                        
                if (!userp(ob)) return notify_fail("��ֻ�Ա��������ʹ���������\n");
                
                if (banghui != (string)ob->query("bunch/bunch_name"))
                        return notify_fail("��ֻ�Ա��������ʹ���������\n");
                        
                if ((int)me->query("bunch/level") <= (int)ob->query("bunch/level"))
                        return notify_fail("�Է��ڰ��е�ְλ����ߣ�������������Ц��\n");
                        
                if (me->is_busy() || me->is_fighting())
                        return notify_fail("����æ���أ�\n");
                        
                if (ob->is_busy() || ob->is_fighting())
                        return notify_fail("�Է���æ���أ�\n");
                        
                if (ob == me)
                        return notify_fail("�Լ������Լ���\n");
                        
                if (name != "������" && name != "����" && name != "����" && name != "����"
                &&  name != "̳��" && name != "����" && name != "����" && name != "����"
                &&  name != "����")
                        return notify_fail("������ְλ���϶���Ϊ��������������, ����, ����, ̳��, ����, ����, ����, ���� ��\n");
                        
                switch (name)
                { 
                case "������": 
                        lvl = 6;
                        break;
                case "����":
                        lvl = 5;
                        break;
                case "����":
                        lvl = 4;
                        break;
                case "����":
                case "̳��":
                case "����":
                case "����":
                        lvl = 3;
                        break;
                case "����":
                        lvl = 2;
                        break;
                case "����":
                        lvl = 1;
                        break;
                }
                
                if ((int)me->query("bunch/level") <= lvl)
                        return notify_fail("��ְλ̫�ͣ���Ȩ�����������ְλ��\n");
                        
                else 
                {
                        ob->set("bunch/title", name);
                        ob->set("bunch/level", lvl);
                        message_vision("$N����$nΪ��" + banghui + "��" + name + "��\n", me, ob);
                        return 1;
                }
        } else     
                return notify_fail("ָ���ʽ��bunch appoint <ĳ��> <ְ��> �� bunch appoint <ĳ��> <����> <ְ��>\n");
}

int inherit_bunch_master(object me, string arg)
{
        string banghui;
        object ob;
        
        seteuid(getuid()); 
        
        if (! stringp(banghui = me->query("bunch/bunch_name")) || 
            (int)me->query("bunch/level") != 7 ||
            BUNCH_D->query_bunch_info(banghui, "master") != me->query("id"))
                return notify_fail("ֻ�а��İ�������ʹ������ָ�\n");
        
        if (me->is_fighting() || me->is_busy())
                return notify_fail("����æ���ء�\n");
                
        if (! arg)
                return notify_fail("��Ҫ��λ��˭��\n");
                
        if (me->query("id") == arg)
                return notify_fail("��λ���Լ����б�Ҫ��\n");
                
        if (! ob = present(arg, environment(me)))
                return notify_fail("���û����ô����ҡ�\n");
                
        if (! playerp(ob))
                return notify_fail("��ֻ����λ����ҡ�\n");
                
        if (ob->query("bunch/bunch_name") != banghui)
                return notify_fail("��ֻ����λ����������ҡ�\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail("�Է���æ���ء�\n");                
        
        BUNCH_D->add_bunch_info(banghui, "master", ob->query("id"));
        
        ob->set("bunch/level", 7);
        ob->set("bunch/title", "����");
        me->set("bunch/title", "�ϰ���");
        me->set("bunch/level", 6);
        ob->save();
        me->save();
        message_vision("$N����ᡸ" + banghui + "���İ���֮λ��λ����$n��\n", me, ob);
        return 1;
}

int check_bunch(string fame)
{
        if (BUNCH_D->query_bunch_info(fame, "member"))
                return 1;

        return 0;
}

string show_ally(object me, string id)
{
        string *list, str = "";
        int i;
        
        str += sprintf("Ŀǰ%s��ͬ�˰����У�\n\n", id);
        
        if (! list = BUNCH_D->query_bunch_league(id))
                str += "���������ͬ�˰��ɡ�\n\n";
        else 
        {
                for (i = 0; i < sizeof(list); i++) 
                {
                        str += sprintf("%s\n", list[i]);
                }
                str += sprintf("\n�� %d ���ɡ�\n\n", sizeof(list));
        }
        return me->start_more(str);
                
}

int show_bunch_league(object me, string arg)
{
        object ob;
        string bname, tname;
        int flag, i, j;
        
        seteuid(getuid());
        
        if (me->is_busy()) 
                return notify_fail("��Ķ�����û����ɡ�\n");
        
        if (me->is_fighting()) 
                return notify_fail("�㻹��ս���С�\n");
        
        if (! stringp(bname = me->query("bunch/bunch_name")))
                return notify_fail("�㻹û���齨������κΰ��ɡ�\n");
                
        if (! arg) 
        {
                show_ally(me, bname);
                return 1;       
        }
        
        if (! me->query("bunch/level") || 
            me->query("bunch/level") < 7)
                return notify_fail("�㲢����" + bname + "���ɵ���ͷ�ϴ�\n");
                
        if (sscanf(arg, "%s %s", arg, tname) != 2)
                return notify_fail("ָ���ʽ��bunch ally with|cancel <����>\n");
        else 
        {
                if (! check_bunch(tname))  
                        return notify_fail("û��������ɡ�\n");
                
                if (arg == "with")
                {
                        if (tname == bname) 
                                return notify_fail("�㲻�ܸ��Լ����ˡ�\n");
                                
                        if (BUNCH_D->bunch_is_league(bname, tname) ) 
                                return notify_fail("�˰����Ѿ��������ͬ���ˡ�\n");
                                
                        if (! ob = find_player((string)BUNCH_D->query_bunch_info(tname, "master")))
                                return notify_fail("�Է��İ������ڣ����޷��������Ҫ��\n");
                
                        if (me == ob->query_temp("pending/bunch_ally"))
                        {
                                write(HIY "����ʽ�����������" + bname + "��" + tname + "���ͬ��Э�顣\n" NOR);
                                shout(HIY + bname + "��ʽ�������������" + tname + "���ͬ��Э�顣\n" NOR);
                                BUNCH_D->add_league_into_bunch(bname, tname);
                                ob->delete_temp("pending/bunch_ally");
                                return 1;
                        }
                        else
                        {                               
                                write(HIY "�������" + tname + "��ͬ�����顣\n" NOR);
                                tell_object(ob, bname + "��" + me->query("name") + "Ҫ��͹���ɽ���ͬ�˹�ϵ��\n");
                                tell_object(ob, YEL "�����ͬ��Ļ������� bunch ally with " + bname + "��\n" NOR);
                                me->set_temp("pending/bunch_ally", ob);
                                return 1;
                        }

                } 
                else if (arg == "cancel")               
                {
                        if (tname == bname) 
                                return notify_fail("�㲻�ܸ��Լ�������ˡ�\n");
                        
                        if (! BUNCH_D->bunch_is_league(bname, tname)) 
                                return notify_fail("�˰��ɲ�û�и�����ɽ��ͬ�ˡ�\n");
                                                
                        shout(HIY + me->name() + "�������" + bname + "��ʽ���������������" + tname + "��ͬ��Э�顣\n" NOR);
                        BUNCH_D->remove_league_from_bunch(bname, tname);
                        return 1;
                        
                }
                else
                        return notify_fail("ָ���ʽ��bunch ally with|cancel <����>\n");
        }
}

int bunch_arrest(object me, string arg)
{
        string banghui, msg;
        string str;
        object target;
        string *vendetta = ({ });
        int    i, cnt;

        if (! stringp(banghui = me->query("bunch/bunch_name")))
                return notify_fail("�㻹û���齨������κΰ��ɡ�\n");

        if(! arg)
        {
                msg = HIR "ͨ��������\n" NOR;
                msg += "����������������������������������������������\n" NOR;
                
                vendetta = BUNCH_D->query_bunch_info(banghui, "vendetta");
                
                if (! arrayp(vendetta) || sizeof(vendetta) < 1)
                        return notify_fail("Ŀǰû�б�������ͨ�����ˡ�\n");
                        
                cnt = 0;
                for (i = 0; i < sizeof(vendetta); i++)     
                {
                        target = UPDATE_D->global_find_player(vendetta[i]);
                       
                        msg += sprintf("%-18s%s", target->query("name") + "(" + target->query("id") + ")",
                                      (cnt % 4 == 3 ? "\n" : ""));
                        cnt++;
                }
                
                if (cnt == 0 || (cnt % 4))     
                        msg += "\n";
                msg += "����������������������������������������������\n" NOR;
                me->start_more(msg);
                return 1;
        }

        if (! me->query("bunch/level") || 
              me->query("bunch/level") < 7)
                return notify_fail("�㲢����" + banghui + "���ɵ���ͷ�ϴ�\n");
                
        
        if (sscanf(arg,"-a %s", str) == 1)  
        {
                target = UPDATE_D->global_find_player(str);
                
                if (! target)
                        return notify_fail("����׷ɱ����Ҳ������ڡ�\n");
                        
                if (target == me)
                {
                        UPDATE_D->global_destruct_player(target, 1);
                        return notify_fail("׷ɱ�Լ���û����ɡ�\n");
                }
                        
                if ((int)target->query("age") < 18)
                {
                        UPDATE_D->global_destruct_player(target, 1);
                        return notify_fail("׷ɱ����֮����û����ɡ�\n");
                }
                        
                if (target->query("vendetta/" + banghui))
                {
                        UPDATE_D->global_destruct_player(target, 1);
                        return notify_fail("��������ں������С�\n");
                }
                        
                target->set("vendetta/" + banghui, 1);
                target->save();
                
                vendetta = BUNCH_D->query_bunch_info(banghui, "vendetta");
                if (! arrayp(vendetta)) vendetta = ({ });
                vendetta += ({ target->query("id") });
                
                BUNCH_D->add_bunch_info(banghui, "vendetta", vendetta);
                
                if (banghui == (string)target->query("bunch/bunch_name"))
                        message("channel:rumor",
                                HIR"��ҥ������"+ "ĳ�ˣ����ɡ�"+banghui+"����ʼ׷ɱ����"+
                                target->query("name")+"("+target->query("id")+")�������ֵܼ�����ɱ���ۣ�\n"NOR, users());
                else
                        message("channel:rumor",
                                HIR"��ҥ������"+ "ĳ�ˣ����ɡ�"+banghui+"����ʼ׷ɱ"+target->query("name")+"("+target->query("id")+")�������ֵܼ�����ɱ���ۣ�\n"NOR,users());
                                
                UPDATE_D->global_destruct_player(target, 1);
                return 1;
        }
        
        if (sscanf(arg, "-d %s", str) == 1)  
        {
                target = UPDATE_D->global_find_player(str);
                if(! target)    return notify_fail("����Ϸ��û����ô����ҡ�\n");
                if(! target->query("vendetta/" + banghui))
                {
                        UPDATE_D->global_destruct_player(target, 0);
                        return notify_fail("����Ҳ�����׷ɱ�ĺ������С�\n");
                }
                        
                target->delete("vendetta/" + banghui);
                target->save();
                
                vendetta = BUNCH_D->query_bunch_info(banghui, "vendetta");
                if (! arrayp(vendetta)) vendetta = ({ });
                vendetta -= ({ target->query("id") });
                vendetta -= ({ 0 });
                BUNCH_D->add_bunch_info(banghui, "vendetta", vendetta);
                message("channel:rumor",
                       HIR "��ҥ������"+ "ĳ�ˣ����ɡ�"+banghui+"��ֹͣ׷ɱ"+target->query("name")+"("+target->query("id")+")���������⡣\n"NOR,users());
                UPDATE_D->global_destruct_player(target, 1);
                return 1;
        }
        
        return notify_fail("ָ���ʽ��bunch arrest [-a][-d]<���ID>\n");
}

int bunch_invite(object me, string arg)
{
        object ob, *target;
        string bunch;
        int money, i, flag;
        mapping data;
        string *what, stuffid, stuffname;

        if (! arg || arg == "")
                return notify_fail("��Ҫ����˭������İ�᣿\n");
                        
        if (! stringp(bunch = me->query("bunch/bunch_name")))
                return notify_fail("��û�вμ��κΰ�ᣬ�޷��������˼��롣\n");               
        
        flag = 0;
        
        if (intp(me->query("bunch/level")) &&
            (int)me->query("bunch/level") > 4)
                flag = 1;                       
                        
        if (me->query("id") == arg)
                return notify_fail("�����Լ�����\n");
                
        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����û��ô���ˡ�\n");
                
        if (! ob->is_character())
                return notify_fail("��ֻ�����롸�ˡ�������İ�ᡣ\n");
                
        if (ob->query("bunch/bunch_name") == me->query("bunch/bunch_name"))
                return notify_fail(ob->query("name") + "�Ѿ��Ǳ�������ˡ�\n");
                
        if (me->is_fighting() || me->is_busy())
                return notify_fail("����æ���ء�\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail("�Է���æ���ء�\n");
                
        if (! living(ob)) return notify_fail("�����Ū������˵��\n");       
                
        if (playerp(ob) && ! flag)
                return notify_fail("����Ȩ������Ҽ��롸" + bunch + "����\n");

        message_vision("$N����$n�μӰ�ᡸ" + bunch + "����\n", me, ob);
        
        if (! playerp(ob))        
        {
                if (! ob->query("bunch/zhengzhao") || ! ob->is_bunch_npc())
                        return notify_fail("������" + ob->query("name") +
                                "����İ��û����Ȥ��\n");
                                
                if (sizeof(BUNCH_D->query_areas_in_bunch(bunch)) > BUNCH_D->query_bunch_fame(bunch) / 500000)
                        return notify_fail("������İ�������������������" + ob->query("name") +
                                "����İ��û����Ȥ��\n");
                                
                switch (ob->query("bunch/zhengzhao"))  
                {
                case 1: 
                        if ((! stringp(bunch = ob->query("bunch/bunch_name")) ||
                            ob->query("bunch/zhongcheng") < me->query("meili")) &&
                            ob->query("qi") * 100 > ob->query("max_qi") * 80) 
                        {
                                message_vision("$N��$n˵������������ˣ����Ҳ����д�(qiecuo)һ���书��Σ���\n",
                                               ob, me);
                                ob->set_temp("invite/target", me);
                                return 1;
                        }
                        message_vision("$N����$nЦ�������ҿɲ��Ҹ��ʹ�ﰡ����\n", ob, me);
                        return 1;
                        
                case 2: 
                        if (! (bunch = ob->query("bunch/bunch_name")) ||
                            ob->query("bunch/zhongcheng") < me->query("meili"))    
                        {
                                money = atoi(count_div(ob->query("combat_exp"), 1000));
                                
                                if (money < 1) money = 1;
                                
                                money = money * 1000;
                                message_vision("$N���ٺ١��˼�������$n������" +
                                               chinese_number(money / 1000) + "���ƽ���һ����Ҳ���С����\n",
                                               ob, me);
                                ob->set_temp("invite/target", me);
                                ob->set_temp("invite/money", money);
                                return 1;
                        }
                        message_vision("$N����$nЦ�������ҿɲ��Ҹ��ʹ�ﰡ����\n", ob, me);
                        return 1;
                        
                case 3: 
                        if (! (bunch = ob->query("bunch/bunch_name")) 
                        ||  ob->query("bunch/zhongcheng") < me->query("meili"))    
                        {
                                data = ob->query_temp("invite/target");
                                
                                if (! mapp(data)) data = ([]);
                                
                                target = keys(data);
                                
                                if (member_array(me->query("id"), target) != -1) 
                                {
                                        sscanf(data[me->query("id")], "%s:%s", stuffid, stuffname);
                                        message_vision("$N��$n���������Ҳ���˵�����𣿰�" +
                                                       stuffname + "(" + stuffid + ")����������\n",
                                                       ob, me);
                                        return 1;
                                }
                                
                                if (sizeof(target) >= 4)           
                                {
                                        message_vision("$NЦ�������ɴ�ҿ�����" +
                                                       RANK_D->query_respect(ob) + "��ʤ�м���\n",
                                                       ob);
                                        return 1;
                                }
                                
                                what = keys(npcneed);
                                stuffid = what[random(sizeof(what))];
                                stuffname = npcneed[stuffid];
                                data[me->query("id")] = stuffid + ":" + stuffname;
                                ob->set_temp("invite/target", data);
                                message_vision("$N����$n����ֻҪ������������֮�ڰ�" +
                                               stuffname + "(" + stuffid + ")" +
                                               "����������һ�к�������\n",
                                               ob, me);
                                               
                                // remove_call_out("delete_target");
                                call_out("delete_target", 180, ob, me->query("id"));
                                return 1;
                        }
                        message_vision("$N����$nЦ�������ҿɲ��Ҹ��ʹ�ﰡ����\n", ob, me);
                        return 1;
                }
        } else    
        {
                tell_object(ob, "�����Ը�����Է��İ�ᣬ��ʹ�� bunch join " + me->query("id") + "��\n");
                ob->set_temp("invite/target", me);
                return 1;
        }
}

void delete_target(object npc, string name)
{
        mapping data;
        
        if (! objectp(npc)) return;
        
        data = npc->query_temp("invite/target");
        
        if (! mapp(data))   return;
        
        map_delete(data, name);
        npc->set_temp("invite/target", data);
}

int join_bunch(object me, string arg)
{
        object ob;
        string bunch;

        if (! arg || arg == "")
                return notify_fail("��Ҫ����˭�İ�᣿\n");

        if (count_lt(me->query("combat_exp"), 1000))
                return notify_fail("��ų��뽭������ĥ��ĥ���ɡ�\n");    
                                         
        if (stringp(bunch = me->query("bunch/bunch_name")) ||
            stringp(bunch = me->query("league/league_name")))
                return notify_fail("��Ǹ�����Ѿ��ǡ�" + bunch + "�������ˣ��޷�����������ᡣ\n");
                
        if (me->is_fighting() || me->is_busy())
                return notify_fail("����æ���ء�\n");
                
        if (me->query("id") == arg)
                return notify_fail("��û����ô����\n");
                
        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
                
        if ((object)me->query_temp("invite/target") != ob)
                return notify_fail("��Ǹ��" + ob->query("name") + "��û��������μ����İ�ᡣ\n");
                
        if (! stringp(bunch = ob->query("bunch/bunch_name")))
                return notify_fail("��Ǹ��" + ob->query("name") + "���ڲ������κΰ�ᣡ\n");                           

        BUNCH_D->add_member_into_bunch(bunch, me->query("id"));
        BUNCH_D->add_bunch_fame(bunch, me->query("weiwang") / 10); 
        me->set("bunch/time", time());
        me->set("bunch/bunch_name", bunch);
        me->set("bunch/bunch_id", BUNCH_D->query_bunch_info(bunch, "bunch_id"));
        me->set("bunch/type", BUNCH_D->query_bunch_info(bunch, "type"));
        me->set("bunch/level", 1);
        me->set("bunch/title", "����");
                        
        message("channel:rumor", HIM "����̶��᡿ĳ�ˣ�" + me->query("name") + 
                                 "(" + me->query("id") + ")�����ᡸ" + bunch + 
                                 "��������Ϊ��" + bunch + "��Ч����\n" NOR, users());
                                 
        me->delete_temp("invite/target");
        
        return 1;
}

int bunch_color(object me, string arg)
{
        string banghui;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG,
                           CYN, WHT, HIR, HIG, HIY, HIB,
                           HIM, HIC, HIW, NOR, });

        if (! stringp(banghui = me->query("bunch/bunch_name")))
                return notify_fail("�㻹û���齨������κΰ��ɡ�\n");

        if (! me->query("bunch/level") || 
              me->query("bunch/level") < 7)
                return notify_fail("�㲢����" + banghui + "���ɵ���ͷ�ϴ�\n");

        if (! arg || arg == "")
                return notify_fail("��ҪΪ����ѡ��ʲô������ɫ��\n");

        arg = color_filter(arg);
        if (member_array(arg, color) == -1)
                return notify_fail("��ҪΪ����ѡ��ʲô������ɫ�����⣬������ѡ��\n");

        BUNCH_D->add_bunch_info(banghui, "color", arg);
        tell_object(me, "��Ϊ����ѡ���� " + arg + "��ɫ��ʾʾ��" + NOR + " ����ɫ��\n");
        return 1;
}

// �����еĳ�޶�������
int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return 1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return -1;

        return d2[1] - d1[1];
}

// ��ͬ���е����н����Ա����
int sort_member(string id1, string id2)
{
        object ob1, ob2;

        ob1 = find_player(id1);
        ob2 = find_player(id2);
        if (! objectp(ob1) && ! objectp(ob2))
                return strcmp(id2, id1);

        if (objectp(ob1) && objectp(ob2))
                return atoi(count_div(ob2->query("combat_exp"), 100)) - atoi(count_div(ob1->query("combat_exp"), 100));

        if (objectp(ob1))
                return -1;

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: bunch info [���] | hatred [���] | member [��������] 
          bunch top | out | area | all | expell | appoint | inherit
          ally | war | surrender | agree | arrest | invite | join | color

�鿴Ŀǰ�����ڰ��ɵĸ�����Ϣ�����У�

info   ���鿴�����е������Ա״̬��������
hatred ���鿴���ɵĳ�޶���
member ���鿴ĳ�����ɵĳ�Ա��
top    ���鿴���ɵ�����������
area   : �鿴���ɵĵ�����Ϣ��
out    : �����Լ����ڵİ��ɡ�
all    : �鿴���еİ�����Ϣ��
expell : ���������еĳ�Ա���ή�Ͱ���������
appoint: �������ɳ�Աλ�׼�ְ�Ρ�
inherit: ���ó�����֮λ�����������ˡ�
ally   : �鿴�������˼����������ɽ��ˡ�
war    : ��ĳ����������ս����(δ����)
surrender: ���ս״̬�İ�����͡�(δ����)
agree  : ���ܶ�ս״̬�İ�����͡�(δ����)
arrest : ����ͨ���
invite : ����ĳ�˼�����İ�ᡣĳ�˿�������һ��ǿ����еģΣУá�
join   : ����ĳ�����ɡ�
tax    : �趨����˰�ʡ�(δ����)
doc    : ��д����˵����(δ����)
color  : ����Ϊ�������ð��ɵ���ɫ��

��ʦ���Բ鿴�������ɵ���Ϣ��ֻ��Ҫ�����������ϰ��ɵ����ֻ�
�ǰ����е���ҡ�������ʦ����ʹ�� bunch dismiss  ����ǿ�н�ɢ
һ�����ɡ�

see also: area
HELP );
        return 1;
}

