// yang.c ���ϰ� 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "Yang yongfu", "yang" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������������ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/obj/obj/mabudai",
		"/d/city/obj/obj/beixin",
		"/d/city/obj/obj/toukui",
		"/d/city/obj/obj/necklace",
		"/d/city/obj/obj/surcoat",
		"/d/city/obj/obj/shield",
		"/d/city/obj/obj/huwan",
		"/d/city/obj/obj/zhitao",
		"/d/city/obj/obj/huyao",
		"/d/city/obj/obj/caoxie",
		"/d/city/obj/obj/pixue",
		"/d/city/obj/obj/shoutao",
		"/d/city/obj/obj/tieshou",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
