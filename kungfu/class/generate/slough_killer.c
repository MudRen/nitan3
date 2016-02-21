// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit CLASS_D("generate") + "/chinese";

#include <slough.h>

void random_move();
int  is_stay_in_room()  { return 1; }

void create()
{
        string *long; 
        
        ::create();
        long = query("from");        
        set("gender", "����");
        set("nickname", HIB "ɱ�˿�ħ" NOR);
        set("age", 30 + random(30));
        if (sizeof(long) < 1) 
                set("long", "һ�����ص��ˡ�\n");
        else
                set("long", long[random(sizeof(long))]);
        set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 120);
        set("scale", 150);
        set("no_get", 1);

        set_temp("apply/armor", 100);
        set_temp("apply/damage", 15);
        set_temp("born_time", time());
        set_temp("dest_time", 1500 + time());

        add_money("silver", 10 + random(20));

        if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
              string exp; 
              mapping my; 

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me) -2);
        my = query_entire_dbase();

        if (my["max_qi"] > 6000)
                my["max_qi"] = 6000;

        if (my["max_jing"] < my["max_qi"] / 2)
                my["max_jing"] = my["max_qi"] / 2;

        if (my["max_jing"] > 3000)
                my["max_jing"] = 3000;

        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        my["quest_count"] = me->query("quest_count");

        exp = count_div(count_mul(me->query("combat_exp"), 11), 10);
        if (count_gt(exp, query("combat_exp")))
                set("combat_exp", exp);


        if (count_gt(my["combat_exp"], 5000000) && random(100) < 21)
        {
                // ���� > 200K��21%���ʳ��ֶ������
                set_temp("multi-enemy", 1);
        }

        my["jiali"] = query_skill("force") / 3;
}

void init()
{
        object ob, baixing, env;
        object killer = this_object();      
          
        ob = this_player();
        
        if (! this_object()->query_temp("quester"))
                return;

        if (ob->query("id") == query_temp("quester") &&
            ob->query("slough/check")) 
        {
                killer->fight_ob(ob);
                ob->fight_ob(killer);
                COMBAT_D->do_attack(killer, ob, killer->query_temp("weapon"), 0);
                ob->remove_all_enemy(0);
                killer->remove_all_enemy(0);

                message_vision(
                        HIB "$nһ����$N, ���ɷ�˵�������һ����һ�Ǻ�������֮�󼪣�\n" NOR,
                        ob, killer); 
                        
                tell_object(ob, "�����ڲ���ɱ�˿�ħԭ����" + killer->query("family/family_name") + "�İ��ࡣ\n");

                place_npc(killer, ob);
                ob->set("slough/inquiry", 1);
        } else
        if (ob->query("slough/chased") &&
            ! killer->query("baixing") && ob->query("id") == query_temp("quester"))   
        {
                message_vision(
                        HIB "$nһ����$N����Ц��һ��: ����һ����ò��ͷ��ļһ��Ѱ��·���� \n" NOR,
                        ob, killer);
                        
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());

                remove_call_out("kill_baixing"); 
                call_out("kill_baixing", 1, ob);
        } else
        if (ob->query("slough/chased") &&
            killer->query("baixing") && ob->query("id") == query_temp("quester"))  
        {
                message_sort(
                        HIB "$n��м�س�$N˵��: ��ԭ��������һֱ�ڷ�������ɱ�ˣ�������ɱ���ˣ�"
                        "�������ʬ�ɣ������Ͳ�֪��˭�ܰ�����ʬ�ˣ��� \n" NOR, ob, killer);
                command("heihei " + ob->query("id"));

                this_object()->set_leader(ob);
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
}

void kill_ob(object ob)
{
        int lvl;

        exert_function("powerup");

        if (ob->query("slough/id") != query("id"))
        {
                ::kill_ob(ob);
                return;
        }

        if (lvl = query_temp("multi-enemy"))
        {
                // ���ֶ������
                delete_temp("multi-enemy");
                call_out("do_help_me", 1 + random(2), ob);
        }
        ::kill_ob(ob);
}

void do_help_me(object ob)
{
        if (! objectp(ob) || environment(ob) != environment())
                return;

        switch (random(3))
        {
        case 0:
                message_vision(HIW "\n$N" HIW "�����ȵ�������һ��" +
                               ob->name(1) +
                               HIW "����λ����Ҫ�ٵ��ˣ��������" +
                               RANK_D->query_self(this_object()) +
                               "һ�ѣ���\n" NOR, this_object(), ob);
                break;

        case 1:
                message_vision(HIW "\n$N" HIW "��Ȼ���വ"
                               "�ڣ������˲���΢΢һ㶡�\n" NOR,
                               this_object());
                break;

        case 2:
                message_vision(HIW "\n$N" HIW "һ����Х������"
                               "�಴������ԶԶ�Ĵ��˿�ȥ��\n" NOR,
                               this_object());
                break;
        }

        call_out("do_continue_help", 1 + random(4), ob);
}

