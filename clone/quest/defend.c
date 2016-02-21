// �������defend.c

#include <ansi.h>
#include <quest.h>

inherit QUEST_OB;

#include <defend.h>

#define ENEMY_FAM             my["enemy_fam"]      // ���������Ե�����
#define DEFEND_FAM            my["defend_fam"]     // Ҫ����������
#define MASTER_ID             my["master_id"] 
#define PLACE                 my["place"] 
#define MIN_EXP               30000                // ��С EXP Ҫ��

nosave object dmaster = 0;

// �����������ɺ�а�ɣ�����Ϊ�˷�ֹ����һ�������Լ�����
// �Լ��Ļ����������Ȼ��Ҳ���ѱ��⣩��һ����ԣ�������
// �ɹ���а�ɣ�����а�ɹ������ɵģ����硰��������Χ����
// ��������������������������ɡ�ʲô�ģ�����������֪����
// ��Щ�����Ǻ���˵������а�ģ������һ���������Ľ�ݵȵȣ�
// �������Ǿ���Ϊ��ͬʱ����������������������ɣ��ǡ���
// ����а������˵�ǡ�������а����Ҳ����˵�������ⳡ����
// �е�̬���ǣ��ȿ��ܹ������ɣ�Ҳ���ܹ���а�ɣ���Ȼ��Ҳ
// ���ܹ���������а�����ɡ�

// �����б�
string *zps = ({
        "�䵱��", "��ɽ����", "ȫ���", "��Ĺ��",
        "���չ�", "�һ���", "�������", "���ϻ���", 
        "������", "ؤ��", "������", "��ң��", 
        "����", "��ɽ����","��������",
});

// а���б�
string *xps = ({
        "������", "Ѫ����", "������", "ŷ������", 
        "������", "Ľ������", "�������",
});

void die(object ob);
void npc_destructed();
void move_enemy(object enemy, string family);
void remove_enemy();
int  ask_defend(object ob, object me);
int  ask_finish(object ob, object me);

// ������󴴽�
void create()
{
        seteuid(getuid());
        setup();
}

// ����һ������
// �������ɵ��˵������ͱ��������������ƣ��Ѿ��������
// �ɵ�����Ҫ��������˿���ȥɱ��Щ���ˣ�����ʱ�䵽��
// �Ϳ���Ҫ������
void init_quest(int num, string family_name)
{
        int i;
        mapping my;
        object enemy;
        string *family;
        string enemy_fam;
        object env;
        
        my = query_entire_dbase();

        // �������������
        set_name("Χ��" + family_name);
        
        // ������ɹ����ߵ�����
        family = keys(familys);
        if (member_array(family_name, xps) != -1)
        {
                family = family - xps - ({ family_name });
                enemy_fam = family[random(sizeof(family))];
        }
        // ������������ϳ�
        else 
        {
                family = family - zps - ({ family_name });
                enemy_fam = family[random(sizeof(family))];
        }
        
        // ��¼�����������Ϣ
        ENEMY_FAM = enemy_fam;
        DEFEND_FAM = family_name;
        MASTER_ID = familys[family_name]["master_id"];
        PLACE = familys[family_name]["master_place"];
        
        env = get_object(PLACE);
        
        if (! objectp(dmaster = present(MASTER_ID, env)) ||
            dmaster->query("startroom") != base_name(env))
        {
                destruct(this_object());
                return;      
        }
        
        // ����NPC�ĶԻ���Ϣ
        dmaster->set("inquiry/" + name(), "���������ָ�� defend ����ȡ������������");
        dmaster->set("inquiry/" + ENEMY_FAM, "���" + ENEMY_FAM + "����̫�ɶ��ˣ�"
                                            "�Ŵ�������" + DEFEND_FAM +"���ơ�");
        dmaster->set("inquiry/" + DEFEND_FAM, "���¾���" + DEFEND_FAM + "������ѽ��"
                                            "��Ը��Ը��������һ��֮����������У�");
        dmaster->set_temp("override/ask_defend", (: ask_defend :));
        dmaster->set_temp("override/ask_finish", (: ask_finish :));
        
        // ����ָ��λ�����ߵ���
        for (i = 0; i < num; i++)
        {
                enemy = new("/clone/npc/enemy");
                enemy->create_family(enemy_fam, familys[enemy_fam]["generation"] 
                                                + (-1 + random(2)), "����" );
                enemy->setup_family(enemy_fam);                                
                enemy->set("is_attacking", family_name);
                enemy->set("long", "������ǰ������" + family_name + "��һ��" + enemy_fam + "���ӡ�\n");  
                              
                // enemy->set_temp("override/die", (: die :));
                
                move_enemy(enemy, family_name);
        }

        CHANNEL_D->do_channel(dmaster, "family",
                        sprintf("��˵%s��һ����Ӵ��ɱ�����ɣ��������Ʋ��", enemy_fam)); 

        // �л�������״̬
        change_status(QUEST_READY);

        // ������������ʱ�䣺5����
        set("live_time", 300);

        // �Ǽ�ҥ����Ϣ
        register_information();
}

