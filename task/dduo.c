#include <ansi.h> 
inherit TASK; 
void create() 
{
    set_name( HIC "���ǵĹ���" NOR, ({ "our story", "story" }) );  
    set_weight(1); 
    if( clonep() )
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "book"); 
            set("long", "һ��д����Ҷ�Ͷ��İ�����µ��顣\n"); 
          } 
    set("owner", "���"); 
    setup(); 
}
