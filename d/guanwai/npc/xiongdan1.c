// xiongdan1.c

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("�ܵ���", ({"xiongdan gan", "xiongdan", "gan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ܵ��ɡ�\n");
                set("value", 1000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_fighting()) return notify_fail("ս���в��ܳԶ�����\n");
        if (me->is_busy()) return notify_fail("����æ���أ�\n");

        this_player()->set("eff_qi", this_player()->query("max_qi"));
        message_vision("$N����һ���ܵ��ɣ����þ���ö��ˡ�\n", this_player());
        destruct(this_object());
        return 1;
}