void send_enemy(int num, string family_name)
{
        object enemy;
        string enemy_fam;
        string *family;
        int i;

        family = keys(familys);
        if (member_array(family_name, xps) != -1)
        {
                family = family - xps - ({ family_name });
                enemy_fam = family[random(sizeof(family))];
        }
        // ������������ϳ�
        else 
        {
                family = family - zps - ({ family_name });
                enemy_fam = family[random(sizeof(family))];
        }

        for (i = 0; i < num; i++)
        {
                enemy = new("/clone/npc/enemy");
                enemy->create_family(enemy_fam, familys[enemy_fam]["generation"] 
                                                + (-1 + random(2)), "����" );
                enemy->setup_family(enemy_fam);                                
                enemy->set("is_attacking", family_name);
                enemy->set("long", "������ǰ������" + family_name + "��һ��" + enemy_fam + "���ӡ�\n");  
                              
                enemy->set_temp("override/die", (: die :));
                
                move_enemy(enemy, family_name);
        }

        return;
}

// ���ߵ��ˣ��� ENEMY �� chat_msg ��Ҳ�к��У�
void move_enemy(object enemy, string family)
{
        string *places = familys[family]["place"];
        string place = places[random(sizeof(places))];
        object room;

        if (objectp(room = environment(enemy)))
        {
                tell_room(room, enemy->name() + "һ����Ͳ����ˡ�\n");
        }
#ifdef DEBUG        
        CHANNEL_D->do_channel(this_object(), "sys",
                sprintf("%s : %O", enemy->short(), place)); 
#endif
        enemy->move(place);
        tell_room(place, "ֻ��һ��" + enemy->query("family/family_name") + "���Ӳ�֪ʲôʱ�����˳�����\n");

        return;
}

// �ָ�NPC�����������ʱ�����ָ�������NPC
void restore_npc()
{
        mapping my = query_entire_dbase();
        object npc_ob;

        if (! objectp(npc_ob = dmaster))
                return;

        npc_ob->delete_temp("override/ask_defend");
        npc_ob->delete_temp("override/ask_finish");
        npc_ob->delete("inquiry/" + name());
        npc_ob->delete("inquiry/" + ENEMY_FAM);
        npc_ob->delete("inquiry/" + DEFEND_FAM);
        dmaster = 0;
}

// ��������
void cancel_quest()
{
        remove_enemy();
        restore_npc();
        ::cancel_quest();
}

// ��ʱ���ˣ����ߵ���
void remove_enemy()
{
        object *enemys;
        int i;
        mapping my = query_entire_dbase();
        
        enemys = children("/clone/npc/enemy");
        enemys = filter_array(enemys, (: $1->query("is_attacking") == $(DEFEND_FAM)
                                      && $1->query("family/family_name") == $(ENEMY_FAM) :));

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
        return; 
}

