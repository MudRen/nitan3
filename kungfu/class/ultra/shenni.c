// shenni �Ϻ�����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;


#define ULTRA_OPINION   "��ʦ"
#define OPINION_TYPE    HIY "�ڼҹ���" NOR 
#define MY_OPINION      "force"

#define QUEST_SN_D(x)   ("/quest/questsn/quest/questsn" + x)
#define QUEST_WUGOOD_D  ("/quest/questsj/quest_sj")
#define SNMSG_D         ("/quest/questsn/quest/shenni-msg")
#define ANTI_ROBOT      "/kungfu/class/ultra/robot"

mixed ask_opinion();
int give_quest();
int give_up();
void destory(object ob);
string time_period(int timep);

string* sn_msg = ({
        "�Ϻ�����΢Ц��˵����",
        "�Ϻ���������۾�ڤ˼Ƭ�̵�����",
        "�Ϻ������ͷ�����룬˵������",
        "�Ϻ������������֣�˵������",
        "�Ϻ�����΢΢Ц��Ц������",
});

string* qin_msg1 = ({
        "���������ǵ����ѣ�����name����Ӱ������̬������������Ҳ�Ϳ����ˣ�",
        "����˵name����ķ�ֳ��Ӱ���˵��ص���̬���������ǲ�Ӧ�����ɱ���",
        "�ѵ�nameҲ�����������鷳������ϡ�棬�ҵ����뿴������",
        "������Ļ�԰���źܶ�Ķ������û��name��",
        "�ڿ��е�ʱ�򣬿�������������ܹ�����������name��ʵͦ�ɰ��ģ�",
        "���������һ����ϲ��������ˣ�������name�������͸�����������ò�����",
        "�����ϴ��ɱɱ�ģ��ٲ�����nameҲ�����޹����ۣ������ı�������",
});

string* qin_msg2 = ({
        "��ȥ���������������ɡ���",
        "ȥ�ҵ�����������������",
        "���ܰ�������������ô����",
        "�������һ��ȥ���Ұ��������ɡ���",
        "����Ū�����ҡ���",
});

string  *my_opinions = ({ "force" });

// ��ͷ�ļ�����������Ƕ��
#include <ultra.h>

void create()
{
        set_name("�Ϻ�����", ({ "nanhai shenni", "shenni", "nanhai" }) );
        set("title", HIG "����ʦ" NOR);
        set("gender", "Ů��");
        set("age", 91);
        set("long", "����һλ�������ᣬ��������ʲô��ͬ��\n");
        set("attitude", "peaceful");
        set("class", "bonze");
        set("str", 30);
        set("int", 37);
        set("con", 39);
        set("dex", 33);

        set("max_qi", 9999);
        set("max_jing", 9999);
        set("neili", 9999);
        set("max_neili", 9999);
        set("jiali", 70);

        set("combat_exp", 50000000);

        set("inquiry", ([
                "��ָ��ͨ" : "�����ұ̺��񹦹���ָ������ı仯�������ҵ��������������ڸ�һ�ˡ�",
                "����"     : (: ask_opinion :),
                "opinion"  : (: ask_opinion :),
                "��ѧ����" : "�ú�����Լ�����ѧ����(martial-cognize)����ʱ��ʲô�书����С���ƣ�",
                "����" : "�����׺ݵ����������ɵ��ˣ�������������������(quest)��\n",
        ]));

        set_skill("strike", 500);
        set_skill("finger", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("staff", 500);
        set_skill("bluesea-force", 500);
        set_skill("martial-cognize", 500);
        set_skill("literate", 220);

        map_skill("parry", "bluesea-force");
        map_skill("force", "bluesea-force");
        map_skill("dodge", "bluesea-force");
        map_skill("finger", "bluesea-force");
        map_skill("strike", "bluesea-force");
        map_skill("staff", "bluesea-force");

        prepare_skill("finger", "bluesea-force");
        prepare_skill("strike", "bluesea-force");

        set("opinion/ultra",  1);
        set("opinion/master", 1);

        set("rank_info/self", "����");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/zhubang")->wield();

        set("startroom", "/d/xiakedao/zhuwu2");
        check_clone();
}

void init()
{
        object me;

        if (! interactive(me = this_player()))
                return;

        me->delete_temp("want_opinion");
        if (ultrap(me))
                message_vision("$Nü��΢΢һ����\n", this_object(), me);        
        add_action("give_quest", "quest");
        add_action("give_up","giveup");
}

mixed ask_opinion()
{
        object me;
        object ob;

        me = this_player();

        if (count_lt(me->query("combat_exp"), 200000))
                return "�ߣ�������书Ҳ�����������ۣ�";

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
                return "�����ˣ����ڹ��������Ϊ�Ѿ��Ƶ�������ʦ�ˣ�Ҫ�Ǻ�ƶ����ϼ���Ҳ����";

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

                message_vision("$N��Ϊ��ŭ�Ķ�$n������û������æ���𣿡�\n",
                               this_object(), me);
                return 1;
        }

        switch(me->query_temp("want_opinion/shenni"))
        {
        case 0:
                command("say �ðɣ����ǹ�һ�У�����һ��������");
                break;
        case 1:
                command("say ��׼����û�У����˾����ɡ�");
                break;
        case 2:
                message_vision(CYN "$N" CYN "��ü��$n" CYN
                               "�������ҿ��������ǹ����µġ���\n" NOR,
                               this_object(), me);
                break;
        case 3:
                command("say ����ұ���������죡");
                return 1;
        }

        me->add_temp("want_opinion/shenni", 1);
        return 1;
}

