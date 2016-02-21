// WenSong.c
// pal 1997.05.11

#include <ansi.h>
#include "mingjiao_job.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();

void create()
{
        set_name("�Ų���", ({ "wen cangsong", "wen", "cangsong", }));
	set("long",
        "����һλ�ߴ��ΰ���������ӣ���һ���ײ����ۡ�\n"
        "���������������е���ͷ����������򲻵�֮�£�����һ���������ݵĺ��ӡ�\n"
	);

        set("title", HIG "����" HIC "��ľ��" NOR "����ʹ");
	set("gender", "����");
	set("attitude", "friendly");
        set("class", "fighter");

        set("age", 48);
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

        create_family("����", 37, "��ľ������ʹ");
        set("inherit_title",HIG"����"NOR"��ľ�����"NOR);

	set("inquiry", ([
		"name" : "���¾������̾�ľ������ʹ�Ų��ɣ���֪�����к�ָ�̡�",
		"����" : (: ask_job :),
		"job"  : (: ask_job :),
		"����" : (: ask_abandon :),
		"abandon" : (: ask_abandon :),
	]));

	setup();

        carry_object("/d/mingjiao/obj/qimeigun")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,axe,shugan;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣��Ǹ������Ǹҷ��ɸ���ʲô�����ء�\n";

        if (count_gt(player->query("combat_exp"), 400000))
                 return "��λ"+RANK_D->query_respect(player)+"ʵս�����Ѿ��ĸߣ�����ͷ���ܡ�\n";
	if (fam["generation"] <37)
		 return "��λ"+RANK_D->query_respect(player)+"�������̵�λ�ĸߣ�����ͷ���ܡ�\n";

	if ( player->query("mingjiao/job")=="mu_kanshu" && shugan=present("shu gan",player) )
	{
		if (shugan->query("owner")==player->query("id"))
		{
			command("pat "+player->query("id"));
			if (axe=present("axe",player))
				destruct(axe);
			message_vision("�Ų��ɽ���һ�����ڣ���$N�����ɽ��˹�ȥ��\n",player);
			destruct(shugan);
			player->delete_temp("apply/short");
			remove_call_out("reward");
			call_out("reward",1,this_player(),"����");
			return player->query("name")+"�ɵò�����ȥ�ú���Ϣ��Ϣ��\n";
		}
		else
			return "��������㿳�İɡ���͵����\n";
	}

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","mu_kanshu");
	
	axe=new(OBJ_PATH"/axe");
	axe->move(player);
	tell_object(player,"�Ų��ɸ���һ�Ѹ�ͷ��\n");
	
	return "���������ã��ֵ��������󷨣���ľ�����ˣ���ȥ�����￳Щ���ɿ�������\n";

}   

#include "zhangqishi.h"
