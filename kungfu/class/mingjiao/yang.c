// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yang.c ����

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();
string dagger();

void create()
{
        set_name("����",({"yang xiao","yang","xiao"}));
	set("title",HIG "����" HIR "��ң����" NOR);
        set("long", "���������̵Ĺ�����ʹ���ͷ�ң�ϳ���ң���ɵ����С�\n"+
                    "������һ���������Ȼ�������꣬������ȥ��ʮ��Ӣ��������\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen", -15000);
        set("str", 26);
        set("per", 29);
        set("int", 29);
        set("con", 27);
        set("dex", 30);         
        set("max_qi",4000);
        set("max_jing", 3000);
        set("eff_jingli", 3000);
        set("jiali", 80);
        set("combat_exp", 1600000);
        set("level", 40);
        set("no_get",1);
        set("no_quest", 1);
        set("dagger-book", 1);
        set("ling-book", 1);
        
        set_skill("sword",280); 
        set_skill("blade",280);
        set_skill("literate",250);
        set_skill("claw", 280);
        set_skill("strike", 280);
        set_skill("hanbing-mianzhang", 280);
        set_skill("yingzhua-shou", 280);
        set_skill("dodge",280);
        set_skill("force", 280);
        set_skill("qingfu-shenfa", 280);
        set_skill("lieyan-dao",280);
        set_skill("liehuo-jian",280);
        set_skill("shenghuo-shengong", 280);
        set_skill("parry", 280); 
        set_skill("martial-cognize", 200);      
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("sword", "liehuo-jian");
        map_skill("parry", "liehuo-jian");
        map_skill("blade", "lieyan-dao");
        map_skill("claw", "yingzhua-shou");
        map_skill("strike", "hanbing-mianzhang");

        prepare_skill("strike", "hanbing-mianzhang");
        prepare_skill("claw", "yingzhua-shou");
        
        create_family("����", 35, "������ʹ");

        set("inquiry", ([
                "ذ������" : (: dagger :),
                "book" : (: dagger :),
                "������" : (: ask_me :),
                "�����׻�":"��˵�������˴��й�ѧ�����ҩ֮�����Ƴ�һ�ְ�����\n"
                        "�����������׻𵯡����в����Ի�ҩ����ǿ�����ɻ������䡣\n",
        ]));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command("perform strike.jue") :),
                (: command("perform strike.xi") :),                
                (: command("perform claw.xue") :),             
        }));
        
        set("master_ob",4);
	setup(); 
        if (random(10) > 5)
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear();
}


void attempt_apprentice(object ob)
{
        mapping fam = ob->query("family");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 10000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
                
        if (! fam || fam["family_name"] != "����")
        {
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 120) 
        {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }
        if ((int)ob->query_int() < 30) 
        {
                command("say ��ң���ɵ��书�����ӣ�Ҫѧ����Щ�书���ǵ��м��ߵ����ԡ�");
                command("say �����Է��棬"+RANK_D->query_respect(ob)+"�Ƿ񻹲�����");
                return;
        }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title")+"���µ���");
}
 
void init()
{
        object me, ob;
        mapping fam;
        
        ::init();
        ob = this_player();
        me = this_object();  
              
        if (interactive(ob) && ! wizardp(ob)
           && base_name(environment(me))=="/d/mingjiao/longwang"
           && ((fam = ob->query("family")) && fam["family_name"] != "����" ))
        {
                command("say ���������̵��صأ���˵�����ˣ�������������Ҳ��������������Ͽ��뿪�˵أ�");
                command("consider " + ob->query("id"));  
                remove_call_out("kill_ob");
                call_out("kill_ob", 5, ob); 
        }
        
        if (interactive(ob) && ob->query_temp("mj_jiaozhu"))           
                command("nod " + ob->query("id"));   
        else 
                command("hehe " + ob->query("id"));      
}

string dagger()
{
        mapping fam = this_player()->query("family");
        object ob; 
               
        if (! fam || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
                
        if (this_player()->query_skill("dagger", 1) > 101)
                return "���ذ���Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã������������˰�";    
                    
        if (this_player()->query_skill("shenghuo-shengong", 1) < 100)
                return "�������̵�ʱ���ж̣�����ʱ�������ɡ�";
     
        if (this_object()->query("dagger-book") < 1)
                return "�������ˣ��ҵġ�ذ�����ۡ��Ѿ������������ˡ�";     
                         
        ob = new("/clone/book/dagger-book");
        ob->move(this_player());
        
        this_object()->add("dagger_book", -1);
        
        return "�ðɣ�������������ġ�ذ�����ۡ����͸����ˡ�";
}

string ask_me()
{ 
        mapping fam; 
        object ob, *clone;
        int i, j;

        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
                
        if (this_player()->query_skill("shenghuo-shengong", 1) < 100)
                return "�������̵�ʱ���ж̣�û��Ȩ��ʹ�������";
                
        if (! this_player()->query_skill("shenghuo-ling"))
                return "���ֲ�ʹ��������������ʲô��";
                
        ob = present("tieyan ling", this_player());
        if (ob && ob->query_amount() >= 2)
                return "�����϶��Ѿ���ô���ˣ���Ҫ���ʲô��";
                
        if (this_object()->query("ling_book") < 1)       
                return "�������ˣ��������Ѹ�ȫ������ȥ�ˡ�"; 

        ob = new("/d/mingjiao/obj/tieyan-ling");        
        ob->move(this_player());
        
        this_object()->add("ling_book", -1);
        
        return "�ðɣ���������������ȥ�ɣ����㲻Ҫ����Ϊ�񣬶�෢չ�����̽��ڡ�";
}

void reset()
{
        set("ling-book", 1);
        set("dagger-book", 1);
}
