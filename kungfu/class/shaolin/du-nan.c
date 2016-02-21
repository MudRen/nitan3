// dunan.c

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#define HEISUO          "/clone/lonely/heisuo2"
#define CAOJIE          "/clone/lonely/caojie"

mixed ask_me();
mixed ask_cao();

void create()
{
        object ob1, ob2;
	set_name("����", ({ "du nan", "nan" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ��ڣ������������ɡ�\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2500000);

	set("str", 33);
	set("int", 32);
	set("con", 34);
	set("dex", 31);

	set("qi", 5200);
	set("max_qi", 2600);
	set("neili", 7400);
	set("max_neili", 7400);
	set("level", 40);
	set("jiali", 100);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);

	set_skill("buddhism", 300);
	set_skill("force", 260);
	set_skill("whip", 260);
	set_skill("parry", 260);
	set_skill("dodge", 250);

	set_skill("hunyuan-yiqi", 260);
	set_skill("shaolin-xinfa", 260);
	set_skill("riyue-bian", 260);
	set_skill("shaolin-shenfa", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("strike", 260);
	set_skill("xumishan-zhang", 260);
	set_skill("claw", 250);
	set_skill("hand", 250);
	set_skill("longzhua-gong", 250);
	set_skill("qianye-shou", 250);
	set_skill("martial-cognize", 220);

	map_skill("strike", "xumishan-zhang");

	prepare_skill("strike", "xumishan-zhang");

	set_skill("medical", 220);
	set_skill("shaolin-yishu", 220);

	set("inquiry", ([
		"������"     : (: ask_me :),
		"��ݽ�"     : (: ask_cao :),		
	]));

	set("count", 0);
	if (random(16) == 8) add("count", 1);

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

                ob2 = find_object(CAOJIE);
                if (! ob2) ob2 = load_object(CAOJIE);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        ob2->wear();
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

	if (uptime() < 1800)
		return "�����������֮������������ޱȣ������ڿ�û�С�";

	if ( present("puti zi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"������ֻ��һ�ţ����Ҿ��������ϣ�����̰�����У�";

	if ( present("puti zi", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"������ֻ��һ�ţ����Ҿ�����������ȡ�ߣ�����̰�����У�";

	if (query("count") < 1)
		return "�����������֮����ɼ������ޱȣ����������ڿ�û�С�";

	ob = new("/d/shaolin/obj/puti-zi");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n���Ѳ�ȻһЦ�����ų�̾һ������������ȡ���������ƿ�����������ӵݸ�$N��\n\n", this_player());

	return "�ҵ������ڷ�����ǰ���º�Ը��ÿʮ������ɽ�󴨣��������գ�\n" +
	       "���ɵ����������ӣ�������Ե�ˣ��ܵô��컯���������Ϊ֮��";
}

mixed ask_cao()
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

        ob = find_object(CAOJIE);
        if (! ob) ob = load_object(CAOJIE);

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
		return "��ʱ��ݽᲢ�����������С�";

        ob->move(this_object());

        command("sigh");
        command("give shen caojie to " + me->query("id"));
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
                        ([ "perform" : "can_perform/riyue-bian/shang",
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
