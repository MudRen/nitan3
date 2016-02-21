// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhangwuji.c

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_jiuyang();
mixed ask_qiankun();
mixed ask_ling();

string ask_book();
string ask_qishang();

int ask_hu_quest();
int ask_hu();
int ask_hdg();
void destroy(object ob);
void restart(object me, object ob);

void create()
{
        seteuid(getuid());
        set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
        set("long", @LONG
���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�
�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������
����Ӣ�ۡ�
LONG );
        set("title",HIG "����" HIM " ����" NOR);
        set("gender", "����");
        set("age", 20);
        set("no_get", 1);
        set("shen_type",1);
        set("attitude", "friendly");
        set("class", "fighter");

        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);

        set("qi", 5800);
        set("max_qi", 5800);
        set("jing", 2700);
        set("max_jing", 2700);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 120);
        set("level", 50);
        set("combat_exp", 2900000);
        set("score", 455000);
        set("book_count", 1);
    
        set_skill("force", 450);
        set_skill("unarmed", 450);
        set_skill("dodge", 450);
        set_skill("parry", 450);
        set_skill("cuff", 450);
        set_skill("sword", 460);
        set_skill("blade", 450);
        set_skill("strike", 450);
        set_skill("claw", 450);
        set_skill("throwing", 450);
        // set_skill("duoming-jinhua", 450);
        set_skill("jiuyang-shengong", 450);
        set_skill("shenghuo-shengong", 450);
        set_skill("lingxu-bu", 280);        
        set_skill("qingfu-shenfa", 450);     
        set_skill("qiankun-danuoyi", 450);
        set_skill("qishang-quan", 450);
        set_skill("taiji-quan", 450);
        set_skill("taiji-jian", 450);
        set_skill("taiji-dao", 450);
	set_skill("lieyan-dao", 450);
	set_skill("liehuo-jian", 450);  
	// set_skill("yingzhua-shou", 450);   
	// set_skill("hanbing-mianzhang", 450);   
        set_skill("shenghuo-ling", 450);
        set_skill("guangming-zhang", 220);
        set_skill("medical", 450);
        set_skill("literate", 500);          
        set_skill("martial-cognize", 380);      

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("unarmed", "jiuyang-shengong");
        map_skill("strike","guangming-zhang");
        map_skill("cuff", "qishang-quan");
        map_skill("sword","shenghuo-ling");
        map_skill("parry","qiankun-danuoyi");
        map_skill("blade","taiji-dao");
        // map_skill("claw", "yingzhua-shou");
        // map_skill("throwing", "duoming-jinhua");
        // map_skill("strike", "hanbing-mianzhang");
        
        prepare_skill("cuff", "qishang-quan");

        set("inherit_title",HIG"����"HIY"����ʹ��"NOR);
        create_family("����", 34, "����");

        set("no_teach", ([
                "jiuyang-shengong"  : "����ҿɲ��ܴ��㡣",
                "taiji-jian"        : "�㻹������̫ʦ���ɣ�",
                "taiji-quan"        : "�㻹������̫ʦ���ɣ�",
                "taiji-dao"         : "�㻹������̫ʦ���ɣ�",
                "qishang-quan"      : "��ѧ����ȭ�㻹�������常лѷ�ɣ�",
                "qiankun-danuoyi"   : "Ǭ����Ų��ֻ�����̽��������������ѵ�������������",
        ]));

        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({
                (: command("perform sword.hua") :),
                (: command("perform sword.xi") :),
                (: command("perform sword.lian") :),
                (: command("perform sword.can") :),
                (: command("perform cuff.shang") :),
                (: command("perform cuff.fei") :),
                (: command("yun shield") :),
                (: command("yun powerup") :),
                (: command("yun recover") :),
        }) );
        
        set("chat_chance", 2);
        set("chat_msg",({
                "���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
                "���޼�̾��������ʧһ֪��, ����λ�, �������, ����, ��������?��\n",
                "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
        }));

        set("inquiry",([
                "����"     : "���������������ʲô����\n",
                "��ëʨ��" : "�������常л������ְ˾��\n",
                "лѷ"     : "���������常�Ĵ�š�\n",
                "�Ŵ�ɽ"   : "�������Ҹ���������? \n",
                "������"   : "����������������΢������\n",
                "������"   : "��̫ʦ�������ɺ�? \n",
                "����"     : "����ʧһ֪��, ����λ�, �������, ����, ��������?\n",
                "С��"     : "С���ҿ�һֱ�������ĺô���\n",
                "������"   : "������ȥ����ɽ, �������ҡ�\n",
                "�����ؼ�" : (: ask_jiuyang :),        
                "������"   : (: ask_ling :),  
                "Ǭ����Ų��" : (: ask_qiankun :),   
	        "����ͨ"   : (: ask_hu_quest :),
	        "����ţ"   : (: ask_hu :),
	        "������"   : (: ask_hdg :),
	        "����ȭ��" : (: ask_qishang :),	        	      
                "�ؼ�"     : (: ask_book :),  
	                   
        ]));
        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/unarmed_damage", 180);
        set_temp("apply/armor", 180);

        set("master_ob",5);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
        // carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/book/shenghuo-ling")->wield();
        add_money("silver",70);
}

