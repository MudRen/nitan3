// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();

void create()
{
        set_name("��ң",({"fan yao","fan","yao"}));
	set("title", HIG "����" HIR "��ң����" NOR);
        set("long", "���������̵Ĺ�����ʹ�������кϳ���ң���ɵķ�ң��\n"+
                    "������һ���������Ȼ�������꣬������ȥ��ʮ��Ӣ��������\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 26);
        set("per", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 30);
        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 80);
        set("combat_exp", 1500000); 
        set("level", 40);
        set("heiyu", 1);

        set_skill("sword", 270); 
        set_skill("dodge", 270);
        set_skill("force", 270);
        set_skill("blade", 270);
        set_skill("literate", 250);
        set_skill("claw", 270);
        set_skill("strike", 270);
        set_skill("hanbing-mianzhang", 270);
        set_skill("yingzhua-shou", 270);
        set_skill("qingfu-shenfa", 270);
        set_skill("shenghuo-shengong", 270);
        set_skill("lieyan-dao", 270);
        set_skill("liehuo-jian", 270);
        set_skill("parry", 270);
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
                 "���������" : (: ask_me :),
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
                carry_object("/clone/weapon/blade")->wield();
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

string ask_me()
{
        mapping fam; 
        object ob, *clone;
        int i, j;
        
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
                
        if (this_player()->query_skill("shenghuo-shengong", 1) < 50)
                return "�������̵�ʱ���ж̣������������㻹�����ʸ�ʹ�á�\n";
                
        if (this_player()->query_temp("marks/��1"))
                return "�㲻�Ǹ����˺��������������ô��Ҫ��";
                
        if (present("heiyu duanxugao", this_player()))
                return "�����ϲ��Ǵ��ź������������ô��Ҫ��";
                
        if ((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
                return "�����ڲ���Ҫ�ú�������ࡣ";
                
        if (this_object()->query("heiyu") < 1)       
                return "�������ˣ�����������Ѹ�ȫ������ȥ�ˡ�"; 
        
        ob = new("/d/mingjiao/obj/heiyu"); 
        ob->move(this_player());
        this_player()->set_temp("marks/��1", 1);
        this_object()->add("heiyu", -1);
        
        return "�ðɣ���к�������������ȥ�ðɡ�";
}

void reset()
{
        set("heiyu", 1);
}
