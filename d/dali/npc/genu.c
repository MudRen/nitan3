// genu.c

inherit NPC;

void create()
{
    set_name("��Ů",({ "ge nv", "girl" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "����һ������Ϊ���ĸ�Ů��\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 700);
	set("shen_type", 1);
        set("per", 22);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object("/d/dali/npc/obj/kenao")->wear();
        carry_object("/d/dali/npc/obj/yaoqin")->wield();
}

