// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// peng.c ��Ө��

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("��Ө��", ({ "peng yingyu","peng","yingyu" }) );
	set("title", HIG "����" HIW "�����" NOR);    
        set("gender", "����");
        set("age",51);
        set("class", "bonze");
        set("long","������������ɢ��֮һ���˳�����С�\n");
        set("rank_info/respect","��ʦ");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("per", 12);
        set("max_qi",1500);
        set("max_jing",1200);
        set("jiali",50);
        set("eff_jingli",1100);        
        set("combat_exp", 600000);
        set("level", 10);

        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("literate", 130);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("liehuo-jian", 85);
        set_skill("qingfu-shenfa", 85);
        set_skill("shenghuo-shengong", 80);
        set_skill("hand", 80);
        set_skill("qianye-shou", 85);
        
        map_skill("force","shenghuo-shengong");
        map_skill("hand","qianye-shou");
        map_skill("dodge","qingfu-shenfa");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        prepare_skill("hand", "qianye-shou");

        create_family("����", 36, "��ɢ��");


        set("master_ob",1);
	setup();
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{     
        command("say �����ӷ����գ����գ�ƶɮ����ò��յ����ˡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}
