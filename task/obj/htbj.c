#include <ansi.h> 
inherit TASK; 
void create() 
{ 
    set_name(HIR"���챦��"NOR, ({ "book", "book" }) ); 
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "book"); 
            set("long", "һ��д�Ż��챦���ڹ����ؼ���\n"); 
         }
    set("owner", "����"); 
    setup();
}
