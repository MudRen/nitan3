#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIR"���ľ�"NOR, ({ "shexin jue" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "ؤ�ﳤ�����о������ľ��������¼���޹���˵���Կ��Ʊ��˵����ǡ�\n");
          }
    set("owner", "���о�");
    setup();
}
