#include <ansi.h>  
inherit TASK;  
void create()  
{
    set_name(HIW"̫��ȭ��"NOR, ({ "tjqj" }) );  
    set_weight(1); 
    if( clonep() )
            destruct(this_object());  
    else {  
            set("unit", "��"); 
            set("material", "book");  
            set("long", "�������Դ��书̫��ȭ���ķ���\n");  
      } 
      set("owner", "������");  
        setup();  
}
