#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIW"�廨��"NOR, ({ "xiuhua zhen", "zhen" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "����һö�廨�룬ǧ��С�������е�Ѱ��֮�\n");
                set("value", 100);
                set("rigidity", 100); 
                set("material", "steel");
                set("wield_msg", "$N���ĵĴ�����ɰ���ȡ��һö$n������ָ�䡣\n");
                set("unwield_msg", "$N�����е�$n�ջ�����ɰ��С�\n");
        }
        init_sword(40);
        setup();
}                

