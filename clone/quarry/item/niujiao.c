#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "Ϭţ��" NOR, ({ "xiniu jiao", "xiniu", "jiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�����ĳ���Ϭţ�ǣ���Ʒ��������ԭ�ϣ��ǳ����\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 500000);
                set("base_weight", 1000);
        }
        setup();
}
int query_autoload()
{
        return 1;
}