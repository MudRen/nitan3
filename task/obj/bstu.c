#include <ansi.h>
inherit TASK;
void create()
{
    set_name( WHT "��ɽͼ" NOR, ({ "bstu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ϸ�İ�ɽ��ͼ�����½�д��һ��С�֣�
            �ɶ���ʮ��������ģ�����˫ʱ����\n");
          }
    set("owner", "����");
    setup();
}
