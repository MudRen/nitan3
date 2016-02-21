// yang.c ���ϰ� 

inherit BUNCHER;

inherit F_DEALER;

void create()
{
	set_name("������", ({ "yang yongfu", "yang" }));
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
                "/clone/cloth/cuttonp",
                "/clone/misc/sleepbag",
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
                "/d/city/npc/obj/kaolu",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
                // "/d/city/npc/obj/muxiang",
		"/d/xingxiu/obj/fire",
		"/d/item/obj/chanhs",
		"/d/city/obj/rrose",
		"/d/city/obj/yrose",
		"/clone/misc/wood",
		"/clone/misc/shoeshine",
		"/clone/misc/brush",
                "/clone/misc/yanhuo",
                "/clone/misc/diaogan",
                "/clone/misc/yuer",
                "/d/taohua/obj/bagua",                
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

