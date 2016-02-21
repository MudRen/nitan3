// old.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"old man","old","man"}));
	set("title",HIY"������"NOR"����");
	set("long",
	"����һ�����������ߣ�̫��Ѩ���ʣ����۾���������Ȼ�书���ߡ�\n"+
        "Ȼ����ɫ��������һ��������Ů��Ϊ�����ƺ�����ʲô������ʮ�ֿ�����\n");
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 30+random(50));

	set("shen_type", -1);

	set("str", 25 + random(10));
	set("dex", 25 + random(10));

	set("max_qi", 800 + random(800));
	set("max_jing", 400 + random(400));
	set("max_neili", 1000 + random(1000));
	set("jiaji", 15 + random(15));
	set("combat_exp", 50000 + random(50000));

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	set_temp("apply/damage", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object obj;
	if (! objectp(ob))
		return;

        if (interactive(ob))
        {
		if (obj = present("used gao", ob))          
			unconcious();
	}
	return;
}
