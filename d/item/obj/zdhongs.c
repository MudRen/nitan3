// zdhong-stone.c �յ��

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR "�յ��" NOR, ({ "zdhong stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR "��ʯ�Ǻ챦ʯ������ϧ��һ�֡�ɫ�������޷����ڹ��ߵ������»ᷴ���\n"
                                "���˵������ǹ⡣���ǰ������ɰ��顢�����Ʒ�¸��еĴ�����Ե���\n"
                                "������˵����յ����˽��ὡ�����١�������������ͥ��г���ഫ����\n"
                                "����ʿ�����ϸһ��С�ڣ���һ���챦ʯǶ����ڣ���Ϊ�������Դﵽ\n"
                                "��ǹ�����Ŀ�ġ�\n" NOR);
                set("value", 500000);
                set("unit", "��");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
                set("magic/power", 100);
                set("armor_prop/per", 7);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