int calc_level(object me, string skill)
{
        int lvl;
        string sp;

        lvl = me->query_skill(skill, 1) / 2;
        sp = me->query_skill_mapped(skill);
        if (! sp) return lvl;

	lvl += me->query_skill(sp, 1);
        if (me->query("max_neili") > 4000) lvl += 20;
        return lvl;
}

void do_congration(object me)
{
        command("chat �����������ǲ���");
}

int accept_hit(object me)
{
        command("heng");
        command("say �����" + RANK_D->query_rude(me) + "���������ҵ������ˣ�");
        kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        //object weapon;

        if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
        {
                message_vision("$N��$n�������ܺã���Ҳ������ʦ�����ˣ�"
                               "���ɣ����ǱȻ�һ�£���\n",
                               this_object(), me);
                return 1;
        }

        if (! me->query_temp("want_opinion/shenni"))
        {
                command("say ���ʲôҪ���Ҷ��֣�");
                return 0;
        }

        command("look " + me->query("id"));

        COMBAT_D->do_attack(this_object(), me, 0);

        if (me->query("qi") <= 0)
        {
                message_vision("\n$Nҡҡͷ��$n�����������ڵ��书"
                               "�����Զ������һ�ж��Ӳ�ס����\n",
                               this_object(), me);
                return notify_fail("����Ҫ�úõ����������ˡ�\n");
        }

        message_combatd("$N�������������$n������ԣ�����ͬʱ����������"
                       "��һ���ֻ������ͷ����������������\n��Ȼ$N����"
                       "һ�����ջع�����û��һ�����ͣ�������$n��Ϊ�Ȼ��\n",
                       this_object(), me);
        if (me->query("neili") < 3000)
        {
                message_vision("$Nҡҡͷ��$n�������ʲ����������㣬����"
                               "�Ժ��������㽫�����������������ɣ���\n",
                               this_object(), me);
                return notify_fail("�������ǻ�ȥ����һ�������ɣ�\n");
        }
        me->set("neili", 0);
        

        call_out("check_opinion", 2, me);
        set_temp("opinion", me);
        me->delete_temp("want_opinion");
        message_vision("\n$Nһ���ֵ��������ˣ��������롣��\n",
                       this_object(), me);
        return notify_fail("���������ļ������õ�һ�����\n");
}

