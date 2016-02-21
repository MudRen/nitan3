// dizi.c
inherit NPC;

void create()
{
        mapping name = NAMES_D->random_name(0, 0, "��", 0, 0);

        if (! name)
		name = ([ "name": "�Ʒ�",  "id": ({ "tang feng", "tang", "feng" }) ]);
		
        set_name(name["name"], name["id"]);
        set("gender", "����");
        set("long",
                "�������ҵ��ӣ���һ���ɫ�ľ�װ\n"
        );
        set("combat_exp", random(50000));
        set("class", "tangmen");
        set("neili", random(500));
        set("max_neili", random(500));

        set("title", "�������ҵ���");
        set_skill("force", 10+random(80));
        set_skill("dodge", 10+random(80));
        set_skill("throwing", 10+random(80));
        set_skill("parry", 10+random(80));
        setup();

        add_money("silver", 5);
        carry_object("clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="��������" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �������ҵ��Ӳ��ͱ��ɵ��˹��С�");
        return 0;
}

