// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yin.c ������

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();
string ask_book();

void create()
{
        set_name("������",({"yin tianzheng","yin","tianzheng"}));
	set("title",HIG "����" HIW "��üӥ��" NOR);
        set("long", "���������̵��Ĵ󻤷�֮һ��һ����Ŀ����ͺ�����ߡ�\n"+
                    "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n");                    
        set("age", 61);
        set("attitude", "peaceful");
        set("shen", -13000);
        set("str", 35);
        set("per", 20);
        set("int", 25);
        set("con", 28);
        set("dex", 25);        
        set("max_qi", 3000);
        set("max_jing", 2700);
        set("eff_jingli", 2500);
        set("jiali", 70);
        set("combat_exp", 1300000);
        set("level", 30);
        set("jian_count", 1);
        
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("claw", 290); 
        set_skill("parry", 250);         
        set_skill("literate", 210);
        set_skill("qingfu-shenfa", 250);
        set_skill("shenghuo-shengong", 240);
        set_skill("yingzhua-shou", 290);
        set_skill("martial-cognize", 200);      
               
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        
        prepare_skill("claw","yingzhua-shou");

        create_family("����", 36, "��������");
        
        set("inquiry", ([
                 "����" : (: ask_me :),
                 "�׺罣" : (:ask_me :),
                 "ӥצ�ַ�" : (: ask_book :),
        ]));
        
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform claw.xue") :),
	}) );
	        
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
	
        if (! fam || fam["family_name"] != "����"){
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 100) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }     
        if ((int)ob->query_str() < 28) {
                command("say ��ѧ�ҵ�ӥצ�ַ�������Ҫ���㹻��������");
                command("say �ڱ������棬"+RANK_D->query_respect(ob)+"�Ƿ��Ӳ��˵㣿");
                return;
        }   
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title")+"���½���");
}

string ask_me()
{
	object me = this_player();
        object ob;

        if (count_lt(me->query("combat_exp"), 100000))
                return RANK_D->query_respect(me)+"�����������������²��ܱ�ס��ѱ�����";
                
        if (me->query_temp("askbhj"))
                return "��ղŲ����ʹ���ô��";

        if (this_object()->query("jian_count") < 1) 
                return "�������ˣ��ҵİ׺籦���Ѹ����������ˡ�";  
        		
        ob = new("/d/mingjiao/obj/baihong-jian");
        ob->move(me);
        this_object()->add("jian_count", -1);
	me->set_temp("askbhj", 1);
        return "�ðɣ���Ѱ׺籦�������ȥ�ɣ����㲻Ҫ����Ϊ�񣬳�Ϊ�������塣";
}

string ask_book()
{
        mapping fam; 
        object ob;
        
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��"; 
                
        if (this_player()->query_skill("claw", 1) > 30)
                return RANK_D->query_respect(this_player())+"�����Ѿ�����Ҫ�Ȿ���ˣ����������������̵����ðɣ�";
                
        ob = new("/d/mingjiao/obj/hand_book");
        ob->move(this_player());
        
        return "�ðɣ��Ȿ��ӥצ�ַ������û�ȥ�ú����С�";
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

void reset()
{
        set("jian_count", 1);
}
