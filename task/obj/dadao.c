#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIW"��"NOR, ({ "da dao" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "һ����ͨ�󵶣����˵����һ����Ժ��⣬û��ʲô�ر���ˡ�\n");
          }
    set("owner", "éʮ��");
    setup();
}
