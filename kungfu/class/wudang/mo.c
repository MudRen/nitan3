#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_me();
mixed ask_me1();
mixed ask_me2();

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo" }));
        set("nickname", "�䵱����");
        set("long", 
                "��������������ߵ���Ī���ȡ�\n"
                "����������ʮ���꣬�Ե�����δ�ѡ�\n"
                "��Ҳ�ǽ������������壬����Զ�������͡�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 24);
        set("int", 27);
        set("con", 25);
        set("dex", 22);
        
        set("max_qi", 3600);
        set("max_jing", 1800);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 60);
        set("combat_exp", 850000);
        set("score", 300000);

        set_skill("force", 150);
        set_skill("yinyun-ziqi", 150);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 150);
        set_skill("unarmed", 135);
        set_skill("taiji-quan", 135);
        set_skill("strike", 150);
        set_skill("zhenshan-zhang", 150);
        set_skill("hand", 100);
        set_skill("paiyun-shou", 100);
        set_skill("wudang-zhang", 125);
        set_skill("parry", 140);
        set_skill("sword", 130);
        set_skill("wudang-jian", 130);
        set_skill("taiji-jian", 130);
        set_skill("taoism", 70);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "zhenshan-zhang");
        map_skill("hand", "paiyun-shou");

        prepare_skill("unarmed", "taiji-quan");

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        set("inquiry", ([
                "��ɽ��ţ" : (: ask_skill1 :),
                "̫������" : (: ask_skill2 :),
                // "��ָ�ὣ" : (: ask_me :),
                // "������"   : (: ask_me1 :),
                // "raozhi"   : (: ask_me :),
                // "qingshu"  : (: ask_me1 :),
		// "teach"    : (: ask_me2 :),
		// "ָ��"     : (: ask_me2 :),
        ]));
        
        create_family("�䵱��", 2, "����");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.sui" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob", 4);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 2000 )
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)ob->query_skill("yinyun-ziqi", 1) < 50)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 50)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ������");
                command("say �ҿ��㻹��Ҫ���������Է��������������������"
                        "�ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ�����ܺú��ù����������䵱����!");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/zhenshan-zhang/da"))
                return "�̵ܽ��Ҷ����ˣ����Լ���ϰ�ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("zhenshan-zhang", 1) < 1)
                return "������ɽ�ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 50)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 6000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("zhenshan-zhang", 1) < 40)
                return "�����ɽ����Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 200)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "��"
                       "�����\n��һЦ��������������\n" NOR, me,
                       this_object());
        command("say �����ټ򵥲������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���ɽ��ţ����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("zhenshan-zhang"))
                me->improve_skill("zhenshan-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhenshan-zhang/da", 1);
        me->add("family/gongji", -50);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/wudang-jian/sheng"))
                return "���Լ�ȥ��ϰ�ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("wudang-jian", 1) < 1)
                return "�����䵱������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 80)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 8000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("force") < 80)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("wudang-jian", 1) < 60)
                return "����䵱������Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 300)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_vision(HIY "$n" HIY "΢΢һЦ���ӻ�������ȡ����һ��"
                       "���ף�ָ������һ�ζ�$N" HIY "ϸ\n˵���ã�$N"
                       HIY "һ����һ�ߵ�ͷ��\n" NOR, me, this_object());
        command("say �㶮����");
        tell_object(me, HIC "��ѧ���ˡ�̫����������\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("wudang-jian"))
                me->improve_skill("wudang-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wudang-jian/sheng", 1);
        me->add("family/gongji", -80);

        return 1;
}

