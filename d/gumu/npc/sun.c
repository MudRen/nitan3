#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

string ask_job();
string ask_ping();
string ask_jiedu();

void create()
{
        set_name("������", ({ "sun popo", "sun", "popo" }));
        set("gender", "Ů��");
        set("age", 55);

        set("long", sort_msg("����С�������������衣������һ��������Ƥ"
                "���ĳ����������������㣬����Ц�ݸ���ʮ�ֳ�ª������"
                "��֮��ȴ���ʴ�����֮�⣬��ʱ�������ие�һ����ů��\n"));

        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 160);
        set_skill("yunv-xinfa", 160);
        set_skill("sword", 140);
        set_skill("yunv-jian", 160);
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 160);
        set_skill("parry", 140);
        set_skill("unarmed", 140);
        set_skill("meinv-quan", 140);
        set_skill("literate", 140);
        set_skill("qufeng", 90);
        set_skill("martial-cognize", 140);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "yunv-jian");
        map_skill("unarmed", "meinv-quan");

        prepare_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 2, "����");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 60);
        set_temp("apply/unarmed_damage", 60);
        set_temp("apply/armor", 100);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform unarmed.you") :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.mei" :),
        }) );

	set("inquiry", ([
		"job"  : (: ask_job :),
                "����" : (: ask_job :),
		"���ƿ" : (: ask_ping :),
		"�ⶾ" : (: ask_jiedu :),
        ]));
        
        set("env/wimpy", 50);

        set("coagents", ({
                ([ "startroom" : "/d/gumu/zhengting.c",
                   "id"        : "xiao longnv" ]),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}

string ask_job()
{
	object ob2;
	object ob = this_player();
	object me = this_object();

        if (count_gt(ob->query("combat_exp"), 400000))
                 return "��λ"+RANK_D->query_respect(ob)+"ʵս�����Ѿ��ĸߣ�����ͷ���ܡ�\n";
                 
        if (ob->query("family/family_name") != "��Ĺ��")
	        return "��λ" + RANK_D->query_respect(ob) + "���ҹ�Ĺ�ɵ��ӣ�����ͷ���\n";

        if (ob->query("scheming")) 
                return "���ڽ�ֹ�� Scheme ����������\n"; 
                
        if (ob->query_temp("gm_xunfeng"))
        {
		command("hmm " + ob->query("id"));
		return "�㻹û������񣬾�����Ҫ�µģ�\n";
	}

        if (present("feng xiang", environment(ob)))
                return "�㻹���Ȱ�������ķ�������������Ҫ����\n";
        /*
	if (time() < ob->query( "mp_job_time" ) +180)
	{
		tell_object( ob, "����ȥЪϢһ�°�.\n" );
		return "\n";
	}
        */
	ob->set( "mp_job_time", time() );
	me->add_temp("job_pos", -1);

	command("nod");
	command("say �ã�������������"+RANK_D->query_respect(ob)+"��������ȥ��Щ���۰ɡ�");
	ob2 = new("/d/gumu/npc/obj/beehive");
	ob2->set("owner", ob);
	ob2->set("mi_lvl", 0);
	if (! ob->query_temp("bee_count"))
	{
		ob->set("bee_count", ob->query("bee_count") - 2);
		if (ob->query("bee_count") < 1) 
		        ob->set("bee_count", 1);
		ob->set_temp("bee_count", ob->query("bee_count"));
	}
	if (ob->query_temp("bee_count") > 5) 
	        ob->set_temp("bee_count", 5);
	ob2->set("bee_count",ob->query_temp("bee_count"));
	ob2->set_amount(ob->query_temp("bee_count"));
	ob2->move(ob);
	ob->set_temp("gm_xunfeng",1);
	ob->set("gm/job", 1);
	ob->set("gm/time", time());
	message_vision("$N��$n"+chinese_number(ob2->query_amount())
		+"��"+HIW"����䡣\n"NOR, me, ob);
	return "��ȥ��أ�С����ȸ��\n";
}

string ask_ping()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// ���ϴ��Ķ���
	int i, j;
	object ping;

	if (pl->query("family/family_name") != "��Ĺ��")
		return "���ƿ�����棬ȴ��Ϊ���ɵ���������\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == CYN "���ƿ" NOR )
			j += 1;
	if (j > pl->query_temp("bee_count") + 4){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("Ҫ��ô�����ƿ��ʲô��\n");
	}
	
	command("nod");
	ping = new("/d/gumu/npc/obj/qingci-ping");
	ping->set("liquid/remaining",0);
	ping->move(me);
	command("give ping to "+pl->query("id"));
	return ("�����ƿ��С�ִ࣬��Ū���ˣ�\n");
}

string ask_jiedu()
{
	object pl = this_player();
	object me = this_object();
	object ping, xiang;

	if ( pl->query("family/family_name") != "��Ĺ��" ) {
		if ((int)pl->query_condition("yufeng_poison")) {
			command("laugh "+pl->query("id"));
			command("shrug");
			return ("��ϲ��������䶾Ҳûʲô�����ģ�ֻ������ҩ�ɽ���ѣ�\n");
		}
		else return 0;
	}

	if (present("qingci ping", pl))
		return ("�㲻���н�ҩ��\n");

	if (!(int)pl->query_condition("yufeng_poison")) 
	        return ("��û�ж�ѽ��");
	
	ping = new("/d/gumu/npc/obj/qingci-ping");
	ping->move(me);

	xiang = present("feng xiang", pl);
	if ( xiang && xiang->query("mi_lvl")>1) {
		message_vision("$N�����������ĸ��ӡ�\n", me);
		message_vision("$N�������һ��װ������۵�ľ�塣\n", me);
		message_vision("$N�������������װ�����ƿ��\n", me);
		message_vision("$N�������ָ�ԭ״��\n", me);

		ping->set("liquid/remaining",xiang->query("mi_lvl")/2 +1);
		xiang->set("mi_lvl",0);
	}
	else ping->set("liquid/remaining",1);

	command("give ping to "+pl->query("id"));
	return ("�Ͻ���ȥ�ðɣ�");
}
