inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("���۴�", ({ "huafen dai", "dai"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ζ����Ļ��۴�\n");
                set("value", 1000);
        }
}

