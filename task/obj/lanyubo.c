#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIC"����"NOR,({ "lanyu bo", "bo" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "ֻ");
            set("material", "stone");
            set("long", "һֻ���������ƶ��ɵ�ҩ������Ȼʹ���վã���˿��û���ƺۡ�ҩ����\n������΢���綾, Ȼ���㹻����͵��֮�ˡ�\n");
          }
    set("owner", "������");
    setup();
}
