// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lu.c ³�н�

#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;

#include "fight.h"

void create()
{
        set_name("³�н�", ({ "lu youjiao", "lu", "youjiao" }));
        set("long", @LONG
³�н���Ȼ�书�㲻�ö�����֣������ڽ���
��ȴ������������Ϊ����ؤ�����������壬��
�¹������䣬��ú��߹������ء�
LONG);
        set("nickname", HIG "�ư���ͷ" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4500);
        set("max_jing", 3500);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 220);
        set("combat_exp", 2500000);
        set("level", 20);
        set("score", 500000);
        set("shen_type", 1);
        
        set_skill("force", 240);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
	set_skill("unarmed", 240);
	set_skill("changquan", 240);
        set_skill("hand", 240);
        set_skill("shexing-diaoshou", 240);
        set_skill("strike", 240);
        set_skill("xiaoyaoyou", 240);
        set_skill("zhenjing-baili", 200);
        set_skill("qianlong-wuyong", 200);
        set_skill("hongjian-yulu", 200);
        set_skill("parry", 240);
        set_skill("staff", 240);
        set_skill("dagou-bang", 240);
        set_skill("fengmo-zhang", 240);
        set_skill("blade", 240);
        set_skill("liuhe-dao", 240);
        set_skill("jueming-tui", 240);
        set_skill("begging", 280);
        set_skill("checking", 280);
        set_skill("literate", 220);
        set_skill("martial-cognize", 240);

        set("no_teach", ([
                "dagou-bang"      : "�򹷰�������ֻ�м�λ�����ܹ�ѧϰ��Ҫѧȥ�Ұ�����",
                "zhenjing-baili"  : "�����Ʒ����Ǻ��ϰ������ͣ��Ҳ������״��ڡ�",
                "qianlong-wuyong" : "�����Ʒ����Ǻ��ϰ������ͣ��Ҳ������״��ڡ�",
                "hongjian-yulu"   : "�����Ʒ����Ǻ��ϰ������ͣ��Ҳ������״��ڡ�",
        ]));

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("unarmed", "jueming-tui");
        map_skill("staff", "dagou-bang");
        map_skill("parry", "dagou-bang");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("strike", "xiaoyaoyou");

        create_family("ؤ��", 18, "����");

        set("coagents", ({
                ([ "startroom" : "/d/city/gbxiaowu",
                   "id"        : "hong qigong" ]),
        }));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.chuo" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.tian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("master_ob",4);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

          if (count_lt(ob->query("combat_exp"),  150000))
        {
                command("say ��Ľ������鲻�������������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query("shen") < 20000)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }

        if (ob->query("family/beggarlvl") < 4)
        {
                command("say ���ڱ���ĵ�λ̫�ͣ����������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query_skill("force") < 120)
        {
                command("say ����ڹ���򻹲��������������λ����ѧϰ�ɡ�");
                return;
        }
        command("nod");
        command("say �Ժ���͸����Ұɣ��ɱ�������¡�");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
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

        case "�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shexing-diaoshou/chan",
                           "name"    : "�����",
                           "sk1"     : "shexing-diaoshou",
                           "lv1"     : 100,
                           "sk2"     : "hand",
                           "lv2"     : 140,
                           "neili"   : 2000,
                           "gongxian": 600,
                           "shen"    : 4000, ]));
                break;
                                
        default:
                return 0;
        }
}                
