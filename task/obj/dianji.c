#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIG"�ؾ���伮"NOR, ({ "dian ji" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "����Ǵ����ֲؾ���������������ѧ�伮��\n");
          }
    set("owner", "������ɮ");
    setup();
}