int accept_kill(object me)
{
        if (count_lt(me->query("combat_exp"), 500000000))
        {
                message_vision("$N��ŭ����������С����ʲô"
                               "�ң����ҹ�����˵��һ�ư�$n�����ڵء�\n",
                               this_object(), me);
                me->unconcious();
                return -1;
        }
        command("sigh");
        command("say �ܺã����껹��û������ʲô�Һ��ҽ����ĸ��֣�");
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("character") != "�ĺ�����" && me->query("character") != "��ʿ��˫")
        {
                command("say ���������Բ����������²��˺��ģ�"
                        "��û����Ȥ���㣡");
                return -1;
        }

	if (skill == "martial-cognize")
		return 1;

        if (! ultrap(me))
        {
                command("say ��ѧ�ҵı̺��񹦣��㻹�����ʸ�"
                        "������˴���ʦ��˵�ɣ�");
                return -1;
        }

        if (me->query_skill(skill, 1) >= 180)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }

        if (skill != "bluesea-force")
                return 1;

        if (me->query_temp("can_learn/shenni/bluesea-force"))
                return 1;

        me->set_temp("can_learn/dugu/bluesea-force", 1);
        command("nod");
        command("say �����ҽ����ҵľ�ѧ�̺��񹦣��ܲ���ѧ��"
                "�Ϳ�����컯�ˣ�");
        return 1;
}

void unconcious()
{
        /*
        message("vision", "\n"HIR + name() + "��ɫһ�䣬����һ����"
                "Ѫ������һ�������Ų�����\n\n" NOR, environment());
        command("chat �գ��գ��գ�ƶ��ȥҲ��");
        destruct(this_object());
        */
        recover();
        return;
}

void die()
{
        /*
        message("vision", "\n"HIR + name() + "���һ����������һ����"
                "Ѫ������һ�����ʹ˲�����\n\n" NOR, environment());
        command("chat ƶ��ȥҲ��");
        destruct(this_object());
        */
        recover();
        return;
}

