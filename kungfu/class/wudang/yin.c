// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yin.c ����ͤ

#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_me();
mixed ask_skill();

void create()
{
        set_name("����ͤ", ({ "yin litin", "yin" }));
        set("nickname", "�䵱����");
        set("long", 
                "�����������������������ͤ��\n"
                "��������ʮ�꣬�����ܸɣ�������������һ�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 4200);
        set("max_jing", 2100);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 100);
        set("combat_exp", 1250000);
        set("score", 45000);

        set_skill("force", 165);
        set_skill("yinyun-ziqi", 165);
        set_skill("taiji-shengong", 165);
        set_skill("dodge", 175);
        set_skill("tiyunzong", 175);
        set_skill("unarmed", 170);
        set_skill("taiji-quan", 170);
        set_skill("strike", 165);
        set_skill("wudang-zhang", 165);
        set_skill("hand", 180);
        set_skill("paiyun-shou", 180);
        set_skill("parry", 175);
        set_skill("sword", 160);
        set_skill("wudang-jian", 160);
        set_skill("raozhi-roujian", 180);
        set_skill("taiji-jian", 160);
        set_skill("taoism", 120);
        set_skill("literate", 100);

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "raozhi-roujian");
        map_skill("strike", "wudang-zhang");

        prepare_skill("unarmed", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "���´���": (: ask_me :),
                "����"    : (: ask_me :),
                "���ͬ��": (: ask_skill :),
        ]));

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chuankong" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob", 4);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 8000 )
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)ob->query_skill("yinyun-ziqi",1) < 70)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����������϶��µ㹦��?");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 70)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ġ�");
                command("say �ҿ��㻹��Ҫ���������Է�����������������"
                        "����ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ�����ܺú��ù�������аħ�����");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/raozhi-roujian/chuankong"))
                return "�Լ��úö���ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("raozhi-roujian", 1) < 1)
                return "������ָ�ὣ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 250)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 15000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("raozhi-roujian", 1) < 100)
                return "�����ָ�ὣ�������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ���γ����䳤��ͻȻ��$N" HIY
                       HIY "������;�н�����\n�䣬�Ǳ��������Ƴ���һ����"
                       "�����������ۣ�Ʈ����������\n����ʮ���С���ָ�ὣ"
                       "�������һ�С����´��ա���\n" NOR, me,
                       this_object());
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����´��ա���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("raozhi-roujian"))
                me->improve_skill("raozhi-roujian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/raozhi-roujian/chuankong", 1);
        me->add("family/gongji", -250);

        return 1;
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/tong"))
                return "�Լ��úö���ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 250)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 15000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("taiji-jian", 1) < 100)
                return "���̫�����������ң�Ҫ��������";

        message_sort(HIY "$n" HIY "���˵�ͷ������Ȼ$N" HIY "Ҳ��"
                     "�ұ����ˣ���ô�Ҿͽ�����ܽȥ�����������"
                     "���ġ����ͬ�١������㣬�мǣ����򲻵���ʱ"
                     "ǧ��Ҫʹ�ã������ţ�$n��ʼ��ϸ�������а�"
                     "�ء�\n" NOR, me, this_object());
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����ͬ�١���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/tong", 1);
        me->add("family/gongji", -250);

        return 1;
}



