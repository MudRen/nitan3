#include <ansi.h>
inherit TASK;
void create()
{
    set_name(WHT"����̵�"NOR, ({ "duan di", "di",}));
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "ֻ");
            set("material", "stone");
            set("long", WHT"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���ף���Ө�ɰ���\n" NOR);
          }
    set("owner", "�ɻ���");
    setup();
}
