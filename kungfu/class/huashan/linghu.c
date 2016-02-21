// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// linghu.c �����

#include <ansi.h>
#include "qizong.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();
string ask_ylj1();
string ask_ylj2();
string ask_ylj3();
mixed learn_chongling();

void create()
{
        set_name("�����", ({ "linghu chong", "linghu", "chong" }));
        set("nickname", "��ʦ��");
        set("long", "����Ľ��ݣ�����Ũü���ۣ������Ѱ�����ͬ���������ϴ�\n"
                    "�ǻ�ɽ������һ���еĶ�����֡�\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        
        set("qi", 4800);
        set("max_qi", 4800);
        set("jing", 2400);
        set("max_jing", 2400);
        set("neili", 5700);
        set("max_neili", 5700);
        set("jiali", 60);
        set("level", 30);
        set("combat_exp", 2200000);
        set("score", 150000);

        set_skill("blade", 200);
        set_skill("cuff", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("strike", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("cuff",200);
        set_skill("poyu-quan", 200);
        set_skill("force", 200);
        set_skill("yijinjing", 200);
        set_skill("zixia-shengong", 200);
        set_skill("dodge", 200);
        set_skill("parry", 220);
        set_skill("sword", 240);
        set_skill("huashan-jianfa", 240);
        set_skill("chongling-jian", 240);
        set_skill("dugu-jiujian", 240);
        set_skill("literate", 240);
        set_skill("tanqin-jifa", 400);
        set_skill("xiaoao-jianghu", 400);
        set_skill("qingxin-pushan", 400);
        set_skill("martial-cognize", 230);
        
        map_skill("force", "yijinjing");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "huashan-zhangfa");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        map_skill("tanqin-jifa", "xiaoao-jianghu");
        
        prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

        set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.yi" :),
                (: exert_function, "recover" :),
	}) );
	
        create_family("��ɽ��", 14, "����");

        set("inquiry", ([
                "������" : "�����Ѿ��ܾ�û�м��������˼��ˡ���������",
                "��ӯӯ" : "��Ҫ��ʲô�������鷳��",
                "����������" : "�����ӨӨ�����ҵ�...",
                "Ц������"   : "���������Ϻ�������ʦ����������...����",
                "����"       : (: ask_me :),
                "���齣��"   : (: learn_chongling :),
                "����"       : (: ask_ylj3 :),
                // "ī������"   : (: ask_ylj2 :),
                // "������ã���ı���" : (: ask_ylj1 :),
        ]));

        set("no_teach", ([
                "yijinjing"    : "���������ش����ɷ�����ʦ���ڣ��Ҳ������Խ��㡣",
                "dugu-jiujian" : "�����������ҾŽ���ʱ�����������Բ���˽"
                                 "�Դ��ڣ��㻹��ѧϰ�����书�ɣ�",
        ]));

        set("music_book", 1);
        set("master_ob",3);
	setup();                
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/heimuya/npc/obj/card2");
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "tanqin-jifa" &&
            skill != "xiaoao-jianghu" &&
            skill != "qingxin-pushan")
        {
                command("say �Բ���...�Ҳ��ܴ�������Щ����Ҫ����ѧ����ټ�������ࡣ");
                return -1;
        }

        if (me->query_temp("can_learn/linghu/" + skill))
                return 1;

        me->set_temp("can_learn/linghu/" + skill, 1);
        command("say �ðɣ����Ȼ��" + to_chinese(skill) +
                "����Ȥ���Ҿͽ���һ�㡣");

        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("family/family_name") == "��ɽ����")
        {
                command("say ���ǽ��ڵİ����ҿɲ������㣬��ʦ����ͬ��ģ�");
                return;
        }
        
	if ((int)ob->query("shen") < 0) 
	{
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_int() < 25) 
	{
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�һ�ɽ���书��");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if ((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	return;
}

