// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tang.c ����

inherit NPC;

string ask_xunluo();
string ask_jihe();

void create()
{
        set_name("����", ({ "tang yang", "tang", "yang" }));
        set("gender", "����");
        set("age", 44);                
        set("rank_info/respect","����");
        set("title","���̺�ˮ������ʹ");
        set("str", 25);
        set("int", 20);
        set("con", 24);
        set("dex", 24);
        set("per", 20);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
        set("jiali",30);        
        set("level", 8);
        set("combat_exp", 150000);
        
        set_skill("parry",60);
        set_skill("sword",60);
        set_skill("qingfu-shenfa",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("liehuo-jian",60);
        set_skill("shenghuo-shengong",60);
        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("parry","liehuo-jian");
        map_skill("sword","liehuo-jian");
        
        create_family("����",37,"����");
                
        set("inquiry", ([
                "��ӡ"  : (: ask_xunluo :),
                "����"  : (: ask_jihe :),
        ]));
        
        set("xl", 5);
        set("xl2", "tang");   
           
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/red-cloth")->wear();
}

string ask_jihe()
{
        if (! this_player()->query_temp("mj/ling"))
                return "����ʲôѽ���Է�ʱ�䵽�ˣ�";
                
        command("nod");
        command("say �����̵��������㳡���ϡ�");
        this_object()->move("/d/mingjiao/gmd");
        return "��ȥ����������ʹ��";
}

void attempt_apprentice(object ob)
{     
        command("say ���ڽ��·�æ��������ò��յ����ˡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}

#include "xunluo.h";

