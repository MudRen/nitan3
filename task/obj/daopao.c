#include <armor.h>
#include <ansi.h>
inherit TASK;

void create()
{
        set_name( HIB "���Ե���" NOR, ({ "daopao" }) );
        set_weight(3000);
        if( clonep() )
            destruct(this_object());
        else {
                set("unit", "��");
                set("long", "����һ�����а��Ե���\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        set("owner", "��ͷ��");
        setup();
}
