// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhike.c ֪��

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("֪�͵���", ({ "zhike daozhang", "zhike" }));
        set("long", 
                "�����䵱ɽ��֪�͵�����\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
       set("no_get", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);

        set("combat_exp", 7500);
        set("score", 1000);

        set_skill("force", 80);
        set_skill("yinyun-ziqi", 40);
        set_skill("dodge", 80);
        set_skill("strike", 40);
        set_skill("wudang-zhang", 40);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("wudang-jian", 80);
        set_skill("taoism", 20);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        map_skill("strike", "wudang-zhang");

        prepare_skill("strike", "wudang-zhang");


        set("chat_chance",2);
        set("chat_msg", ({
                "֪�͵���˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
                "֪�͵���˵�������������䵱�����Ż����ҵ�һ��Ҫ��������(volunteer)������˿��и����\n"
        }));

        create_family("�䵱��", 4, "����");

        setup();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        ::init();
        add_action("do_volunteer", "volunteer");
}

int do_volunteer()
{
        object me = this_player();
        object *ob;
        object *obs; 
       // int i;

        if (me->query_temp("in_guard")) 
                return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");

        if (me->query("family/family_name") != "�䵱��")
        {
                message_vision("֪�͵������һ������Ϊ���ɵĵ��ӣ�����ô�������أ���\n", me);
                return 1;
        }

	if( environment(this_object())->query("short") != "������" )
        {
                message_vision("��ѽ������ô������ѽ�������Ȼ�ȥ��\n", me);
                return 1;
        }

        if (count_ge(me->query("combat_exp"), 400000))
         {
                message_vision("֪�͵���һҾ�������ҷ���׳ʿ����ֻ\n", me);
                return 1;
        }
        
        ob = all_inventory(environment(me));
        obs = filter_array(ob, 
                           (: interactive($1) && 
                           $1 != $(me) && 
                           $1->query_temp("in_guard") && 
                           environment($1) :)); 

        if (sizeof(obs) > 3)
                return notify_fail("֪�͵�������˵���Ѿ��в�������ɽ���ˣ���һ�������ɡ�\n");

        tell_room(environment(me), me->query("name") + "��ʼ���䵱ɽ��ֵ�ء�\n");
        set("qi", 30000);
        set("jing", 30000);
        me->set_temp("in_guard", 1); 
        
        // remove_call_out("end_guard");
        call_out("end_guard", 150, me);
        // remove_call_out("clone_meng");
        call_out("clone_meng", 30, me);
        return 1;
}

void clone_meng(object me)
{
        object ob;
        int maxskill;
        string maxexp;
        int maxqi;
        
        if (! me) return;

        if (! me->query_temp("in_guard")) 
                return;

        maxskill = me->query_skill("force", 1);
        maxqi = me->query("eff_qi");
        maxexp = me->query("combat_exp");
        
        if (environment(me)->query("short") != "������")
        {
                tell_object(me,"�����䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
                call_out("end_guard", 0, me);
                return;
        }

        tell_room(environment(me), "ɽ��ͻȻ������һ������󺺡�\n");

        ob = new("/d/wudang/npc/mengmian.c");
        if (! me->is_ghost())
        {
                ob->move(environment(me));
        }
        ob->set("combat_exp", maxexp);
        if (maxskill > 5 && count_gt(maxexp, 50000))
        {
                ob->set_skill("kuang-jian", maxskill*2/3);
                ob->set_skill("sword", maxskill*2/3);
                ob->set_skill("parry", maxskill*2/3);
                ob->set_skill("unarmed", maxskill*1/2);
                ob->set_skill("dodge", maxskill*2/3);
        } else 
        {
                ob->set_skill("kuang-jian", 5);
                ob->set_skill("sword", 5);
                ob->set_skill("parry", 5);        
                ob->set_skill("unarmed", 5);
                ob->set_skill("dodge", 5);        
        }
        ob->set("qi",maxqi);        
        ob->set("volunteer_owner", me->query("id"));        

        ob->set("title", HIR "�����" NOR);
        ob->kill_ob(me);
        message_vision(HIR "\n$N����$n���һ����ɱ��!��\n" NOR, ob, me); 
        tell_room(environment(me), "ɽ��ͻȻ������һ������󺺡�\n");
        
        ob = new("/d/wudang/npc/mengmian.c");
        if (! me->is_ghost())
        {
                ob->move(environment(me));
        }

        ob->set("combat_exp", maxexp);
        if (maxskill > 5 && count_gt(maxexp, 50000))
        {
                ob->set_skill("kuang-jian", maxskill);
                ob->set_skill("sword", maxskill);
                ob->set_skill("parry", maxskill);
                ob->set_skill("unarmed", maxskill);
                ob->set_skill("dodge", maxskill);
        } else 
        {
                ob->set_skill("kuang-jian", 5);
                ob->set_skill("sword", 5);
                ob->set_skill("parry", 5);        
                ob->set_skill("unarmed", 5);
                ob->set_skill("dodge", 5);        
         }
        ob->set("qi", maxqi);        
        ob->set("volunteer_owner", me->query("id"));        
        
        ob->set("title", HIR "�����" NOR);
        ob->kill_ob(me);
        me->kill_ob(ob);
        message_vision(HIR "\n$N����$n���һ����ɱ��!��\n" NOR, ob, me); 

        call_out("clone_meng", 100, me);
}

void end_guard(object me)
{
        object *enemys;
        int i;
        if (! me) return;

        remove_call_out("clone_meng");
        if (! me->query_temp("in_guard")) return;

        me->delete_temp("in_guard"); 
        
        if (environment(me)->query("short") == "������")
        {
                 me->add("family/gongji", random(8) + 4);
                me->add("combat_exp", random(220) + 120);
               if (count_gt(me->query("potential"), me->query_potential_limit()))
               me->add("potential", 1);
               else
               me->add("potential", random(50) + 80);
                
                tell_room(environment(me), me->query("name") + "���䵱ɽ��ֵ����������\n");
                tell_object(me, "�����䵱ɽ��ֵ����������\n");
        } else 
        {
                tell_room(environment(me), me->query("name") + "���䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
                tell_object(me, "�����䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
        }
        enemys = children("/d/wudang/npc/mengmian");
        enemys = filter_array(enemys, (: $1->query("volunteer_owner") == $(me->query("id")) :));
        if (sizeof(enemys) > 0)
        {
                for (i = 0; i < sizeof(enemys); i++)
                {
                        if (enemys[i]->is_fighting())
                        {
                                enemys[i]->remove_all_killer();
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "ͻȻ��ɫһ�䣬Ѹ�ٹ������У�����սȦת�����ˡ�\n");
                        }
                        else {
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "��ֵһ�㣬ͻȻ��ɫ��䣬����ææ�������ˡ�\n");
                        }
                        destruct(enemys[i]);
                }
        }
}

void die()
{
        object *me, *enemys;
        int i;

        me = all_inventory(environment());
        
        for (i = 0; i < sizeof(me); i ++)
                me[i]->delete_temp("in_guard"); 

        enemys = children("/d/wudang/npc/mengmian");
        if (sizeof(enemys) > 0)
        {
                for (i = 0; i < sizeof(enemys); i++)
                {
                        if (enemys[i]->is_fighting())
                        {
                                enemys[i]->remove_all_killer();
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "ͻȻ��ɫһ�䣬Ѹ�ٹ������У�����սȦת�����ˡ�\n");
                        }
                        else {
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "��ֵһ�㣬ͻȻ��ɫ��䣬����ææ�������ˡ�\n");
                        }
                        destruct(enemys[i]);
                }
        }
        ::die();
}
