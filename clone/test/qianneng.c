// zhenyu.c ����������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "Ǳ�ܵ�" NOR, ({ "qianneng dan", "dan" }) );
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ�����۴�С��ҩ�裬���˱ǣ�һ��֮�±���Ŀ�\n"
                                "����������ҩ�������Ž�����Ĺ������ֳ��أ���\n"
                                "���Ļ�����ͣ������������һ�㡣\n" NOR);
                set("value", 500000);
                set("unit", "��");
               set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        	message_vision(HIW "$N" HIW "һ������������һ��Ǳ�ܵ���ֻ��$P"
                               HIW "����һ�������϶�ð����������\n" NOR, me);

        	
        
        	me->add("potential", 30000);

        
        return 1;
}

int query_autoload()
{
        return 1;
}
