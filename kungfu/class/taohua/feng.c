// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "taohua.h"

inherit NPC;
inherit F_MASTER;
inherit F_VENDOR;

int ask_me();
int do_sell(string arg);
int do_hit(string arg);

void create()
{
        set_name( "������" ,({ "feng tiejiang", "feng", "smith" }));
        set("gender", "����");
        set("age", 39);
        set("long", "���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ��\n"
                    "���Ȳзϣ������³���һ�����ȡ�\n");
        /*          "��Ĭ���ǻ�ҩʦ��С��һ��ͽ�ܣ����ĸ�������������\n"
                    "��Ϊ��³�����Ļ�������ʵ��һ���Һ���ʵ�����ӡ�\n");
        */
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 24);
        set("con", 27);
        set("dex", 23);
        set("shen_type",1);
        set("max_qi", 4200);
        set("max_jing", 2100);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("level", 20);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("bibo-shengong", 180);
        set_skill("unarmed", 160);
        set_skill("xuanfeng-tui", 160);
        set_skill("strike", 160);
        set_skill("luoying-shenzhang", 160);
        set_skill("finger", 140);
        set_skill("tanzhi-shentong", 140);
        set_skill("dodge", 160);
        set_skill("luoying-shenfa", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("luoying-shenjian", 160);
        set_skill("literate", 140);
        set_skill("martial-cognize", 140);

        map_skill("force", "bibo-shengong");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "luoying-shenzhang");
        map_skill("finger", "tanzhi-shentong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");

        prepare_skill("unarmed", "xuanfeng-tui");
        prepare_skill("strike", "luoying-shenzhang");

        // create_family("�һ���", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sui" :),
                (: perform_action, "finger.jinglei" :),
                (: perform_action, "strike.qimen" :),
                (: perform_action, "unarmed.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));
        
        /*
        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "��Ĭ��˵����ʦ���۰�Сʦ�ã�������⬼�һֱ��Сʦ�ô��š�\n" NOR,
                CYN "��Ĭ�����������˵������ʦ�����õ�����һ������ǲ��򵥣�\n" NOR,
        }));
        */

        set("vendor_goods", ({
                "/d/village/npc/obj/hammer",
		"/clone/weapon/gangdao",
        }));
        
        set("inquiry", ([
                /*
                "��ʦ" : (: ask_me :),
                "Ͷʦ" : (: ask_me :),
                "��а" : "��ʦ�˳ƶ�а���Ǻǡ�",
                "����" : "ŷ���������ʦ���������ĸ��֣��˳��϶��",
                "�ϵ�" : "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
                "��ؤ" : "��ؤ���߹���ؤ��������������ݳ��⡣",
                "����" : "����ʦ���İ�Ů��",
                "��ҩʦ" : "��Ҫ�ݷü�ʦ��",
                "�һ���" : "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
                "�һ���" : "���Ͼ����ˡ�",
                "��������" : (: ask_skill1 :),
                */
                "name"    : "С���շ룬�����˶����ҷ�������",
		"here"    : "������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�",
		"��ͷ"    : "��ͷ... ��Ǹ����ͷ�Ѿ�������...",
		"����"    : "������С������������������ã�һ��ֻҪ������Ǯ��",
		"��"      : "Ŷ�����Ǹ���ɽ�������Ŵ�ģ�С�����������£�����û�˷��ǿ������\n"
                            "�ţ�������ǰ��������ͽ��ɽȥ�ˣ���֪ʲ��ʱ��Ż�������ȡ����",
		"ȡ��"    : "С��һ��Ҫ���������ŵ����Ų��ܸ�����",
		"��Ĭ��"  : "�������������С���Ѿ��þ�û����������...",
		"���Ŷݼ�": "�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�",
		"����"    : (: ask_me :),
		"����"    : (: ask_me :),
        ]));
        set("master_ob", 4);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/village/npc/obj/hothammer")->wield();
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	add_action("do_hit", "hit");
	add_action("do_hit", "da");
}