// Ҫ���������ȥɱ�ˣ�ȥ����Ҫ���ŵ����ƣ�
int ask_defend(object ob, object me)
{
        string *places, place;

        string *msg_now = 
        ({
                "������ų�����������", "��������ƺ���̫ƽ��", 
                "�������ʱ�е��˽���", "��������ƺ��ܲ�����", 
                "��˵�Ϳ�Ҫ�е��˽���", "�����˶Ա��Ż�������",
        });
        string *msg_do =
        ({
                "�Ͽ쵽�Ĵ�Ѳ��Ѳ��", "ע�����ܶ�Ҫȥ���", 
                "ɽ��ɽ�¶���ϸ����", "�ڱ���Ҫ���ú�����",
                "����Ҫ�ط����÷���", "�÷�ֹ���˹���ɽ��",
        });
        string *msg_place =
        ({
                "��Ȼ˵����ɽ��ˮ�㣬����", "Ҳ��һ����Ҫλ�ã�����",
                "�ô�Ҳ�Ǹ���Ҫ�ؿ������", "�Ͼ��������Ҫ�أ���ô",
                "�����е������˹�������", "���µ��˹���������", 
        });

        if (! me->query("family/family_name"))
        {
                ob->command("haha" + me->query("id"));
                message_sort(HIC "$N" HIC "��$n" HIC "������" + RANK_D->query_respect(me) 
                                +"�������ɣ�����Ҫʲô�����أ���\n" NOR, ob, me);
                tell_object(me, HIW "�㻹���Ȱݸ�ʦ����Ҫ����ɡ�\n" NOR);
                return 1;
        }
        
        if (ob->query("family/family_name") != me->query("family/family_name"))
        {
                ob->command("?" + me->query("id"));
                message_sort(HIC "$N" HIC "����üͷ��$n" HIC "��������λ" 
                        + me->query("family/family_name") +"��"+ RANK_D->query_respect(me) +
                        "���������Ҵ����˰ɣ���\n" NOR, ob, me);
                tell_object(me, HIW "�ⲻ�����Լ������ɣ��㲻Ӧ������λʦ��Ҫ����ѽ��\n" NOR);
                return 1;
        }

        if (count_lt(me->query("combat_exp"), MIN_EXP))
        {
                ob->command("sigh");
                message_sort(HIC "$N" HIC "��$n" HIC "�����������㻹�ǵ�ˮƽ��Щ"
                                "������������񲻳١���\n" NOR, ob, me);
                tell_object(me, HIW "���������� " +MIN_EXP+" �㾭��ֵ��������\n" NOR);
                return 1;
        }

        if (me->query_temp("defend_quest") && ! wizardp(me))
        {
                ob->command("yi");
                message_sort(HIC "$N" HIC "�ɻ�ض�$n" HIC "�������㲻���Ѿ�����"
                                "���������ô��\n��ô�������ң���\n" NOR, ob, me);
                tell_object(me, HIW "��ȥ����׼��������������ɰɡ�\n" NOR);
                return 1;
        }

        else
        {
                places = familys[me->query("family/family_name")]["place"];
                place = places[random(sizeof(places))];
                place = place->query("short");

                send_enemy(10, me->query("family/family_name"));

                command("nod" + me->query("id"));
                message_sort(HIC "$N" HIC "����ض�$n" HIC "�������ðɣ�" 
                        + msg_now[random(sizeof(msg_now))] +"����Ҫע��\n"
                        + msg_do[random(sizeof(msg_do))] + "����\n" NOR, ob, me);
                
                tell_object(me, HIW + ob->name() + HIW "���ĸ����㣺��" 
                        + place + HIW"����ط�" + msg_place[random(sizeof(msg_place))]
                        +"\n����ö�ע��ע�⡣��\n" NOR);

                me->set_temp("defend_quest/start", 1);
                me->apply_condition("swjob", 30 + random(30));
                return 1;
        }
}

