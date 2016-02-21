// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// feng.c ������

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

mapping po_type = ([ "�ƽ�ʽ" : ({ "sword" }),
                     "�Ƶ�ʽ" : ({ "blade" }),
                     "��ǹʽ" : ({ "staff" }),
                     "�Ʊ�ʽ" : ({ "hammer", "club", "dagger" }),
                     "����ʽ" : ({ "whip" }),
                     "����ʽ" : ({ "unarmed", "finger", "claw",
                                   "strike", "hand", "cuff" }),
                     "�Ƽ�ʽ" : ({ "throwing" }),
                     "����ʽ" : ({ "force" }), ]);

int check_skill(string skill);
mixed teach_lonely_sword();

void create()
{
        set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
        set("title", "��ɽ���ڳ���");
        set("nickname", HIW "��������" NOR);
        set("long", @LONG
����ǵ������𽭺��Ļ�ɽ���޷��������
�����ۣ��������������ֽ������ݳ���ü��
��һֱ������һ�ɵ�����������ɫ����Ȼ�Ե�
��Ľ���֮��һֱ����������
LONG);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 6000);
        set("max_jing", 5000);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 200);
        set("level", 60);
        set("combat_exp", 4000000);

        set_skill("force", 500);
        set_skill("zixia-shengong", 500);
        set_skill("huashan-neigong", 480);
        set_skill("dodge", 500);
        set_skill("feiyan-huixiang", 500);
        set_skill("huashan-shenfa", 500);
        set_skill("parry", 520);
        set_skill("sword", 520);
        set_skill("dugu-jiujian", 520);
        set_skill("blade", 500);
        set_skill("fanliangyi-dao", 500);
        set_skill("strike", 480);
        set_skill("hunyuan-zhang", 480);
        set_skill("cuff", 480);
        set_skill("poyu-quan", 480);
        set_skill("literate", 480);
        set_skill("martial-cognize", 420); 

        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "dugu-jiujian");
        map_skill("blade", "fanliangyi-dao");
        map_skill("sword", "dugu-jiujian");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ����", 0, "����");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.yi" :),
                (: perform_action, "sword.poqi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("can_perform/dugu-jiujian", ({ "sword", "blade", "staff",
                                           "hammer", "club", "dagger",
                                           "whip", "unarmed", "finger",
                                           "claw", "strike", "hand",
                                           "cuff", "force", "throwing" }));

        set("no_teach", ([
                "dugu-jiujian" : (: teach_lonely_sword :),
        ]));
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("master_ob",5);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob, me = this_object();

	::init();

        if (! objectp(me)) return;
        if (file_name(environment(me)) == "/d/huashan/xiaofang")
        {
	        if (interactive(ob = this_player()) && ! ob->is_fighting() 
	        &&  sizeof(ob->query_temp("win")) != 6 
	        &&  ! wizardp(ob)) 
	        {
		        remove_call_out("auto_kill");
		        call_out("auto_kill", 1, ob );
	        } else if (! ob->query("see_feng"))
	        {
	                remove_call_out("improve_sword");
		        call_out("improve_sword", 1, ob );
	        }
        }
}

int auto_kill(object ob)
{
	object me = this_object();

	command("say �üһﾹ��ı���ҹ����ɣ��������ɣ�");
	me->kill_ob(ob);
	ob->fight(me);
	return 1;
}

int improve_sword(object ob)
{
	int my_sword, add_level;

        if (! objectp(ob)) return 1;
	my_sword = ob->query_skill("sword", 1);
	command("say " + RANK_D->query_respect(ob) + "��Ȼһ�����������ҿ�ν��Ե������ָ����һЩ�����ɡ�");
	message_vision("�����￪ʼΪ$N��˵���������ľ��塣\n", ob);

	if (my_sword < 100) 
	{
		add_level = my_sword + 20;
		tell_object( ob, "��Ļ������������˶�ʮ����\n");
	} else
	if (my_sword < 120) 
	{
		add_level = my_sword + 10;
		tell_object( ob, "��Ļ�������������ʮ����\n");
	} else
	if (my_sword < 150) 
	{
		add_level = my_sword + 5;
		tell_object( ob, "��Ļ��������������弶��\n");
	}
	else {
		message_vision("���������$N���ȵء���������һ����\n", ob);
		command("say " + RANK_D->query_respect(ob) + "�Ľ�����Ȼ�������ң����಻ʤ�����\n");
		tell_object(ob, "��Ļ��������ѳ�¯����֮������������ûʲô��ָ��������ˣ�\n");
		ob->set("see_feng", 1);
		return 1;
	}

	ob->set_skill("sword", add_level);
	ob->set("see_feng", 1);
	ob->add("combat_exp", 15000);
	return 1;
}

mixed teach_lonely_sword()
{
        object me;

        me = this_player();
        
        if (me->query("family/family_name") != "��ɽ��"
            && me->query("family/family_name") != "��ɽ����")
        {
                command("say �߿����ǻ�ɽ�ĵ�����һ�Ų��̡�");
                return -1;
        }
        
        if (me->query_skill("dugu-jiujian", 1) > 120)
        {
                if (me->query_temp("feng_has_told"))
                {
                        command("say ���Լ��ú����ɣ�");
                        return -1;
                }

                command("pat " + me->query("id"));
                command("say ���׽���Ҫ���Լ��������Ժ����Լ�������аɣ�");
                me->set_temp("feng_has_told", 1);
                return -1;
        }

        if (me->query_temp("learnd_lonely_sword"))
                return 0;

        me->set_temp("learnd_lonely_sword", 1);
        command("say �ܺã��ܺá����Ž������ڽ��⣬������ʽ��");
        command("say ����ѧϰ���в��ɾ�������ʽ��");
        return 0;
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name") != "��ɽ��"
            && ob->query("family/family_name") != "��ɽ����")
        {
                command("say �߿����ǻ�ɽ�ĵ�����һ�Ų�����");
                return;
        }

        command("say �Ҳ���ͽ������������ɡ�");
}