int give_quest()
{
    //mapping quest,qgood,skills,robot_quest;
    mapping quest,qgood,robot_quest;
    //object me,target,thing,npc,the_ob;
    object me,thing,npc;
    //int i, giveup,tag,want,lev,lev1,time;
    int i, giveup,tag,want;
    mixed exp;
    int lvl,all_lvl;
    //string msg,*sname,place,the_race;
    string msg,place;

    me = this_player();
    exp = me->query("combat_exp");

    if( (me->query("character") != "���ռ�թ") && 
            (me->query("character") != "��ʿ��˫") &&
            (me->query("character") != "�ĺ�����"))
    {
        write("�Ϻ�����ҡͷ������������ʵ��������½��������̫�����Ĵ������������ұ���Ҫ����ɡ�\n");
        return 1;
    }
    /*
    if( !(me->query("shen") > 0))
    {
        write("�Ϻ����ῴ����ֻ��ҡͷ�������߽���������Ҫ������Ȼ�ҽ�����ɱֹɱ��������а��̫�أ��������˰ɣ���\n");
        return 1;
    }
    */
    if(count_lt(exp, 500000))
    {
        write("�Ϻ�����΢Ц������������Դ����������ڵľ��飬��������ʵ��̫��Σ�գ��ú�ȥ������������ͷ�������ҡ�\n");
        return 1;
    }

 
    if ( quest = me->query("quest_sn") )
    {
        write("�Ϻ�����Ǻ�Ц��˵���ļ����ǺȲ������డ����Ҫ�ż�����������\n");
        return 1;
    }

    if (mapp(me->query("quest_kh")))
    {
        write("�Ϻ�����΢΢һ��˵������̫�಻�Ǹ�����������ô��Ҫ���㻹���������ͷ������ɡ�\n");
        return 1;
    }


    giveup = me->query_temp("sn_giveup");
    if((time()-me->query("questsn_giveup_time")) < 20 + giveup*2 &&!wizardp(me))
    {
        write("�Ϻ�����Ц�Ŷ���˵��������ô�겻��������ô��˳������Ҫ�ż����Ⱥú�����ԭ�������\n");
        return 1;
    }


    quest = ([]);
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

    i = me->query("questsn_times");
    if((i > 20 && random(20)==18) || wizardp(me))
    {
        qgood = QUEST_WUGOOD_D->query_good();
        msg = qgood["msg"+random(4)];
        want = random(qgood["max_num"] - qgood["min_num"] + 1) + qgood["min_num"];
	msg = YEL"�Ϻ�����ǺǴ�Ц�����˵�˵��������İ��������治����\n"+msg
            +"\n���뷨Ūһ��"+qgood["name"]+"������ԼҪ "+want+" "+qgood["unit"]+"���ж��ٿ����Ƚ����١�ȥ�գ���\n"NOR;
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
        me->set("quest_sn",quest);
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

            npc->set("shen", -atoi(count_div(npc->query("combat_exp"), 2000)));
            msg="�Ϻ��������ݶ���˵����"+npc->name(1)+
                "���������Σ�����֣���˵�������" + 
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
            me->set("quest_sn",quest);

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
                quest = QUEST_SN_D(lvl)->query_quest();
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
        case "��":
                msg = sn_msg[random(sizeof(sn_msg))] + replace_string(qin_msg1[random(sizeof(qin_msg1))],"name",quest["name"]) + qin_msg2[random(sizeof(qin_msg2))];
                break;
        case "ɱ":
                if (quest["object"]->query("race") != "����")
                {
                        quest["type"] = "��";
                        msg = sn_msg[random(sizeof(sn_msg))] + replace_string(qin_msg1[random(sizeof(qin_msg1))],"name",quest["name"]) + qin_msg2[random(sizeof(qin_msg2))];
                        break;
                } else msg=SNMSG_D->query_snmsg("ɱ",quest["name"]);
                break;
        case "Ѱ":
                msg=SNMSG_D->query_snmsg("Ѱ",quest["name"]);
                break;
        case "��":
                npc = new(CLASS_D("generate") + "/sn_receiver.c");
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
                msg = sn_msg[random(5)]+"�㿴�ܷ���ҽ�"+thing->name(1)+"����"+npc->name(1)+"����"
                                        "����������"+place+"���Ͻ�ȥ����Ȼ����ʱ�������ܾͲ����ˡ�";
                if (!thing->move(me))
                {
                    thing->move(environment());
                    message_vision("�Ϻ����Ὣ$N������ڵ��ϡ�\n",thing);
                } else message_vision("�Ϻ����Ὣ$N����$n��\n",thing,me);
                quest["thing"] = thing;
                quest["send_to"] = thing->query("send_to");
                break;
    }
    }
    quest["msg"] = msg;
    quest["level"] = tag;
    if (quest["type"] == "ɱ" && (random(6) == 3 || wizardp(me)))
    {
        robot_quest = ANTI_ROBOT->get_question();
        msg = "�Ϻ�����΢Ц��˵�������Ҹս�����ͬ�˵Ŀ��������һ�£���ȥ֪ͨһ��" + quest["name"] + NOR"���¿����ǣ�\n";
        msg += robot_quest["question"];
        msg += "��ֻ��Ҫ��������"HIR"��ͨ��������ʽ"NOR"���͹�ȥ�����ˣ����͵�ָ���ǣ�whisper��\n";
        quest["type"]   = "��";
        quest["msg"]  = msg;
        quest["answer"] = robot_quest["answer"];
    }

    me->set("quest_sn", quest);
    if(stringp(quest["msg"])&&quest["msg"]!="")
                write(YEL""+quest["msg"]+"\n"NOR);
    else
    {
                write(YEL""+msg+"\n"NOR);
                me->set("quest_sn/msg", msg);
    }
    return 1;
}

