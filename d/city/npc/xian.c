// xian. ���ϰ�

inherit BUNCHER; 
inherit F_DEALER;

void create()
{
	set_name("���ϰ�", ({ "xian laoban", "xian" }));
	set("title", "����¥�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "ϴ�ϰ徭Ӫ�洫����������¥���ж��ꡣ\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		"/d/city/npc/obj/hdjiudai",
		"/d/city/npc/obj/kaoya",
	}));

	setup();
        add_money("silver", 50);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
