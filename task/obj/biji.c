#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( WHT "ɢ�ıʼ�" NOR, ({ "biji" }) ); 
        set_weight(2); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "��"); 
                set("material", "paper"); 
                set("long", "һ��ɢ�ıʼǣ������ַ�����ֻ���ô��廪�������˷·������侳��\n"); 
        } 
        set("owner", "����"); 
        setup(); 
} 