int accept_object(object me, object ob)
{
    //int rank,exp,pot,score,times, i,tag,all_quest_sn, bonus;
    int exp,pot,score,times, i,tag,all_quest_sn, bonus;
    mapping quest;
    object gold,who,obj;
    string msg;
    //int mar,weiwang,shen,quest_count;
    int mar,weiwang,quest_count;
    mixed special = 0;
    mixed money = 0;
    
    who = this_object();
    
    if( (me->query("character") != "���ռ�թ") && (me->query("character") != "�ĺ�����") && !(me->query("shen") > 0))  
    {
        write("�Ϻ����ᾪ�ȵĵ���������˭���������������ʲô����\n");
        return 0;
    }
    else if(!(quest = me->query("quest_sn")))
    {
        write("�Ϻ�����Ǻ�Ц��������֪������Т���ң����ǿ��Կ�ʵ���ж�������㻹���Լ����Űɡ���\n");
        return 0;
    }

    if(ob->query("money_id"))
    {
           if (ob->value() < 500000)
           {
                   tell_object(me,"�Ϻ�����Ǻ�һЦ���Ҳ�ȱǮ���������Ǯ�����Լ����������԰ɡ�\n");
                   return notify_fail("�Ϻ���������˵�����������100���ƽ��Ҿ�ȡ�����������\n");
           }
           me->delete("quest_sn");
           tell_object(me,"�Ϻ��������ַ���" + ob->name(1) + "���������˵��������������������˰ɡ�\n");
           destruct(ob);
           return 1;
    }

    if(quest["type"]!="Ѱ"&&quest["type"]!="��"&&quest["type"]!="��"&&quest["type"]!="��")
    {
        write("�Ϻ�����΢Ц��������û�н���ȥ�Ҷ���ѽ���������ջء���\n");
        return 0;
    }

    if (userp(ob) || 
        ob->is_item_make() ||
        ob->query_save_file())
    {
        write("�Ϻ������ŭ�����������С�ӣ���Ȼ����ƭ�������������ˣ���������ץ��������\n");
        me->get_into_prison(this_object(), 0, 30);
        log_file( "static/QUEST_DIJIAO", sprintf("%s(%s)(��������)����%s(%s)(%s)����\n", me->query("name"),
             me->query("id"),ob->name(),ob->query("id"),ctime(time()) ) );
        return 1;
    }

    if ( quest["type"] == "��" )
    {
        if (!ob->is_receipt() || ob->query("reply_to") != who->query("id"))
        {
            write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
            return 0;
        }
        if ( ob->query("reply_by") != quest["send_to"] )
        {
            write("�Ϻ�����ӹ���һ������ü���������Ż�ִ��˭����ģ���������Ū�ң���\n");
            return 0;
        }
        if ( ob->query("receive_from") != me->query("id") )
        {
            write("�Ϻ�����ӹ���һ������ü���������Ż�ִ�����Լ��õ���ô����������Ū�ң���\n");
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
                    write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                
                if ( !mapp(ob->query("armor_prop")) ||
                     !stringp(ob->query("armor_type")) )
                {
                    write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
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
                    write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                
                if ( !mapp(ob->query("weapon_prop")) )
                {
                    write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                quest["bonus"] = bonus;
                break;
            default :
                if ( !(bonus = quest["check_file"]->check_value(base_name(ob))) )
                {
                    write("�Ϻ�����ӹ���һ������ü���������������ո�ʲô����\n");
                    return 0;
                }
                quest["bonus"] = bonus;
                break;
        }
    } else if ( ob->name(1) != quest["name"] )
    {
        write("�Ϻ�����˵�������ⲻ������Ҫ�ġ���\n");
        return 0;
    }

//    message_vision("$N��$n�����Ϻ����ᡣ\n",me,ob);��give��Ϣ�ظ�haiyan
    times = me->query("questsn_times"); //��������
    tag = me->query("quest_sn/level")+1;       //����ȼ�
    if((i=me->query("questsn_times")) < 15)   i =15-i;
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
            me->add("quest_sn/ok",1);
            write("�Ϻ�����ӹ������˵�˵������Ҫ�ľ���������� "+quest["ok"]+" �ˣ�̫���ˣ����� "+(quest["want"]-quest["ok"])+" ��������Ŭ������\n");
            score /= 3;
            exp /= 2;
            pot /= 2;
            mar /= 2;
            weiwang /= 2;
            QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "mar" : mar, 
                                  "weiwang" : weiwang, "score" : score]), 1);
            me->add("quest_sn/all_bonus", exp);
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
    write("�Ϻ�����ӹ������ĵ�Ц��˵��������ѽ�������������ɵúܺã���\n");
    destruct(ob);
    if(!random(10))
    {
        i=(exp/60+1);
        if(i>30) i=30;
        gold=new("/clone/money/gold");
        gold->set_amount(i);
        tell_object(me,"Ȼ��ȡ��һ���ƽ���㣺�����߽�����������Ҫ����Ǯ����������Щ���ӣ�����ȥ�ðɣ���\n"
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
        me->set("questsn_times",1);
    else
        me->add("questsn_times",1);
   me->set_temp("sn_giveup",0);        

   me->add("total_hatred",-5);
   if (me->query("total_hatred") < 0) me->set("total_hatred",0);

   quest_count = me->query("questsn_times")%500;
   if (quest_count == 50)
   {
       msg = "$N�Ǻ�Ц�������������㻹���ԣ�����"+chinese_number(me->query("questsn_times"))+
       "��������ɵ�ƯƯ����������Ŭ������\n";
	special = 1;
	   } else
       if (quest_count == 100)
   { 
       msg = "$NЦ�ĺϲ�£�죬������һ�۵�������־����"+chinese_number(me->query("questsn_times"))+
       "������ɵøɾ���������\n";
       special = "/d/shaolin/obj/puti-zi";
   } else
    if (quest_count == 150)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else
    if (quest_count == 200)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else
    if (quest_count == 250)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
        money = 1;
    } else

    if (quest_count == 300)
    {
        msg = "$N̾���������ǳ���������ǰ�ˣ��벻�������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
	 special = "/clone/gift/tianxiang";
    } else
    if (quest_count == 350)
    {
        msg = "$N����һ��������������ĺ��ʺ�ѧ�䣬������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
	 special = "/clone/gift/tianxiang";
    } else
    if (quest_count == 400)
    {
        msg = "$N̾����������һ����ѧ��Ű����벻�������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
         special = "/clone/gift/jiuzhuan";
    } else
    if (quest_count == 450)
        {
        msg = "$N����������������ţ�������ţ�����������"+chinese_number(me->query("questsn_times"))+
               "��������һ��©�����ף����ף���\n";
        special = "/clone/gift/jiuzhuan";
    } else
       if (quest_count == 0)
   {
       msg = "$N����̾�˿�����������û�뵽������"+chinese_number(me->query("questsn_times"))+
       "��������һʧ�֣������Ժ����������Щ��������������\n";
       special = "/clone/gift/xuanhuang";
   } else
       if ((quest_count % 10) == 0)
   {
       msg = "$N΢΢��ͷ�����ɵĲ�����Ȼ����"+chinese_number(me->query("questsn_times"))+
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

    me->delete("quest_sn");

   //��¼�������Ĵ�������Ҫ���������������1000����������Ƭ
   all_quest_sn = (int)me->query("all_quest_sn");
   if (!all_quest_sn) all_quest_sn = 0;
   all_quest_sn += 1;
   if (all_quest_sn == 1000)
   {
       obj = new("/clone/enchase/YELjewel.c");
       tell_object(me,this_object()->name() + "�ֶ�����˵�ͷ�����Ѿ������������һǧ����������������\n" +
                   "�и�" + obj->query("name") + "���ͽ������ˣ�\n");
       if (!obj->move(me))
               obj->move(environment());
       me->set("all_quest_sn",0);
   } else me->set("all_quest_sn",all_quest_sn);

   return 1;
}

int give_up()
{
   // object me,ob,obj;
   object me,ob;
    //int giveup,rank;
    int giveup;
    mapping quest;
    
    me = this_player();
    if( me->query("quest_sn")) 
    {
    if( (me->query("character") != "���ռ�թ") && (me->query("character") != "�ĺ�����") && !(me->query("shen") > 0))  
        return 1;
    }
    if((quest =  me->query("quest_sn")))
    {
        message_vision("$Nί���ĵ��Ϻ�������ǰ���ߣ������������û����ɣ������������˼ҵ�����......��\n",me);
        if (quest["type"] == "��")
        {
                message_vision("$N����üͷ��$n˵���������Ǵ�һ������ô������ô�ѣ���ȥ��ϸ���룬�������һ��Ҫ��ɣ�\n",this_object(),me);
                return 1;
        }
        if (quest["type"] == "��")
        {
                if (objectp(ob = quest["thing"]))
                {
                        ob->move("/d/register/prison");
                        destruct(ob);
                }
        }
        message_vision("�Ϻ������$N΢Ц��˵:��û��ϵ���´κú�Ŭ������������\n", me);
        
        if (quest["type"] == "��")
        {
                me->delete("quest_sn");
                return 1;
        }
        me->set("questsn_times",0);

        giveup = me->query_temp("sn_giveup");
        if ( giveup < 1 )
            me->set_temp("sn_giveup",1);
        else if ( giveup < 5 )
            me->set_temp("sn_giveup",giveup+1);
        else me->set_temp("sn_giveup",5);

        me->set("questsn_giveup_time",time());
   
        me->delete("quest_sn");
    }
    else
        write("�Ϻ�����΢Ц�Ÿ����㣺����Ŀǰû���κ����񡣡�\n");
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
    ob->move("/d/wizard/prison");
    destruct(ob);
    return ;
}
