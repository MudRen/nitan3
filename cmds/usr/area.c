// Copyright (C) 2005, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_CLEAN_UP;

int do_area_kaifa(object me, string arg);
int do_area_tisheng(object me, string arg);
int show_area_all(object me, string arg);

int sort_areas(string f1, string f2, mapping fame)
{
        if (fame[f2]["bunch_name"] != fame[f1]["bunch_name"])
                return strcmp(fame[f2]["bunch_name"], fame[f1]["bunch_name"]);

        return strcmp(fame[f2]["bunch_name"], fame[f1]["bunch_name"]);
}

void create() { seteuid(getuid()); }

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
        case "kaifa":
                return do_area_kaifa(me, arg);
        
        case "tisheng":
                return do_area_tisheng(me, arg);
                
        case "all":
                return show_area_all(me, arg);

        }

        write("��Ч�Ĳ�����\n");
        return 1;
}

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

int do_area_kaifa(object me, string arg)
{
        string fam;
        string *member;
        string area;
        string msg;
        mapping data;
        int j, kaifa, money;    
        object npc;

        if (! stringp(fam = me->query("bunch/bunch_name")))
                return notify_fail("��û�м����κΰ�ᣬ�޷���������������̡�\n");
                
        if (! arrayp(member = BUNCH_D->query_bunch_areas(fam)))
        {
                write("���ڰ���" + fam + "û���κε��̡�\n");
                return 1;
        }
        
        member -= ({ 0 });
                
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
        
        if (! arg)
        {
                msg = sprintf(HIC "\n%-18s%-28s%-8s%-8s%-18s\n" NOR,
                                "��������", "פ�ذ���", "������", "�ҳ϶�", "��������");
                      
                msg += HIY "����������������������������������������������������������������������\n" NOR;
                
                j = 0;
                foreach (area in member)
                {
                        data = BUNCH_D->query_area_info(area, "dbase");
                        
                        if (! mapp(data)) continue;
                                        
                        j++;
                        msg += sprintf(HIC "%-18s%-28s%-8s%-8s%-18s\n" NOR,
                                        data["area_name"], 
                                        data["npc_name"] + "(" + data["npc_id"] + ")",
                                        data["kaifa"] + "%", 
                                        data["zhongcheng"] + "%",
                                        data["last_money"] / 100 + " ��"); 
                }

                if (j < 1)
                        return notify_fail(arg + "����û���κε��̡�\n");

                msg += "\nĿǰ" + HIM + fam + NOR + "����" + HIM + chinese_number(j) + NOR + "�����̡�\n";
                msg += HIY "����������������������������������������������������������������������\n" NOR;
        
                write(msg);
                return 1;
        }
        
        area = base_name(environment(me));
        
        if (arg != environment(me)->short())
                return notify_fail("����뵽ʵ�ز��ܽ��е��̿�����\n"); 
        
        if (BUNCH_D->query_area_info(area, "bunch_name") != fam)        
                return notify_fail("���ﲻ������İ��ɵ��̣����ʲô������\n"); 

        if (BUNCH_D->query_area_info(area, "npc_id")) 
                npc = present(BUNCH_D->query_area_info(area, "npc_id"), environment(me)); 
                
        if (! objectp(npc)) 
                return notify_fail("����" + arg + "���̿����ģΣУò�δ��λ���޷����п�����\n"); 
        
        data = BUNCH_D->query_all_areas();
        kaifa = data[area]["kaifa"]; 

        if (kaifa >= 100) 
                return notify_fail(arg + "�Ŀ������Ѵﵽ��󣬲����ٿ�����\n");

        money = kaifa * 10000;
        
#ifdef LONELY_IMPROVED
        if (count_lt(me->query("balance"), money))
#else           
        if ((int)me->query("balance") < money) 
#endif
        {
                return notify_fail("�����ϵ�Ǯ����������" + arg + "����Ҫ" +
                                   MONEY_D->money_str(money) + "��\n");
        }
        
        me->add("balance", -money);
        me->save();
        
        BUNCH_D->add_area_info(area, "kaifa", 1);    
     
        write("�㻨����" + MONEY_D->money_str(money) + "������" + arg + "�Ŀ�����������һ�㣡\n");
        return 1;
}        

