#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( HIY "��⿴�ȫ" NOR, ({ "pengren book" }) ); 
        set_weight(2); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "paper"); 
                set("long", "����һ������ȥ�������С���ӣ�����������⣬�࣬�˹��ư˴���ĸ��ּ���������\n"); 
        } 
        set("owner", "����"); 
        setup(); 
} 
