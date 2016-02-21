// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// NPC dai.c ���˿

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("���˿",({"dai qisi","dai","qisi"}));
	set("title", HIG "����" MAG "��������" NOR);
        set("gender","Ů��");
        set("long",  "�������̵��Ĵ󻤷�֮һ������������\n"+
                     "������������ǵ������̵ĵ�һ��Ů��\n"+
                     "�������Ѹߣ��Բ���ɫ�Բ������ꡣ\n");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 24);
        set("int", 40);
        set("con", 26);
        set("dex", 30);        
        set("max_qi", 2800);
        set("max_jing", 2200);
        set("eff_jingli", 2000);
        set("jiali", 10);
        set("combat_exp", 1100000);
        set("level", 30);

        set_skill("throwing",280); 
        set_skill("dodge",240);
        set_skill("force", 240);
        set_skill("duoming-jinhua",280);
        set_skill("literate", 230);
        set_skill("qingfu-shenfa", 240);
        set_skill("shenghuo-shengong", 240);
        set_skill("parry", 240);
        set_skill("claw", 240);
        set_skill("yingzhua-shou", 220);
        set_skill("martial-cognize", 200);   
                
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("throwing", "duoming-jinhua");
        map_skill("parry", "duoming-jinhua");
        map_skill("claw", "yingzhua-shou");
        
        prepare_skill("claw", "yingzhua-shou");
        
        create_family("����", 36, "��������");
        set("master_ob",4);
	setup();
        
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
        carry_object("/d/mingjiao/obj/luopan");
        carry_object("/d/mingjiao/obj/jinhua")->wield();
}

void attempt_apprentice(object ob)
{
        mapping fam = ob->query("family");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 5000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
                
        if (! fam || fam["family_name"] != "����")
        {
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        
        /*
        if(ob->query("gender")!="Ů��"){
                command("say "+RANK_D->query_respect(ob)+"���ǻ�ȥ�ɣ�����ֻ��Ů���ӡ�");
                return;
        }
        */

        if ((int)ob->query_skill("shenghuo-shengong", 1) < 100) 
        {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }
        
        if ((int)ob->query_int() < 28) 
        {
                command("say ��ѧ�ҵĽ𻨰����������ܹ��۹��ķ��������˷���");
                command("say ���������Է��棬"+RANK_D->query_respect(ob)+"�Ƿ��Ӳ��˵㣿");
                return;
        }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ������Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title") + "���½���");
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "����ɻ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/duoming-jinhua/fei",
                           "name"    : "����ɻ�",
                           "sk1"     : "duoming-jinhua",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        default:
                return 0;
        }
}
