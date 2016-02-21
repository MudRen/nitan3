// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��̶Ұ��", ({ "nitan yelao", "yelao" }));
        set("gender", "����");
        set("age", 2100);
        set("title", CYN "��������" NOR);
        set("long", sort_msg(
                "��˵�е�����ǰ������˵������ǧ��ǰ��������룣��ֽ���ǧ����䡣"
                "��Ц��������ǧ�أ����µ��书�����Ÿ����������£�������������"
                "��ʣ��ų��ǡ�������֪��������������һ���书�ǳ����뻯������"
                "���֣�������ǧ��δ�����˶��֡�������һֱ�������ݳ�������Ϊ����"
                "ÿ���ڴ˽������ֵ�ʡ�\n"));        
        set("combat_exp", 30000000);
        set("shen_type", 0);
        set("max_neili", 500000);
        set("neili", 500000);
        set("max_qi",40000);
        set("max_jing",20000);
        set("max_jingli",20000);
        set("jingli",20000);
        set("per",25);
        set("jiali", 400);
        
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("jiuyang-shengong",500);

        set("chat_chance", 2);
        set("chat_msg", ({  
                CYN "Ұ����ɫһ�������Ե��������ɷ���������Ʒ��һ���书�ĸߵ͵�����Σ�\n"
                "�������������壬�Ͷ����ƣ����湶������ؼ��ˣ���\n" NOR
        }));

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob = this_player();

        if (ob->query("slough/inquiry"))
        {
                message_sort(HIC "$N��¶΢Ц����$n��ͷ�������������"
                             "�����鵽ʲôû�У��鵽�˾Ϳ�����ң�answer <����>�� ��\n" NOR,
                             this_object(), ob);
                add_action("do_answer", "answer");
        }
}

int do_answer(string arg)
{
        return SLOUGH_D->do_answer(this_object(), this_player(), arg);
}

mixed accept_ask(object who, string topic) 
{
        switch (topic)
        {
        case "quest": 
        case "��������":
        case "�Ͷ�����":
                return SLOUGH_D->ask_quest(this_object(),  who); 
        default: 
                return 0;
        }
}

int accept_object(object who, object ob) 
{
        return SLOUGH_D->accept_object(this_object(), who, ob); 
}
