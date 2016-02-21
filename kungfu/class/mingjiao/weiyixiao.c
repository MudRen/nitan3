// WeiYiXiao.c
// pal 1997.05.10

#include <ansi.h>
#include "fawang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ΤһЦ", ({"wei yixiao", "wei", "yixiao",}));
	set("long",
		"�����û�����һֻ���������\n"
		"������ɫ�����˵ġ�\n"
	);

	set("title",HIG "����" HIC "��������" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 48);
	set("shen_type", 1);

	set("str", 28);
	set("int", 27);
	set("con", 33);
	set("dex", 38);

	set("max_qi", 4500);
	set("max_jing", 2200);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 100);

	set("combat_exp", 1800000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set_skill("strike", 220);
	set_skill("literate", 110);

	set_skill("shenghuo-xinfa", 180);
	set_skill("qingfu-shenfa", 220);
	set_skill("shenghuo-quan", 180);
	set_skill("guangming-zhang", 180);
	set_skill("liehuo-jian", 180);
	set_skill("hanbing-mianzhang", 220);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "hanbing-mianzhang");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("strike","hanbing-mianzhang");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform xixueqingfu") :),
	}) );
	create_family("����", 35, "��������");
        set("inherit_title",HIG"����"NOR"����ɢ��"NOR);

	set("master_ob",4);
	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}
int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "���಻��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-mianzhang/jue",
                           "name"    : "���಻��",
                           "sk1"     : "hanbing-mianzhang",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "��Ѫ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-mianzhang/xi",
                           "name"    : "��Ѫ����",
                           "sk1"     : "hanbing-mianzhang",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;
                
        default:
                return 0;
        }
}
