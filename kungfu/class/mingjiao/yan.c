// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yan.c ��ԫ

inherit NPC;

string ask_xunluo();
string ask_jihe();
void create()
{
        set_name("��ԫ", ({ "yan tan", "yan", "tan" }));
        set("gender", "����");
        
        set("age", 45);
        set("long", "���˰������֣�Բ��ʯ�ģ�ģ�����ǿ�Ц��\n"+
                    "����ȴ���������������ų����̵�һ����֮ʿ��\n");        
        set("rank_info/respect","����");
        set("title","���̺���������ʹ");
        set("str", 33);
        set("int", 20);
        set("con", 22);
        set("dex", 22);
        set("per", 10);
        set("level", 8);
        set("no_get", "��ԫ������˵̫���ˡ�\n");

        set("combat_exp", 160000);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
        set("jiali",30);
        
        set_skill("sword", 60);
        set_skill("parry",60);
        set_skill("qingfu-shenfa",60);
        set_skill("liehuo-jian",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("shenghuo-shengong",60);
        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("����", 37, "����");
        
        set("inquiry", ([
                "��ӡ"  : (: ask_xunluo :),
                "����"  : (: ask_jihe :),
        ]));
        set("xl", 3);
        set("xl2", "yan");
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

