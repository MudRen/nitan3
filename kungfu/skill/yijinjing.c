// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yijinjing.c ���� �׽��


#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force) { return 1; }     

int query_neili_improve(object me)   
{
        int lvl;  
        lvl = (int)me->query_skill("yijinjing", 1);  
        return (lvl / 20) * (lvl / 10) * 25 * 15 /100; 
}

int valid_learn(object me)
{
        if (me->query("con") < 20)
                return notify_fail("���о���һ�����ֻ������ǰ������ð��̫��Ѩͻͻ������\n");
                
        if (me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ�׽�񹦣�\n");

        /*
        if (me->query_skill("freezing-force", 1))
                return notify_fail("���Ѿ����׽�񹦺ͱ��Ϻ�����������һ�����ڹ��ˡ�\n");
        */

        if (me->query_skill("force", 1) < me->query_skill("yijinjing", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���������������������׽�񹦣�\n");

        if (me->query("gender") != "����")
                return notify_fail("�㲻�����ԣ��޷���ϰ�׽�񹦡�\n");

        return ::valid_learn(me);
}

void skill_improved(object me)
{
        int skill, lit;
        
        skill = me->query_skill("yijinjing", 1);
        lit = me->query_skill("literate", 1);
        
        if (skill == 200 && ! me->query("sl/yijinjing"))
        {
                tell_object(me, HIW "\n��Ȼ����е�������Ϣ���ߣ�ԽתԽ�죬˲ʱ���Ѿ���ȫ������������һ���죬������ڵ���֮�У�\n" NOR);
                me->add("max_neili", random(lit + skill));
                if (me->query("max_neili") > me->query_neili_limit()) 
                        me->set("max_neili", me->query_neili_limit()); 
                me->set("sl/yijinjing", 1);
        }
        if (skill == 400)
        {
                tell_object(me, HIW "\n��Ȼ����е�������Ϣ���ߣ�ԽתԽ�죬˲ʱ���Ѿ���ȫ������������ʮ���죬������ڵ���֮�У�\n" NOR);
                tell_object(me, HIW "�������ɰٶ��������ˡ�\n" NOR);
                me->set_temp("nopoison", 1);
        }
}

int practice_skill(object me)
{
        return notify_fail("�׽��ֻ����ѧ(learn)����������Ϊ��\n");
}

string exert_function_file(string func)
{
        return __DIR__"yijinjing/" + func;
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : "���Ϻ�����֣�����ׯ��",
                "start_my_msg" : "�������죬�ų�һ�������Ϣ˳��������������\n",
                "start_other_msg" : "�������죬һ�Ṥ�򣬴ӿڱǴ������³�����������Խ��ԽŨ������������ȫ��\n",
                "halt_msg" : "����һ����������Ϣ�������˻�ȥ��վ��������\n",
                "end_my_msg" : "����Ϣ���˸�С���죬���ص���չ�վ��������\n",
                "end_other_msg" : "ֻ������"+me->name()+"�İ���������ɢ���ִӿڱǴ����˻�ȥ��\n",
                "heal_msg" : "˫�ֺ�ʲ����ϥ�������������������䡱����ʼ�˹����ˡ�\n",
                "heal_finish_msg" : "����վ��ֻ��ȫ��˵������������죬����������գ����գ����Ž���������¾�ѧ����\n",
                "heal_unfinish_msg" : "�³���Ѫ������վ�𣬵���ɫ�԰ף���������������\n",
                "heal_halt_msg" : "һ�����������ӷ�˫��Ӷ���ѹ����Ϣ��վ��������\n",
        ]);
}

string *fanzhen_msg = ({
        "ֻ���$N���ڸ��У���������һ�뷭ת��\n",
        "���ȷ��𣬽�$N��������ֽ��ȫ��Ѫɫ��\n",
        "���$N�ķ����ѣ�����������������\n",
        "�����Ѳ���ȫ����$N�����������ȥ��\n",
        "���$N������ת�������������߰˲���\n",
        "��$Nһײ��ֻ���$p�ؿ���Ѫ��ӿ��\n",
        "$N����ײ��һ���޻����棬����Ϊ��ĺ�ǽ��һ�㣬����������\n",
        "$N������$p��ͻȻ����һ�𣬵�ʱ���˳�ȥ��\n",
});

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        string msg;
        int ap, dp;
        int jiali;
        object weapon1;
        
        if (me->query("family/family_name") != "������")
                return;
                
        if ((int) me->query_skill("yijinjing", 1) < 200 ||
            ! living(me))
                return;                      

        if ((jiali = ob->query("jiali")) < 1)
                return;

        ap = ob->query_skill("force") + ob->query("neili");
        dp = me->query_skill("force") + me->query("neili");                        

        if (ap / 2 + random(ap) < dp)
        {
                if (! objectp(weapon1 = ob->query_temp("weapon")))
                {
                        result = ([ "damage" : -damage ]);
                        
                        msg = random(2) ? HIR "$n��������һ�ɷ���֮����" : HIR "$n���Ͻ�ղ����������Ķ���";   
                              
                        msg += fanzhen_msg[random(sizeof(fanzhen_msg))] + NOR;             
                
                        ob->receive_damage("qi", damage, me);
                        ob->receive_wound("qi", damage / 2, me);                              
                        
                        result += ([ "msg" : msg ]);
                        
                        return result;
                } else
                {
                        result = ([ "damage" : -damage ]);

                        switch (random(5))
                        {
                        case 0:  
                        case 1:
                        case 2:
                        case 3:                                                
                                result += ([ "msg" : HIR "������һ�����ε�ǽ��$n��ǰ�赲�ţ����"
                                                     "$N" HIR "һ���ӱ����������$N" 
                                                     HIR "�ֱ۷��飡\n" NOR ]);
                                break;
                        default:
                                result += ([ "msg" : HIR "���$n��������һ�ɷ���֮����$Nֻ������һ�ȣ�" + 
                                                     weapon1->name() + HIR "��ʱ���ֶ������ɳ����⣡\n" NOR]);
                                weapon1->unequip();
                                weapon1->move(environment(ob));
                                ob->reset_action();
                                if (! ob->is_busy())
                                        ob->start_busy(1);
                                break;
                        }

                        return result;
                }
        }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int skill;
        int i = 1,j;    

        if (me->query("family/family_name") != "������")
                return;
                
        if (me->query_skill("yijinjing", 1) < 400 ||
            me->is_busy())
                return;
                
        skill = me->query_skill("force");

        i = damage_bonus * (skill + 1) / 1000;
        i = i/2+ random(i);
        if (me->query_temp("weapon"))
                i = i*3;
        if (me->query_temp("apply/damage")>=100)
                i = i/3;

        j = me->query_skill("yijinjing", 1) / 20;  
        message_combatd(HIR"$N"+HIR+"����һ����ţ������ھ�����������˫�ۣ�������֮�ƹ���$n��\n" NOR, me,victim);

        return i;
} 

string query_description()  
{
        return
        "�׽��������ͷ�Ⱦ��������ڼ��⣬Ϊ���Ϸ�ħ�񹦡����ڹ�����������"
        "֮��������һ�����޷�ѧ�ɣ������׶ηֱ�Ϊ��0-200��200-400��>400����"
        "���׽��ǿ���壬�����Ϊ���м��ɽ�����ħ���ɽ��֮�壻�߼��ɿ�"
        "����ħ�����Σ����������ٶ����֡�";
}

