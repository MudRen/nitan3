// hongshongm.c ��ľ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "����ľ" NOR, ({ "hongshong wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "��");
                set("long", 
                        "���ɣ��ֳƺ��ɣ����ֲ����й���������������ľ������Ӳ���У�����\n"
                        "ֱͨ��ɫ�����ۣ����̲��䣬���׼ӹ����͸��������Ǳ�������Ҫ��ľ��\n"
                        "ԭ�ϡ�\n");
        }
        setup();
}

int fire(object me, object ob)
{
        object fire;

        if (environment()->query_temp("warm") >= 40)
                return notify_fail("�����Ѿ����ȵ��ˣ��㻹�ǻ����ط����ɡ�\n");

        message_vision("$N��" + ob->name() + "��ȼ��" + name() +
                       "��һƬ���Ļ��ӳ�������ܡ�\n", me);

        fire = new("/clone/misc/needfire");
        fire->move(environment(me));

        destruct(this_object());
        return 1;
}

