#include <ansi.h>
inherit TASK;
void create()
{
    set_name( CYN "����" NOR, ({ "yi yang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ���������·������������滹��һ�ɵ��������㡣\n");
          }
    set("owner", "����");
    setup();
}
