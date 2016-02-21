// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;

string ask_job();
void reward_dest(object obj, object ob);
void thank_dest(object obj, object ob);

void create()
{
        set_name("�𴦻�", ({"qiu chuji", "qiu"}));
        set("gender", "����");
        set("age", 36);
        set("class", "taoist");
        set("nickname",HIM"������"NOR);
        set("long",
                "�����ǽ������˳ơ������ӡ����𴦻������ˣ�����������\n"
                "�����⣬��ĿԲ����˫ü�絶����ò���ϣ�ƽ���������\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("title","ȫ������֮��");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 4800);
        set("max_qi", 4800);
        set("jing", 2400);
        set("max_jing", 2400);
        set("neili", 5100);
        set("max_neili", 5100);
        set("jiali", 100);
        set("level", 20);
        set("combat_exp", 1400000);
        set("no_get", 1);

        set_skill("force", 185);
        set_skill("quanzhen-xinfa", 185);
        set_skill("sword", 185);
        set_skill("quanzhen-jian",185);
        set_skill("dodge", 180);
        set_skill("jinyan-gong", 180);
        set_skill("parry", 185);
        set_skill("strike", 185);
        set_skill("chongyang-shenzhang", 185);
        set_skill("haotian-zhang", 185);
        set_skill("literate", 150);
        set_skill("finger",170);
        set_skill("zhongnan-zhi", 170);
        set_skill("taoism",190);
	set_skill("medical", 180);
	set_skill("liandan-shu", 180);
	set_skill("cuff",150);
	set_skill("chunyang-quan",150);
        set_skill("array",150);
	set_skill("beidou-zhenfa", 150);

	map_skill("array","beidou-zhenfa");	
        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("coagents", ({
                ([ "startroom" : "/d/quanzhen/shiweishi",
                   "id"        : "ma yu" ]),
                ([ "startroom" : "/d/quanzhen/wanwutang",
                   "id"        : "wang chuyi" ]),
        }));

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "������ͨ��": "������ͨ���Ǳ��ŵ�һ��������ϧ�ұ�������������û�����ɡ�",
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]) );

        set("master_ob",3);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}


void greeting(object ob)
{
        mapping fam;
        int i ;
        object me;

        me = this_object();
        if (! ob || environment(ob) != environment() || ! living(me))
                return;

        if (interactive(ob) && base_name(environment()) == query("startroom"))
        {
                if ( !(fam = ob->query("family")) || fam["family_name"] != "ȫ���")
                {
                        if (ob->is_not_bad())
                                command("say �����Ǳ����صأ����߶�С��Щ��");
                        else
                        {
                                command("say ����ħͷ�����Ҵ�����ȫ���صأ���һ��Ҫɱ���㣡");
                                kill_ob(ob);
                        }
                } else
                        command("smile "+ob->query("id"));
        }
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("quanzhen-xinfa",1) < 120 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 12000)
        {
                command("say ��Ŀǰ����̫�������������������������ң�\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˣ��ɱ�������ȫ�����ӵ���ͷ��");
        command("recruit " + ob->query("id"));
}

string ask_job()
{
        mapping job_stat;
        object ob = this_player();
        object me = this_object();
        int good_skill;
        object yaochu;
        object ob2;

        job_stat = ob->query_temp("qz/caiyao");

        if (ob->query("family/family_name") != "ȫ���")
                return "��λ" + RANK_D->query_respect(ob) + "����ȫ��̵��ӣ�����ͷ���\n";

        if (count_gt(ob->query("combat_exp"), 400000))
                return "��λ"+RANK_D->query_respect(ob)+"ʵս�����Ѿ��ĸߣ�����ͷ���ܡ�\n";
                             
        if (job_stat)
        {
                command("hmm "+ob->query("id"));
                return "�㻹û������񣬾�����Ҫ�µģ�\n";
        }

        command("nod");
        command("say �ã���������õĲ�ҩ�������ˣ���ȥɽ��������ȥ��һЩ������");

        if (objectp(yaochu = present("yao chu", ob)))     
                destruct(yaochu);
      
        ob2 = new("/d/quanzhen/obj/yaochu");
        ob2->move(me);
        ob->set_temp("qz/caiyao",1);
        command("give yao chu to "+ob->query("id"));

        return "��ȥ��أ�·��ҪС��һЩ��\n";
}

int accept_object(object me, object obj)
{
        object ob = this_player();
        int r; 
        if (r = ::accept_object(me, obj)) 
                return r; 

        command("say " + obj->name() + "?");

        if (obj->query("id") == "chuan bei" ||
            obj->query("id") == "fu ling" ||
            obj->query("id") == "gouzhi zi" ||
            obj->query("id") == "he shouwu" ||
            obj->query("id") == "huang lian" ||
            obj->query("id") == "ju geng" ||
            obj->query("id") == "jinyin hua" ||
            obj->query("id") == "sheng di") 
        {

                if ((ob->query("family/family_name") == "ȫ���") && 
                    (ob->query("id") == obj->query("player"))) 
                {
	                call_out("reward_dest", 1, obj, ob);
                } else 
                {
                        call_out("thank_dest", 1, obj, ob);
                }

                return 1;
        }

        command( "hmm" );
        command( "say ������ⶫ����ʲ�᣿" );
        return 0;
}

void reward_dest(object obj, object ob)
{
        int time;
        object yaochu;
        
        if (! objectp(ob))
                return;
                
        if (objectp(yaochu = present("yao chu", ob)))
                destruct(yaochu);
                
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"�ɵĲ�����ȥ��Ϣһ�°ɣ�\n");

        if (ob->query_temp("qz/caiyao",1))
	{
		ob->delete_temp("qz/caiyao");
	}
        if (objectp(obj))
        destruct(obj);
}


void thank_dest(object obj, object ob)
{
        command( "jump");
        command( "say ���Ǻ���Ҫ��Щҩ�ģ���л����\n");
	destruct(obj);
}
