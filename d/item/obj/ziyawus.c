// ziyawu-stone.c ������

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "������" NOR, ({ "ziyawu stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "������������״��ʯ���ѣ��ֳ�ʯ��ʯ�����ǹŴ��Ƚϳ������е͵���ʯ\n"
                                "֮һ����ɫŨ�޴�������������������ϲ���ı�ʯƷ�֡������������\n"
                                "��������������ʵ���Ѱ�����١�\n" NOR);
                set("value", 50000);
                set("unit", "��");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "wood");
                set("magic/power", 100);
                set("armor_prop/per", 5);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

