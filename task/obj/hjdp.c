#include <ansi.h>  
inherit TASK;  
void create()  
{ 
    set_name(HIW"���ҵ���"NOR, ({ "daopu" }) );  
    set_weight(10);
       if( clonep() ) 
            destruct(this_object());  
    else { 
            set("unit", "��");
            set("material", "book");  
            set("long", "���ҵ��׶�ʧ����һҳ��\n");
        }
       set("owner", "���"); 
        setup();  
}
