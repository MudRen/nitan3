// huang ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "ȭ�Ź���" NOR 
#define MY_OPINION      "unarmed"

#define QUEST_HS_D(x)   ("/quest/quesths/quest/quesths" + x)
#define QUEST_WUGOOD_D  ("/quest/questsj/quest_sj")
#define HSMSG_D         ("/quest/quesths/quest/huangshang-msg")
#define ANTI_ROBOT      "/kungfu/class/ultra/robot"

mixed ask_opinion();
mixed ask_skill();
int give_quest();
int give_up();
void destory(object ob);
string time_period(int timep);

string  *my_opinions = ({ "unarmed", "finger",
                          "strike", "cuff", "hand", "claw" });

string* hs_msg = ({
        "����ͷҲ��̧��˵����",
        "���ѷ���һ������������",
        "���ѵ�ͷ�����룬˵������",
        "��������һ�ݹ��ģ�˵������",
        "����΢΢Ц��Ц������",
});

// ��ͷ�ļ�����������Ƕ��
#include <ultra.h>

void create()
{
        set_name("����", ({ "huang shang", "huang" }) );
        set("title", HIY "����ʦ" NOR);
        set("gender", "����");
        set("age", 92);
        set("long", "�����������ţ��������书�ߵ͡�\n");
        set("attitude", "peaceful");
        set("str", 32);
        set("int", 39);
        set("con", 37);
        set("dex", 32);

        set("max_qi", 20000);
        set("max_jing", 20000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 100);

        set("combat_exp", 50000000);

        set("inquiry", ([
                "�����澭" : "�벻������������д��һ����ѧ�ĵþ���ΪΣ�������Ĳ���֮�",
                "����"     : (: ask_opinion :),
                "opinion"  : (: ask_opinion :),
                "��ѧ����" : "��ѧ����(martial-cognize)�����ң���̸ʲô�书�أ�",                
                "���Ĵ�" : (: ask_skill :),
                "����"     : "���Ժã����Ǹ���Ļ���������������������(quest)��\n",
        ]));

        set_skill("unarmed", 500);
        set_skill("finger", 500);
        set_skill("claw", 500);
        set_skill("strike", 500);
        set_skill("hand", 500);
        set_skill("cuff", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("jiuyin-shengong", 500);
        set_skill("martial-cognize", 500);
        set_skill("literate", 200);

        map_skill("parry", "jiuyin-shengong");
        map_skill("force", "jiuyin-shengong");
        map_skill("dodge", "jiuyin-shengong");
        map_skill("unarmed", "jiuyin-shengong");
        map_skill("finger", "jiuyin-shengong");
        map_skill("strike", "jiuyin-shengong");
        map_skill("hand", "jiuyin-shengong");
        map_skill("cuff", "jiuyin-shengong");
        map_skill("claw", "jiuyin-shengong");

        prepare_skill("claw", "jiuyin-shengong");
        prepare_skill("cuff", "jiuyin-shengong");

        set("opinion/ultra",  1);
        set("opinion/master", 1);

        set("rank_info/self", "ĳ��");

        setup();
        carry_object("/clone/cloth/cloth")->wear();

        set("startroom", "/d/dali/lushui");
        check_clone();
}

void init()
{
        object me;

        if (! interactive(me = this_player()))
                return;

        me->delete_temp("want_opinion");
        if (ultrap(me))
        {
                message_vision(CYN "$N" CYN "΢΢һЦ����$n"
                               CYN "���˵�ͷ��\n" NOR,
                               this_object(), me);
        }
        if( !is_fighting() &&random(5)==0)
        {
        	remove_call_out("greeting");
        	call_out("greeting", 1, me);
        }        
        add_action("give_quest", "quest");
        add_action("give_up","giveup");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(ob->query("quest_hs") && ob->query("shen") < 0)
                write("����˵����" + ob->query("name")+ ",���������ɵ���ô���ˣ�\n");
}

mixed ask_opinion()
{
        object me;
        object ob;

        me = this_player();

        if (count_lt(me->query("combat_exp"), 200000))
                return "�Ǻǣ�������书��̸ʲô���ۣ�";

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
                return "��������ȭ�ŷ������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�����Ҫ��Ҫ�����У�";

        if (is_fighting(me))
                return "��������ʲô������Ӯ���ң����Լ����Լ����۰ɣ�";

        if (me->is_fighting())
                return "��Ȼ���ɣ����Ҹ������ǡ�";

        if (objectp(ob = query_temp("opinion")))
        {
                if (ob == me)
                {
                        command("say ����ʲô������Ҫ���ҡ�");
                        return 1;
                }

                message_vision(CYN "$N" CYN "���ڳ�˼��û�лش�$n"
                               CYN "��ֻ�ǰ��˰��֡�\n" NOR,
                               this_object(), me);
                return 1;
        }

        switch(me->query_temp("want_opinion/huang"))
        {
        case 0:
                command("look " + me->query("id"));
                command("say �ðɣ�����ֹ���һ�У��ҿ������ˮƽ��Ρ�");
                break;
        case 1:
                command("say ����˵������һ���ҿ�����");
                break;
        case 2:
                message_vision(CYN "$N" CYN "��ü��$n" CYN
                               "�������ҿ��������ǹ����µġ���\n" NOR,
                               this_object(), me);
                break;
        case 3:
                command("say ���ұ�������죡");
                return 1;
        }

        me->add_temp("want_opinion/huang", 1);
        return 1;
}

int calc_level(object me, string skill)
{
        int lvl;
        string sp;
        mapping action;

        lvl = me->query_skill(skill, 1) / 2;
        sp = me->query_skill_mapped(skill);
        if (! sp) return lvl;

        lvl += me->query_skill(sp, 1);
        action = SKILL_D(sp)->query_action(me, 0);
        if (mapp(action))
                lvl += (action["force"] + action["attack"] +
                        action["parry"] + action["dodge"] - 150) / 15;
        return lvl;
}

void do_congration(object me)
{
        command("chat ��ϲ��λ" + RANK_D->query_respect(me) + "��������"
                "������ֹ������������Ŭ������");
}

int accept_hit(object me)
{
        if (me->query_temp("want_hit/huang") >= 2)
        {
                command("heng");
                command("say �²���������Ҫ�����Ǿ�ȥ���ɣ�");
                kill_ob(me);
                return 1;
        }

        command("shake");
        command("say ��λ" + RANK_D->query_respect(me) + "��"
                "����֮���м�óȻ���ơ�");
        me->add_temp("want_hit/huang", 1);
        return 0;
}

int accept_fight(object me)
{
        object weapon;

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
        {
                message_vision(CYN "$N" CYN "��ϲ����$n" CYN
                               "�������ܺã������һ�û�к���"
                               "ʦ���ֹ����У����ɣ���\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (! me->query_temp("want_opinion/huang"))
        {
                command("say ƽ���޹ʶ�ʲô�֣�");
                return 0;
        }

        if (objectp(weapon = me->query_temp("weapon")))
        {
                command("say �������е�" + weapon->name() + NOR +
                        CYN "���ҷ��£�" NOR);
                return 0;
        }

        if (me->query("qi") * 100 / me->query("max_qi") < 80||
            me->query("jing") * 100 / me->query("max_jing") < 80)
        {
                command("say ������״̬���ѣ�����Ϣ������˵�ɣ�");
                return 0;
        }

        command("nod");
        COMBAT_D->do_attack(me, this_object(), 0);
        COMBAT_D->do_attack(this_object(), me, 0);

        if (me->query("qi") <= 0)
        {
                message_vision(CYN "\n$N" CYN "ҡҡͷ��$n" CYN
                               "�����������ڵ��书�����Զ����"
                               "��һ�ж��Ӳ�ס����\n" NOR,
                               this_object(), me);
                return notify_fail("����Ҫ�úõ����������ˡ�\n");
        }

        call_out("check_opinion", 2, me);
        set_temp("opinion", me);
        me->delete_temp("want_opinion");
        message_vision(CYN "\n$N" CYN "���ͷ���������ˣ����ȵ�"
                       "������������롣��\n" NOR,
                       this_object(), me);
        return notify_fail("���������ļ������õ�һ�����\n");
}

int accept_kill(object me)
{
        if (count_lt(me->query("combat_exp"), 500000000))
        {
                message_vision(CYN "$N" CYN "��ŭ����������С����"
                               "ʲô�ң����ҹ�����˵��һ�ư�$n" CYN
                               "�����ڵء�\n" NOR, this_object(), me);
                me->unconcious();
                return -1;
        }
        command("sigh");
        command("say �ܺã����껹��û������ʲô�Һ��ҽ����ĸ��֣�");
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("character") != "��������" &&
            me->query("character") != "��ʿ��˫")
        {
                command("say ���ɷ����������ƶ�����һ��Ҫ��"
                        "�����䣬�����Բ��������ˡ�");
                return -1;
        }

        if (skill == "martial-cognize")
                return 1;

        if (! ultrap(me))
        {
                command("say ��ѧ�ҵľ����񹦣��㻹�����ʸ�"
                        "������˴���ʦ��˵�ɣ�");
                return -1;
        }

        if (me->query_skill(skill, 1) >= 180)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }

        if (skill != "jiuyin-shengong")
                return 1;

        if (me->query_temp("can_learn/huang/jiuyin-shengong"))
                return 1;

        me->set_temp("can_learn/huang/jiuyin-shengong", 1);
        command("nod");
        command("say �ܺã��Ҿʹ�������񹦰ɣ��ɲ�Ҫ��������"
                "�ĸ�����");
        return 1;
}

void unconcious()
{
        /*
        message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
                "Ѫ������һ�������Ų�����\n\n" NOR, environment());
        command("chat �գ��գ��գ��Ϸ�ȥҲ��");
        destruct(this_object());
        */
        recover();
        return;
}

mixed ask_skill()
{
        object me;
        
        me = this_player();

        if (me->query("can_perform/jiuyin-shengong/xin"))
        {
             command("say �㲻���Ѿ�������");
             return 1;
        }

        if (! me->query("can_learn/jiuyin-shengong/xin"))
        {               
               message_sort(HIM "\n����̾����������������д��һ����ѧ�ĵã���Ի�������澭��������"
                            "��������о���ѧ֮�ã����Ͼ���ΪΣ�������Ĳ���֮���������ܽ����ϡ�"
                            "�������ռ��뽻�����ң��ұ㴫����С����Ĵ󷨡���\n", me);
               command("tan");

               return "����������Σ�";
        }

        
        if (me->query_skill("jiuyin-shengong", 1) < 240)
        {
               command("say ������񹦻�򻹲������һ����ܴ������У�");
               return 1;
        }
        if (me->query_skill("martial-cognize", 1) < 240)
        {
               command("say ����ѧ�������㣬������ȥ��ĥ��һ�°ɣ�");
               return 1;
        }
        if (  ! me->query("can_perform/jiuyin-shengong/shou")
           || ! me->query("can_perform/jiuyin-shengong/zhi")
           || ! me->query("can_perform/jiuyin-shengong/zhua")
           || ! me->query("can_perform/jiuyin-shengong/zhang") )
        {
               command("shake");
               command("say ���㽫��������������������������Ұɣ�");
               return 1; 
        }

        command("nod");
        command("say �ܺã��ܺã�");
        command("say ��Ȼ�����Ҿʹ������Ĵ󷨣�");
        message_sort(HIC "\n���ѽ�$N" HIC "�������ԣ�����$N" HIC "����С���ֹ��˼��䡣"
                       "���Ѳ�ʱ������������ֵı��飬$N" HIC "�����߿������ã�$N" HIC
                       "һ����Х���������Ƕ�Ȼ��ʧ���������� ����\n", me);
        command("haha");
        
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("jiuyin-shengong"))
                me->improve_skill("jiuyin-shengong", 1500000);
        if (me->can_improve_skill("martial-cognize"))
                me->improve_skill("martial-cognize", 1500000);

        tell_object(me, HIG "��ѧ���ˡ����Ĵ󷨡���\n" NOR);
        me->set("can_perform/jiuyin-shengong/xin", 1);
        return 1;
}
void die()
{
        /*
        message("vision", "\n"HIR + name() + "���һ����������һ����"
                "Ѫ������һ�����ʹ˲�����\n\n" NOR, environment());
        command("chat �Ϸ�ȥҲ��");
        destruct(this_object());
        */
        recover();
        return;
}
/*
int accept_object(object me, object ob) 
{
        if (base_name(ob) != "/clone/lonely/book/zhenjing1"
          && base_name(ob) != "/clone/lonely/book/zhenjing2")
        {
               command("say ��������ֶ�����ʲô��");
               return 0;
        } 
      
        if (base_name(ob) == "/clone/lonely/book/zhenjing1")
        {
               command("nod");
               command("say �ܺã��ܺã�");
               if (me->query("give_zhenjing2"))
               {
                     command("haha");
                     command("say ��Ȼ�����Ҿʹ�����У��������ʱ�����ң�");
                     tell_object(me, HIG "���Ѿ������㡸���Ĵ󷨡���\n" NOR); 
                     me->set("can_learn/jiuyin-shengong/xin", 1);
                     me->delete("give_zhenjing1");
                     me->delete("give_zhenjing2");
                     destruct(ob);
                     return 1;
               }
               me->set("give_zhenjing1", 1);
               command("say ����һ���������澭�²᡹���㾡���ҵ��������ң�");
               destruct(ob);
               return 1;
        } 

        if (base_name(ob) == "/clone/lonely/book/zhenjing2")
        {
               command("nod");
               command("say �ܺã��ܺã�");
               if (me->query("give_zhenjing1"))
               {
                     command("haha");
                     command("say ��Ȼ�����Ҿʹ�����У��������ʱ�����ң�");
                     tell_object(me, HIG "���Ѿ������㡸���Ĵ󷨡���\n" NOR); 
                     me->set("can_learn/jiuyin-shengong/xin", 1);
                     me->delete("give_zhenjing1");
                     me->delete("give_zhenjing2");
                     destruct(ob);
                     return 1;
               }
               me->set("give_zhenjing2", 1);
               command("say ����һ���������澭�ϲ᡹���㾡���ҵ��������ң�");
               destruct(ob);
               return 1;
        } 
 
}
*/

