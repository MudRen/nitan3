#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"Ǭ��һ����"NOR, ({"yiqi dai", "dai" }) );
        set_weight(1000);
        set_max_encumbrance(5000);
        
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "��");
                set("long", "����һ���������Ĵ��ӡ��ǳ�Ǹ�����쳣������ȥ\n"
                        "������Ȼ�����Ǵֲ����ƣ���˺��ȥȴ�����ޱȡ�\n");
                set("value", 10000);
                set("material","silk");
                set("treasure",1);
        }        
        setup();
}

