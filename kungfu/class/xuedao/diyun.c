// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("����", ({ "di yun", "di","yun" }));
        set("long", 
                "������"+HIR"Ѫ����"NOR+"���ӵ��ơ�\n"
                "�����꿴���������Ͱ��ġ�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 3500);
        set("max_jing", 1500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);
        set("level", 40);
        set("combat_exp", 5000000);
        set("score", 40000);
        
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("hand", 400);
        set_skill("mizong-neigong", 400);
        set_skill("dashou-yin", 400);
        set_skill("unarmed", 400);
        set_skill("blade", 400);
        set_skill("literate", 400);
        set_skill("xuehai-mogong", 400);
        set_skill("xuedao-daofa", 400);
        set_skill("force", 400);
        set_skill("shenkong-xing", 400);
        set_skill("cuff", 400);
        set_skill("yujiamu-quan", 400);
        set_skill("sword", 400);
        set_skill("mingwang-jian", 440);        
        set_skill("liancheng-jianfa", 400);
        set_skill("shenzhaojing", 400);
                
        map_skill("unarmed", "shenjingzhao");
        map_skill("cuff", "yujiamu-quan");
        map_skill("force", "shenzhaojing");
        map_skill("blade", "xuedao-daofa");
        map_skill("parry", "xuedao-daofa");
        map_skill("dodge", "shenkong-xing");
        map_skill("sword", "liancheng-jianfa");

        create_family("Ѫ����", 6, "����");

        set("master_ob", 3);
	setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen")  < 100000) 
        {
                command("sigh");
                command("say ���Ѿ����Ų��յ����ˣ�����ذɡ�");
                return;
        }
        if ((int)ob->query_skill("xuehai-mogong", 1) < 120) {
                command("say ��Ѫ�����������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ����Ѫ��ħ���϶��µ㹦��");
                return;

        }
        if ((int)ob->query_skill("lamaism", 1) < 100) {
                command("say ����Ѫ���ţ���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +


                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }
        
        command("say �ðɣ����㻹�Ǹ��˲ţ�Ѫ���ſ����ÿ����ˡ�");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;
        
        case "��Ӱ��ȭ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenzhaojing/ying",
                           "name"    : "��Ӱ��ȭ",
                           "sk1"     : "shenzhaojing",
                           "lv1"     : 100,
                           "sk2"     : "unarmed",
                           "lv2"     : 100,                           
                           "gongxian": 800, ]));
                break;

        case "��Ӱȭ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenzhaojing/wu",
                           "name"    : "��Ӱȭ��",
                           "sk1"     : "shenzhaojing",
                           "lv1"     : 120,
                           "sk2"     : "unarmed",
                           "lv2"     : 120,
                           "gongxian": 800, ]));
                break;

        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/erguang",
                           "name"    : "����ʽ",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 600, ]));
                break;

        case "�̼�ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/cijian",
                           "name"    : "�̼�ʽ",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 800, ]));
                break;
                
        case "ȥ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/qujian",
                           "name"    : "ȥ����",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 600, ]));
                break;
                                                                                
        default:
                return 0;
        }
}
