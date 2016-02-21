// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

inherit F_DEALER;

int ask_xueyi();
string ask_xiao();

void create()
{
	set_name("����", ({ "qu san", "san", "qu" }));
	set("title", "�Ƶ��ϰ�");
	set("nickname", "����");
	set("gender", "����");
	set("age", 25);
	set("long",
		"��������°ᵽ�˵ص�һ�����ӡ����޾���ʵ��к��ſ��ˣ�"
		"�۾���ʱ�����ؿ�����ա�\n");
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
        set_skill("literate", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "bibo-shenfa");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "luoying-shenzhang");
        map_skill("finger", "tanzhi-shengong");
        map_skill("throwing", "tanzhi-shentong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");

        prepare_skill("finger", "tanzhi-shentong");

        set("xiao_count", 1);

	set("attitude", "friendly");
	set("inquiry", ([
		"��ҩʦ" : "��ʦ����ʲô�������ﲻ��ҩ��\n",
		"��ҩ"   : "����ҩ���ǲ���ҩ��\n",
		"�����" : "�����ң�������˵�����Ҳ���ʶ��\n",
		"����"   : "���ô������\n",
		"ѧ��"   : (: ask_xueyi :),
		"����"   : (: ask_xiao :),
	]));
	
        // create_family("�һ���", 2, "����");
	set("vendor_goods", ({
		"/d/city/obj/peanut",
	}));

	setup();
	carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/taohua/obj/bagua");
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
		
	say("��������������˵������λ" + RANK_D->query_respect(ob) + 
            "��������㻨���¾ưɡ�\n");
}

/*
void unconcious()
{
	object ob;
	object who = this_player();

        message_vision("\nͻȻ��ֻ�������þ����һ˿������$N���һ�������ԣ�\n",
                who);
	who->receive_damage("qi",100);
	who->receive_wound("qi",100);
	ob = new (__DIR__"obj/tiebagua");
        ob->move(environment(this_object()));
	:: unconcious();
}
*/

int accept_object(object me, object obj)
{
	call_out("accept_obj", 2, me, obj);
	return 1;
}

int accept_obj(object me, object obj)
{
	if (obj->query("name") == "��ҩʦ����") 
	{
		command("ah");
		message_vision(CYN "$N˫�ֲ�����չ�����ţ����ҴҵĶ���������\n", this_object());
		message_vision(CYN "$Nһ�߶���һ������ӯ����\n", this_object());
		command("cry");
		command("say ��л"+ RANK_D->query_respect(me) + "�ˡ�\n");
		me->set_temp("huang_shouyu", 1);
	}

	if (obj->query("name") == "������") 
	{
		command("ah");
		command("say �ⲻ����Ů���Ķ������������������ˣ���");
		me->set_temp("shagu_amulet", 1);
	}

	if (me->query_temp("huang_shouyu") 
	    &&  me->query_temp("shagu_amulet")) 
	{
		command("say ��ĳ��Ф����Ϊʦ�����ǣ�����ʦ����ҹǣ�ң�����" +
		        RANK_D->query_respect(me) + "���ı����ˡ�\n");	
		        
		command("thank " + me->query("id"));
			
                if (me->query("family/family_name") == "�һ���")
                // &&  me->query("family/master_name") != "��ҩʦ") 
        	{
		        command("say " + RANK_D->query_respect(me) + "���ʲ�����������" +
		                "���Ψ��һ�����գ����������书��ǳ���ɵ㲦" + RANK_D->query_respect(me) + "һ����");
		        command("say " + RANK_D->query_respect(me) + "ֻ������ѯ�ʡ�ѧ�ա����ɡ�");
		        me->set("help_lingfeng", 1);
		        me->delete_temp("huang_shouyu");
		        me->delete_temp("shagu_amulet");	
		        me->set_temp("lingfeng_teach", 1);
		}
	}	
	destruct(obj);
	return 1;
}

int ask_xueyi()
{
	object me, *ob;
	int i, k = 0;

	me = this_player();
	if (! me->query_temp("lingfeng_teach") 
	&&  (me->query("family/master_name") != "�����"))
	{
		command("say " + RANK_D->query_respect(me) + "˵Ц�ˣ�����ֻ�Ǹ������Ƶģ���ɶ�ɽ̵ģ�");
		return 1;
	}

	if (base_name(environment(me)) != "/d/hangzhou/jiudian")
	{
		command("say ��ûص��Ƶ���˵��");
		return 1;
	}

        ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++) 
	{
                if (! living(ob[i])) 
                        continue;
		k++;
	}

	if (k > 2) 
	{
		command("whisper " + me->query("id") + 
		        "�����Ŀ�ڶ࣬ʵ���Ǵ�������֮���������ȴ�����Χ������˵��");
		return 1;
	}

	command("say " + RANK_D->query_respect(me) + "��������");
	tell_object(me, CYN "���������ƾɵĲ��£�����һ�����ۣ����������˼��ѡ�\n" NOR);
	tell_object(me, CYN "�������������һֻ��������ת�������ÿ�����һ���죬"
	                "���������Էֿ���¶���������һ��������\n" NOR);
        me->set_temp("taohua/master", this_object()->name());
        me->move("/d/hangzhou/mishi");

	return 1;
}


string ask_xiao()
{
	object me = this_player(); 
	object ob;
        mapping myfam;
        
        myfam = (mapping)me->query("family");	
	if (! myfam || myfam["family_name"] != "�һ���") 
	{
	        command("xixi");
	        return RANK_D->query_respect(me) + "��ʲô����Ҫ�������£�";
	}
	
		
	if (query("xiao_count") < 1)
		return "������ⲻ�ã�������Ǯ����棿";
	
	if (present("tong xiao", this_player()) || this_player()->query_temp("get_xiao"))
		return RANK_D->query_respect(me) + "��û�аѹ��潻���Ƶ�����";
	
	command("say " + RANK_D->query_respect(me) + "�Ǵ��һ������ģ�");
	
	if (me->query_skill("bibo-shengong", 1) < 100)
	        return "���ŻƵ����ղ������챦������Щ���棬���������˼Ҽ��͡�";
	
	if (me->query_skill("yuxiao-jianfa", 1) < 100)
	        return "���ŻƵ����ղ������챦������Щ���棬���������˼Ҽ��͡�";
	
	
	command("touch " + me->query("id"));
        ob = new("/clone/weapon/tongxiao");
	ob->move(this_player());
	add("xiao_count", -1);
	this_player()->set_temp("get_xiao", 1);
	
	message_vision("�����ݸ�$Nһ֧��ͭ�\n", this_player());
        
        return "�ҽ��յõ�һ�����棬�鷳������Ƶ������ͼ��͡�";
}	
