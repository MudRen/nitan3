#include <ansi.h> 
inherit TASK; 
void create()  
{ 
    set_name(HIB"ʥ����"NOR, ({ "ling", "shenghuo ling" }) );  
    set_weight(1);
    if( clonep() ) 
            destruct(this_object());  
    else { 
          set("unit", "��");  
          set("material", "dagger"); 
            set("long", "���̶�ʧ��ʥ�����ơ�\n"); 
          } 
          set("owner", "����ʹ");
          setup();
} 
