// mancloth 
// by ruri
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"�ײ�����"NOR, ({ "baibu qingshan", "cloth","shan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ����ɫ������ϴ��ʮ�ָɾ���\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 1);
        }
        setup();
}

