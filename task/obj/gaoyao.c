#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( HIC "��ҩ" NOR, ({ "gaoyao" }) ); 
        set_weight(2); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "paper"); 
                set("long", "����һ�����Ƶĸ�ҩ�������ŵ����Ĳ�ҩ��ζ��\n"); 
        } 
        set("owner", "���촨"); 
        setup(); 
} 
