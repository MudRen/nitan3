#include <ansi.h>
inherit TASK;
void create()
{
    set_name("��Ѽ�ط�", ({ "kaoya mifang", "mifang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�����Ǳ�����������ȫ�۵ó��ϰ�Ŀ�Ѽ�ط���\n");
          }
    set("owner", "���ϰ�");
    setup();
}
