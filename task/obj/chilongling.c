#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( RED "������" NOR, ({ "chilong ling" }) ); 
        set_weight(50); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "iron"); 
                set("long", "��������𽭺��ĳ������������͸��Ѫ��ɫ�Ĺ�â������ȥɷ�����ˡ�\n"); 
        } 
        set("owner", "�޸�����"); 
        setup(); 
} 
