 // labazhou.c
 // By Plzw 2004-08-29
 
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({ "laba zhou", "zhou" }) );
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "ֻ������������ð��أ����һ�������ݴ�����꽫������һ���ྡ������֮ɫ������ȥ˵�����Ĺ��졣\n" NOR);
                set("value", 1);
                set("unit", "��");
                set("only_do_effect", 1); 
        }
}

int do_effect(object me)
{
        // �Ѿ��ȹ�
        if (me->query("gift/labazhou"))
        {
                message_vision(HIY "$N" HIY "�������룬���˸���׳��죬���Ǿ���û��ʲô���á�\n" NOR, me);
                destruct(this_object());
                return 1;
        }
        // ����Ч��
        if (me->query("story/labazhou"))
        {
                message_vision(HIY "$N" HIY "�������룬ֻ��ҩ���̱ǣ����ȴ����Ĳ����ѳԣ���̼����˸���׳��졣\n" NOR, me);
                if (random(10) == 1) 
                {
                        message_vision(HIC "$N" HIC "������������ģ��ǳ��úȡ�\n"NOR, me);
                        destruct(this_object());
                        return 1;  // 10% �ļ���û��Ч��
                }

                me->set("gift/labazhou", 1);

                message_vision(HIC "$N" HIC "����һ������ӿ����������ʱ���þ���Ϊ֮һ��\n" NOR, me);

                destruct(this_object());
                return 1;
        }
        else
        // û���й��µĲ��ܺ�
                return notify_fail("������������ˣ�ֻӳ�������̣�ҩ���̱ǣ��䶾��֪�����̲�ס��ҪŻ�¡�\n");
}

