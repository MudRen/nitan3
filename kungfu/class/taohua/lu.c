// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lu.c ½�˷�

#include <ansi.h>
#include "taohua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

string ask_me();
int    ask_xfsy();

void create()
{
        set_name( "½�˷�" ,({ "lu chengfeng", "lu", "chengfeng" }));
        set("gender", "����");
        set("nickname", HIC "����ׯ��" NOR);
        set("age", 52);
        set("long", "½�˷��ǻ�ҩʦ�ĵ��ĸ�ͽ�ܡ������޽���΢���׷�����\n"
                    "��Ŀ��࣬˫������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 24);
        set("int", 30);
        set("con", 25);
        set("dex", 21);

        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 120);
        set("combat_exp", 1000000);
	set("bagua_count", 5);
	set("yulu_count", 5);

        set_skill("force", 200);
        set_skill("bibo-shengong", 200);
        set_skill("unarmed", 200);
        set_skill("xuanfeng-tui", 200);
        set_skill("strike", 200);
        set_skill("luoying-shenzhang", 200);
        set_skill("finger", 180);
        set_skill("tanzhi-shentong", 180);
        set_skill("dodge", 180);
        set_skill("luoying-shenfa", 180);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("luoying-shenjian", 200);
	set_skill("whip", 180);
	set_skill("canglang-bian", 180);
        set_skill("literate", 180);
        set_skill("qimen-wuxing", 160);
        set_skill("calligraphy", 160);
        set_skill("martial-cognize", 160);

        map_skill("force", "luoying-xinfa");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "luoying-shenzhang");
        map_skill("finger", "tanzhi-shentong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "luoying-shenjian");
        map_skill("whip", "canglang-bian");
        map_skill("sword", "luoying-shenjian");

        prepare_skill("unarmed", "xuanfeng-tui");
        prepare_skill("strike", "luoying-shenzhang");

        create_family("�һ���", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sui" :),
                (: perform_action, "strike.wuxing" :),
                (: perform_action, "unarmed.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "��а"   : "��ʦ�˳ƶ�а���Ǻǡ�",
                "����"   : "ŷ���������ʦ���������ĸ��֣��˳��϶��",
                "�ϵ�"   : "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
                "��ؤ"   : "��ؤ���߹���ؤ��������������ݳ��⡣",
                "����"   : "����ʦ���İ�Ů��",
		"÷����" :"�������ﺦ���Һÿࡣ����Ҫ��͵������Ҳ���ˣ�����Ҫ͵ʦ���ġ������澭����",
		"������" :"����÷���綼��ʦ����ͽ���кκ�˵�������˺����Һÿ࣡�Ұ����죬���ǰ���������֮�͡�",
		"�����" :"���ʦ��ר���似����������һŮ����֪���������Σ�",
		"��Ĭ��" :"��ɳ��һ���������ǰ��Ѱ��Ĭ�磬��ʦ�����Ե�����������ڸգ��������÷ǳ��ֶβ��ܱ�����¶��ݣ�����",
		"��ҩʦ" : "����ʦ��һŭ֮�£�������ʦ�ֵ�����һ����ϽŽ����һ�����",				
		"�һ���" : (: ask_me :),
                "��������" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
                "����ɨҶ��" : (: ask_xfsy :),
        ]));
        set("master_ob", 4);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

void init()
{
	::init();
	add_action("do_recite", "recite");
}

void attempt_apprentice(object ob)
{
        string master;
        if (! permit_recruit(ob))
                return;
        /*
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
        */
        if (ob->query_temp("pending/recite")) 
        {
		command("say ��ֱɲ��ģ���ʶǳ������ׯ���������㣿");
		return;
	} else 
	{
		command("say һλ�������ڱ�ׯ������ʫ���ڣ�������ܲ�ȫ��Ҳ����������ׯһ��");
		message_vision("½ׯ��������$N��˵�������������ڴ�������(recite)�����ɡ�\n",
		               this_player());
		ob->set_temp("pending/recite", 1);
	}
}

int do_recite(string arg)
{
	string name, new_name, ttt;
	
	if (! this_player()->query_temp("pending/recite"))
		return 0;
		
	if (! arg) 
	        return notify_fail("��˵ʲô��\n");
	        
	this_player()->set_temp("pending/recite", 0);
	
	message_vision("$N����˵����" + arg + "\n", this_player());
	
	if (arg == "���������ɲ����º�ɳ") 
	{
		command("smile");
		if (this_player()->query("gender") == "����") 
		        ttt = "����";
		else  
		if (this_player()->query("gender") == "Ů��") 
		        ttt = "����";
                else 
                {
                        command("sigh");
                        command("say " + "�䱾���ˣ��κ��Թ�����ׯ�붫�����޹�������ȥ�ɣ�");
                        return 0;
                }
		command("say " + "�ã��ã�" + RANK_D->query_respect(this_player()) +
		        "��Ȼ����ǿ�ǡ����˾���������" + ttt +"�ɡ�");
		        
		command("recruit " + this_player()->query("id"));
		this_player()->set("title", "����ׯ" + ttt);
	} else 
	{
		command("say ����׶����������û�������ҵ����ӣ�");
	}
	return 1;
}

