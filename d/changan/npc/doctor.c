// doctor.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ʱ�Ź�", ({ "shi jiugong", "shi", "jiugong"}));
        set("str", 20);
	set("gender", "����");
        set("title", "ҩ���ƹ�");
	set("age", 66);
	set("long", "��˵ʱ�Ź�ԭ�ǽ����е���ҽ��\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
        	"/d/changan/npc/obj/jinchuang",
		"/d/changan/npc/obj/yangjing",
	}));

	setup();
	carry_object("/d/changan/npc/obj/choupao")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
