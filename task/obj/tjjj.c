#include <ansi.h>   
inherit TASK;  
void create()   
{ 
    set_name(HIW"̫������"NOR, ({ "tjjj" }) );   
    set_weight(1);  
         if( clonep() ) 
            destruct(this_object());   
    else { 
        set("unit", "��");  
        set("material", "book"); 
        set("long", "�������Դ��书̫�������ķ���\n");   
     } 
     set("owner", "������"); 
        setup();  
}
