#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIY"���־�"NOR, ({ "san zi jing" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ���ּ�����ľ���\n");
          } 
    set("owner", "�쵤��");
}      
