#include <ansi.h>
#include "wudang.h"

#define WUDANG    "/clone/book/wudang"
inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;
inherit F_COAGENT;

mixed ask_book1();
mixed ask_book2();
mixed ask_skill();

void create()
{
        set_name("��Զ��", ({ "song yuanqiao", "song" }));
        set("nickname", "�䵱����");
        set("long", 
                "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
        set("gender", "����");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 31);
        set("int", 27);
        set("con", 32);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 160);
        set("combat_exp", 1500000);
        set("score", 70000);

        set_skill("force", 200);
        set_skill("yinyun-ziqi", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 160);
        set_skill("tiyunzong", 160);
        set_skill("unarmed", 185);
        set_skill("taiji-quan", 185);
        set_skill("strike", 185);
        set_skill("wudang-zhang", 185);
        set_skill("zhenshan-zhang", 185);
        set_skill("hand", 185);
        set_skill("paiyun-shou", 185);
        set_skill("parry", 180);
        set_skill("sword", 185);
        set_skill("wudang-jian", 185);
        set_skill("shenmen-jian", 185);
        set_skill("taiji-jian", 185);
        set_skill("taoism", 190);
        set_skill("literate", 120);
        set_skill("medical", 200);
        set_skill("liandan-shu", 200);

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "zhenshan-zhang");
        map_skill("hand", "paiyun-shou");

        prepare_skill("unarmed", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�䵱ҩ��"   : (: ask_book1 :),
                "̫��ʮ��ʽ" : (: ask_book2 :),        
                "���Ŵ�"     : (: ask_skill :),
                "����"       : (: ask_skill :),
        ]));

        set("book_count", 1);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
        }) );

        set("coagents", ({
                ([ "startroom" : "/d/wudang/houyuan",
                   "id"        : "yu lianzhou" ]),
        }));

        set("master_ob", 4);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}
void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;
        if ((int)ob->query("shen") < 25000)
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        if ((int)ob->query_skill("yinyun-ziqi", 1) < 80)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }
        if ((int)ob->query_skill("taoism", 1) < 80)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ġ�");
                command("say �ҿ��㻹��Ҫ���������Է������������������"
                        "��ĵ����ķ���");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ������ȫ�����������ķ�������������裡");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_book1()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�䵱��")
                return "���ֲ������䵱�ɵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query("shen") < 10000)
                return "�������������ò������Ȿ���һ����ܸ��㡣";

        if ((int)me->query_skill("wudang-yaoli", 1) < 50)
                return "����䵱ҩ����˽�̫ǳ�����ǹ���ʱ����˵�ɡ�";

        ob = find_object(WUDANG);
        if (! ob) ob = load_object(WUDANG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ǳ�ҩ�������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��䵱ҩ�����ڲ��������";

                if (owner->query("family/family_name") == "�䵱��")
                        return "����������ʱ����ͬ��" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�䵱ҩ������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ�䵱ҩ�������ȥ���ɣ���Ҫ�����ж���");
        command("give liandan miben to " + me->query("id"));
        return 1;
}

mixed ask_book2()
{
        object ob;
        
        if (this_player()->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(this_player()) + 
                       "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        add("book_count", -1);
        ob = new("/clone/book/force_book");
        message_vision("$N�ó�̫��ʮ��ʽ(shu)��$n��\n",
                       this_object(), this_player());
        ob->move(this_player(), 1);
        return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

void reset()
{
        set("book_count", 1);
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/shenmen-jian/ci"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query("shen") < 140000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("shenmen-jian", 1) < 160)
                return "�������ʮ�����������ң�Ҫ��������";

        if (me->query("family/gongji") < 200)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY
                       HIY "���������ֹ��˼��䣬�ְγ�"
                       "���䳤�������������������Ȼ��"
                       "�͵�бб�̳���\n��ʽ���ӣ�����"
                       "��㻪�����ԡ�\n" NOR,
                       me, this_object());
        command("nod");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����Ŵ̡���һ�С�\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 160000);
        me->set("can_perform/shenmen-jian/ci", 1);
        me->add("family/gongji", -200);        
        return 1;
}

/*
mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/ci"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 200)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 30000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("force") < 160)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("taiji-jian", 1) < 120)
                return "���̫�����������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����������"
                       "���˼��䣬�ְγ����䳤\n�������������������"
                       "Ȼ���͵�бб�̳�����ʽ���ӣ�����\n��㻪����"
                       "�ԡ�\n" NOR, me, this_object());
        command("nod");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����Ŵ̡���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/ci", 1);
        me->add("family/gongji", -200);

        return 1;
}
*/

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "���಻��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/paiyun-shou/mian",
                           "name"    : "���಻��",
                           "sk1"     : "paiyun-shou",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 100,                   
                           "gongxian": 500,
                           "shen"    : 30000, ]));
                break;

        case "��ɽ��ţ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/zhenshan-zhang/da",
                           "name"    : "��ɽ��ţ",
                           "sk1"     : "zhenshan-zhang",
                           "lv1"     : 100,
                           "sk2"     : "force",
                           "lv2"     : 100,                   
                           "gongxian": 400,
                           "shen"    : 30000, ]));
                break;

        default:
                return 0;
        }
}
