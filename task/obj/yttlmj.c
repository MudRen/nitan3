#include <ansi.h> 
inherit TASK; 
void create() 
{ 
    set_name(HIW"���������ؼ�"NOR, ({ "mi ji", "miji" }) ); 
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "book"); 
            set("long", "һ�����콣������������ؼ���\n"); 
         }
    set("owner", "������"); 
    setup();
}
