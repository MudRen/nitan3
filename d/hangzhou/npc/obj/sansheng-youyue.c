// hua1.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIW"������Լ"NOR, ({"sansheng youyue", "youyue",}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���׵İٺϻ���������ô¡�ص����ֵ���Щ�����ˡ�\n");
                set("value", 10000);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n�����޼䣬΢΢һЦ��\n");
                set("unequip_msg", "$N���ĳ�̾������ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
