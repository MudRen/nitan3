// hw-yuebing.c 
// smallbear 02.9.13

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(CYN"��ζ�±�"NOR, ({"haiwei yuebing","yuebing"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�麣ζ�±��������б��㡢��ᡢ�ϲˡ������ȣ���ζ΢�����ʣ��Ը������ơ�\n"NOR);
                set("unit", "��");
                set("value", 10000);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

