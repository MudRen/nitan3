#include <ansi.h>
inherit TASK;
void create()
{
    set_name(CYN"������"NOR, ({ "kelan jing", "jing"}));
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��������������˹������ͽ�ıر�֮�\n");
          }
    set("owner", "����ͩ");
    setup();
}