int give_quest()
{
   // mapping quest,qgood,skills,robot_quest;
   mapping quest,qgood,robot_quest;
   // object me,target,thing,npc;
   object me,thing,npc;
   // int i, giveup,tag,want,lev,lev1;
   int i, giveup,tag,want;
    mixed exp;
    int all_lvl,lvl;
    //string msg,*sname,place;
    string msg,place;

    me = this_player();
    exp = me->query("combat_exp");

    if( (me->query("character") != "��������") &&
            (me->query("character") != "��ʿ��˫") &&
           (me->query("character") != "������"))
    {
        write("�������㣺�������Ը���ˣ��������ʲô��\n");
        return 1;
    }
    if( !(me->query("shen") < 0))
    {
        write("���ѿ�����ֻ��ҡͷ�������߽��������ǹ��������������ҽ��������ɱֹɱ����ɱ�Բ������������˰ɣ���\n");
        return 1;
    }
    if (count_lt(exp, 500000))
    {
        write("���Ѷ���˵�����������ڵľ��飬����Ҫ���ĥ������\n");
        return 1;
    }
 
    if ( quest = me->query("quest_hs") )
    {
        write("���Ѷ���˵���Ȱ������ϵ����������˵��\n");
        return 1;
    }
    if (mapp(me->query("quest_dg")))
    {
        write("���Ѷ���˵��������ܵ������㻹û��ɣ�Ī�������Ϸ��ִ�\n");
        return 1;
    }

    giveup = me->query_temp("hs_giveup");
    if((time()-me->query("quesths_giveup_time")) < 20 + giveup*2)
    {
        write("���Ѷ������һ�����������겻�������Ҷ���ı��ֺܲ����⣬�ȷ�ʡһ�����\n");
        return 1;
    }

// ���¸�����
                if (count_le(exp, 600000))         tag = 0;
                else if (count_le(exp, 900000))    tag = 1;
                else if (count_le(exp, 1200000))   tag = 2;
                else if (count_le(exp, 1800000))   tag = 3;
                else if (count_le(exp, 2500000))   tag = 4-random(3);
                else if (count_le(exp, 3200000))   tag = 5-random(3);
                else if (count_le(exp, 4000000))   tag = 6-random(3);
                else
    {
                        if (random(15) == 0 || (count_gt(exp, 10000000) && random(10) == 0))
            tag=8;
        else tag=7-random(3);
    }

    i = me->query("quesths_times");
    if((i > 20 && random(20)==18) || wizardp(me))
    {
        qgood = QUEST_WUGOOD_D->query_good();
        msg = qgood["msg"+random(4)];
        want = random(qgood["max_num"] - qgood["min_num"] + 1) + qgood["min_num"];
	msg = YEL"����΢΢Ц�ţ������˵������������������\n"+
	      msg+"\n"+
              "���뷨Ūһ��"+qgood["name"]+"������ԼҪ "+want+" "+qgood["unit"]+"���ж��ٿ����Ƚ����١�ȥ�գ���\n"NOR;
        write(msg);
        quest = ([ 
                   "id"         : qgood["id"],
                   "name"       : qgood["name"], 
                   "msg"        : msg, 
                   "want"       : want,
                   "type"       : "��", 
                   "check_file" : qgood["check_file"], 
                   "level"      : tag,
                   "bonus"      : 0,
                   "all_bonus"  : 0,
                ]),
        me->set("quest_hs",quest);
        return 1;
    }

    if(tag==8)
    {
            npc = new(CLASS_D("generate") + "/player_npc.c");
                        NPC_D->place_npc(npc, count_lt(me->query("combat_exp"), 500000)  ? ({ "����һ��", "����ɽ", "����", "����" }) :
                                              count_lt(me->query("combat_exp"), 800000) ? ({ "����һ��", "����ɽ", "����" }) : ({"����һ��", "����"}));
            npc->set_from_me(me,1);
            npc->add_temp("apply/attack", npc->query_skill("force") / 3);
            npc->add_temp("apply/dodge", npc->query_skill("force") / 3);
            npc->add_temp("apply/parry", npc->query_skill("force") / 3);
            npc->add_temp("apply/damage", 200 + random(100));
            npc->add_temp("apply/unarmed_damage", 200 + random(100));
            npc->add_temp("apply/armor", 200 + random(300));
            npc->set_temp("quester", me->query("id"));
            npc->set("auto_perform",1);
            NPC_D->random_move(npc);
            NPC_D->random_move(npc);
            NPC_D->random_move(npc);
            place = npc->query("place");

            npc->set("shen", atoi(count_div(npc->query("combat_exp"), 2000)));
            msg="�������������˵����"+npc->name(1)+
                "������ʼ�����޳�֮ͽ���Σ�����֣���˵�������" + 
                place + "����ȥ�������ɣ���\n";

            quest = ([
                "name" : npc->name(1),
                "id"   : npc->query("id"),
                "bonus": (200+random(51)),
                "type" :"ɱ",
                "level":8,
                "chinese_w":place,
                "where":npc->query("startroom"),
                "msg":msg,
		"object":base_name(npc),
            ]);
            tell_object(me,quest["msg"]+"\n");
            me->set("quest_hs",quest);

            return 1;
    }
    else
    {
            if (count_gt(exp, 4000000))
            {
                all_lvl = 0;
                lvl = random(28) + 1;
                for (i = 1;i < 8;i ++)
                {
                    all_lvl += i;
                    if (lvl > all_lvl - i && lvl <= all_lvl)
                    {
                        lvl = i;
                        break;
                    }
                }
            } else lvl = tag;
            while(1)
            {
                quest = QUEST_HS_D(lvl)->query_quesths();
                                if (quest["type"] == "ɱ" || quest["type"] == "��")
                                {
                                        if (! get_object(quest["object"])->is_master())
                                             break;
                                } else
                    break;
            }

/*
    if(undefinedp(quest["msg"]) || quest["msg"] == "")
*/
    switch(quest["type"])
    {
        case "ɱ":
                msg=HSMSG_D->query_hsmsg("ɱ",quest["name"]);
                break;
        case "Ѱ":
                msg=HSMSG_D->query_hsmsg("Ѱ",quest["name"]);
                break;
        case "��":
                npc = new(CLASS_D("generate") + "/hs_target.c");
                        NPC_D->place_npc(npc, count_lt(me->query("combat_exp"), 500000)  ? ({ "����һ��", "����ɽ", "����", "����" }) :
                                              count_lt(me->query("combat_exp"), 800000) ? ({ "����һ��", "����ɽ", "����" }) : ({"����һ��", "����"}));
                NPC_D->set_from_me(npc, me, 100);
                npc->set_temp("quester",me->query("id"));
                NPC_D->random_move(npc);
                NPC_D->random_move(npc);
                NPC_D->random_move(npc);
                place = npc->query("place");
                msg = hs_msg[random(5)]+npc->name(1)+"ȥ�������ͬ��������߲���Ǯ���ط��ֶ���ֶ�β��ã�"
                        "��˵����������"+place+"����ȥ���ԣ�\n���Ҳ�ղ���Ǯ������������"+quest["name"]+"����������Ҫ��ʾ(chushi)һ�¡�";
                thing = new("/quest/quesths/wulin-ling");
                thing->move(me);
                message_vision("���ѽ��������$N��\n",me);
                quest["target"] = npc->query("id");
                break;
        case "��":
                npc = new(CLASS_D("generate") + "/hs_receiver.c");
                        NPC_D->place_npc(npc, count_lt(me->query("combat_exp"), 500000)  ? ({ "����һ��", "����ɽ", "����", "����" }) :
                                              count_lt(me->query("combat_exp"), 800000) ? ({ "����һ��", "����ɽ", "����" }) : ({"����һ��", "����"}));
                NPC_D->set_from_me(npc, me, 100);
                npc->set_temp("quester", me->query("id"));
                NPC_D->random_move(npc);
                NPC_D->random_move(npc);
                NPC_D->random_move(npc);
                place = npc->query("place");
                thing = new(quest["object"]);
                thing->set("send_to",npc->query("id"));
                thing->set("send_from",query("id"));
                thing->set("send_from_name",query("name"));
                msg = hs_msg[random(5)]+"����ҽ�"+thing->name(1)+"����"+npc->name(1)+"����"
                                        "����������"+place+"������ʱ�������ܾ��뿪�ˡ�";
                if (!thing->move(me))
                {
                    thing->move(environment());
                    message_vision("���ѽ�$N���ڵ��ϡ�\n",thing);
                } else message_vision("���ѽ�$N����$n��\n",thing,me);
                quest["thing"] = thing;
                quest["send_to"] = thing->query("send_to");
                break;
    }
    }
    quest["msg"] = msg;
    quest["level"] = tag;
    if (quest["type"] == "ɱ" && random(6) == 3)
    {
        robot_quest = ([]);
        robot_quest = ANTI_ROBOT->get_question();
        msg = "";
        msg += "����֣��˵�������Ҹս�����ͬ�˵Ŀ��������һ�£���ȥ֪ͨһ��" + quest["name"] + NOR"���¿����ǣ�\n";
        me->set_temp("test",robot_quest);
        msg += robot_quest["question"];
        msg += "��ֻ��Ҫ��������"HIR"��ͨ��������ʽ"NOR"���͹�ȥ�����ˣ����͵�ָ���ǣ�whisper��\n";
        quest["type"]   = "��";
        quest["msg"]  = msg;
        quest["answer"] = robot_quest["answer"];
    }

    me->set("quest_hs", quest);
    write(msg + "\n");
    return 1;
}

