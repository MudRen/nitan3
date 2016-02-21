// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wufu.c ����»

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();
string ask_me1();
string ask_me2();
int do_give(object ob, object me, object who);
void destroy(object ob);

void create()
{
        set_name("����»", ({ "yin wulu", "yin", "wulu" }));
        set("title","������ӥ�ֶ�����");
        set("age", 45);
        set("long","������ҵ����ˡ�\n");
        set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("per", 10);
        set("level", 10);
        set("no_get", "����»������˵̫���ˡ�\n");
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        
        set_skill("dodge",90);
        set_skill("force", 90);
        set_skill("qingfu-shenfa", 90);
        set_skill("shenghuo-shengong", 90);
        set_skill("yingzhua-shou",90);
        set_skill("claw",90); 
        set_skill("parry", 90);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        
        prepare_skill("claw","yingzhua-shou");
        
        create_family("����",38,"����");    
         
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("inquiry", ([
                 "Ѳ��" : (: ask_me :),
                 "���" : (: ask_me1 :),
                 "����" : (: ask_me2 :),
        ]));
        set("master_ob",1);
	setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();       
}

void attempt_apprentice(object ob)
{        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0) 
        {
                command("say " + RANK_D->query_respect(ob) +
                        "������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ�������������̰벽��");
                return;
        }
        
        command("look " + ob->query("id"));
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", "������΢�ý���");
}

string ask_me()
{
        mapping fam; 
        object ob, me, obj;
        
        me = this_player();
        ob = this_object();
        
        if (! (fam = me->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

        if (count_lt(me->query("combat_exp"), 5000))
                return me->name()+"���书��΢������ô����������Ѳ���أ�\n";

        if (me->query_condition("job_busy"))
                return "��!�㾹Ȼ��ͬʱ���������";

        if (me->query("mingjiao_job") > 2000) 
                return "��Ϊ���������˺ܶ๱�ף�Ѳ������ô��Σ��������ЪЪ�ɡ�";

        if (me->query_temp("mj/xunluo"))
                return "�㲻����Ѳ������ô���������";

        if (me->query_temp("mj/over"))
                return "���ϴ�Ѳ�߽�����û�����ء�";

        if (me->query("job_name") =="����Ѳ��")
                return "���ϴ�����Ѳ����������꣬��������Ϣһ�°ɡ�";

        if (me->query("jiuyang/read"))
                return "�㻹��Ϊ���̸�Щ����°ɣ�Ѳ�ߵ�������ñ�����̵���ȥ�ɰ�";
 
        if (me->query_condition("mj_xunluo"))
        {
                if (! me->query_temp("mj/fail"))
                        return "�ţ���ո�Ѳ����ϣ�������ȥ��Ϣ��Ϣ�ɡ�";
                else 
                        return "��ոշ����ˣ�����ȥ��Ϣһ�ᣬ���������ɡ�";
        }
        me->set_temp("mj/xunluo", 1);
        
        message_vision(CYN"\n$N��"+me->name()+"����һЦ��˵������Ȼ����������ڹ�������Сɳ��֮��ú�Ѳ�ߡ�\n"NOR, ob, me);
        me->apply_condition("mj_xunluo", 200);
        me->set("job_name","����Ѳ��");
        me->delete_temp("mj/fail");

        obj = new("/d/mingjiao/obj/lingpai");
        obj->set("owner", me->query("id"));
        obj->move(me); 
        return "����Ҫ����λ��ʹ������������ɢ�˺����ֵ����޸����㻭ӡ(ask about ��ӡ)��
            Ѳ������Ժ󣬻���������(ask yin wulu about ���)��\n";    
}

string ask_me1()
{
        mapping fam; 
        object ob, me;
        
        me = this_player();
        ob = this_object();

        if (! (fam = me->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(me)+"����˵Щʲô����";      
                  
        if (! me->query_condition("mj_xunluo")){
                me->delete_temp("mj/xunluo");
                return "��������ô�ò�Ѳ���꣬����û�ã�";
        }
        
        if (! me->query_temp("mj/xunluo"))
                return "��ɣ����ʲô��";
                
        if (me->query_temp("mj/xunluo") < 8)
                return "�㻹û��Ѳ����ɣ���ô�ͻ����ˣ�";
                
        command("nod " + me->query("id"));         
        me->delete_temp("mj/xunluo");
        me->set_temp("mj_task1", 1);
        me->set_temp("mj/over", 1);
        return " �ã�" + me->name() + "����ɵúܺã������Ƹ��Ұɡ�";    
}

string ask_me2()
{
        object me = this_player();
        mapping fam;

        if (! (fam = me->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(me)+"����˵Щʲô����";        

        if (! me->query_temp("mj/xunluo")
                && ! me->query_condition("mj_xunluo"))
                return "�������������û����������ʲô����";

        if (me->query_temp("mj/fail"))
                return "��ոշ�����������Ҫ����ʲô����";

        command("disapp "+ me->query("id"));
        me->delete_temp("mj/xunluo");
        me->apply_condition("mj_xunluo", 6);
        me->set_temp("mj/fail", 1);
        return "�������Ϣһ�ᣬ������������Ѳ�߰ɡ�";
}

int accept_object(object who, object ob)
{
        int r;
        object me;
        
        me = this_object();
        if (r = ::accept_object(who, ob))
                return r;
                        
        if (ob->query("name") != "Ѳ����" || ob->query("id") != "xunluo ling") 
        {
               command("say �����ⶫ��������ʲô��˼��");
               command("doubt "+me->query("id"));  
               return 0;
        }           
        if (ob->query("owner") != who->query("id"))
        {
               command("say �����Ʋ�����İ���������ô�õ��ģ�");
               command("hmm "+who->query("id"));
               call_out("destroy", 1, ob);  
               return 1;
        }
        if (! who->query_temp("mj_task1"))
        {
               command("say �㻹ûѲ���꣬�����Ƹ��Ҹ��");
               command("push "+who->query("id"));  
               return 0;
        }
        if (me->query("ling"))
        {
               command("say ���ٵȻᣬ���Ҽ�����Ͽ����ơ�");
               return 0;
        }
        who->delete_temp("mj_task1");
        command("say �ã������������ȥ����Τ�����ɡ�"); 
        
        if (who->query_condition("mj_xunluo") > 10)   
                who->apply_condition("mj_xunluo", 10);  
                
        ob->set("long", "����һƬ����Ƭ���Ƶ����ƣ�������Ѳ�ߵ��ӵ����֤����\n"+
                        "����д�˼����֣�Ѳ�ߣ�"+who->name()+"��\n");
        ob->set("task_ok", 1);
        me->set("ling", 1);
        call_out("do_give", 1, ob, me, who);
        return 1;
}

int do_give(object ob, object me, object who)
{
        message_vision("\n$N��Ѳ������д��д������\n",me);
        if (! objectp(present(who, environment(me)))){
                message_vision("$N˵����Ү���Ǽһ���ô�����ˣ�\n", me);
                command("drop "+ob->query("id"));
                me->delete("ling");
                return 1;
        }
        if (! living(who))
        {
                command("sigh "+who->query("id")); 
                ob->move(who);
                me->delete("ling");
                message_vision("$N��$n�Ž�"+who->name()+"�·��\n", me, ob);
                return 1;
        }
        else 
        {
                me->delete("ling");
                command("give "+ob->query("id")+" to "+who->query("id")); 
                return 1;
        }
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
