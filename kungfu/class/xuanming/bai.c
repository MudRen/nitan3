// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "xuanming.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

void create()
{
        set_name("�������", ({ "baisun daoren", "baisun", "daoren" }));
        set("gender", "����");
        set("long", @LONG
��������ڤ�ȿ�ɽ��ʦ������ˣ�ֻ�����ٷ�Ʈ����˫��������䣬���˾�η��
LONG);
        set("shen_type", -1);
        set("age", 72);
        set("str", 40);
        set("con", 38);
        set("int", 40);
        set("dex", 46);
        set("max_qi", 7400);
        set("max_jing", 3400);
        set("qi", 7400);
        set("jing", 3400);
        set("neili", 8500);
        set("max_neili", 8500);
        set("jiali", 250);
        set("level", 40);
        set("combat_exp", 3200000);

        set_skill("force", 420);
        set_skill("xuanming-shengong", 420);
        set_skill("dodge", 400);
        set_skill("lingxu-bu", 400);
        set_skill("strike", 420);
        set_skill("xuanming-zhang", 420);
        set_skill("parry", 420);
        set_skill("literate", 460);
        set_skill("martial-cognize", 320);
        
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "lingxu-bu");
        map_skill("parry",  "xuanming-zhang");

        prepare_skill("strike", "xuanming-zhang");
             
        create_family("��ڤ��", 1, "��ɽ��ʦ");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({               
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "¹�ȿ�"    :   "�����Ұ�ͽ��\n",
                "�ױ���"    :   "������ʦ�ܡ�\n", 
        ]));

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

        set("master_ob", 5);
	setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void attempt_apprentice(object ob)
{
        tell_object(ob, "��ڤ���ݲ����š�\n");
        return;
        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < -35000)
        {
                command("say �ߣ��Ұ�����˴Ӳ����������˽�����");
                return;
        }        
    
        if (ob->query_skill("minggu-xinfa", 1) < 160)
        {
                command("say ��ڤ���ķ�����㣬���Ǹ���ͽ������ϰ��ϰ�ɣ�");
                return ;
        }
        
        if (ob->query_skill("strike", 1) < 160)
        {
                command("say ������Ʒ���Ϊ���������Ժ����ѧϰ����ڤ�Ⱦ�ѧ��ڤ���ƣ�");
                return ;
        }

//        if (ob->query("combat_exp") < 500000)
        if (count_lt(ob->query("combat_exp"), 500000))
        {
                command("say �㽭�����黹���㣬����ȥ�ള��һ�°ɣ�");
                return;
        }

        command("nod");
        command("say �ã��ã��Ϸ���վ������㡣");
        command("haha");
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

        case "��Ӱ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/ying",
                           "name"    : "��Ӱ����",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     : 180,
                           "dodge"   : 150,
                           "free"    : 1,
                           // "gongxian": 420,
                           "shen"    : -38000, ]));
                break;

        case "ֻ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/zhe",
                           "name"    : "ֻ������",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     :  130,
                           "force"   :  180,
                           "free"    :  1,
                           // "gongxian":  580,
                           "shen"    : -43000, ]));
                break;

        case "���κ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/lang",
                           "name"    : "���κ���",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     : 180,
                           "sk2"     : "xuanming-shengong",
                           "lv2"     : 180,
                           "neili"   : 3000,
                           "free"    : 1,
                           // "gongxian": 1200,
                           "shen"    : -68000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query_skill(skill, 1) >= 400)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }
                
        if (ob->query_temp("can_learn/baisun/xuanming-zhang") &&
            skill == "xuanming-zhang")
                return 1;

        if (ob->query_temp("can_learn/baisun/xuanming-zhang") &&
            skill == "strike")
                return 1;

        if (ob->query_temp("can_learn/baisun/xuanming-zhang") &&
            skill == "xuanming-shengong")
                return 1;

        if (ob->query_temp("can_learn/baisun/xuanming-zhang") &&
            skill == "force")
                return 1;                                

        if (skill == "xuanming-zhang")
        {
                message_vision("$N���˿�$n�����ͷ������ڤ����Ҳû��ʲô��ѧ�ġ�\n",
                               this_object(), ob);
                ob->set_temp("can_learn/baisun/xuanming-zhang", 1);
                return 1;
        }

        command("say ��ֻ����һ����ڤ���ƣ���ɲ�ҪΪ���ҡ�");
        return -1;
}
