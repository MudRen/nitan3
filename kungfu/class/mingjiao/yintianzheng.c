// YinTianZheng.c
// pal 1997.05.09

#include <ansi.h>
#include "fawang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�\n"
        "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n"
	);
                                                          
	set("title",HIG "����" HIW "��üӥ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set_skill("strike", 180);
	set_skill("claw", 220);
	set_skill("literate", 120);

	set_skill("shenghuo-xinfa", 180);
	set_skill("xiaoyaoyou", 180);
	set_skill("shenghuo-quan", 180);
	set_skill("guangming-zhang", 180);
	set_skill("liehuo-jian", 180);
	set_skill("sougu", 220);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "sougu");
	map_skill("claw", "sougu");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	create_family("����", 35, "��������");
        set("inherit_title",HIG"����"NOR"����ɢ��"NOR);
	set("master_ob",3);
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}
int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "��Ѫצ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sougu/xue",
                           "name"    : "��Ѫצ",
                           "sk1"     : "sougu",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        default:
                return 0;
        }
}

