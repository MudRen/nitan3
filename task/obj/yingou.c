#include <ansi.h> 
inherit TASK; 
void create() 
{ 
   set_name(HIW"����" NOR, ({ "yin gou" }) ); 
   set_weight(10); 
   if( clonep() ) 
           destruct(this_object()); 
   else { 
        set("unit", "��"); 
        set("material", "stone"); 
        set("long", "�䵱�����У��Ŵ�ɽ������������\n"); 
         } 
        set("owner", "�Ŵ�ɽ"); 
        setup(); 
}
