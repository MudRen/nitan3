#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( HIB "�Ҵ�ذ��" NOR, ({ "bishou" }) ); 
        set_weight(20); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "iron"); 
                set("long", "����һ�Ѷ�С������ذ�ף�ذ�ױ��Ͽ���һ���������֣���������׽����\n"); 
        } 
        set("owner", "���"); 
        setup(); 
} 
