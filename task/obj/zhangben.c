#include <ansi.h>
inherit TASK;
void create()
{
    set_name( CYN "�ʱ�" NOR, ({ "zhang ben" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�������˱���������������ļ�¼��һ�����Ŀ��\n");
          }
    set("owner", "������");
    setup();
}
