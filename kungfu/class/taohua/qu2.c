// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qu.c �����

#include <ansi.h>
#include "taohua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_book1();
mixed ask_book2();
mixed ask_skill1();

#define HETU    "/clone/book/hetu"
#define LUOSHU  "/clone/book/luoshu"

void create()
{
        set_name("�����", ({ "qu lingfeng", "qu", "lingfeng" }));
        set("gender", "����");
        set("age", 46);
        set("long", "������ǻ�ҩʦ�Ĵ�ͽ�ܣ�Ҳ�ǻ�ҩʦ������ͽ������\n"
                    "�Ի�ҩʦһ�����Ĺ������������Ը�Ź֣�������ʦ��\n"
                    "��а�����������޳�����òӢ��������ƮƮ������������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 24);
        set("con", 27);
        set("dex", 23);
        set("shen_type",1);
        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 120);
        set("level", 20);
        set("combat_exp", 1000000);

        set_skill("force", 200);
        set_skill("bibo-shengong", 200);
        set_skill("unarmed", 180);
        set_skill("xuanfeng-tui", 180);
        set_skill("strike", 180);
        set_skill("luoying-shenzhang", 180);
        set_skill("finger", 200);
        set_skill("throwing", 200);
        set_skill("tanzhi-shentong", 200);
        set_skill("dodge", 200);
        set_skill("luoying-shenfa", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("luoying-shenjian", 200);
	set_skill("whip", 200);
	set_skill("canglang-bian", 200);
        set_skill("literate", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "bibo-shenfa");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "luoying-shenzhang");
        map_skill("finger", "tanzhi-shengong");
        map_skill("throwing", "tanzhi-shentong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("whip", "canglang-bian");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");

        prepare_skill("finger", "tanzhi-shentong");

        create_family("�һ���", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sui" :),
                (: perform_action, "finger.jinglei" :),
                (: perform_action, "strike.qimen" :),
                (: perform_action, "unarmed.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "��а"     : "��ʦ�˳ƶ�а���Ǻǡ�",
                "����"     : "ŷ���������ʦ���������ĸ��֣��˳��϶��",
                "�ϵ�"     : "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
                "��ؤ"     : "��ؤ���߹���ؤ��������������ݳ��⡣",
                "����"     : "����ʦ���İ�Ů��",
                "��ҩʦ"   : "��Ҫ�ݷü�ʦ��",
                "�һ���"   : "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
                "�һ���"   : "���Ͼ����ˡ�",
                "������" : (: ask_skill1 :),
                "��ͼ"     : (: ask_book1 :),
                "����"     : (: ask_book2 :),
        ]));
        set("master_ob", 4);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

/*
void attempt_apprentice(object ob)
{
        string master;

        if (! permit_recruit(ob))
                return;

        if (stringp(master = ob->query_temp("taohua/master")))
        {
                if (master != name())
                {
                        command("say ��ʦ���������" + master + "��������ô��"
                                "�������ˣ�");
                        return;
                }
                command("say �ðɣ���Ȼ��ʦ����Ҿ��������ˣ�����Ҫ�ú�������"
                        "�����Ĺ�ء�");
                command("recruit " + ob->query("id"));
                ob->delete_temp("taohua/master");
                return;
        }

        command("shake");
        command("say �ҿɲ���������ͽ���㻹���Ҽ�ʦ�Ƶ����ɣ�");
}
*/

void attempt_apprentice(object ob)
{
	string ttt;

        if (! permit_recruit(ob))
                return;
                
        if ((int)ob->query_skill("bibo-shengong", 1) < 60)
        {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����ڹ���Ϊ�϶��µ㹦��");
                return;
        }

        if ((int)ob->query_skill("literate", 1) < 60)
        {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ������ѧ�����϶��µ㹦��");
                return;
        }

	if (this_player()->query("gender") == "����") 
	        ttt = "����";
	        
	else  if (this_player()->query("gender") == "Ů��") 
	        ttt = "����"; 
	        
	command("recruit " + ob->query("id"));
	ob->set("title", "����ׯ" + ttt);
	command("say " + "��Ȼ������Ϊͽ�����Ҳ�ϲ���������㻹��½ʦ�ܵ����£��������᣿\n");
	command("say " + "������������Ƚ����ҵ��ң�ע����ñ��˷����ˡ�\n");
	return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/luoying-shenjian/fenglei"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("luoying-shenjian", 1) < 1)
                return "������Ӣ�񽣶�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 120)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("luoying-shenjian", 1) < 80)
                return "�����Ӣ�񽣻������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "���˿�$N" HIY "��û˵ʲô�����ִӻ�������ȡ"
                     "����һ�����ף�ָ������һ�ζ�$N" HIY "ϸ˵���ã�$N" HIY "һ"
                     "����һ�߲�ס�ص�ͷ��\n\n" NOR, me, this_object());

        command("nod");
        command("say ���в������ӣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������񽣡���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("luoying-shenjian"))
                me->improve_skill("luoying-shenjian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/luoying-shenjian/fenglei", 1);
        me->add("family/gongji", -120);

        return 1;
}

mixed ask_book1()
{
        object ob, owner, me = this_player();

        if (! me->query_temp("taohua/countbook"))
                return "�Բ���ûʦ���������鼮ˡ����衣";

        ob = find_object(HETU);

        if (! ob) ob = load_object(HETU);
        owner = environment(ob);

        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ��Ǳ�����ͼ���������������ڿ�ô��";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ������ʦ���ѽ�����ͼ����������ˡ�";

                if (owner->query("family/family_name") == "�һ���")
                        return "�Ǳ�����ͼ����������ʦ��" + owner->query("name") +
                               "���У���Ҫ����ȥ�����ɡ�";
                else
                        return "�Ǳ�����ͼ���������䵽��" + owner->query("name") +
                               "���У���ȥ�����ɣ�";
        }
        ob->move(this_object());

        message_vision(CYN "$N" CYN "̾������Ȼ��ʦ��������Ȿ����ͼ����"
                       "������ɡ�\n" NOR, this_object(), me);
        command("give he tu to " + me->query("id"));
        return 1;
}

mixed ask_book2()
{
        object ob, owner, me = this_player();

        if (! me->query_temp("taohua/countbook"))
                return "�Բ���ûʦ���������鼮ˡ����衣";

        ob = find_object(LUOSHU);

        if (! ob) ob = load_object(LUOSHU);
        owner = environment(ob);

        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ��Ǳ������项�������������ڿ�ô��";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ������ʦ���ѽ������项��������ˡ�";

                if (owner->query("family/family_name") == "�һ���")
                        return "�Ǳ������项��������ʦ��" + owner->query("name") +
                               "���У���Ҫ����ȥ�����ɡ�";
                else
                        return "�Ǳ������项�������䵽��" + owner->query("name") +
                               "���У���ȥ�����ɣ�";
        }
        ob->move(this_object());

        message_vision(CYN "$N" CYN "̾������Ȼ��ʦ��������Ȿ�����项��"
                       "������ɡ�\n" NOR, this_object(), me);
        command("give luo shu to " + me->query("id"));
        return 1;
}

int accept_fight(object ob)
{
        command("wield jian");
}

