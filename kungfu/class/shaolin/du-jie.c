// dujie.c

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#define HEISUO          "/clone/lonely/heisuo3"
#define JINLAN          "/clone/lonely/jinlan"

mixed ask_me();
mixed ask_jia();

void create()
{
        object ob1, ob2;
	set_name("�ɽ�", ({ "du jie", "jie" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�Ұף���һ��ֽһ����\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2300000);

	set("str", 32);
	set("int", 30);
	set("con", 33);
	set("dex", 31);

	set("qi", 5000);
	set("max_qi", 2500);
	set("neili", 6700);
	set("max_neili", 6700);
	set("level", 40);
	set("jiali", 90);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);

	set_skill("buddhism", 250);
	set_skill("force", 255);
	set_skill("whip", 255);
	set_skill("parry", 250);
	set_skill("dodge", 240);

	set_skill("hunyuan-yiqi", 255);
	set_skill("shaolin-xinfa", 255);
	set_skill("riyue-bian", 255);
	set_skill("shaolin-shenfa", 240);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("finger", 250);
	set_skill("jingang-zhi", 250);
	set_skill("martial-cognize", 220);

	map_skill("finger", "jinggang-zhi");

	prepare_skill("finger", "jingang-zhi");

	set_skill("medical", 200);
	set_skill("shaolin-yishu", 200);

	set("inquiry", ([
		"�����"     : (: ask_me :),
		"���[����"   : (: ask_jia :),		
	]));

	set("master_ob",4);
	setup();

        if (clonep())
        {
                ob1 = find_object(HEISUO);
                if (! ob1) ob1 = load_object(HEISUO);
                if (! environment(ob1))
                {
                        ob1->move(this_object());
                        ob1->wield();
                } else
                {
                        ob1 = new("/d/shaolin/obj/changbian");
                        ob1->move(this_object());
                        ob1->wield();
                }

                ob2 = find_object(JINLAN);
                if (! ob2) ob2 = load_object(JINLAN);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        ob2->wear();
                } else
                {
                        ob2 = new("/d/shaolin/obj/xuan-cloth");
                        ob2->move(this_object());
                        ob2->wear();
                }
        }
}

mixed ask_me()
{
	mapping fam; 
	object ob;
	
	if (! this_player()->query_temp("valid_in_fumoquan"))
	{
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		kill_ob(this_player());
                return 1;
	}

        if (this_player()->query_temp("valid_in_fumoquan") != 1)
        {
                command("heng");
                return 1;
        }

	if (present("jingang zhao", this_player()))
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ��������ϣ�����̰�����У�";

	if (present("jingang zhao", environment()))
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ�����������ȡ�ߣ�����̰�����У�";

	ob = get_object("/d/shaolin/obj/jingang-zhao");
        if (! ob || environment(ob) && environment(ob) != this_object())
                return "��Ǹ���������ˣ�������Ѿ�����ȡ���ˡ�";

	ob->move(this_player());

	message_vision("\n�ɽ�һ�����Ե�����$N���ã�Ť������������ȡ������ֵݸ�$N��\n\n", this_player());

	return "���ܰ����������ϲ���������������޲�����ȷʵ�������������־�������ˣ�";
}

mixed ask_jia()
{
	object ob;
        object me;
        object owner;

        me = this_player();

	if (! me->query_temp("valid_in_fumoquan"))
	{
		command("say ���󱲣�����͵���շ�ħȦ�������������������㣡");
		kill_ob(me);
                return 1;
	}

        if (me->query_temp("valid_in_fumoquan") != 1)
        {
                command("heng");
                return 1;
        }

//        if (me->query("combat_exp") < 1000000)
        if (count_lt(me->query("combat_exp"), 1000000))
                return "�����΢ĩ���£�������Ħ��ʦ���µ�����������";

        ob = find_object(JINLAN);
        if (! ob) ob = load_object(JINLAN);

        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�������Ѿ�������ô���㻹�������ģ�";

	if (owner == environment(me))
        {
                command("sneer");
                command("get " + ob->query("id"));
                return "��������û�˸���Ū���ģ�������";
        }

        if (objectp(owner) && owner != this_object())
		return "��ʱ���[���Ĳ������������С�";

        ob->move(this_object());

        command("disapp1");
        command("give jinlan jiasha to " + me->query("id"));

        if (! query_temp("armor/cloth"))
        {
                ob = new("/d/shaolin/obj/xuan-cloth");
                ob->move(this_object());
                ob->wear();
        }
        return 1;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/riyue-bian/he",
                           "name"    : "���־�",
                           "sk1"     : "riyue-bian",
                           "lv1"     : 100,
                           "sk2"     : "force",
                           "lv2"     : 100,                           
                           "gongxian": 1000, ]));
                break;

        default:
                return 0;
        }
}

#include "/kungfu/class/shaolin/du.h"
