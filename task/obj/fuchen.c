#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIW"����" NOR, ({ "chenfu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "֧");
            set("material", "paper");
            set("long", "һ֧��ͨ�ĳ���\n");
          }
    set("owner", "���ʦ̫");
    setup();
}
