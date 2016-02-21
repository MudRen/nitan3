// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// liuhe-dao.c ؤ�����ϵ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N���һ��������$w�󿪴��أ������ӵ�ʹ�����Ǳ����졹��ն��$n��$l",
        "attack": 55,
        "dodge" : 56,
        "parry" : 54,
        "damage": 120,
        "lvl" : 0,
        "skill_name" : "�Ǳ�����",
        "damage_type":  "����"
]),
([      "action":"$N�˵���磬һ�С����Ǻ�ɽ�������ưԵ�֮��������$n��������Ϳ�����",
        "attack": 60,
        "dodge" : 60,
        "parry" : 65,
        "damage": 130,
        "lvl" : 10,
        "skill_name" : "���Ǻ�ɽ",
        "damage_type":  "����"
]),
([      "action":"$Nһ�š����է�ϡ���ͻȻ����$n���࣬Ѹ�͵�������ն����ʽ��Ȼ�ϳ�һ��ԲȦ",
        "attack": 60,
        "dodge" : 60,
        "parry" : 55,
        "damage": 140,
        "lvl" : 25,
        "skill_name" : "���է��",
        "damage_type":  "����"
]),
([      "action":"$N���챯Ц���漴�ӵ�ն��һʽ������޳�����$w��Ϊһ˿˿���⣬����$n$l",
        "attack": 70,
        "dodge" : 65,
        "parry" : 70,
        "damage": 140,
        "lvl" : 35,
        "skill_name" : "����޳�",
        "damage_type":  "����"
]),
([      "action":"$Nʩչ���ͺ�����������$n������$w���ſ�Ұ���磬�����ޱȵ���������",
        "attack": 63,
        "dodge" : 60,
        "parry" : 70,
        "damage": 145,
        "lvl" : 45,
        "skill_name" : "�ͺ�����",
        "damage_type":  "����"
]),
([      "action":"$N��ɫׯ�أ��ӵ�ʹ�����������ҡ���$w���϶�����$n����������һ�������׺䶥",
        "attack": 70,
        "dodge" : 70,
        "parry" : 75,
        "damage": 145,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("��Ļ����������̫ǳ��\n");
                
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level, num=0;
        object ob;

        level = (int)me->query_skill("liuhe-dao",1);
        ob = me->select_opponent();
        
        if (me->query_temp("lianhuan")) 
        {
                num = 1+random(2);
                message_combatd(YEL "\n$N����������������" + chinese_number(num + 1) + "����\n" NOR, me);
                for (i = 1; i < num; i++) 
                {
                        if ((me->is_fighting(ob) || ob->is_fighting(me)) && ob->query("qi") > 0)
                                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                        else break;
                }
        }
        
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if ((int)me->query("qi") < 70)
                return notify_fail("����������������ϵ�����\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("����������������ϵ�����\n");
                
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-dao/" + action;
}