mixed ask_me()
{
        object me;
        object ob;

        me = this_player();
        if (query("music_book") < 1)
                return "�ҵ������Ѿ����ȥ�ˡ�\n";

        ob = new("/clone/book/qin");
        ob->move(me, 1);
        message_vision("$n�����׸���$N����������ȥ�ú�ѧϰ�ɡ�\n",
                       me, this_object());
        set("music_book", 0);
        return 1;
}

void reset()
{
        set("music_book", 1);
}

/*
void unconcious()
{
        die();
}
*/

mixed learn_chongling()
{
        object me = this_player();
        int lv = me->query_skill("huashan-jianfa", 1);

        if (me->query_skill("chongling-jian"))
               return "�㲻���Ѿ�������\n";

        if (me->query("family/family_name") != "��ɽ��")
               return "��˵ʲô���Ҳ����ף�\n";
 
        if (lv < 100)
               return "����齣����Ϊ�������һ����ܴ������У�\n";
        message_vision(HIW "$N" HIW "˵���������׽������Һ�Сʦ��������ʱ��ͻ������"
                       "�������ģ����Ǵӻ�ɽ�������ݻ���������ɿ����ˣ���˵�꽫����"
                       "�齣������ͷ��β�ظ�$n" HIW "��ʾ��һ�飡\n" NOR,
                       this_object(), me);        
        
        command("haha");
        tell_object(me, HIG "��ѧ���ˡ����齣������\n" NOR);

        if (! me->query("have_ask_chongling")) {
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("huashan-jianfa"))
                me->improve_skill("huashan-jianfa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("have_ask_chongling", 1);
        }

        command("say ����˶��پͿ��㻪ɽ��������Ϊ�ˣ�ʣ�µľͿ����Լ���ȥ��ϰ��");

        me->set_skill("chongling-jian", lv / 10);
        
        return 1;       
}

int accept_object(object who, object ob)
{
	object obn;

	if (! who || environment(who) != environment())
		return 0;
		
	if (! objectp(ob))
		return 0;
		
	if (! present(ob, who))
		return notify_fail("��û�����������\n");

	if ((string)ob->query("name") != "��")
		return notify_fail("����岻��Ҫ���������\n");
		
        say("�����˫��������ӯӯ���ţ��������£����׻�����������ȥ����ӯӯ���������Ҿ�ȥ����!");
	obn = new("/d/heimuya/npc/obj/card2");
	obn->set_amount(1);
	obn->move(who);
	destruct(ob);
        return 1;
}

string ask_ylj1()
{
        object me;
        
        me = this_player();
        command("haha "+me->query("id"));
        me->set_temp("ylj/step1", 1);
        
        return sort_string("��̨Ҳ֪������£����ǵ����ֵ���Ϊ�Ⱥ�ɽ�ɵ�����ʦ�ã����"
                           "������ﲮ�⿪����Ц���º��ɽ�Ķ���ʦ������û���ң�������"
                           "��һ�������Ѿ�����ī��������Ҫ����������һ�Ѿ�������������"
                           "����Ц������.....\n", 64, 3);
}

string ask_ylj2()
{
        object me;
        
        me = this_player();
        if (! me->query_temp("ylj/step1"))
                return "����Ǹ��������ܡ�\n";
                
        me->set_temp("ylj/step2", 1);
        me->delete_temp("ylj/step1");
        
        return "˵����ī������Ҳ��һ�������һֱ�Ҳ���������ʦ�������˷����������...��\n";
}

string ask_ylj3()
{
        object me, obj;
        
        me = this_player();
        if (! me->query_temp("ylj/step2"))      
                return "����Ǹ��������ܡ�\n";
                
        me->delete_temp("ylj/step2");
        command("look " + me->query("id"));
        
        if ((int)me->query("shen") > 100000)
        {
                obj = new(__DIR__"obj/xuantie");
                obj->move(me);
                // me->set_temp("ylj/step3", 1);
                return "����̨һ�����������������������̨������̨���ҵ���\n"
                       "����ʦ�����ɱ���������������Ҳ�����Ѷ���ʦ����һ������.....\n";
        }
        return "����Ǹ��������ܡ�\n";
}
