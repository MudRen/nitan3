// smith.c

#include <ansi.h>

inherit SMITH;

mixed  ask_back();

void create()
{
        set_name("����", ({ "tie jiang", "tie", "smith" }));
        set("title", "�������ϰ�");
        set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
        set("attitude", "friendly");
        set("vendor_goods",({
                "/clone/weapon/changjian",
                "/d/baituo/obj/tiezheng",
                "/clone/weapon/longbow",
                "/clone/weapon/wolfarrow",
                "/clone/weapon/zhujian",
                "/clone/weapon/hammer",
                "/clone/weapon/tudao",
                "/clone/weapon/dagger",
                "/clone/weapon/tiegun",
                "/clone/weapon/gangdao",
                "/clone/cloth/tiejia",
                "/clone/weapon/gangjian",
                "/clone/weapon/qimeigun",
                "/clone/weapon/dadao",
                "/clone/weapon/jiedao",
                "/clone/weapon/falun",
                "/clone/weapon/arrow",  
                "/clone/weapon/bow",  
                "/clone/weapon/bow1",
                "/clone/weapon/bow2",
                "/clone/weapon/bow3",
                "/clone/weapon/bow4",
                "/clone/weapon/bow5",
                "/clone/weapon/bow6",
                "/clone/weapon/bow7",
                "/clone/weapon/bow8",                                
                "/d/item/obj/jingtie",
                "/clone/weapon/gangzhang",
        }));

        set("inquiry", ([
                "Ѫ���ޱ�" : (: ask_back :),
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

varargs int receive_damage(string type, int n, object who)
{
        if (! objectp(who) || ! interactive(who) || who == this_object())
                return 0;

        tell_object(who, HIR "�㷢��" + name() +
                    HIR "����һЦ����Ȼ����һ���ļ£�����һ���㱡�\n" NOR);
        return who->receive_damage(type, n, this_object());
}

varargs int receive_wound(string type, int n, object who)
{
        if (! objectp(who) || ! interactive(who) || who == this_object())
                return 0;

        tell_object(who, RED "�����" + name() +
                    RED "�����Ц��ֻ���û�����һʹ��ֱ��������\n" NOR);
        return who->receive_wound(type, n, this_object());
}

mixed ask_back()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "Ѫ����")
        {
                message_vision("$N�Թ��Եĸɻ����û������$n��˵ʲô��\n",
                               this_object(), me);
                return -1;
        }

        message_vision("$N��Ȼ̧��ͷ�����������´�����һ��"
                       "��$n���۽�΢΢һ����\n�������еĻ�"
                       "�ƣ������������������\n˵�գ�$N��"
                       "��$n����ææ�ĳ�������ȥ��\n", this_object(), me);
        tell_object(me, "�����" + name() + "���������ţ�������"
                    "һ���ص���" + name() + "ָ��ǰ�������һֱ��"
                    "�����ˣ�ȥ�ɣ���\n");
        tell_object(me, HIW "�����˺ܾã�Խ��Խ�䣬��Ȼ��ǰһ����"
                    "���Ѿ����������⣬ֻ�������Ļ�ѩӳ���ۻ����ҡ�\n" NOR);
        me->move("/d/xuedao/sroad8");
        return -1;
}


