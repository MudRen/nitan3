//jinfuhuan.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�𸴻�", ({ "jin fuhuan", "jin","fuhuan" }));
        set("title", "�鱦���ϰ�");
        set("shen_type", 1);
        set("str", 35);
        set("gender", "����");
        set("age", 45);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
        	"/d/changan/npc/obj/ring",
        	"/d/changan/npc/obj/wrists",
        	"/d/changan/npc/obj/neck",
        }));

       setup();

       carry_object("/d/changan/npc/obj/choupao")->wear();
       add_money("silver", 50);
}

void init()
{
       add_action("do_buy", "buy");
       add_action("do_list", "list"); 	
}
