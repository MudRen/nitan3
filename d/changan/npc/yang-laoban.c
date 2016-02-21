//yang-laoban.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "yang laoban", "yang","laoban" }));
        set("title", "����¥�ϰ�");
        set("shen_type", 1);
        set("str", 24);
        set("gender", "����");
        set("age", 55);
        set("long", "���ϰ岻����������ƹ񣬻�������Ĵ����\n�����յ�һ�ֺòˡ�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                "/d/changan/npc/obj/zuixunfeng",
                "/d/changan/npc/obj/snxiangji",
                "/d/changan/npc/obj/lhjiyu",
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
