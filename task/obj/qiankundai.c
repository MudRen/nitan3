#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( MAG "Ǭ����" NOR, ({ "qiankun dai" }) ); 
        set_weight(20); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "paper"); 
                set("long", "һ������ͨͨ������Щ�ƾɲ����Ĳ�����֪�������к��õ�����֮���١�\n"); 
        } 
        set("owner", "˵����"); 
        setup(); 
} 
