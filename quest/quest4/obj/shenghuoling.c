#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(RED"ʥ����"NOR, ({ "shenghuo ling", "ling" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", 
                BLK"����һöʥ����������ںڵĺ������ۣ�����������������˲�˹���֡�\n"NOR);
                set("rigidity", 100); 
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N�ӻ����ͳ�һö$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�ջػ��С�\n");
        }
        init_sword(40);
        setup();
}

