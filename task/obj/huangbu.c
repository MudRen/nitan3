#include <ansi.h> 
inherit TASK; 
void create()
{ 
    set_name(HIY"�Ʋ�" NOR, ({ "huangbu"}) ); 
    set_weight(1); 
    if( clonep() )
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "paper");
            set("long", "һ���ɫ�Ĳ��������˼�����ɫ���֡�\n��������޵��֡�\n"); 
         } 
    set("owner", "���˷�"); 
    setup(); 
}
