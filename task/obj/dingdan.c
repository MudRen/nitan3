inherit TASK;
#include <ansi.h>
void create()
{
    set_name( HIM"�ͻ�����" NOR, ({ "dingdan" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ϸ�Ķ���������������Ժ��Ԥ�������\n");
        }
    set("owner", "Τ����");
    setup(); 
}
