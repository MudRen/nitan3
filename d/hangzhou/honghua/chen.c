// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chen.c �¼���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�¼���", ({ "chen jialuo", "chen","jialuo" }));
        set("title", HIR "�컨���ܶ���" NOR);
        set("long", 
"��һ��ģ��ֱ�Ǹ������˼ҵ������ӵܣ���������Ŀ�����ǣ���
�ۻ���������ҡ��һ�����ȣ���ɷ���������ţ�����˹�ġ���
��ٲȻ�Ǹ���鹫�ӡ�\n");
        set("nickname", HIW"��������"NOR);
        set("gender", "����");
        set("class", "scholar");
        set("age", 22);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("level", 40);       
        set("max_qi", 3500);
        set("max_jing", 1200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 2000000);
        set("score", 500000);

        set_skill("literate", 400);
        set_skill("force", 450);
        set_skill("dodge", 450);
        set_skill("unarmed", 450);
        set_skill("parry", 450);
        set_skill("cuff", 450);
        set_skill("strike", 450);
        set_skill("hand", 450);
        set_skill("claw", 450);
        set_skill("zhanshen-xinjing", 450);
        set_skill("zhuangzi-wu", 450);
        set_skill("baihua-cuoquan", 450);
        set_skill("martial-cognize", 280);

        map_skill("dodge", "zhuangzi-wu");
        map_skill("force", "zhanshen-xinjing");
        map_skill("unarmed", "baihua-quan");
        map_skill("hand", "baihua-cuoquan");
        map_skill("parry", "baihua-cuoquan");
        map_skill("claw", "baihua-cuoquan");
        map_skill("strike", "baihua-cuoquan");
        map_skill("cuff", "baihua-cuoquan");

        prepare_skill("unarmed", "baihua-cuoquan");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hong" :),
                (: perform_action, "unarmed.luan" :),   
                (: perform_action, "unarmed.yi" :),                            
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        
        create_family("�컨��", 2, "�ܶ���");
        setup();
        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/clone/cloth/yaodai")->wear();
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

        case "�ٻ�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/baihua-cuoquan/luan",
                           "name"    : "�ٻ�����",
                           "sk1"     : "baihua-cuoquan",
                           "lv1"     : 180,
                           "dodge"   : 150,
                           "free"    : 1,
                           // "gongxian": 420,
                           "shen"    : 38000, ]));
                break;

        case "�ٻ�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/baihua-cuoquan/yi",
                           "name"    : "�ٻ�����",
                           "sk1"     : "baihua-cuoquan",
                           "lv1"     :  130,
                           "force"   :  180,
                           "free"    :  1,
                           // "gongxian":  580,
                           "shen"    : 43000, ]));
                break;

        case "ս������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/baihua-cuoquan/hong",
                           "name"    : "ս������",
                           "sk1"     : "baihua-cuoquan",
                           "lv1"     : 180,
                           "sk2"     : "zhanshen-xinjing",
                           "lv2"     : 180,
                           "neili"   : 3000,
                           "free"    : 1,
                           // "gongxian": 1200,
                           "shen"    : 68000, ]));
                break;

        case "����" : 
               return MASTER_D->teach_pfm(me, this_object(), 
                       ([ "perform" : "can_perform/zhuangzi-wu/hua", 
                          "name" : "����", 
                          "sk1" : "zhuangzi-wu", 
                          "lv1" : 150, 
                          "neili" : 1000, 
                          "free" : 1, 
                          "shen" : 40000, 
                       ])); 
                break; 


        default:
                return 0;
        }
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query_skill(skill, 1) >= 400)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }              

        if (ob->query_temp("can_learn/chen/baihua-cuoquan"))
                return 1;

        if (skill == "baihua-cuoquan")
        {
                message_vision("$N���˿�$n�����ͷ�������Ҽ�Ȼ�����Ե���Ҿʹ�����ٻ���ȭ��\n",
                               this_object(), ob);
                ob->set_temp("can_learn/chen/baihua-cuoquan", 1);
                return 1;
        }

        command("say ��ֻ�ܴ�����ٻ���ȭ����ص��书����ɲ�ҪΪ���ҡ�");
        return -1;
}

void unconcious()
{
        die();
}
