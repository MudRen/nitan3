// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#define GIFT_NAME "��վ����"
inherit ITEM;

int do_fen(string arg);

void create()
{
        set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
        set_weight(200);
        if (clonep())
	        set_default_object(__FILE__);
        else {
	        set("unit", "��");
	        set("long", @LONG
������̶�Ŀ�վ������԰��ĵ������츳�֣�fen��������Ҫ������������
��ʽΪ fen ���� 1 ���ָ�ʽ��
LONG );
	        set("value", 0);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
	        set("no_put", 1);
                set("no_drop", 1);
        }
        setup();
}

void init()
{
        object me = this_player();
        
        if (me == environment()) 
        {
                add_action("do_fen", "fen");
        }
}

int do_fen(string arg)
{    
        string htsx;
        int jnd;

        object me = this_player();

        if (! arg || sscanf(arg, "%s %d", htsx, jnd) != 2) 
                return notify_fail("ָ���ʽ��fen <��������> <����>\n"); 

        if ((int)me->query("tianfu") < 1)
                return notify_fail("��Ŀǰû��ʣ���κε������츳�������������䣡\n"); 

        if (htsx != "����" && htsx != "����" && htsx != "����" && htsx != "��"
                && htsx != "str" && htsx != "int" && htsx != "con" && htsx != "dex") 
                return notify_fail("��ֻ���Խ������츳�������䵽���������ԡ����Ǻ����������츳�����ϣ�\n"); 

        if (jnd < 1) return notify_fail("�����츳�����ķ���ÿ������Ҫ���ǣ��㡣\n");

        if (jnd > (int)me->query("tianfu"))
                return notify_fail("��û����ô��������츳������\n"); 

        switch (htsx)
        {
        case "����": 
        case "str":
                me->add("str", jnd);
                tell_object(me, HIY "ڤڤ�У����ƺ��о���һ����â����������ڣ�\n" NOR);
                tell_object(me, HIG "��ġ�" + HIR + "��������" + NOR + HIG "�������� " + HIR + chinese_number(jnd) + NOR + HIG + " �㣡\n" NOR);
                break;
        case "����":
        case "int":
                me->add("int", jnd);
                tell_object(me, HIY "ڤڤ�У����ƺ��о���һ����â����������ڣ�\n" NOR);
                tell_object(me, HIG "��ġ�" + HIR + "��������" + NOR + HIG "�������� " + HIR + chinese_number(jnd) + NOR + HIG + " �㣡\n" NOR);
                break;
        case "����":  
        case "con":  
                me->add("con", jnd);
                tell_object(me, HIY "ڤڤ�У����ƺ��о���һ����â����������ڣ�\n" NOR);
                tell_object(me, HIG "��ġ�" + HIR + "�������" + NOR + HIG "�������� " + HIR + chinese_number(jnd) + NOR + HIG + " �㣡\n" NOR);
                break;
        case "��":
        case "dex":
                me->add("dex", jnd);
                tell_object(me, HIY "ڤڤ�У����ƺ��о���һ����â����������ڣ�\n" NOR);
                tell_object(me, HIG "��ġ�" + HIR + "������" + NOR + HIG "�������� " + HIR + chinese_number(jnd) + NOR + HIG + " �㣡\n" NOR);
                break;
        default:  
                return notify_fail("ָ���ʽ��fen <��������> <����>\n");
                break;
        }
        me->add("tianfu", -jnd);
        
        if ((int)me->query("tianfu") < 1)
        {
                me->delete("tianfu");
                destruct(this_object());
        }

        if ((int)me->query("tianfu") > 0)
                tell_object(me, HIG "��Ŀǰ���� " + chinese_number(me->query("tianfu")) + " �������츳û�з��䣡\n\n" NOR);
        return 1;
}

void owner_is_killed() { destruct(this_object()); }