int accept_object(object me, object ob)
{
   // int rank,exp,pot,score,times,i,tag,all_quest_hs,bonus;
   int exp,pot,score,times,i,tag,all_quest_hs,bonus;
    mapping quest;
    object gold,who,obj;
    string msg;
   // int mar,weiwang,shen,quest_count;
   int mar,weiwang,quest_count;
    mixed special = 0;
    mixed money = 0;
    
    who = this_object();
    
    if( (me->query("character") != "��������") && (me->query("character") != "������") && !(me->query("shen") <0))  
    {
        write("��������������Ǻ��ˣ���\n");
        return 0;
    }
    else if(!(quest = me->query("quest_hs")))
    {
        write("����˵�������޹�����»���������ջء���\n");
        return 0;
    }

    if (ob->query("money_id"))
    {
                if (ob->value() < 500000)
           {
                   tell_object(me,"�����������õĶ���˵����ôһ���Ǯ����������ʲô�����Լ����������ðɣ�\n");
                   return notify_fail("����̧ͷ���죬����˵�����������100���ƽ𣬻����Ҿ��������������\n");
           }
           me->delete("quest_hs");
           tell_object(me,"���ѽӹ����" + ob->name(1) + "��΢΢Ц��Ц����ͷ����������������������˰ɡ�\n");
           destruct(ob);
           return 1;
    }

    if (quest["type"]!="Ѱ"&&quest["type"]!="��"&&quest["type"]!="��"&&quest["type"]!="��")
    {
        write("����˵��������û�н���ȥ�Ҷ������������ջء���\n");
        return 0;
    }
    
    if (userp(ob) || 
        ob->is_item_make() ||
        ob->query_save_file())
    {
        write("���Ѵ�ŭ�����������С�ӣ���Ȼ����ƭ�����������ˣ���������ץ��������\n");
        me->get_into_prison(this_object(), 0, 30);
        log_file( "static/QUEST_DIJIAO", sprintf("%s(%s)(��������)����%s(%s)(%s)����\n", me->query("name"),
             me->query("id"),ob->name(),ob->query("id"),ctime(time()) ) );
        return 1;
    }

    if ( quest["type"] == "��" )
    {
        if ( (string)ob->query_temp("zheng") != me->query("id") )
        {
            write("���ѽӹ�����һ��ŭ������������������ģ�������ƭ���������ߣ���Ľ������������ˣ���\n");
            me->add("weiwang",-weiwang*(random(5)+4)/4);
            if (me->query("weiwang") < 0) me->set("weiwang",0);
            return 0;
        }
    } else if ( quest["type"] == "��" )
    {
        if (!ob->is_receipt() || ob->query("reply_to") != who->query("id"))
        {
            write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
            return 0;
        }
        if ( ob->query("reply_by") != quest["send_to"] )
        {
            write("���ѽӹ���һ������Ȼ��ŭ���������Ż�ִ��˭����ģ���������Ū�ң���\n");
            return 0;
        }
        if ( ob->query("receive_from") != me->query("id") )
        {
            write("���ѽӹ���һ������Ȼ��ŭ���������Ż�ִ�����Լ��õ���ô����������Ū�ң���\n");
            return 0;
        }
    } else if ( quest["type"] == "��" )
    {
        switch( quest["id"] )
        {
            case "HEAD_OBJ":
            case "ARMOR_OBJ":
            case "CLOTH_OBJ":
                if ( !(bonus = quest["check_file"]->check_value(base_name(ob))) )
                {
                    write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                
                if ( !mapp(ob->query("armor_prop")) ||
                     !stringp(ob->query("armor_type")) )
                {
                    write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                quest["bonus"] = bonus;
                break;
            case "SWORD_OBJ":
            case "BLADE_OBJ":
            case "HAMMER_OBJ":
            case "STAFF_OBJ":
                if ( !(bonus = quest["check_file"]->check_value(base_name(ob))) )
                {
                    write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                
                if ( !mapp(ob->query("weapon_prop")) )
                {
                    write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                quest["bonus"] = bonus;
                break;
            default :
                if ( !(bonus = quest["check_file"]->check_value(base_name(ob))) )
                {
                    write("���ѽӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                quest["bonus"] = bonus;
                break;
        }
    } else if ( ob->name(1) != quest["name"] )
    {
        write("����˵�������ⲻ������Ҫ�ġ���\n");
        return 0;
    }

//    message_vision("$N��$n�������ѡ�\n",me,ob);��give��Ϣ�ظ�haiyan
    times = me->query("quesths_times"); //��������
    tag = me->query("quest_hs/level")+1;       //����ȼ�
    if((i=me->query("quesths_times")) < 15)   i = 15 - i;
    else i = 1;
    exp = tag*240 + quest["bonus"]*9;
    if (random(2))
    exp += random(times);
    exp = exp/i;
    
    if (tag > 4 && i > 5)
	exp /= 2;

    if (quest["type"]=="��")
    {
	exp = quest["bonus"]*(tag + 1);
	exp += random(exp/2);
    }

    pot = exp/(2+random(2));
    score = random(exp/20);
    weiwang = random(exp/15);

    if (times + 1 > 200)
	  mar = exp/3 + random(times);
    else mar = 100 + random(100);

    if (mar > 3000) mar = 3000;

    if(quest["type"]=="��")
    {
        if((int)quest["want"]>(quest["ok"]+1))
        {
            me->add("quest_hs/ok",1);
            write("���ѽӹ������ͷ˵������ "+quest["ok"]+" �ˣ��ܺã����� "+(quest["want"]-quest["ok"])+" ��������Ŭ������\n");
            exp /= 2;
            pot /= 2;
            mar /= 2;
            weiwang /= 2;
            score /= 3;
            QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "mar" : mar, 
                                  "weiwang" : weiwang, "score" : score]), 1);
            me->add("quest_hs/all_bonus", exp);
            destruct(ob);
            return 1;
        }
        exp += quest["all_bonus"]/2;
        pot = exp/(2+random(2));
        weiwang = random(exp/15);
        mar = mar*2;
        mar += mar/4 * quest["want"];
        score = score;
    }
    write("���ѽӹ���˵�������ܺã������������ɵò�����\n");
    destruct(ob);

    if (quest["type"]=="��" && objectp(obj = present("wulin ling", me)))
	destruct(obj);

    if(!random(10))
    {
        i=(exp/60+1);
        if(i>30) i=30;
        gold=new("/clone/money/gold");
        gold->set_amount(i);
        tell_object(me,"Ȼ��ȡ��һ���ƽ���㣺����ν���Щ���ӣ��´μ���Ŭ������\n"
                       HIW"\n�㱻������ "+i+" ���ƽ�\n");
        if(!gold->move(me))
        {
            message_vision("����$N���϶���̫�أ��ƽ�һ���Ӵ����л����˵��ϡ�\n",me);
            gold->move(environment());
        }
        QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "mar" : mar,
                            "weiwang" : weiwang, "score" : score, "percent" : 50 ]), 1);
    }
    else QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "mar" : mar,
                              "weiwang" : weiwang, "score" : score ]), 1);
    
    if ( times < 1 )
        me->set("quesths_times",1);
    else
        me->add("quesths_times",1);
        me->set_temp("hs_giveup",0);        

   me->add("total_hatred",-5);
   if (me->query("total_hatred") < 0) me->set("total_hatred",0);

   quest_count = me->query("quesths_times")%500;
   if (quest_count == 50)
   {
       msg = "$N�Ǻ�Ц�������������㻹���ԣ�����"+chinese_number(me->query("quesths_times"))+
       "��������ɵ�ƯƯ����������Ŭ������\n";
	special = 1;
	   } else
       if (quest_count == 100)
   { 
       msg = "$NЦ�ĺϲ�£�죬������һ�۵�������־����"+chinese_number(me->query("quesths_times"))+
       "������ɵøɾ���������\n";
       special = "/d/shaolin/obj/puti-zi";
   } else
    if (quest_count == 150)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else
    if (quest_count == 200)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else
    if (quest_count == 250)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else

    if (quest_count == 300)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
	 special = "/clone/gift/tianxiang";
    } else
    if (quest_count == 350)
    {
        msg = "$N����һ��������������ĺ��ʺ�ѧ�䣬������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
	 special = "/clone/gift/tianxiang";
    } else
    if (quest_count == 400)
    {
        msg = "$N̾����������һ����ѧ��Ű����벻�������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
         special = "/clone/gift/jiuzhuan";
    } else
    if (quest_count == 450)
        {
        msg = "$N����������������ţ�������ţ�����������"+chinese_number(me->query("quesths_times"))+
               "��������һ��©�����ף����ף���\n";
        special = "/clone/gift/jiuzhuan";
    } else
       if (quest_count == 0)
   {
       msg = "$N����̾�˿�����������û�뵽������"+chinese_number(me->query("quesths_times"))+
       "��������һʧ�֣������Ժ����������Щ��������������\n";
       special = "/clone/gift/xuanhuang";
   } else
       if ((quest_count % 10) == 0)
   {
       msg = "$N΢΢��ͷ�����ɵĲ�����Ȼ����" +
       chinese_number(me->query("quesths_times")) +
       "�ζ�û��ʧ�֣�������������ɣ���\n";
   }
   if (special) {
       // message_vision(msg, who, me);
       QUEST_D->special_bonus(who, me, special);
   }
    if (money) {
        // message_vision(msg, who, me);
        QUEST_D->money_bonus(who, me, money);
    }

    me->delete("quest_hs");

   //��¼�������Ĵ�������Ҫ���������������1000������ˮ����Ƭ
   all_quest_hs = (int)me->query("all_quest_hs");
   if (!all_quest_hs) all_quest_hs = 0;
   all_quest_hs += 1;
   if (all_quest_hs == 1000)
   {
       obj = new("/clone/enchase/GRNjewel.c");
       tell_object(me,this_object()->name() + "�ֶ�����˵�ͷ�����Ѿ������������һǧ����������������\n" +
                   "�и�" + obj->query("name") + "���ͽ������ˣ�\n");
       if (!obj->move(me))
               obj->move(environment());
       me->set("all_quest_hs",0);
   } else me->set("all_quest_hs",all_quest_hs);
   return 1;
}

