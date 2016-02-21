// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("���ǹ���", ({ "gong zi", "gong" }) );
        set("gender", "����" );
        set("shen_type", -1);
        set("age", 25);
        set("str", 25);
        set("cor", 25);
        set("cps", 25);
        set("int", 25);
        set("long",
        "���Ǹ�ü��Ŀ������깫�ӣ��������Ƿϣ�һ�����Ѭ�ˣ�������ھ�ɫ�����Կ������ӡ�\n" );

        set("combat_exp", 20000);
        set("attitude", "heroism");
        set("chat_chance", 15);
        set("chat_msg", ({
                "����˵��: ���������ڵõ�"HIR"����"NOR"�Ĵ��ұ��ˣ�! \n",
                (: random_move :)
        }) );
        
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "����˵��: �㵱����˱��ӵ��� ? ��֪������˭ ! \n",
                "���Ӻ�Ȼ����һ�����������棬��������;ȴ�ּ�æ���С�\n",
                "����˵��: ���뿪�� ! �Ҳ��ܴ���� !....\n"
        }) );

        set("inquiry", ([
                "����"   : (: ask_me :),
        ]) );

        set_skill("sword", 50);
        set_skill("dodge", 40);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("clone/cloth/cloth")->wear();
}

string ask_me(object who)
{
        int i;
        object *ob;

        if (query("revealed")) 
        {
                if (is_killing(who)) 
                        return "���Ȼ֪�����ҵ����ܣ��������������\n";
                else 
                {
                        kill_ob(who);
                        who->fight_ob(this_object());
                        return "֪�������ܵ��˶��������������ɣ�\n";
                }
        }

        if ((random(10) < 5) || is_fighting())
                return "���......\n";

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",  20);


        message("vision",
                HIY "���ǹ�������ͻȻ�ų����ԵĹ�â��ŭ��˵������С��,��Ȼ���ǹ���������,��ȥ���ɣ���\n"NOR,
                environment(), this_object());
                
        set("title", HIB"����"NOR);
        set_name("����",({ "li si", "li" }));
        carry_object("clone/misc/xiao")->wear();
        set("pursuer", 1);
        set("vendetta/authority", 1);
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("bellicosity", 100);
        set("combat_exp", 1000);
        set("max_qi",100);
        set("max_neili",120);
        set("max_jingli",120);  
        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("tiyunzong", 20);
        set_skill("parry", 10);
        set_skill("sword", 12);
        set_skill("taiji-jian", 20);
        set_skill("taoism", 30);
        set_skill("literate", 40);
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !playerp(ob[i]) ) continue;
                if(count_lt(ob[i]->query("combat_exp",1), 5000))
                        continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
        add_money("silver", 20);
        set("revealed", 1);
        return "����,��Ȼ֪�����ҵ�������͵�����\n";
}

