#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( HIB "��" NOR, ({ "gui dao" }) ); 
        set_weight(40); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "iron"); 
                set("long", "����һ�ѹ�����䵶������ϸ����������񣬵������졣\n"); 
        } 
        set("owner", "����"); 
        setup(); 
} 