int do_area_tisheng(object me, string arg)
{
        string bunch;
        string someone;
        string *member;
        mapping data;      
        int amount;
        int money;
        object ob;
        string area;
        string msg;
        int j;

        if (! stringp(bunch = me->query("bunch/bunch_name")))
                return notify_fail("��û�вμ��κΰ�ᣬ�޷������κΣΣУá�\n");

        if (! arrayp(member = BUNCH_D->query_bunch_areas(bunch)))
        {
                write("���ڰ���" + bunch + "û���κε���פ�ذ��ڣ���������˭���ҳ϶��ء�\n");
                return 1;
        }
        
        member -= ({ 0 });
                
        if (sizeof(member) < 1)
                return notify_fail(bunch + "����û���κε���פ�ذ��ڣ���������˭���ҳ϶��ء�\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy() || me->is_fighting())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }
        
        if (! arg)
        {
                msg = sprintf(HIC "\n%-18s%-28s%-8s%-8s%-18s\n" NOR,
                                "��������", "פ�ذ���", "������", "�ҳ϶�", "��������");
                      
                msg += HIY "����������������������������������������������������������������������\n" NOR;
                
                j = 0;
                foreach (area in member)
                {
                        data = BUNCH_D->query_area_info(area, "dbase");
                        
                        if (! mapp(data)) continue;
                                        
                        j++;
                        msg += sprintf(HIC "%-18s%-28s%-8s%-8s%-18s\n" NOR,
                                        data["area_name"], 
                                        data["npc_name"] + "(" + data["npc_id"] + ")",
                                        data["kaifa"] + "%", 
                                        data["zhongcheng"] + "%",
                                        data["last_money"] / 100 + " ��"); 
                }

                if (j < 1)
                        return notify_fail(arg + "����û���κε���פ�ذ��ڡ�\n");

                msg += "\nĿǰ" + HIM + bunch + NOR + "����" + HIM + chinese_number(j) + NOR + "������פ�ذ��ڡ�\n";
                msg += HIY "����������������������������������������������������������������������\n" NOR;
        
                write(msg);
                return 1;
        } 
                               
        if (sscanf(arg, "%d %s", amount, someone) != 2)
                return notify_fail("���������鿴�����\n");                

        if (amount < 0 || amount > 10)
                return notify_fail("ÿ��������ֵ����С����Ҳ���ܴ���ʮ�㡣\n");
                                
        if (! ob = present(someone, environment(me)))
                return notify_fail("���û����ô���ˡ�\n");
                                
        if (! ob->is_character())
                return notify_fail("����������������\n");
                
        if (userp(ob))
                return notify_fail("��ֻ����������ΣУð��ڵļ��ܡ�\n");
                
        if (! living(ob))
                return notify_fail("����Ȱ�" + ob->query("name") + "Ū����˵��\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail(ob->query("name") + "��æ���ء�\n");

        if (bunch != (string)ob->query("bunch/bunch_name"))
                return notify_fail("��ֻ������������ڵģΣУð��ڡ�\n");
                
        if (! ob->is_bunch_npc())
                return notify_fail(ob->query("name") + "�ƺ����ڲ���������������\n");
                
        area = base_name(environment(ob));

        if (BUNCH_D->query_area_info(area, "bunch_name") != bunch ||
            BUNCH_D->query_area_info(area, "npc_id") != ob->query("id"))
                return notify_fail(ob->query("name") + "�ƺ����ڲ���������������\n");

        if ((int)BUNCH_D->query_area_info(area, "zhongcheng") >= 
            (int)ob->query("bunch/max_zhongcheng"))
                return notify_fail(ob->query("name") + "���ҳ϶��Ѿ��ﵽ��󣬲���Ҫ���������ˡ�\n");

        money = amount * 10000;
                
#ifdef LONELY_IMPROVED
        if (count_lt(me->query("balance"), money))
#else           
        if ((int)me->query("balance") < money) 
#endif
                return notify_fail("�����ϵ�Ǯ������" + ob->query("name") +
                                   "���ҳ϶�ÿ����һ����Ҫһ���ƽ�\n");
                                
        me->add("balance", -money);
        me->save();
                
        if ((int)BUNCH_D->query_area_info(area, "zhongcheng") + amount >= 100)
        {
                BUNCH_D->set_area_info(area, "zhongcheng", 100);
                ob->set("bunch/zhongcheng", (int)ob->query("bunch/max_zhongcheng"));
        } else    
        {
                BUNCH_D->add_area_info(area, "zhongcheng", amount);
                ob->add("bunch/zhongcheng", amount);
        }
                
        write("�㻨�� " + money / 10000 + " ���ƽ𣬽�" + ob->query("name") + "���ҳ϶�������" + amount + "�㣡\n");

        return 1;
}

int show_area_all(object me, string arg)
{
        mapping all_areas;
        string *areas;
        string  area, msg;
        mapping data;
        int     j;

        if (! mapp(all_areas = BUNCH_D->query_all_areas()))
        {
                write("������̶û���κε��̿ɱ��������á�\n");
                return 1;
        }
        
        areas = keys(all_areas);

        if (sizeof(areas) < 1)
                return notify_fail("��̶����û���κε��̿ɱ��������á�\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }
        
        areas = sort_array(areas, (: sort_areas :), all_areas);
        msg = sprintf(HIC "\n%-18s%-28s%-14s%-10s\n" NOR,
                      "��������", "פ�ذ���", "��������", "�ʽ�(�ƽ�)");
                      
        msg += HIY "����������������������������������������������������������������������\n" NOR;
                
        j = 0;
        foreach (area in areas)
        {
                data = BUNCH_D->query_area_info(area, "dbase");
                
                if (! mapp(data)) continue;

                j++;
                msg += sprintf(HIC "%-18s%-28s%-16s%6d\n" NOR, 
                               data["area_name"], 
                               data["npc_name"] + "(" + data["npc_id"] + ")",
                               stringp(data["bunch_name"]) ? data["bunch_name"] : "�� �� ��", 
                               data["money"] / 10000);
        }

        if (j < 1)
                return notify_fail("������̶û���κε��̿ɱ��������á�\n");

        msg += "\nĿǰ��̶����" + HIM + chinese_number(j) + NOR + "�����̡�\n";
        msg += HIY "����������������������������������������������������������������������\n" NOR;
        
        write(msg);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: area kaifa [������] | tisheng [���̰���ID] | all

�鿴Ŀǰ�����ڰ��ɵ��̵ĸ�����Ϣ�����У�

kaifa   ����������е��̣����Ӱ�����롣
tisheng ���������������פ�ص���NPC���ҳ϶ȡ�
all     : �鿴���еĵ�����Ϣ��

see also: bunch 
HELP );
        return 1;
}
