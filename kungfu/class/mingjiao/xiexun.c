// XieXun.c
// pal 1997.05.09

#include <ansi.h>
#include "fawang.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

mixed ask_cheng();


void create()
{
        set_name("лѷ", ({"xie xun", "xie", "xun", }));
        set("long",
        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"
        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"
        );

        set("title",HIG "����" HIY "��ëʨ��" NOR);
        set("level",9);
        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 63);
        set("shen_type", 1);
        set("per", 20);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);

        set("combat_exp", 900000);
        set("score", 800000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set_skill("strike", 180);
	set_skill("finger",200);
	set_skill("literate", 110);

	set_skill("shenghuo-xinfa", 180);
	set_skill("lingxu-bu", 180);
	set_skill("shenghuo-quan", 180);
	set_skill("guangming-zhang", 180);
	set_skill("liehuo-jian", 180);
	set_skill("huanyin-zhi", 200);
	set_skill("qishang-quan",200);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "qishang-quan");
	map_skill("cuff", "qishang-quan");
	map_skill("finger","huanyin-zhi");

	prepare_skill("cuff", "qishang-quan");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: command("perform hunpofeiyang") :),
        }) );
        create_family("����", 35, "��������");
        set("inherit_title",HIG"����"NOR"����ɢ��"NOR);
        set("inquiry", ([
                "����" : (: ask_cheng :),
        ]));
        set("master_ob",3);
	setup();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

mixed ask_cheng()
{
        object me;
        me = this_player();

        if (me->query("can_story/qishangquan"))
                return "�㲻���Ѿ���Ӧ����ɱ���������뷴�ڣ�";

        command("ok");
        command("say ֻҪ����Ұѳ���ɱ���Ҿʹ�������ȭ��");
        me->set("can_story/qishangquan",1);
        return 1;
}

