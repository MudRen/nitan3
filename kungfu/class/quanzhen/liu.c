// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("������", ({"liu chuxuan", "liu"}));
        set("gender", "����");
        set("age", 38);
        set("class", "taoist");
        set("nickname",WHT"������"NOR);
        set("long",
                "������ȫ����ͽ�����������ˣ��������С�������μ�����һ\n"
                "���������š�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("title","ȫ������֮��");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 4400);
        set("max_qi", 4400);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4600);
        set("max_neili", 4600);
        set("jiali", 100);
        set("level", 15);
        set("combat_exp", 850000);

        set_skill("force", 160);
        set_skill("quanzhen-xinfa", 160);
        set_skill("sword", 160);
        set_skill("quanzhen-jian",160);
        set_skill("dodge", 140);
        set_skill("jinyan-gong", 140);
        set_skill("parry", 150);
        set_skill("finger",150);
        set_skill("zhongnan-zhi", 150);
        set_skill("literate", 100);
        set_skill("strike", 150);
        set_skill("chongyang-shenzhang", 150);
        set_skill("haotian-zhang", 150);
        set_skill("finger",150);
        set_skill("array",120);
	set_skill("beidou-zhenfa", 120);      
	set_skill("taoism",120);

        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "������"     : (: ask_skill1 :),
                "����������" : (: ask_skill1 :),
        ]) );

        set("master_ob",3);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("quanzhen-xinfa",1) < 70 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 6000)
        {
                command("say ����һЩ���������������˵�ɣ���\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/chongyang-shenzhang/lian"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("chongyang-shenzhang", 1) < 1)
                return "�����������ƶ�ûѧ����̸���п��ԣ�";

        if (me->query("family/gongji") < 100)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 10000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("chongyang-shenzhang", 1) < 100)
                return "����������Ʋ�����죬���ߵ������ɡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "üͷһ�壬���´�����$N" HIY "һ��"
                     "�����¸����𻰣���������һ������Ȼ���һ������ʱ"
                     "˫�Ʒ׷ɣ��ƾ�������˷��ƹ���������ƻֺ�֮����"
                     "\n\n" NOR, me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ����������ơ���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("chongyang-shenzhang"))
                me->improve_skill("chongyang-shenzhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/chongyang-shenzhang/lian", 1);
        me->add("family/gongji", -100);

        return 1;
}