void init()
{
        object ob;

        ::init();

        if (interactive(this_player()) && this_player()->query_temp("fighting"))
        {
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
                this_player()->add_temp("beat_count", 1);
        }       
        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob)!=environment()) return;
        if ((int)ob->query("shen") < -50000)
        {
                command("wield yitian jian");
                command("hit" + (string)ob->query("id"));
                command("unwield yitian jian");
        } else
        if ((int)ob->query("shen") < -5000)
        {
                command("say ħ����������ѧ������������Ȱ������������"
                        "���سɷ�");
        } else
        if((int)ob->query("shen") < -100)
        {
                command("say ��λ���ѣ����н��������е����������߽�аħ�����");
        } else
        if((int)ob->query("shen") >= 0)
        {
                command("say �������������ߣ�Ȱ����ӱ��ء�");
        } else
        if((int)ob->query("shen") > 50000)
        {
                command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳���");
        }
        return;
}

int accept_fight(object ob)
{
        if ((count_lt(ob->query("combat_exp"),  30000)) && (ob->query("shen") > 0))
        {
                message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣�"
                               "��ȥ�ɡ�\n",ob);
                return 0;
        }
        message_vision("���޼�һ����˵������λ" + RANK_D->query_respect(ob) +
                       "����������ˡ�\n", ob);
        return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

        if (! permit_recruit(ob))
                return;

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "����")
	{
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( ob_fam["generation"] > my_fam["generation"] + 2)
	{
                command("say " + RANK_D->query_respect(ob) + "������ȥ�ҽ��������ֵܺú�ѧѧ�书�ɡ�");
		return;
	}

        if ((int)ob->query("shen") < 90000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
        
        if (count_lt(ob->query("combat_exp"), 1000000))
	{
		command("say ��ľ���̫�٣��ú���ȥ���������������ɱ�������̶����� !");
		return;
	}

        command("say �����ã�������������һλ�������֣����ǿ�ϲ�ɺ� !");

        command("say ��ϲ������Ϊ���̹���ʹ�ߣ�");
        command("recruit " + ob->query("id"));

	return;
}

int accept_object(object who, object ob)
{
        int r;
        object me;
        mapping fam;

        me = this_object();
        fam = who->query("family");

        if (playerp(ob)) 
                return 0; 
                        
        if (r = ::accept_object(who, ob))
                return r;
                        
        if (ob->query("id") == "jin mao")
        {
                tell_object(who, GRN "���޼ɼ�����˵�������ҵ��ҵ��常�ˡ�\n" NOR);
                if (! who->query_temp("marks/�常"))
                        who->set_temp("marks/�常", 1);
                remove_call_out("destrory");
                call_out("destrory", 1, ob);
                return 1;
        }                                
        if ((string)ob->query("id") == "shenghuo ling")
        {
                if (! (fam) || fam["family_name"] != "����")
                {
                        command("thank "+ (string)who->query("id"));
                        command("say ��л��Ϊ�����һ���ʥ���֪��Ӧ����ôлл�㣿\n");
                        call_out("destroy", 1, ob);
                        return 1;
                }
                if (fam["family_name"] == "����" 
                    && (fam["master_name"] != "���޼�" || who->query_temp("mj_jiaozhu")))
                {
                        command("nod "+ (string)who->query("id"));
                        command("say ��Ϊ�����һ���ʥ���ʹ��Ͳ�С����\n");
                        call_out("destroy", 1, ob);
                        who->add("shen", 2000);
                        who->add("combat_exp", 100+random(50));
                        tell_object(who,HIW"�㱻������һЩ����;���ֵ��\n"NOR);
                        return 1;
                }                                
                if (me->query("mj_jiaozhu"))
                {
                        command("pat "+ (string)who->query("id"));
                        command("say �������������Ѿ��������ҵ��ˡ�\n");
                        return 0;
                }                 
                command("ah " + (string)who->query("id"));
                command("say �㾹�һ��˱���ʥ��������ҵĵ��ӣ�");
                command("say �ϴ���������������Ѱ��ʥ���ߵ�����ϰ�����񹦣���ȥ�ص������԰ɡ�");
                who->set_temp("mj_jiaozhu", 1);
                me->set("mj_jiaozhu", 1);
                call_out("destroy", 1,  ob);
                remove_call_out("restart");
                call_out("restart", 3600, me, ob);
                return 1;
        } else 
                return 0;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "�һ�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liehuo-jian/jue",
                           "name"    : "�һ�������",
                           "sk1"     : "liehuo-jian",
                           "lv1"     : 100,
                           "neili"   : 1000,
                           "gongxian": 400,
                           "shen"    : 50000, ]));
                break;
                
        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/xi",
                           "name"    : "������",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/lian",
                           "name"    : "������",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;
        case "�⻪��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/hua",
                           "name"    : "�⻪��",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 160,
                           "neili"   : 2400,
                           "gongxian": 900,
                           "shen"    : 80000, ]));
                break;
        case "��Ѫ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/can",
                           "name"    : "��Ѫ��",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;
        case "���ػ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/jiu",
                           "name"    : "���ػ���",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;
        case "����һ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/hun",
                           "name"    : "����һ��",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;        
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/pi",
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;        
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/po",
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;        
        case "ħ�����޼�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/ri",
                           "name"    : "ħ�����޼�",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;        
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_learn/jiuyang-shengong/enable_weapon",
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;        
        case "��Ų��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qiankun-danuoyi/yi",
                           "name"    : "��Ų��",
                           "sk1"     : "qiankun-danuoyi",
                           "lv1"     : 200,
                           "neili"   : 5000,
                           "force"   : 200,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;       
        default:
                return 0;
        }
}