void do_continue_help(object ob)
{
        int n;
        object *obs;

        if (! objectp(ob) || environment(ob) != environment())
                return;

        n = random(3) + 1;
        ob->set_temp("slough/help_count", n);
        message("vision", HIR "˵ʱ�٣���ʱ�죡ͻȻת��" +
                          chinese_number(n) +
                          "���ˣ�һ�����ǰ������������"
                          "�з�����\n" NOR, environment());

        // ���ɰ���
        obs = allocate(n);
        while (n--)
        {
                obs[n] = new(CLASS_D("generate") + "/slough_killed.c");
                NPC_D->set_from_me(obs[n], ob, 100);
                obs[n]->delete_temp("multi-enemy");
                obs[n]->set_temp("help_who", this_object());
                obs[n]->set_temp("is_helper", 1);
        }

        // ����ս��
        set_temp("help_ob", obs);
        set_temp("help_count", sizeof(obs));
        obs->move(environment());
        obs->set_leader(this_object());
        obs->kill_ob(ob);
}

void start_kill(object ob)
{
        int t;  
        if(! objectp(ob))
        {
                destruct(this_object());
                return;
        }         
        t = ob->query("combat_exp") / 10000000;
        if (t < 1) t = 1;
        if (t > 5) t = 5;
        
        remove_call_out("kill_baixing");
        call_out("kill_baixing", (t * 90 + 30), ob);
}

int kill_baixing(object ob)
{
        object baixing;

        if (! this_object()->query("baixing")) 
        {
                baixing = new("/quest/quest3/baixing");
                baixing->set("waiting", ob->query("id"));
                baixing->move(environment(this_object()));

                this_object()->set_leader(baixing);
                baixing->set_leader(this_object());
                kill_ob(baixing);
                set("baixing", baixing->query("id")); 
        }
        return 1;
}

int filter_to_bonus(object ob, object aob)
{
        if (! playerp(ob) || ! living(ob) ||
            ! ob->is_killing(query("id")))
                // ��������Ҳ��Ҳ�����ɱ��(NPC)
                return 0;

        // Э���Ķ���һ��
        return (aob == ob->query_temp("quest/assist"));
}

