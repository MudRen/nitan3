#include <ansi.h>
inherit TASK;
void create()
{
    set_name("������", ({ "guaishe zhang", "shezhang", "zhang"}));
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "wood");
            set("long", "һ�������������ߵ����ȣ���ͷ���л��أ�ҧ�����������ޱȣ�\n");
          }
    set("owner", "ŷ����");
    setup();
}
