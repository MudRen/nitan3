#include <ansi.h>  
inherit TASK;
void create()
{
    set_name(RED"ͨ����ʾ"NOR, ({ "tongji gaoshi", "gaoshi"}) );  
    set_weight(10);  
    if( clonep() )  
            destruct(this_object());  
    else { 
            set("unit", "��");
            set("material", "paper");  
            set("long", "һ��ͨ����ʾ��\n"); 
       }
       set("owner", "����");  
       setup();  
}