// �������NPC������ʱ�򣬼���Ƿ���Խ��н���ĳЩ��ҡ�����
// �Ķ��󣺰�������������������������ˣ� ��Ȼ����Ҫ��ɱ��
// ��������������ɶ�����ξ�������������жԸ�NPC����ɱ
// �������Э�������������ߵ���ҡ�
void die(object killer)
{
        object *obs;            // ���������п��Խ�����
        object dob;             // �������NPC����
        object hob;             // Э����
        object aob;             // ��Э����
        int qlevel;             // ��������ĵȼ�
        int lvl;                // NPC�ĵȼ�
        int scale;              // NPC���еİ��ֺ����ܵĴ���
        int n;                  // ���Խ������˵���Ŀ
        int exp;                // ��Ҫ�Ϸֵľ���
        int pot;                // ��Ҫ�Ϸֵ�Ǳ��
        int weiwang;            // ��Ҫ�Ϸֵ�����
        int score;              // ��Ҫ�Ϸֵ�����
        int extra_exp;          // ���ε��˵Ķ��⾭��
        int extra_pot;          // ���ε��˵Ķ���Ǳ��
        string quester;         // ��Ҫ��������������ID
        object qob;             // ��Ҫ�������������Ҷ���
        object baixing;

        // �ҵ�ɱ����(NPC)���Ǵ����ҵ���
        if (! objectp(dob = killer))
                dob = query_defeated_by();

        if (objectp(dob) && dob->query_temp("owner"))
                dob = dob->query_temp("owner");

        while (1)
        {
                // ��¼���������Ѿ���ֹ
                if (stringp(quester = query_temp("quester")))
                {
                        qob = UPDATE_D->global_find_player(quester);
                        if (qob->query("slough/id") == query("id"))
                                qob->set("slough/notice", "die");
                        UPDATE_D->global_destruct_player(qob, 1);
                }

                if (dob && dob->query("slough/id") == query("id"))
                        // ���Լ�������
                        break;

                if (dob) aob = dob->query_temp("quest/assist");
                if (aob && aob->query("slough/id") == query("id"))
                        // ��Э������ɱ����
                        break;

                // �����������߻�������������Э������ɱ�������¼֮��
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s����ɱ���ˡ�", name()));

                break;
        }
        
        if (! aob) aob = dob;

        if (! aob)
        {
                remove_call_out("kill_baixing");
                // û���ҵ� QUEST ������
                ::die();
                return;
        }
        
        if (query("baixing") &&
             objectp(baixing = present(query("baixing", environment(this_object())))))
        {
                message_vision(CYN "$N��$n��ʾ���ĵĸ�л��\n" NOR, baixing, dob);
                baixing->command("bye " + dob->query("id"));
                destruct(baixing);
        }        
        
        if (! query_temp("baixing_killed"))
        {
                dob->set("slough/succeed", 1);
                tell_object(dob,
                        HIY "�������׿Խ���֣��ɹ��Ľ���˵��صİ��գ�\n" NOR); 
        }  

        if (dob->query("id") == query_temp("quester") &&
            dob->query("slough/succeed") != 1)
        {
                tell_object(dob,
                        HIW "�������ʧ��δ�ܳɹ�����ܺ����գ�\n" NOR);
        }
        
        // �쿴Ŀǰ����ɱ�ҵ��ˣ��Ƿ�Ҳ��ֵ�ý�����
        obs = all_inventory(environment());
        obs = filter_array(obs, (: filter_to_bonus :), aob);

        if ((n = sizeof(obs)) > 0)
        {
                // ���Ҵ����ҵ��ˣ�����ɱ���ҵ���
                dob = query_defeated_by();

                // ���������أ��ܹ����������е��˷֣����ÿ
                // �˼���һ������������д�������˵���һ�
                // �ö����һЩ������
                lvl = NPC_D->check_level(this_object());
                exp = 15 + random(10) + lvl;
                pot = 9 + random(5) + lvl;
                weiwang = 8 + random(6) + lvl / 2;
                score = 9 + random(6) + lvl / 2;

                // �����������ĵȼ����н�������
                switch (aob->query("slough/level"))
                {
                case 1:
                        break;
                case 2:
                        exp += exp / 2;
                        pot += pot / 2;
                        weiwang += weiwang / 2;
                        score += score / 2;
                        break;
                case 3:
                        exp += exp;
                        pot += pot;
                        weiwang += weiwang;
                        score += score;
                        break;
                default:
                        exp = exp / 2 + 1;
                        pot = pot / 2 + 1;
                        weiwang = weiwang / 2 + 1;
                        score = score / 2 + 1;
                        break;
                }
                // ���NPC�����˰��֣�����Ի�ö��⾭��
                if (scale = sizeof(query_temp("help_count")) > 0)
                {
                        exp += exp * scale;
                        pot += pot * scale;
                }
                // �����˾��־��飺Ϊʲô����n + 2��������Ϊ
                // �����ҵ��˷����ݾ��飬������n + 1���ټ���
                // ��������������1����ô����n + 2��
                exp = exp / (n + 2) + 1;
                pot = pot / (n + 2) + 1;
                weiwang = weiwang / (n + 2) + 1;
                score = score / (n + 2) + 1;

                // ��������ҵĶ��⽱��
                if (objectp(dob) && member_array(dob, obs) != -1)
                {
                        extra_exp = 1 + random(exp);
                        extra_pot = 1 + random(pot);
                        if (count_lt(dob->query("combat_exp"), count_div(query("combat_exp"), 2)))
                        {
                                // ���ֵ����书�Ƚϵͣ���õĶ��⽱����
                                extra_exp *= 2;
                                extra_pot *= 2;
                        } else
                       if (count_gt(dob->query("combat_exp"), count_mul(query("combat_exp"), 2)))
                        {
                                // ���ֵ����书̫�ߣ���õĶ��⽱����
                                extra_exp /= 2;
                                extra_pot /= 2;
                        }
                }

                // ���н���
                foreach (hob in obs)
                {
                        // �����ӳٽ�����Ϊʲô��ô���ã��ܼ򵥣�
                        // ��Ϊ��ϣ������ڿ���NPC�����Ժ���ܹ�
                        // ����������
                        GIFT_D->delay_bonus(hob, ([ "exp"     : exp + random(4) +
                                                    ((hob == dob) ? extra_exp : 0),
                                                    "pot"     : pot + random(3) +
                                                    ((hob == dob) ? extra_pot : 0),
                                                    "weiwang" : weiwang + random(3),
                                                    "score"   : score + random(3),
                                                    "prompt"  : "����" + name() + "֮��" ]));
                }
        }
        
        remove_call_out("kill_baixing");
        // ��������
        ::die();

        return ;
}

int accept_fight(object ob)
{
        command("say �ã����ǾͱȻ��Ȼ���");
        kill_ob(ob);
        return 1;
}

int accept_hit(object ob)
{
        command("say ����ȥ�ɣ�");
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        command("say �ߣ�������");
        return 1;
}

void random_move()
{
        if (query_temp("is_helper"))
        {
                // is a helper
                if (! environment())
                {
                        // not in environment? unavaliable npc.
                        destruct(this_object());
                        return;
                }

                if (! query_temp("help_who"))
                {
                        // owner is killed. destruct this helper
                        if (! living(this_object()))
                                message_vision("$N���������˹�����\n",
                                               this_object());
                        
                        message_vision("$N�������ܣ����Ҵҵ������ˡ�\n",
                                       this_object());
                        destruct(this_object());
                        return;
                }

                // move with owner
                return;
        }

        if (time() > query_temp("dest_time"))
        {
                message_vision("$N����ææ�����ˡ�\n", this_object());
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s���ӵ�����ɽ���󣬴Ӵ˲��ٳ�û�����䡣", name()));
                log_file("static/killed_die", sprintf("%s %s(%s) vanished because timeout(%d:%d).\n",
                                                      log_time(), name(), query("id"),
                                                      time() - query_temp("born_time"),
                                                      query_temp("dest_time") - query_temp("born_time")));
                destruct(this_object());
                return;
        }
        NPC_D->random_move(this_object());
}