mixed ask_jiuyang()
{
        mapping fam;
        object ob;
        object me = this_player();
                        
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
                
        if (! this_player()->query_temp("marks/�常"))
                return "������ܰ����ҵ��ҵ��常лѷ���ǻ����Կ��ǣ�";

        if (me->query("jiuyang/zhang"))
                return "��֪�����������С��˻��ĺ�����ô��";
                
        me->set("jiuyang/zhang", 1);
        return "�뵱��̫ʦ�������������������ɡ�������ʥ�����������������˵���������С���\n"+
               "��֪���˻��кκ��塣";
}

/*
mixed ask_ling()
{
        mapping fam;
        object ob;
        
        if (! (fam = this_player()->query("family")) 
                || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player()) +
                       "�뱾������������Ҫ����Ǻξ��ģ�\n";
                       
        if (this_player()->query_skill("shenghuo-ling", 1) < 100)
                return "���ʥ�������̫ǳ��ҪȥҲû�õģ�\n";
                
        if (this_player()->query_skill("qiankun-danuoyi", 1) < 100)
                return "���Ǭ����Ų���ķ�����̫ǳ��ʥ��������ҿɲ�̫���ģ�\n";

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$NҪ��һ�������\n",this_player());

	return "�ðɣ�ƾ�������������������������ս��";
}
*/
mixed ask_ling()
{
        mapping family, skl; 
        string *sname;
        object ob;
        int i;
        
        if ( !(family = this_player()->query("family")) || family["family_name"] != "����")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

        skl = this_player()->query_skills();
        sname  = sort_array( keys(skl), (: strcmp :) );

        for(i=0; i<sizeof(skl); i++) 
        {
                if (skl[sname[i]] < 30) 
                return RANK_D->query_respect(this_player()) + 
                "����������������ȡ�����";
        }

        ob = new("d/mingjiao/obj/tieyanling");
        ob->move(this_player());
        message_vision("$NҪ��һ�������\n",this_player());

        return "�ðɣ�ƾ�������������������������ս��";

}