int ask_finish(object ob, object me)
{
        int killed, exp, pot, gongxian;

        if (! me->query("family/family_name"))
        {
                ob->command("haha" + me->query("id"));
                message_vision(HIC "$N" HIC "��$n" HIC "������" + RANK_D->query_respect(me) 
                                +"�������ɣ�����Ҫʲô�����أ���\n\n" NOR,ob,me);
                tell_object(me, HIW "�㻹���Ȱݸ�ʦ����Ҫ����ɡ�\n" NOR);
                return 1;
        }

        if (ob->query("family/family_name") != me->query("family/family_name"))
        {
                ob->command("?" + me->query("id"));
                message_vision(HIC "$N" HIC "����üͷ��$n" HIC "��������λ" +
                               me->query("family/family_name") + "��" + RANK_D->query_respect(me) +
                               "���������Ҵ����˰ɣ���\n" NOR,ob,me);
                tell_object(me, HIW "�ⲻ�����Լ������ɣ��㲻Ӧ������λʦ��Ҫ����ѽ��\n" NOR);
                return 1;
        }

        if (! me->query_temp("defend_quest/start"))
        {
                ob->command("sigh");
                message_vision(HIC "$N" HIC "�ɻ�ض�$n" HIC "�������㶼��������������񣬾���Ҫ��������\n" NOR, ob, me);
                tell_object(me, HIW "���ܵ���Ҫ������ɡ�\n" NOR);
                return 1;
        }

        if (! me->query_temp("defend_quest/finish"))
        {
                ob->command("sigh");
                message_vision(HIC "$N" HIC "�ɻ�ض�$n" HIC "�������������û�����أ����ھ���Ҫ��������\n" NOR, ob, me);
                tell_object(me, HIW "�����������Ҫ�����ɡ�\n" NOR);
                return 1;
        } else 
        {
                if (! me->query_temp("defend_quest/killed"))
                {
                        ob->command("hmm");
                        message_vision(HIC "$N" HIC "���ͷ��$n" HIC "�������ðɣ����������湦δ�����Ͳ����㽱���ˡ���\n" NOR, ob, me);
                        me->delete_temp("defend_quest");
                        return 1;
                } else 
                {
                        killed = (int)me->query_temp("defend_quest/killed");
                        ob->command("nod");

                        exp = killed * 40 + random(200);
                        exp = exp / 2 + random(exp / 2);
                        pot = exp / 3 + random(2);
                        gongxian = killed * 3;
                        
                        message_vision(HIC "$N" HIC "���ͷ��$n" HIC "�������ã����������ɹ���ɱ��" +
                                       chinese_number(killed) + "�����ˣ������Ǹ����һ�㽱������\n" NOR, ob, me);
                        /*               
                        tell_object(me, HIW "���������õ���" + chinese_number(exp) + "�㾭��ֵ��" +
                                       chinese_number(pot) + "��Ǳ��ֵ�Ľ�����������ɹ�������ˡ�\n" NOR);
                        */                
                        me->delete_temp("defend_quest");

                        QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "gongxian" : gongxian ]), 1);

                        return 1; 
                }
        }
}

