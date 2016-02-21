// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yin2.c ��Ұ��

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_xunluo();

void create()
{
        set_name("��Ұ��",({"yin yewang", "yin", "yewang"}));
        set("title","������ӥ�ֶ���΢������");
        set("long", "����ҡ���ȣ���·������ɳ���𣬱�������ˮ����Ʈ��һ�㡣\n"+
                    "�����̵����������һֻСС��ӥ��˫��չ��������ʮ����\n"+
                    "��ͣ���һ˫�۾�������磬�������䣬�������ˡ�������\n"+
                    "����ӥ�ֶ���΢���������������̽������׾˸���Ұ����\n");
        set("age", 41);
        set("no_bark",1);
        set("env/wimpy", 40);
        set("attitude", "peaceful");
        set("shen", -8000);
        set("str", 25);
        set("int", 22);
        set("con", 25);
        set("dex", 25);
        set("per", 24);
        set("level", 12);        
        set("max_qi", 1500);
        set("max_jing", 1300);
        set("jiali", 50);
        set("combat_exp", 800000);        

        set_skill("claw",110); 
        set_skill("dodge",110);
        set_skill("force", 110);
        set_skill("literate",110);
        set_skill("qingfu-shenfa", 110);
        set_skill("shenghuo-shengong", 110);
        set_skill("yingzhua-shou",110);
        set_skill("liehuo-jian",110);
        set_skill("lieyan-dao",110);
        set_skill("parry", 110);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        
        prepare_skill("claw","yingzhua-shou");

        set("inquiry", ([
                "��ӡ"  : (: ask_xunluo :),
        ]));
        set("xl", 8);
        set("xl2", "yin2");
        create_family("����",37,"����");
        
        set("master_ob",2);
	setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();       
}

void attempt_apprentice(object ob)
{        
        mapping fam = ob->query("family");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 500) {
		command("say " + RANK_D->query_respect(ob) +
			"������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ��������������书���ˡ�");
		return;
	}
	
        if (! fam)
        {
                command("hmm");
                command("say "+RANK_D->query_respect(ob)+"������ȥ��������ֵ�ѧ������������ɡ�"); 
                return;
        }

        if ((int)ob->query_skill("shenghuo-shengong", 1) < 50) 
        {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }     
        command("look " + ob->query("id"));
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","������΢������������");
}

int accept_object(object who, object ob)
{
        int r;
        object me = this_object();
        
        if (r = ::accept_object(who, ob))
                return r;        
        
        if (me->query("family/family_name") != "����" || ob->query("name") != "������")
        {
                command("? "+who->query("id"));
                command("say ����Ҷ�����ʲô��ͼ����");
                return 0;
        }
        if (! who->query_temp("shouwei"))
        {
                command("say ���������ģ�û�õ���������������������");
                return 0;
        }
        if (ob->query("name") == "������")
        {
                command("say �ðɣ����Ȼ�������飬���������������һ�������ɡ�");
                who->apply_condition("mj_shouwei", random(4) + 7);
                who->set_temp("shouweied", 1);
                return 1;
        }
        return 1;
}

#include "xunluo.h";
