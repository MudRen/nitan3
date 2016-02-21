// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wei.c ΤһЦ

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void destroy(object ob);

void create()
{
        set_name("ΤһЦ",({"wei yixiao","wei","yixiao"}));
	set("title",HIG "����" HIC "��������" NOR);
        set("long", "�������̵��Ĵ󻤷�֮һ������������\n"+
                    "����ĸߴ�������ˣ�����һ����Ṧ��\n");
        set("age", 51);
        set("attitude", "peaceful");
        set("shen", -12000);
        set("str", 26);
        set("int", 26);
        set("con", 25);
        set("dex", 45);        
        set("max_qi", 3000);
        set("max_jing", 2400);
        set("eff_jingli", 2000);
        set("jiali", 70);
        set("combat_exp", 1200000);
        set("level", 30);

        set_skill("strike", 280); 
        set_skill("literate", 210);
        set_skill("dodge", 290);
        set_skill("force", 250);
        set_skill("qingfu-shenfa", 290);
        set_skill("hanbing-mianzhang", 280);
        set_skill("shenghuo-shengong", 240);
        set_skill("parry", 250);
        set_skill("martial-cognize", 200);   
                
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("strike", "hanbing-mianzhang");
        map_skill("parry", "hanbing-mianzhang");
        prepare_skill("strike","hanbing-mianzhang");

        create_family("����", 36, "���̷���");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command("perform strike.jue") :),
                (: command("perform strike.xi") :),                
        }));
        set("master_ob",4);
	setup();
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam = ob->query("family");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 5000) {
		command("say " + RANK_D->query_respect(ob) +
			"������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ��������������书���ˡ�");
		return;
	}                
        if(!fam || fam["family_name"] != "����"){
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 100) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }        
        if ((int)ob->query_skill("dodge", 1) < 100) {
                command("say ��ѧ�ҵ��Ṧ����������һ�����Ṧ������");
                command("say ���Ṧ���棬" + RANK_D->query_respect(ob)+"�Ƿ����ò�����");
                return;
        }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title")+"���½���");
}

int accept_object(object who, object ob)
{
        int exp, job, pot, bonus, gold;
        int r;

        object me = this_object();

        if (r = ::accept_object(who, ob))
                return r;
                        
        if (ob->query("name") != "Ѳ����" || ob->query("id") != "xunluo ling") 
        {
               command("? " + who->query("id"));  
               return 0;
        }
        if (ob->query("owner") != who->query("id")){
               command("say �ߣ������Ǵ���͵���ģ�");
               call_out("destroy", 1, ob);  
               return 1;
        }
        if (! ob->query("task_ok"))
        {
               command("say �������㻹�����ø�����»�ɡ�");
               command("pat " + who->query("id"));  
               return 0;
        }
        if (! who->query_condition("mj_xunluo"))
        {
               command("say ��ô��ʱ�䣬�㶼����ȥ�ˣ�");
               command("disapp "+ who->query("id"));
               call_out("destroy", 1, ob);  
               return 1;
        }
        
        command("nod");
        command("say Ը�������������е��Ӷ�����ڷ����ϣ�");
        bonus = who->query_temp("mj/attacker1");
        
        if (bonus > 7) bonus = 7;
        exp = 400 + random(350)+ bonus * 50;
        job = who->query("mingjiao_job");
        gold = job / 50 + random(job / 50);
        
        if (gold < 1) gold = 1;
        if (gold > 15) gold = 14 + random(3);
        
        if (count_lt(who->query("combat_exp"), 2000000)) 
                who->add("combat_exp", exp);
        if (who->query("combat_exp") > 2000000) 
                pot = 100 + random(60);
        else
                pot= exp / 5 + random(exp / 6);
                
        who->add("potential", pot);
        who->add("mingjiao_job", 1);
        who->add("contribution", 50);
        who->delete_temp("mj/attacker1");
        who->delete_temp("mj/over");
        
        MONEY_D->pay_player(who, gold * 10000);
        message_vision("\n$N����$nһЩ" HIY "�ƽ�" NOR "��\n" NOR, this_object(), who);
        
        command("whisper " + who->query("id")+" �������ˣ���Щ������ȥ�úÿ��һ���ɡ�");
        tell_object(who, "���Ѿ�Ϊ�������" + chinese_number(job) + "�ι����ˣ��ٺú�Ŭ���ɡ�\n");
       
        call_out("destroy", 1, ob);
        return 1;
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

void destroy(object ob)
{
        destruct(ob);
        return;
}