string ask_me()
{
	mapping fam;
	object ob;

	if (! (fam = this_player()->query("family")) || 
	        fam["family_name"] !="�һ���")
		return RANK_D->query_respect(this_player()) +
	               "���ׯ������������֪�˻��Ӻ�̸��";
	               
	if (query("bagua_count") < 1)
		return "������̫���ˣ���ʲô��������˵�ɡ�";
		
	if (present("tie bagua", this_player()) || this_player()->query_temp("get_bagua"))
		return "������������һ�����һ�ԣ�����û�и��ݼ�����ʦ����";
		
	if (this_player()->query_skill("qimen-wuxing", 1) < 60 ||
	this_player()->query_skill("bibo-shengong", 1) < 60)
		return "�һ����ϻ������أ��㹦�򲻹������ǲ�ȥΪ�";
		
	add("bagua_count", -1);
	ob = new("/d/taohua/obj/bagua");
	ob->move(this_player());
	this_player()->set_temp("get_bagua", 1);
	
	message_vision("½�˷�ݸ�$Nһ�������ԡ�\n", this_player());
	return "�ϵ�֮��ǧ��С�ģ����¿��Լ�����Ҳ�ﲻ��ʲôæ�ˡ�";
}
/*
mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/pikong-zhang/dai"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("pikong-zhang", 1) < 1)
                return "���������ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 80)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("pikong-zhang", 1) < 80)
                return "��������ƻ������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "����$N" HIY "���˵�ͷ��˵�������Ҹ�����ʾ"
                     "һ�飬�ɿ���ϸ�ˣ����������䣬��ʱֻ��$n" HIY "˫�ƽ�����"
                     "�����������������Ȧ������һ������$N" HIY "�ȥ����������"
                     "�����ޱȡ�\n\n" NOR, me, this_object());

        command("smile");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����Ǵ��¡���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("pikong-zhang"))
                me->improve_skill("pikong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pikong-zhang/dai", 1);
        me->add("family/gongji", -80);

        return 1;
}
*/

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/canglang-bian/lang"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("canglang-bian", 1) < 1)
                return "�������˱޷���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 200)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("canglang-bian", 1) < 80)
                return "��Ĳ��˱޷��������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "����$N" HIY "���˵�ͷ��˵�������Ҹ�����ʾ"
                     "һ�飬�ɿ���ϸ�ˣ����������䣬��ʱֻ��$n" HIY "���г���"
                     "��������������޾�������գ��澫���ޱȡ�\n\n" NOR, me, 
                     this_object());

        command("smile");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������졹��\n" NOR);
        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("canglang-bian"))
                me->improve_skill("canglang-bian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/canglang-bian/lang", 1);
        me->add("family/gongji", -80);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuanfeng-tui/kuang"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("xuanfeng-tui", 1) < 1)
                return "��������ɨҶ�ȶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 300)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("xuanfeng-tui", 1) < 100)
                return "�������ɨҶ�Ȼ�����������������������";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���ȵ����������ˣ�������$n" HIY
                     "�������µ�һ˲�䣬���Ѱεض��𣬶�Ȼʹ������ɨҶ�ȿ��"
                     "�����������Ʈ������������糾����Я�������ʽ������"
                     "�ƻֺ룬����ֻϮ��$N" HIY "�����������ۡ�\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ��ȥ���Ҫ�ڼ���ϰ��Ī�����˶�ʦ��һ�����ࡣ");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xuanfeng-tui"))
                me->improve_skill("xuanfeng-tui", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuanfeng-tui/kuang", 1);
        me->add("family/gongji", -300);

        return 1;
}

int accept_kill(object me)
{
	if (me->query("family/family_name") == "�һ���")
	{
	        command("say ���ұ���ͬ�ţ����Ҫ�Ӻ����ң�\n");
	        me->set("th_killer", 1);
	        kill_ob(me);
	        return 1;
	}
      return 1;
}

int accept_object(object me, object obj)
{
	call_out("accept_obj", 2, me, obj);
	return 1;
}

int accept_obj(object me, object obj)
{
        if (! me || ! obj) return 0;
	if (obj->query("name") == "����ɨҶ��") 
	{
		command("ah");
		message_vision(CYN "$N˫�ֲ�����չ����ֽ������ϸϸ�Ķ���������\n", this_object());
		message_vision(CYN "$Nһ�߶���һ������ӯ����\n", this_object());
		command("cry");
		command("say ��л"+ RANK_D->query_respect(me) +"�ˡ�\n");
		set("xfsy_xinfa_reading", 1);
		set("xfsy_xinfa_accept", 1);
		if (me->query("family/family_name") == "�һ���")
		        me->set("help_chengfeng", 1);
	}
	call_out("finish_reading", 100 + random(50), obj);
	return 1;
}     

void finish_reading(object obj)
{
	delete("xfsy_xinfa_reading");
	destruct(obj);
}

int ask_xfsy()
{
	object me, obj;

	me = this_player();
	if (query("xfsy_xinfa_reading")) 
	{
		command("say �Բ�ס���һ�û�����ʦ�����ķ���");
		return 1;
	}

	if (me->query("family/family_name") == "�һ���" 
	&&  query("xfsy_xinfa_accept")) 
	{
	        obj = new("/d/taohua/obj/xfsy_xinfa2");
	        obj->move(me);
	        command("say �����ķ�������һЩע�⣬"+RANK_D->query_respect(me) +
		        "���û�ȥ���в���");
		        
	        message_vision("$N�ݸ�$nһ�ű�ֽ��\n",this_object(),me);
	        delete("xfsy_xinfa_accept");
	} else 
	        command("say ����ɨҶ���ķ��Ѳ��������");

	return 1;
}
