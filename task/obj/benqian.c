#include <ansi.h> 
inherit TASK; 
void create() 
{
    set_name(HIR"�����ı�Ǯ"NOR, ({ "benqian" }) ); 
    set_weight(1); 
    if( clonep() ) 
            destruct(this_object()); 
    else { 
            set("unit", "��"); 
            set("material", "paper"); 
            set("long", "һ�ŶĿͷ����ı�Ǯ��\n"); 
          } 
          set("owner", "�Ŀ�"); 
          setup();
}
