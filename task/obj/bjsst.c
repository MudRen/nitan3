#include <ansi.h>
inherit TASK;
void create()
{
    set_name(WHT"�׽�˿����"NOR, ({ "shou tao", "shoutao" }) ); 
    set_weight(1);
    if( clonep() )
       destruct(this_object());
    else {
       set("unit", "˫"); 
       set("material", "steel");
       set("long", "����һ˫�׽�˿���ף��������ʵ��ᱡ�����Լ�ϸ���͵İ׽�˿֯�ɡ�\n"); 
    }
    set("owner", "С��Ů"); 
    setup();
}
