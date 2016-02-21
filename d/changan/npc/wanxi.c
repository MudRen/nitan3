//wanxi.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����ϲ", ({ "xiao wanxi", "xiao", "wanxi"}));
	set("title", "�����ϰ�");
	set("shen_type", 1);
	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 34);
	set("str", 100);
	set("long",
		"����ϲ�Ƕ�����Ա��İ��ܡ�\n");
	set("no_get_from", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("valid_balance", 50000);
	
	setup();
	carry_object("/d/changan/npc/obj/choupao")->wear();
}

void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_expiate", "expiate");
}

int clean_up()
{
        return 0;
}

void die()
{
        message_vision("\n$Nһ���ҽУ����ˡ�\n", this_object());
        destruct(this_object());
}

void unconcious()
{
        die();
}
