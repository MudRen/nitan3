// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chang.c ������

#include <ansi.h>
inherit NPC;

string ask_me();
void create()
{
        set_name("������", ({ "chang yuchun","chang","yuchun" }) );
        set("title", "���̾�ľ�����");
        set("gender", "����");
        set("age",34);
        set("long","����ĸߴ����͹��ˡ�\n");
        set("str", 24);
        set("int", 27);
        set("con", 23);
        set("dex", 20);
        set("per", 20);
        set("shen_type", 1);
        set("max_qi",700);
        set("max_jing",600);
        set("neili",600);
        set("max_neili",600);
        set("jiali",20);        
        set("eff_jingli",400);        
        set("combat_exp", 190000);
        set("level", 10);

        set_skill("unarmed",60);
        set_skill("force",60);
        set_skill("dodge",60);
        set_skill("parry",60);  
        set_skill("blade",60);  

        set_skill("changquan", 60);
        map_skill("parry", "changquan");
        map_skill("unarmed","changquan");
        prepare_skill("cuff", "changquan"); 

        set("inquiry", 
        ([
                "����" : (: ask_me :),
        ]));
        
        set("master_ob",1);
	setup();
        create_family("����", 38, "����");
        carry_object("/d/mingjiao/obj/black-cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{     
        command("say �Ǻǣ����书��΢���ɲ�����ͽ����");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}

void init()
{
        ::init();
        add_action("do_task","task");
}

string ask_me()
{
        object me, ob, ling;
        me = this_player();
        ob = this_object();
        
        if (me->query("family/family_name")!= "����")
                return RANK_D->query_respect(ob) + "���㲻�Ǳ��̵��ӣ��˻��Ӻ�˵��";
                
        if (count_lt(me->query("combat_exp"), 20000))
                return ("����书̫���ȥ��������˵�ɡ�");
                
        if (count_ge(me->query("combat_exp"), 90000))
                return ("�ҿ�����书�����൱�Ĺ����ˣ�ȥ����Ļ�ɡ�\n");
       
        if (me->query_temp("shouwei"))
                return ("��ղź���û��ɰɣ�");
                
        ob->set("shouwei_name",ob->query("name"));
        me->set_temp("shouwei", 1);
        ling = new("/d/mingjiao/obj/sw_ling");
        ling->move(me);
        tell_object(me, "����������һֽ�����顣\n");
        
        return "�ðɣ���ȥ��̳ǰ�������ｻ��Ұ���֣�������ǲ��";
}

int do_task(string arg)
{
        object ob, me;
        ob = this_player();
        me = this_object();
        
        if (! (arg)) return 0;
        if (! (arg == "ok")) return 0;
        if (! ob->query_temp("shouwei")) return 0;
        if (! ob->query_temp("shouweied")) return 0;
        if (ob->query_temp("shouwei_ok")) 
        {
                if (interactive(ob) &&
                    (int)ob->query_condition("mj_shouwei")) 
                {
                        command("kick" + ob->query("id"));
                        return notify_fail(RED "��͵��������ҹ���ȥ��"NOR);
                }          
                ob->add("mingjiao_job", 1);
                command("pat " + ob->query("id"));
                command("say �������ˣ�" + RANK_D->query_respect(ob) + "���ɵúã�");
                ob->add("potential", 25 + random(10));
                ob->add("combat_exp", (int)(ob->query_skill("shenghuo-shengong", 1) / 4) + 90);
                me->delete("shouwei_name");
                me->delete_temp("shouwei");
                ob->delete_temp("shouwei");
                ob->delete_temp("shouweied");
                return 1;
        }
        return notify_fail("����������Ǵ��������ģ�\n");
}

