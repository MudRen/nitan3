#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIR"��ɱ��" NOR, ({ "csl" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ��Ѫ���߰ߵ����ơ�\n");
    }
    set("owner", "ȫ����");
    setup();
}