int ask_me()
{
	say("����������һ����˵������ɻ�ã�������������������ˣ�����ȥ�Ҽ�ʮ��������ɡ�\n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}	

int accept_object(object who, object ob)
{
	object sword;
        if ((string)ob->query("name") == "����" && 
            (string)ob->query("id") == "letter" && ! userp(ob)) 
        {
                if (! query("yl_trigger")) 
                {
	                sword = new(__DIR__"obj/youlong");
                        if (! sword)
                        {
                                say("������˵�����ǽ��类�����ˣ���������һ���ţ�һ���Ǽٵġ�\n");
	                        call_out("destroy", 1, ob);
	                        return 1;
	                }
		        say(
                            "������˵������ѽ��䲻���ۣ���Ҳ��С�˵���Ѫ������Ե��������š�\n"
                            "��������" + sword->query("name") + "������" + who->query("name") + "��\n");
		        sword->move(who);
		        command ("rumor " + who->query("name") + "Ū����һ����������");
                        set("yl_trigger", 1);
                } else 
                        say("��������Ҳ��̧��˵����Ҫ���Լ���ȥ�á�\n");
                call_out("destroy", 1, ob);
	        return 1;
	}

        if ((string)ob->query("name") == "������") 
        {
		if (! query("accept_bagua")) 
		        return 0;
		call_out("accept_obj", 2, who, ob);
		return 1;
	}
	return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

int accept_obj(object me, object obj)
{
        if (obj->query("name") == "������") 
        {
	        message_vision(CYN "$NĦ���������ԣ���������ӯ����\n" NOR, this_object());
	        command("cry");
	        command("say Ĭ�粻Ф����ʦ�����ǣ�ͬ��ǣ�ң�����" + RANK_D->query_respect(me) + "�ˡ�\n");
	        me->set("help_mofeng", 1);
	}
	return 1;
}

int do_sell(string arg)
{
        object ob;

        if (! arg || ! (ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("material") != "steel" && ob->query("material") != "iron")
                return notify_fail("������ֻ�շ�����\n");

        else {
                message_vision("$N������һ" + ob->query("unit") +
                ob->query("name") + "��$n��\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), ob->query_weight() / 70);
                destruct(ob);
        }
	return 1;
}
int do_hit(string arg)
{
	object ob, weapon,  me = this_player();
	string file;
	
	if (! arg || ! (ob = present(arg, this_player()))
	||  me->query_temp("marks/��") < 1)
                return notify_fail("��Ҫ��ʲô��\n");
                
	if (ob->query("material") != "steel" && ob->query("material") != "iron"
	||  ob->query("value") > 0) 
                return notify_fail("�㻹����һ���������ɡ�\n");
                
	if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "hammer")
                return notify_fail("û�к��ʵļһ�����������\n");
                
        if ((int)me->query("jing") < 50)
                return notify_fail("��ľ���̫���ˣ�Ъһ��ɡ�\n");

	if (ob->weight() < 300)
	{
	        file = resolve_path(this_object()->query("cwd"), arg);
	        file = base_name(ob) + ".c";
	        destruct(ob);
                ob = new(file);
	        message_vision("��һ������������һ"  + ob->query("unit") + ob->query("name") +
	                       "������������\n", me);
	        command("thumb " + me->query("id"));
	        command("say " + RANK_D->query_respect(me) + "������㣬����س�һλ��������");	
	        message_vision("��������$N����ͭ�幤Ǯ��\n", me);
	        MONEY_D->pay_player(this_player(), ob->query_weight() / 100);
	        destruct(ob);
	        return 1;
	}

	message_vision("$N��һ" + ob->query("unit") + ob->query("name") + 
	               "�ӽ���¯�պ������˳�����\n", me);
	               
	message_vision("$NȻ��߸߾���" + weapon->query("name") + "�Ȼ���ش���������\n", me);
	
	me->recieve_damage("jing", -30);
	
        if ((int)me->query_skill("hammer",1) <= 100) 
        {
                me->improve_skill("hammer", 1);
                tell_object(me, "��Ļ������������ˡ�\n");
	        ob->set_weight(ob->weight() - 10 * me->query("str"));
                if ((string)weapon->query("id") == "liuxing chui") 	
	        me->improve_skill("hammer", me->query("int"));
	        return 1;
	}
}

void unconcious()
{
	object obj;

	if (! query("revived"))  
	{
                set("eff_jing", (int)query("max_jing"));
                set("jing", (int)query("max_jing"));
                set("jingli", (int)query("max_jingli"));
                set("eff_qi", (int)query("max_qi"));
                set("qi", (int)query("max_qi"));
                set("neili", (int)query("max_neili"));	
                map_skill("strike", "luoying-shenzhang");
                map_skill("dodge", "luoying-shenfa");
                prepare_skill("strike", "luoying-shenzhang");
	        set("revived", 1);
	        message_vision(HIW "$N���һ��������ͻȻ����鶯�쳣��������ʽҲ����ͬ��\n" NOR,
	                       this_object());
	
	        if (objectp(obj = query_last_damage_from())) 
	        {
		        if (present(obj->query("id"), environment(this_object()))) 
		        {
		                this_object()->fight_ob(obj);
		                if (obj->query("family/family_name") == "�һ���")
		                        call_out("halt_fight", 5 + random(10), obj);
		        }
	        }
	        return 0;
	} else 
	::unconcious();
}

void halt_fight(object me)
{
	
        if (this_object()->is_fighting()) 
        {
        	this_object()->remove_all_enemy();
		me->remove_all_enemy();
	}
	message_vision(CYN "$N������Ц������Ĭ�磬�����ù���ȫ�����һ�һ�ɣ��ѵ��㻹Ҫװ��ȥ�𣿣�\n" NOR, me);
	message_vision(CYN "$Nһ�㣬���²��ɵ��������������һԾ������սȦ�����ˡ�\n" NOR, this_object());
	message_vision(CYN "$N��̾һ�������������ҷ�Ĭ������֮�껹�ܼ����һ�ͬ�ţ���֪��ʦ�����˼ҽ����ɺã�\n",
	               this_object());
	this_object()->set("accept_bagua", 1);
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

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/canglang-zhi/tao"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("canglang-zhi", 1) < 1)
                return "��������ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("family/gongji") < 50)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("canglang-zhi", 1) < 80)
                return "��Ĳ���ָ���������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����������Ȼ��ʦ�Ը����������Ҿ�"
                     "�������У���Ҫ�����ˡ���˵��ֻ��$n" HIY "��Ȼ���һָ��"
                     "�׷�����������ָ����Ȼ���죬ȫȫ����$N" HIY "���ܡ�\n\n"
                     NOR, me, this_object());

        command("nod");
        command("say ��������");
        tell_object(me, HIC "��ѧ���ˡ��������졹��\n" NOR);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("canglang-zhi"))
                me->improve_skill("canglang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/canglang-zhi/tao", 1);
        me->add("family/gongji", -50);

        return 1;
}

mixed ask_me()
{
        object me;
        me = this_player();

        if (me->query("family/family_name"))
        {
                if (me->query("family/family_name") != "�һ���")
                {
                        command("say �����������ɣ���ʦ�ǲ���������ģ����߰ɣ�");
                        return 1;
                }

                if (me->query("family/master_name"))
                {
                        command("say �㲻���Ѿ����������һ�����");
                        return 1;
                }
        }

        if (me->query("detach/�һ���"))
        {
                command("say �������뿪���һ��������컹�һ�������ʦ��");
                return 1;
        }

        if (me->query("betrayer/times"))
        {
                command("say ������ʦ֮�ˣ���ʦ�Ǿ��Բ�������Ϊͽ�ģ�");
                return 1;
        }
        command("say �ðɣ��Ҵ�����һ������Լ�ȥ�һƵ����ɡ�");
        message_vision(HIW "\n$N" HIW "�󲽵�������ȥ��$n" HIW "�������\n\n" NOR,
                       this_object(), me);
        this_object()->move("/d/taohua/damen");
        me->move("/d/taohua/damen");
        command("say ���ˣ��Ҵ��㵽���ţ����ȥ�Ϳ��Լ�����ʦ��");
        message_vision("$NͷҲ���ص���������ȥ��\n", this_object());
        this_object()->move(query("startroom"));
        message_vision("$N���Ҵҵ����˹�����\n", this_object());
        return 1;
}
*/
