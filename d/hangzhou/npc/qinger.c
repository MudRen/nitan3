// huoji. 

inherit NPC;
#include <ansi.h>
inherit F_DEALER;

void create()
{
	set_name("���", ({ "qing er", "qing" }));
	set("title", HIM"��ɪ����"NOR);
	set("nickname",HIR"����纽�"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 17);
 	set("per", 30);
	set("long",
"һ����פ������������С�����һЩϡ
���Ķ���������Ź֣���˵������Ե��\n"
);
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
		"���Ц���е�˵����������Ե���������������Ķ����ɣ���\n",
	}));

	set("vendor_goods", ({
		"/d/hangzhou/npc/obj/yuelao-xianshui.c",
		"/d/hangzhou/npc/obj/sansheng-youyue.c",
		"/d/hangzhou/npc/obj/ruyi-su.c",
		"/d/hangzhou/npc/obj/tongxin-jie.c",
		"/d/hangzhou/npc/obj/xuannv-lingfu.c",
		"/d/hangzhou/npc/obj/huangtong-suo.c",
	}));

	setup();
	carry_object("/d/hangzhou/npc/obj/sahua-qun.c")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
