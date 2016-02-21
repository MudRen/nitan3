// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wufu.c ������

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_yin();

void create()
{
        set_name("������", ({ "yin wushou", "yin", "wushou" }));
        set("title","������ӥ�ֶ�����");
        set("age", 46);
	set("long","������ҵ����ˡ�\n");
	set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("per", 10);
        set("level", 8);
        set("env/wimpy", 80);
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        
        set_skill("dodge",90);
        set_skill("force", 90);
        set_skill("qingfu-shenfa", 90);
        set_skill("shenghuo-shengong", 90);
        set_skill("liehuo-jian",90);
        set_skill("yingzhua-shou",90);
        set_skill("claw",90); 
        set_skill("parry", 90);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        prepare_skill("claw","yingzhua-shou");
        
        set("inquiry", ([
                "����»"   : (: ask_yin :),
                "yin wulu" : (: ask_yin :),
        ]) );
        create_family("����", 38, "����");     
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
        ob->set("title","������΢�ý���");
}

string ask_yin()
{
        object me, ob, where;
        
        me = this_player();
        ob = find_living("yin wulu");
        if (! ob) return "�����������������棬����»�ֺ����˸�ɱ�ˡ�\n";
        
        where = environment(ob);
        if (! where) return "����»�ֺ���Ѳ��ȥ�ˣ���Ҳ��֪�������������\n";
        
        return "�ţ���»�ֺ�����" + where->query("short") + CYN "һ��Ѳ�ߡ�" NOR;        
}
