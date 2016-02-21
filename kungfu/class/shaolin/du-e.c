// due.c

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#define FUMODAO         "/d/shaolin/obj/fumo-dao"
#define HEISUO          "/clone/lonely/heisuo1"
#define JIUHUAN         "/clone/lonely/jiuhuan"

mixed ask_me();
mixed ask_dao();
mixed ask_zhang();

void create()
{
        object ob1, ob2;
	set_name("�ɶ�", ({ "du e", "e" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ"
	        "�ݻƣ���ͬһ�ο�ľ��\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2350000);

	set("str", 34);
	set("int", 36);
	set("con", 35);
	set("dex", 33);

	set("qi", 5800);
	set("max_qi", 2900);
	set("neili", 7200);
	set("max_neili", 7200);
	set("level", 40);
	set("jiali", 110);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);

	set_skill("buddhism", 320);
	set_skill("force", 270);
	set_skill("whip", 270);
	set_skill("parry", 270);
	set_skill("dodge", 260);

	set_skill("hunyuan-yiqi", 270);
	set_skill("shaolin-xinfa", 270);
	set_skill("riyue-bian", 270);
	set_skill("shaolin-shenfa", 260);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("finger", 260);
	set_skill("strike", 260);
	set_skill("nianhua-zhi", 260);
	set_skill("sanhua-zhang", 260);
	set_skill("martial-cognize", 220);

	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	set_skill("medical", 250);
	set_skill("shaolin-yishu", 250);

	set("inquiry", ([
		"��ħ��"     : (: ask_me :),
		"��ħ��"     : (: ask_dao :),
                "�Ż�����"   : (: ask_zhang :),
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

                ob2 = find_object(JIUHUAN);
                if (! ob2) ob2 = load_object(JIUHUAN);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        set_temp("handing", ob2);
                }
        }
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
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

	if (present("fumo zhang", this_player()))
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�ѣ����Ҿ��������ϣ�����̰�����У�";

	if (present("fumo zhang", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�ѣ����Ҿ�����������ȡ�ߣ�����̰�����У�";

	ob = get_object("/d/shaolin/obj/fumo-zhang");
        if (! ob || environment(ob) && environment(ob) != this_object())
		return "��Ǹ���������ˣ���ħ���Ѿ�����ȡ���ˡ�";
	ob->move(this_player());

	message_vision("\n�ɶ�Цһ�������ͷ��������������ȡ����ħ�Ƚ���$N��\n\n", this_player());

	return "���Ȼ�ܴ�����շ�ħȦ������Ȼ�ǵ��������еķǷ�������ħ�����ʷ������ˣ�";
}

mixed ask_dao()
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

        if (count_lt(me->query("combat_exp"), 1000000))
                return "�����΢ĩ���£�������Ħ��ʦ���µ�����������";

        ob = find_object(FUMODAO);
        if (! ob) ob = load_object(FUMODAO);

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
                return "��ʱ��ħ���������������С�";

        ob->move(this_object());

        command("buddhi");
        command("give fumo dao to " + me->query("id"));
        return 1;
}

mixed ask_zhang()
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

        if (count_lt(me->query("combat_exp"), 1000000))
                return "�����΢ĩ���£�������Ħ��ʦ���µ�����������";

        ob = find_object(JIUHUAN);
        if (! ob) ob = load_object(JIUHUAN);

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
		return "��ʱ�Ż����Ȳ������������С�";

        ob->move(this_object());

        command("buddhi");
        command("give jiuhuan xizhang to " + me->query("id"));
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
        
        case "���ƾ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/riyue-bian/chan",
                           "name"    : "���ƾ�",
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
