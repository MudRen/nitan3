#include <ansi.h>  
inherit TASK;  
void create()  
{
    set_name(HIG"�����ķ�"NOR, ({ "ylxf" }) );  
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object());  
    else {
            set("unit", "��");  
            set("material", "paper");  
            set("long", "�����ŵ��ڹ��ķ���\n");  
      } 
      set("owner", "�½���"); 
}
