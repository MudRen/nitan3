#include <ansi.h>
inherit TASK;
void create()
{
    set_name(BLU"�䵱¼"NOR, ({ "wudanglu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�����䵱¼��\n");
          } 
    set("owner", "������");
}  
