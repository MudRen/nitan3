#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIG "������" NOR, ({ "bingqipu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "���ظ��ֱ�����һ�����飬������������ķ���Ҳ̫���ˣ���Ĳ��󻰡�\n");
          }
    set("owner", "ʷ��");
    setup();
}
