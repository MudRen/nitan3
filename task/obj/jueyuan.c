#include <ansi.h>
inherit TASK;
void create()
{
    set_name(WHT"��ˮͰ"NOR, ({ "tie shuitong", "shui tong" }) );
    set_weight(100);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "һ����ͨ����ˮͰ��Ͱ����š������¡���������������������֮�\n");
          }
    set("owner", "��Զ");
    setup();
}
