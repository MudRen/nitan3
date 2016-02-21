// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "lingjiu.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
	set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "������"+HIC"�����չ���"NOR+"�Ŀ�ɽ��ʦ.\n"+
	    "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
	    "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
	set("title", HIC"���չ�����"NOR);
	set("gender", "Ů��");
	set("per", 20);
	set("age", 96);
	set("nickname", HIR "Ψ�Ҷ���" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 200);
        set("level", 60);
	set("combat_exp", 5000000);
	set("score", 200000);
	
	set_skill("force", 450);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("hand", 450);
	set_skill("strike", 450);
        set_skill("sword", 450);

	set_skill("zhemei-shou", 450);
	set_skill("liuyang-zhang", 450);
        set_skill("tianyu-qijian", 480);
	set_skill("yueying-wubu", 450);
	set_skill("bahuang-gong", 450);
        set_skill("literate", 200);
        set_skill("martial-cognize", 320);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");
        
	prepare_skill("strike", "liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");
	
	create_family("���չ�", 1, "����");
	
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "sword.san" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
        }) );
        
	set("master_ob",5);
	setup();
	
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/clone/food/jiudai");
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;
                   
        if ((string)ob->query("gender") != "Ů��")
        {
                command("say ��������!");
		return;
        }
        if ((int)ob->query_skill("bahuang-gong", 1) < 230) 
        {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
        }
        if (ob->query_con() < 30) 
        {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
        }
        command("recruit " + ob->query("id"));
        if ((string)ob->query("class") != "dancer")
                ob->set("class", "dancer");
        return;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "һ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liuyang-zhang/zhen",
                           "name"    : "һ������",
                           "sk1"     : "liuyang-zhang",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800, ]));
                break;

        case "�׺�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liuyang-zhang/baihong",
                           "name"    : "�׺�����",
                           "sk1"     : "liuyang-zhang",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 800, ]));
                break;
                
        case "�Ż�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianyu-qijian/pori",
                           "name"    : "�Ż�����",
                           "sk1"     : "tianyu-qijian",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 400, ]));        
                break;

        case "��Ůɢ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianyu-qijian/san",
                           "name"    : "��Ůɢ��",
                           "sk1"     : "tianyu-qijian",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 400, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianyu-qijian/zhu",
                           "name"    : "��������",
                           "sk1"     : "tianyu-qijian",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 400, ]));
                break;

        case "������" :
               return MASTER_D->teach_pfm(me, this_object(),
                       ([ "perform" : "can_perform/zhemei-shou/hua",
                          "name"    : "������",
                           "sk1"     : "zhemei-shou",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 400, ]));
                break;
                                
        default:
                return 0;
        }
}