int check_skill(string skill)
{
        if (skill != "sword" && skill != "dugu-jiujian")
        {
                command("say ��ֻ������������ѧ��ѧ������ѧ�����ˡ�");
                return -1;
        }
        return 1;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("can_learn/feng/dugu-jiujian"))
                return check_skill(skill);

        if (ob->query("can_learn/feng/sword")
           && skill != "dugu-jiujian")
        {
                if (skill == "sword")
                        return 1;

                command("say �������������ǿ������㣬�ٸ������£�");
                return -1;
        }

        if (ob->query_temp("have_asked_feng"))
        {
                command("say ���������");
                return -1;
        }
        
        if (ob->query("family/family_name") != "��ɽ��"
            && ob->query("family/family_name") != "��ɽ����")
        {
                command("say �߿����ǻ�ɽ�ĵ�����һ�Ų��̡�");
                return -1;
        }
        
        if (ob->query("character") == "���ռ�թ"
           || ob->query("character") == "�ĺ�����")
        {
                command("heng");
                command("say �������ľ͸��ҹ���");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("character") == "��������")
        {
                command("hmm");
                command("say �����Բ���������ȴ���ʺ���ϰ���׽�����");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        /*
        if (ob->query("shen") < -10000
           || ob->query("shen") > 10000
           || ob->query("weiwang") > 10000)
        {
                command("say �ҷ�ĳ�Ӳ��ͳ�����ʿ�򽻵������߰ɡ�");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }
        */

        if (ob->query("int") < 26)
        {
                command("sneer");
                command("say �������ͷ�죬߯���˵㣬�߰ɡ�");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("int") < 28)
        {
                command("look " + ob->query("id"));
                command("say �㵹�ǲ��㱿���е�С���������������ǲ��Զ����");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query_skill("sword", 1) < 100)
        {
                command("say �����䲻��������ĶԽ��������Ҳδ��̫���ˡ�");
                return -1;
        }

        if (ob->query("int") < 34)
        {
                if (skill == "sword")
                {
                        command("say �ðɣ��Ҿͽ���һ����ڽ�����֪ʶ��");
                        ob->set("can_learn/feng/sword", 1);
                        return 1;
                }

                if (skill != "dugu-jiujian")
                {
                        command("say ��ֻ�ὣ����Ҫѧ�����ı����ұ��ʦ��ȥ�ɣ�");
                        return -1;
                }

                command("sigh");
                command("say ���������Ǵ�����������¾Ž����ǲ�֮��Զ��");
                return -1;
        }

        if (check_skill(skill) == -1)
                return -1;

        message_sort(HIW "\n$N" HIW "���˵�ͷ����$n" HIW "˵��������"
                     "�ã����á���Ȼ�Ҳ���ͽ��������������ʵ�ڲ���"
                     "�ʹ���һ�㽣���ɡ����׶��¾Ž�����Ϊ���ƣ�����"
                     "�����ܾ�ʽ�������ƽ�ʽ���Ƶ�ʽ����ǹʽ���Ʊ�ʽ"
                     "������ʽ������ʽ���Ƽ�ʽ������ʽ�����һһ�ֽ�"
                     "����������\n" NOR, this_object(), ob);

        tell_object(ob, HIC "\n������ͬ�⴫���㡸���¾Ž�����\n" NOR);
        ob->set("can_learn/feng/dugu-jiujian", 1);
        ob->improve_skill("martial-cognize", 1500000);
        return 1;
}

int accept_ask(object me, string topic)
{
        string *learned, *try_to;
        mixed pot;

        pot = me->query("potential");
        pot = atoi(pot);

        if (! topic || undefinedp(try_to = po_type[topic]))
                return 0;

        if (! (int)me->query_skill("dugu-jiujian", 1))
        {
                command("say �����¾Ž�ô���������������");
                return 1;
        }

        learned = me->query("can_perform/dugu-jiujian");
        if (! arrayp(learned))
                learned = ({ });
        if (member_array(try_to[0], learned) != -1)
        {
                command("say �㲻���Ѿ�ѧ��" + topic + "��ô��");
                return 1;
        }

        command("say �ðɣ�" + topic + "��Ҫ����Ҫ����ϸ�ˡ�");
//        if (me->query("potential") - me->query("learned_points") < 10)
        if (count_lt(count_sub( pot, me->query("learned_points")), 10))
        {
                me->set("learned_points", me->query("potential"));
                tell_object(me, HIG "�����˷�����Ľ̵����ľ���ã����"
                                "����Ǳ�ܲ����ˡ�\n" NOR);
                return 1;
        }

        me->add("learned_points", 10);
        if (random(2))
        {
                write(HIY "�����˷�����Ľ̵��������ĵá�\n" NOR);
                return 1;
        }

        learned -= try_to;
        learned += try_to;
        me->set("can_perform/dugu-jiujian", learned);
        tell_object(me, HIC "��ѧ���˶��¾Ž�֮��" + topic + "����\n");
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("dugu-jiujian"))
                me->improve_skill("dugu-jiujian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        return 1;
}
