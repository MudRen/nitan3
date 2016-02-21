// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

// #include "fight.h"

void create()
{
	seteuid(getuid());
	set_name("�տն�", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "������ؤ");
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("attitude", "peaceful");
        set("class", "beggar"); 
	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);
	set("thief", 0);
	set("level", 6);
	set("combat_exp", 50000);

	set_skill("force", 80);
        set_skill("huntian-qigong", 80);
        set_skill("dodge", 80);
        set_skill("feiyan-zoubi", 80);
        set_skill("unarmed", 100);
        set_skill("changquan", 100);
        set_skill("hand", 80);
        set_skill("shexing-diaoshou", 80);
        set_skill("strike", 80);
        set_skill("xiaoyaoyou", 80);
        set_skill("parry", 80);
        set_skill("staff", 80);
        set_skill("fengmo-zhang", 80);
        set_skill("jiaohua-bangfa", 80);
        set_skill("blade", 80);
        set_skill("liuhe-dao", 80);
        set_skill("begging", 80);
        set_skill("checking", 80);
        set_skill("stealing", 400);
        set_skill("literate", 80);
        set_skill("martial-cognize", 60);
	
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("unarmed", "changquan");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("dodge", "feiyan-zoubi");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "�˴�����");

	set("chat_chance", 20);
	set("chat_msg", ({
		"�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"�տն�������ش��˸���Ƿ��\n",
		"�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: random_move :)
	}) );

	set("master_ob",2);
	setup();
	
        set("startroom", "/d/city/lichunyuan");

	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 10);        
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "ؤ��")
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;

	seteuid(getuid());

	switch( random(5) ) {
		case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
        	 command("smile");
	         command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
        	 command("give 10 silver to " + me->query("id"));
	}
        else {
        	 command("shake");
	         command("say ���ֶ������Ҫ ! ��һ��ȥ !");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//               obj->move(this_player());
        }

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title"); 
        int lvl = ob->query("family/beggarlvl"); 
        if (! permit_recruit(ob))
                return;
                
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
	
	if ((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");

        if (lvl > 0) 
        { 
                ob->set("family/beggarlvl", lvl); 
                ob->set("title", title); 
        } 
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����������£����ˡ�\n", this_object());
	ob = new("/kungfu/class/gaibang/kongkong");
	ob->move("/d/city/lichunyuan");
	destruct(this_object());
}

void remove()
{
	npc::remove();
	}