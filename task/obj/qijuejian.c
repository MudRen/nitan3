#include <ansi.h>  
inherit TASK;  
void create()  
{ 
        set_name( HIR "�߾���" NOR, ({ "qijue jian" }) );  
        set_weight(2); 
        if( clonep() )  
                destruct(this_object());  
        else {  
                set("unit", "��"); 
                set("material", "stone"); 
                set("long", "һ�Ѿ��������������Ǵ�����϶��������彣��\n");  
             }
             set("owner", "������");  
             setup();
}
