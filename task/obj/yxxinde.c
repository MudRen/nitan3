#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( WHT "ҽ���ĵ�" NOR, ({ "yixian xinde" }) ); 
        set_weight(2); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "paper"); 
                set("long", "����һ��ҽ�飬������¼�˸���ҽ��֮����������Ϊҽ֮�䱦��\n"); 
        } 
        set("owner", "����ţ"); 
        setup(); 
} 
