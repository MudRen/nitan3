#include <ansi.h>
inherit TASK;
void create()
{
    set_name(YEL"ͳ������"NOR, ({ "tongling yaopai", "yao pai", "pai"}));
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "����һ������۹������־�ͳ�����ơ�\n");
          }
    set("owner", "��¡");
    setup();
}
