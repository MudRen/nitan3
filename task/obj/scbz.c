#include <ansi.h>  
inherit TASK;
void create()
{
    set_name(HIC"��������"NOR, ({ "scbz", "shengchen bazi" }) );  
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object());  
    else { 
            set("unit", "��");  
            set("material", "paper");
            set("long", "�������֡�������������\n"); 
        }
        set("owner", "����");  
        setup(); 
}
