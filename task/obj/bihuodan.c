#include <ansi.h>  
inherit TASK; 
void create()  
{
   set_name(HIR"�̻�" NOR, ({ "bihuo dan" }) );  
   set_weight(10); 
   if( clonep() ) 
           destruct(this_object());  
   else { 
        set("unit", "��");  
        set("material", "stone");
        set("long", "������ô���յĶ������϶�������ժ���ӵı̻��ˡ�����\n");  
         }
         set("owner", "ժ����");  
         setup();
}
