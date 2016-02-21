// YangXiao.c
// pal 1997.05.09

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("����", ({"yang xiao","yang","xiao",}));
	set("long",
        "����һλ�������������ײ����ۡ�\n"
        "����ò���ţ�ֻ��˫ü�����´������¶��������������ƣ������Դ�˥�����\n"
        "֮�ࡣ�����Բ�������ɫĮȻ���ƺ��ĳ�Զ����������ʲô���顣\n"
	);

	set("title",HIG "����" HIR "������ʹ" NOR);
	set("level",11);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 800000);

	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("sword", 220);
	set_skill("cuff", 220);
	set_skill("strike", 220);
	set_skill("literate", 150);

	set_skill("shenghuo-xinfa", 220);
	set_skill("lingxu-bu", 220);
	set_skill("shenghuo-quan", 220);
	set_skill("guangming-zhang", 220);
	set_skill("liehuo-jian", 220);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("cuff", "shenghuo-quan");
	prepare_skill("strike", "guangming-zhang");

	set("inquiry", 
	([
		"����ʥ����"  : (: ask_me :),
		"����ʥ����"  : (: ask_me :),
		"ʥ����"      : (: ask_me :),
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform qianlibingfeng") :),
	}) );
        set("inherit_title",HIG"����"HIC"���̷���"NOR);
	create_family("����", 34, "������ʹ");
	set("master_ob",4);
	setup();

	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object ();
	ob = this_player ();

	::init();

	if (interactive(ob) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "yangxiao.h"
