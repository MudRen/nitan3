// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// boguang.c �ﲮ��

inherit NPC;

int checking(object me, object ob);
void destob(object me);
int fast_attack(object me, object ob);
int climb_tree(object me);

void create()
{
	set_name("�ﲮ��", ({ "tian boguang", "tian", "boguang" }));
	set("nickname", "�������");
	set("long", 
                "�ﲮ������Ϊ�����г������õĲɻ���������ʶ��ɽ��������\n"
                "��а������һ�ֿ쵶������������˫���Ṧ��������Ҳ��һ�ȵġ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen", 0);
	
        set("max_qi", 2000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("level", 10);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("parry", 80);
	set_skill("luan-blade", 100);
	set_skill("blade", 100);
	set_skill("unarmed", 80);
	set_skill("literate", 50);
	set_skill("ding-dodge", 100);
	set_skill("ding-force", 80);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("parry", "luan-blade");
	map_skill("blade", "luan-blade");
	set("inquiry", ([
		"�����" : "�����������ƽ��һ֪����\n",
		"������" : "���ù��ң�����Ȼ�����ȥ������\n",
		"��ǰ��" : "���ù��ң�����Ȼ�����ȥ������\n",
		"������ǰ��" : "���ù��ң�����Ȼ�����ȥ������\n",
	]));

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init() 
{
	object ob, me = this_object();

	::init();
        if (interactive(ob = this_player()) && !is_fighting() &&  
            ! me->query_temp("said")) 
	{
	        me->set_temp("said", 1);
	        command("say ���ҷ�ǰ������ɵ�ʤ���ҵĿ쵶��˵��");
	        remove_call_out("climb_tree");
	        call_out("climb_tree", 50, me); 	
	}
}

int accept_fight(object ob)
{
        competition_with(ob);
        remove_call_out("checking");
        call_out("checking", 1, this_object(), ob);
        return 1;
}

void lost()
{
        object me, ob;
        
        ob = this_object();
        me = query_competitor();
        
        if (environment(ob)->query("short") == "������")
        {          
                environment(ob)->add("tian_count", 1);
                command( "say " + RANK_D->query_respect(me) + "��Ȼ���������¶��е������������ȥ����ǰ����");
                message("vision", me->name() + "�����ﲮ���߽���ɽ�\n", environment(ob), ({ob}));
                ob->move("/d/huashan/yelin1");
                me->move("/d/huashan/yelin1");
                tell_object(me, "�ﲮ�������߹���ɽ��ɽ��һƬ��ɽҰ�֣���ע�⵽�Ƕ��ƺ��и�ɽ����\n");
                ob->move("/d/huashan/xiaojing1");
                me->move("/d/huashan/xiaojing1");
                tell_object(me,"������ﲮ���������ã�����һ��С·��\n");
                command( "bow" );
                command( "say ��ǰ��ס���ɴ�·��ȥ���ǣ�����ʧ���ˡ�");
                say("�ﲮ��˵���ͷҲ���ص����ˡ�\n");	
                remove_call_out("fast_attack");
                remove_call_out("climb_tree");
                remove_call_out("destob");
                call_out("destob", 2, ob);
        }
                	        
        ::lost();
}

void win()
{
        object me = query_competitor();

        if (! objectp(me))
        {
                command("heihei");
                return;
        }

        remove_call_out("fast_attack");
        remove_call_out("climb_tree");
        call_out("climb_tree", 30, this_object());
        ::win();
}

int checking(object me, object ob)
{
        int my_max_qi;
	object weapon;

        if (! objectp(me) || ! objectp(ob)) 
                return 0;
        
        my_max_qi = me->query("max_qi");
        
        if (me->is_fighting()) 
        {
	        if (! me->query_temp("attack_pending") 
	        &&  objectp(weapon = me->query_temp("weapon"))) 
	        {
	   	        me->set_temp("attack_pending", 1);
           	        remove_call_out("fast_attack");
		        call_out("fast_attack", 3, me, ob);
                }

	        if (! me->query_temp("fought")) 
	        {
		        me->set_temp("fought", 1);
	        }
	        
                return 1;
        }

        if (! present(ob, environment()) && me->query("attack_pending") == 1) 
        {
	        me->delete_temp("attack_pending");
                remove_call_out("fast_attack");
                return 1;
        }

        return 1;
}

void destob(object me)
{
        if (! objectp(me)) 
                return 0;
        
        destruct(me);
}

int fast_attack(object me, object ob)
{
	int i, num;

	me->delete_temp("attack_pending");
	num = random(2) + 3;

	message_vision("�ﲮ���һ����ʹ����쵶����������$N������" + chinese_number(num) + "����\n", ob);

	for (i = 1; i < num + 1; i++) {
	        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	return 1;
}

int climb_tree(object me)
{
        if (! objectp(me)) return 0;
        
        if (me->is_fighting())
        {
                remove_call_out("climb_tree");
                call_out("climb_tree", 50, me);
                return 1;
        }
        
        if (environment(me)->query("short") == "������") 
	{
	        if (! me->query_temp("fought")) 
	        {
	                environment(me)->add("tian_count", 1);	
	                message_vision("�ﲮ��ŭ����ǣ��ÿڴ�����������Ȼ����ݼ���ǰ�����ɰͰ͵ؽ��������������\n", me);
	                message_vision("�ﲮ����ű��������ϣ��ݼ��ܹ�ȥ�ˡ�\n", me);		
	        }
	        else 
	        {
	                message_vision("�ﲮ����˸���Ƿ��\n", me);
	                command("say ˡ�Ҳ��ܷ��㡣");
	                environment(me)->add("tian_count", 1);
	                message_vision("�ﲮ����ű��������ϣ��ݼ��ܹ�ȥ�ˡ�\n", me);
	        }
	}
        else
 	{
	        message_vision("�ﲮ��Ҵ�ææ���뿪�ˡ�\n", me);
	}

	destruct(me);

	return 1;
} 