void die(object ob)
{
        int percent;
        object me;
        string *pills, pill;
        int amount = 300 + random(300);
        string *condition = ({
                "������������Ҫ��֧", "ͷ�ؽ��ᣬ���Ͼ͵�", 
                "ŻѪ��������ð����", "�˺����ۣ������м�", 
        });

        if (objectp(me = ob->query_last_damage_from()) 
        &&  environment(ob) == environment(me) 
        &&  me->query_temp("defend_quest/start") 
        &&  ! me->query_temp("defend_quest/finish")
        &&  ! me->query_temp("defend_quest/waiting"))
        {
                switch (random(15)) 
                {
                        case 1: {
                                message_sort(HIR "�ۼ�$N" HIR + condition[random(sizeof(condition))]
                                                +"��ͻȻ$N���һ�������˼�����\n����ͨ����$n����������"
                                                "\n" NOR, ob, me);
                                tell_object(me, HIW + ob->name()+"ͻȻ�ӻ����ͳ�һ�Ѱ׻��������ӣ�С��"
                                                "�����������λ" + RANK_D->query_respect(me) + "��\n��"
                                                "������һ�棨nod����Σ���" + chinese_number(amount) +
                                                "�������͹����ˣ���\n" NOR);
                                ob->clean_up_enemy();
                                ob->remove_all_enemy(0);
                                ob->clear_condition(0);
                                ob->set("jing", 1);
                                ob->set("qi", 1);
                                me->set_temp("defend_quest/waiting", amount);
                                return;
                        }
                        default: {
                                // ����
                                if (me->query("family/family_name") == ob->query("is_attacking"))
                                        me->add_temp("defend_quest/killed", 1);
                                
                                ob->set_temp("die", 1);
                                
                                QUEST_D->bonus(me, ([ "exp" : 10 + random(30),
                                                      "pot" : 3 + random(20),
                                                      "score" : 3 + random(20) ]));
                                ob->die(me);
                        }
                }
                return;
        }
        if (objectp(me) && me->query("family/family_name") == ob->query("is_attacking")) 
        {
                me->add_temp("defend_quest/killed", 1); 

                QUEST_D->bonus(me, ([ "exp" : 10 + random(30),
                                      "pot" : 3 + random(20),
                                      "score" : 3 + random(20) ]));
        }
        ob->die();
}

// ѯ��DEFENDER - ���ڱ����������
string ask_defender(object knower, object me)
{
        mapping my = query_entire_dbase();

        return CYN "���" HIY + DEFEND_FAM + NOR CYN
               "��˵�������Ǻܴ󣬲�����ξͻ��" HIY 
               + DEFEND_FAM + NOR CYN "���˰ɡ�";
}

// ѯ��ENEMY - �����ߵ�����
string ask_enemy(object knower, object me)
{
        mapping my = query_entire_dbase();

        return CYN "���" HIY + ENEMY_FAM + NOR CYN
               "�ĵ���һ���װ԰Եģ�һ���Ͳ���ʲô�ö�����" NOR;
}

// �������
string query_introduce(object knower)
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC))
        {
                remove_call_out("do_say");
                call_out("do_say", 1);
        }

        return CYN "��˵�Ǹ�" + HIY + ENEMY_FAM + NOR CYN "�ĵ��������ڹ���" +
               HIY + DEFEND_FAM + NOR CYN "�أ�Ҳ��֪��������ʲô���ӡ�" NOR;
}

void do_say(object knower)
{
        if (! objectp(knower) || ! living(knower))
                return 0;

        message_sort("$N���������Ҹ��㶼˵�ˣ���Щ����ѽ��ûһ����"
                       "�������ⲻ���������˰ɣ���\n", knower);
}

// ������ʾ
string query_prompt()
{
        switch (random(3))
        {
        case 0:
                return CYN "�����������Щ����˵��" HIY + name() +
                       NOR CYN "����";
        case 1:
                return "Ҳûʲô���£�ֻ����˵��" HIY + name() +
                       NOR CYN "���ˡ�";
        default:
                return "ǰ���컹���˼�˵��" HIY + name() +
                       NOR CYN "�ء�";
        }
}

// �ǼǸ��������Ϣ
void register_information()
{
        mapping my = query_entire_dbase();

        if (! clonep() || ! mapp(my))
                // �����������Բ��Ǽ�
                return;

        set_information(ENEMY_FAM, (: ask_enemy :));
        set_information(DEFEND_FAM,(: ask_defender :));
}

// ���������Ա�ĳ��֪����
int can_know_by(object knower)
{
        return 1;
}

void check_all_place()
{
        int i, j;
        string *the_place;
        string *family;
        object env;

        family = keys(familys);
        for (i = 0;i < sizeof(family);i++)
        {
                the_place = familys[family[i]]["place"];
                for (j = 0;j<sizeof(the_place);j++)
                        if (!objectp(env = get_object(the_place[j])))
                                log_file("static/defend_quest",sprintf("������������¼��%s\n",the_place[j]));
        }
}

