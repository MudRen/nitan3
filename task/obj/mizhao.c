#include <ansi.h>
inherit TASK;
void create()
{
    set_name("�ʵ���ּ", ({ "mizhao" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���۵ĺܺõ�ֽ����ֽ���Ϻ��񻹸��˴�ӡ��\n");
          }
    set("owner", "�����");
    setup();
}
