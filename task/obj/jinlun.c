#include <ansi.h> 
inherit TASK; 
void create() 
{ 
    set_name(HIY"����"NOR, ({ "jin lun" }) ); 
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "stone"); 
            set("long", "���ַ��������������\n"); 
    } 
    set("owner", "���ַ���"); 
    setup();  
}
