#include <ansi.h>
inherit TASK; 
void create()
{
    set_name(HIR"����ͼ"NOR, ({ "yinhui tu", "tu" }) ); 
    set_weight(1);
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "paper"); 
              set("long", "һ�Ż�����Ů�����ͼ��\n"); 
       }
       set("owner", "Ѫ������"); 
       setup(); 
}
