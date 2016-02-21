// ZhuangZheng.c
// pal 1997.05.11

#include <ansi.h>
#include "mingjiao_job.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();

void create()
{
        set_name("ׯ�", ({ "zhuang zheng", "zhuang", "zheng", }));
	set("long",
        "����һλ�ߴ��ΰ���������ӣ���һ���ײ����ۡ�\n"
        "���������������е���ͷ����������򲻵�֮�£�����һ���������ݵĺ��ӡ�\n"
	);

        set("title", HIG "����" HIW "�����" NOR "����ʹ");
	set("gender", "����");
	set("attitude", "friendly");
        set("class", "fighter");

        set("age", 42);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("cuff", 120);
	set_skill("strike", 120);
	set_skill("throwing", 200);
	set_skill("literate", 100);

	set_skill("shenghuo-xinfa", 120);
	set_skill("lingxu-bu", 120);
	set_skill("shenghuo-quan", 120);
	set_skill("guangming-zhang", 120);
	set_skill("liehuo-jian", 120);
	set_skill("wuxing-jueji", 200);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "shenghuo-quan");
	map_skill("throwing", "wuxing-jueji");

	prepare_skill("cuff", "shenghuo-quan");
	prepare_skill("strike", "guangming-zhang");

        create_family("����", 37, "���������ʹ");
        set("inherit_title",HIG"����"NOR"��������"NOR);

	set("inquiry", ([
		"name" : "���¾����������������ʹׯ���֪�����к�ָ�̡�",
		"����" : (: ask_job :),
		"job"  : (: ask_job :),
		"����" : (: ask_abandon :),
		"abandon" : (: ask_abandon :),
	]));

	setup();

        carry_object("/d/mingjiao/obj/langyabang")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "zhangqishi.h"

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,qiao;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣������ĸҷ��ɸ���ʲô�����أ�\n";

        if (count_gt(player->query("combat_exp"), 400000))
                 return "��λ"+RANK_D->query_respect(player)+"ʵս�����Ѿ��ĸߣ�����ͷ���ܡ�\n";

	if (fam["generation"] <37)
		 return "��λ"+RANK_D->query_respect(player)+"���������е�λ�ĸߣ�����ͷ���ܡ�\n";

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","jin_caikuang");
	
	qiao=new(OBJ_PATH"/qiao");
	qiao->move(player);
	tell_object(player,"ׯ���һ�����¡�\n");
	
	return "��������ڽ��ڸ���ɿ�����������ϵȾ����������ˣ���ȥ\n"
		"������ɽ����Щ����Ȼ�󵽾���������ʯ���Ƴɾ�����\n"
		"����ɽ�ϳ������޳�û�����Լ����С�ġ�\n";	 
}
