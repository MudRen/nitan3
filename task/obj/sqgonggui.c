#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIC"���幬��"NOR, ({ "sqgonggui" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ�����幬�Ĺ���\n");
          } 
    set("owner", "����һ");
        setup();  
}   