mixed ask_qiankun()
{	
        object obj,me;
	me = this_player();
	
	if (this_player()->query_skill("shenghuo-shengong", 1)<100) 
	{
                command("say " + RANK_D->query_respect(me) + "�ƺ�ʥ���ķ���Ϊ��������");
	        return 1;
	}
        if (count_lt(this_player()->query("combat_exp"), 800000))
	{
                command("say " + RANK_D->query_respect(me) + "�ƺ�ʵս���黹������");
	        return 1;
	}
	if (this_player()->query_skill("force", 1)<100) 
	{
                command("say " + RANK_D->query_respect(me) + "�ƺ������ڹ���Ϊ��������");
	        return 1;
	}
      	if (this_player()->query_temp("marks/Ų��")) 
      	{
	        command("say �㲻�Ǹող��ʹ���");
	        return 1;
	}
	else 
	{  
                command("say �ðɣ��Ҿ�׼���������������Ǭ����Ų�ơ��Ժ���Ҫ���������̡�");
                // command("say �㵽����ǰ������ȥ��˵����׼��ġ�");
                command("pat " + me->query("id"));
                command("addoil " + me->query("id"));			
                this_player()->set_temp("marks/Ų��", 1);
                return 1;
	}
	
}

int ask_hu_quest()
{
        object me = this_player();
        if (me->query_temp("hu/quest1") != 2) 
        {
                command("say ��ôͻȻ��������ʲô��");
                return 1; 
        } else 
        {
                command("say ԭ�������������ڣ�");
                command("jump");
                command("say �Ұ�������ݺݵ���������һ�һ�٣�������Ҳ�Լ������Լ��Ķ����ˡ�");
                command("say ���������������Կ�������ػ�ܸ��ˡ�");
                me->set_temp("hu/quest1", 3);
                return 1;
        }
}

int ask_hu()
{
        object me = this_player();
        
        if (! me->query_temp("hu/quest2")) 
        {
                command("say ����ţ�����ųƵ���ҽ�ɣ�ҽ��һ��������Ƣ���е�֡�");
                return 1; 
        } else 
        {
                command("ah");
                command("say ���ǶԲ�ס��������̽�Ҫ���£���ʵ�ڳ鲻����");
                command("say �鷳�����������˰�æ�������Ϳ��š�");
                command("say ����������޼ɰ��ã���������С�����ӡ�");
                command("say �������������ȥ���ú����������ɡ�");
                me->apply_condition("hu_quest", 5);
                new("/d/mingjiao/obj/tieyan")->move(me);
                return 1;
        }
}

int ask_hdg()
{
        object me = this_player();
        command("say �������Ǻ���ţ��ҽ�ľ�����");
        command("say ���ڳ����ϰ����������ź��������ҵ��ˡ�");
        me->set_temp("hdg", 1);
        return 1;
}

string ask_qishang()
{
        mapping fam; 
        object me = this_player();
        
        fam = me->query("family");
        if (! fam || fam["family_name"] != "����" || fam["master_name"] != "���޼�")
                return "��....���ҿɲ��������������ʱ��˰ɡ�";
                
        if (me->query("can_perform/xiexun/qishang"))
                return "�ף��常�����Ѿ�������ȭ��ȭ���������\n";
                
        if (me->query_temp("marks/����"))
                return "�ף��Ҳ��ǽ������ȥ�ݷ����常лʨ������\n";
                
        // me->set("luopan/bhd");
        me->set_temp("marks/����", 1);
        
        command("hmm");
        command("whisper " + me->query("id")+" ���常�ڼ��������ϣ����λ�ڻƵ����Ա��Ű���ʮ���Զ����ٸ�����ĵط���");
        // new("/d/mingjiao/obj/luopan")->move(this_object());
        // command("give luo pan to " + me->query("id"));
        return "������ȭ���ǵ������常���Դ��ҵľ�����������������ĺ��������ͳ���ȥ�ݷ����常�ɣ�\n";
}

string ask_book()
{
        mapping fam; 
        object me = this_player();
        
        fam = me->query("family");
        if (! fam || fam["family_name"] != "����" || fam["master_name"] != "���޼�")
                return "����һ��̫��ȭ�����ǵ������䵱��̫ʦ���͸��ҵġ�";
                
        me->set_temp("marks/��1", 1);
        return "����һ��̫��ȭ�����ǵ������䵱��̫ʦ���͸��ҵģ����ҽ���ɢ���ˡ�";
}

void destroy(object ob)
{     
        if (ob) destruct(ob);
}     

void restart(object me, object ob)
{     
        if(me->query("mj_jiaozhu"))
                me->delete("mj_jiaozhu");
                
        if (ob) destruct(ob);
}     

/*
void unconcious()
{
        die();
}
*/
