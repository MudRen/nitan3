// zhubang.c ���
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIG"������"NOR, ({ "yuzhu zhang" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ���������ֳ����ģ��ƺ��൱��ʵ��\n");
                set("rigidity", 100); 
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_staff(40);
        setup();
}

