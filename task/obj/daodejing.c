#include <ansi.h> 
inherit TASK; 
void create() 
{ 
    set_name(MAG"���¾�"NOR, ({ "daode jing" }) ); 
    set_weight(10); 
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "book"); 
            set("long", "һ�����¾��顣\n"); 
        }
    set("owner", "�������"); 
    setup(); 
}
