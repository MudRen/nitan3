// bj-yuebing.c 
// smallbear 03.9.9
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL"�����±�"NOR, ({"baojian yuebing","yuebing"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�鱣���±������˲Σ�ҩ���۽��±��ھ��ƶ��ɣ��н���֮��Ч��\n"NOR);
                set("unit", "��");
                set("value", 10000);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

