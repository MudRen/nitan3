// wolf.c

inherit NPC;

void create()
{
        string *colors = ({ "��", "��", "��", "��", });
        string color;

        color = colors[random(sizeof(colors))];
        set_name(color + "��", ({ "wolf" }));
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�׺ݵĶ��ǡ�\n");
        set("attitude", "aggressive");

        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
        set("verbs", ({ "bite" }));

        set("combat_exp", 6000);

        set("chat_chance",50);
        set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence", 20);

        setup();
}
void die()
{
        object ob;

        message_vision("$N��ҵĺ��˼���, �ڵ��ϴ��˼��������������ˡ�\n", this_object());
        ob = new(__DIR__"obj/langpi");
        ob->set("name", name() + "Ƥ");
        ob->move(environment(this_object()));
        destruct(this_object());
}

