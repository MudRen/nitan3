#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "��������" NOR, ({ "dayan yuxi", "yuxi" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ��������������Ŵ�����ţ���������Щ����ˡ�\n");
          }
    set("owner", "Ľ�ݲ�");
    setup();
}
