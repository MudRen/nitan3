// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ��ָ��ͨ

#include <ansi.h>

inherit SKILL;

string *xue_name = ({ 
        "�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
        "����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
});

string *action_finger = ({
        "$N��ָ΢����ͻȻ������һʽ��ָ�㽭ɽ����һ�ƾ���ֱϮ$n��$l",
        "$N��������ǰһ��������ͻȻ��������ָ΢������������ָ����ֱϮ$n��$l",
        "$N�ұۻӶ�����ָ����������ǰ����һ�����ߣ����ǡ�һ�´�ˮ��������$n��ǰ��",
        "$NԾ���ڰ�գ�˫�ּ��ӣ���ָ����������ָ���ס�����ǵذ���$nӿȥ",
});

string *action_throwing = ({
        "$N��ָ΢����ͻȻ������һʽ��ָ�㽭ɽ����$w�ƿ�֮��������ֱϮ$n��$l",
        "$N��������ǰһ��������ͻȻ��������ָ΢������������ָ����$w��Х��ֱϮ$n��$l",
        "$N�ұۻӶ�����ָ����������$w����ǰ����һ�����ߣ����ǡ�һ�´�ˮ��������$n��ǰ��",
        "$NԾ���ڰ�գ�˫�ּ��ӣ���ָ����������ָ���ס���������ǵص�$w����$nӿȥ",
});

int valid_enable(string usage) { return usage == "finger" || usage == "throwing" || usage == "parry"; }

int valid_combine(string combo) { return combo == "lanhua-shou"; }
int double_attack() { return 1; } 

int valid_learn(object me)
{
        object weapon;

        if ((int)me->query("int") < 28)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if (weapon = me->query_temp("weapon"))
                if ((string)weapon->query("skill_type") != "throwing")
                        return notify_fail("ѧ��ָ��ͨ������ֻ��ְֳ�����\n");
                        
        if (me->query("max_neili") >= 1000) return 1;
        
        if ((int)me->query_skill("bibo-shengong", 1) < 70)
                return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��\n");
                
        if (me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("��ϰ��ָ��ͨ�����б̲�����ϡ�\n");
                
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
                
        return 1;
}

mapping query_action(object me, object weapon)
{
        //int i, level;
        int level;

        level   = (int) me->query_skill("tanzhi-shentong", 1);
        
        if (random(level) > 100 && me->query_skill("force") > 120 
        &&  me->query("neili") > 200) 
        {
                me->add("neili", -50);
                if (! weapon)
                        return ([
                                "action": HBRED "$Nһ���Ϻȣ�ֻ�������͡�֮�����죬���������������˷�Ϯ��$n" NOR,
                                "force" : 400,
                                "attack": 200,
                                "dodge" : 100,
                                "parry" : 100,
                                "damage_type": "����",
                        ]);
                else
                        return ([
                                "action": HBRED "$Nһ���Ϻȣ�ֻ�������͡�֮�����죬����" + weapon->query("name") + HBRED"������˷�Ϯ��$n" NOR,
                                "damage": 160,
                                "attack": 200,
                                "dodge" : 100,
                                "parry" : 100,
                                "damage_type": "����",
                                "post_action": (:call_other, WEAPON_D, "throw_weapon":)
                ]);
        }

        if (! weapon) 
        {
                return ([
                        "action": action_finger[random(sizeof(action_finger))],
                        "force" : 340 + random(50),
                        "attack": 70 + random(10),
                        "dodge" : 70 + random(10),
                        "parry" : 70 + random(10),
                        "damage_type" : "����",
                ]);
        } else
        {
                return ([
                        "action": action_throwing[random(sizeof(action_throwing))],
                        "damage" : 140 + random(30),
                        "attack": 80 + random(10),
                        "dodge" : 80 + random(10),
                        "parry" : 70 + random(10),
                        "damage_type" : "����",
                        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
                ]);        
        }     
}

int practice_skill(object me)
{
        object weapon;

        if (weapon = me->query_temp("weapon"))
                if ((string)weapon->query("skill_type") != "throwing")
                        return notify_fail("����ָ��ͨ������ֻ��ְֳ�����\n");
                        
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");
                
        if ((int)me->query("neili") < 80)
                return notify_fail("���������������ָ��ͨ��\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tanzhi-shentong/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        string name, weapon;
        mixed result;
        name = xue_name[random(sizeof(xue_name))];
    
        if (victim->is_busy()) return 0;
        
        if (! objectp(weapon = me->query_temp("weapon"))) 
        {
                if ((me->query("neili") > 200) && me->query_skill("tanzhi-shentong", 1) > 100 
                &&  me->query("max_neili") > 1200)
                {
                        victim->start_busy(3);
                        me->add("neili", -30);
                        if (victim->query("neili") <= (damage/2 + 30))
                                victim->set("neili",0);
                        else
                                victim->add("neili", -damage / 2 + 30);
                        return HIR "$NͻȻ��ָ������$n"HIC"��"+name+"��"HIR"��$n��ɫ��Ȼ��ò԰ף���Ϣֱй��\n" NOR;
                } 
        } else 
        {
                if ((me->query("neili") > 200) && me->query_skill("tanzhi-shentong", 1) > 60)
                {
                        victim->start_busy(2);
                        me->add("neili", -30);
                        result = ([ "damage" : damage ]);
                        result += ([ "msg" : HIR "$n��$N�İ�������"HIC"��"+name+"��"HIR"����Ϣ���ң�\n" NOR]);
                        
                        return result;
                }   
        }
 
}

int query_effect_parry(object attacker, object me)
{
        object weapon;
        int lvl;

        if (objectp(weapon = me->query_temp("weapon")))
                if ((string)weapon->query("skill_type") != "throwing")
                        return 0;

        lvl = me->query_skill("tanzhi-shentong", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

/*
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping prepare;
        string attack_skill;
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("tanzhi-shentong", 1) < 100 
        ||  ! living(me) || me->query_temp("weapon"))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("tanzhi-shentong", 1);
             
        if (objectp(weapon = ob->query_temp("weapon"))) 
                attack_skill = weapon->query("skill_type");
        else
        {
                prepare = ob->query_skill_prepare();
                if (! prepare) prepare = ([]);
                else if (sizeof(prepare) == 0)  attack_skill = "unarmed";
                else if (sizeof(prepare) == 1)  attack_skill = (keys(prepare))[0];
                else if (sizeof(prepare) == 2)  attack_skill = (keys(prepare))[ob->query_temp("action_flag")];
        }
        attack_skill = ob->query_skill_mapped(attack_skill);
        
        if (ap / 2 + random(ap) < dp && stringp(attack_skill))
        {
                result = ([ "damage": -damage ]);
                // ȥ�����е��˺�д��
                if (objectp(weapon = ob->query_temp("weapon")))
                {
                        result += (["msg" : HIC "$n" HIC "��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ��"
                                                "��ʱ��" + weapon->name() + HIC"�������ھ�����������"
                                                        "����������" + to_chinese(attack_skill) + "��\n" NOR]);
                }
                else    result += (["msg" : HIC "$n" HIC "��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ��"
                                "�⡸��ָ��ͨ����$N�ġ�" + to_chinese(attack_skill) + "�����˸�����൱��"
                                        "˭Ҳû����˭��\n" NOR]);
                return  result;
        }
}

*/
