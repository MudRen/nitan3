#include <ansi.h>
inherit TASK;
void create()
{
    set_name(YEL"һ���ë"NOR, ({ "jin mao", "mao" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ɫ��ë����\n");
          }
    set("owner", "лѷ");
    setup();
}
