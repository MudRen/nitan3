#include <ansi.h>
inherit TASK;
void create()
{
    set_name( MAG "������" NOR, ({ "hua mingce", "mingce" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���컨��Ļ����ᣬ�����¼�����к컨��ú���������\n�������Ҫ�Ǳ��ٸ��õ��˿ɲ����ˡ�\n");
          }
    set("owner", "�¼���");
    setup();
}