int give_up()
{
    //object me,ob,obj;
    object me,ob;
    int giveup,rank;
    mapping quest;
    
    me = this_player();
    if( me->query("quest_hs")) 
    {
    if( (me->query("character") != "��������") && (me->query("character") != "������") && !(me->query("shen") <0))  
        return 1;
    }
    if((quest =  me->query("quest_hs")))
    {
        message_vision("$Nսս�������ߵ�������ǰ�����С�ĸ���������������������......��\n",me);
        if (quest["type"] == "��")
        {
                message_vision("$N����üͷ��$n˵���������Ǵ�һ������ô������ô�ѣ���ȥ��ϸ���룬�������һ��Ҫ��ɣ�\n",this_object(),me);
                return 1;
        }
        if (quest["type"] == "��")
        {
               if (ob = present("wulin ling",me))
               {
                        ob->move("/d/register/prison");
                        destruct(ob);
               }
        }
        if (quest["type"] == "��")
        {
                if (objectp(ob = quest["thing"]))
                {
                        ob->move("/d/register/prison");
                        destruct(ob);
                }
        }
        message_vision("���Ѷ�$N̾��һ����: ��ô�������Խ��ô�򵥵����鶼�����ˡ�\n", me);
        
        if (quest["type"] == "��")
        {
                me->delete("quest_hs");
                return 1;
        }
        rank = me->query("quest_hs/level");
        me->add("weiwang",-(rank*6+random(rank+4)));
        if ( me->query("weiwang")<0 )
               me->set("weiwang",0);
        write("���Ѹ����㣺����Ľ������������ˣ���\n");

        me->set("quesths_times",0);

        giveup = me->query_temp("hs_giveup");
        if ( giveup < 1 )
            me->set_temp("hs_giveup",1);
        else if ( giveup < 5 )
            me->set_temp("hs_giveup",giveup+1);
        else me->set_temp("hs_giveup",5);

        me->set("quesths_giveup_time",time());
   
        me->delete("quest_hs");
    }
    else
        write("���Ѹ����㣺��Ŀǰû���κ�����\n");
    return 1;
}

string time_period(int timep)
{
    int t, d, h, m, s;
    string time;
    t = timep;
    s = t % 60;             t /= 60;
    m = t % 60;             t /= 60;
    h = t % 24;             t /= 24;
    d = t;
 
    if(d) time = chinese_number(d) + "��";
    else time = "";
 
    if(h) time += chinese_number(h) + "Сʱ";
    if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
    return time;
}

void destory(object ob)
{
    if(!ob) return;
    if(ob->is_character())
        message_vision("$NͻȻһ���̵��ܵ�ûӰ�ˡ�\n",ob);
    ob->move("/d/wizard/wizard_room");
    destruct(ob);
    return ;
}
