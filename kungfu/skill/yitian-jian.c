// ���콣��
// write by snkboy
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action": "$N���⽣â������һ�С����캮â��������$w�󿪴��أ���âֱ��$n��$l",
        "force" : 250,
        "attack": 150,
        "dodge" : 50,
        "parry" : 50,
        "damage": 51,
        "lvl"   : 0,
        "skill_name" : "���캮â",
        "damage_type" : "����"
]),
([      "action": "$N��â���£�����$wһ�С������������������������ֱ����$n��$l",
        "force" : 270,
        "attack": 180,
        "dodge" : 60,
        "parry" : 60,
        "damage": 78,
        "lvl"  : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ���񽣷������������ƽ���������ʵ��׷ɣ��ó�����ǹ�Ʈ��$n",
        "force" : 280,
        "attack": 220,
        "dodge" : 80,
        "parry" : 80,
        "damage": 147,
        "lvl"   : 50,
        "skill_name" : "�񽣷���",
        "damage_type" : "����"
]),
([      "action": "$N�ӽ��ֻ�����������ǰԾ����$wһʽ��Ⱥа���ס�����������֮�ƣ�����$n",
        "force" : 290,
        "attack": 231,
        "dodge" : 81,
        "parry" : 83,
        "damage": 155,
        "lvl"   : 80,
        "skill_name" : "Ⱥа����",
        "damage_type" : "����"
]),
([      "action": "$N���ֽ�ָ��ת������һŤ������$wһ�ǡ�������ħ�����¶��ϴ���$n��$l",
        "force" : 300,
        "attack": 275,
        "dodge" : 95,
        "parry" : 95,
        "damage": 193,
        "lvl"   : 150,
        "skill_name" : "������ħ",
        "damage_type" : "����"
]),
(["action": HIR "$N��ɫ�������أ���������$w"NOR""HIR"��ͻȻԾ������һ��ʹ��һ�С����첻������\n����$w"NOR""HIR"�������ϻ���һ�������Ļ��ߴ���$n��$l" NOR,    
         "damage": 250,  
         "attack": 300,  
         "dodge": 100,  
         "parry": 100,  
         "lvl": 150,  
         "damage_type": "����",  
         "skill_name": "���첻��",  
]), 
(["action": HIY "$N����Ծ��˫���ս�����ͷ��ʹ�����콣�����塰˭�����桱���⿴�Ƽ�򵥵���һ����\n�����صĽ���ֱ��$n��$l��ȥ"NOR,  
         "damage": 300,  
         "attack": 350,  
         "dodge": 120,  
         "parry": 120,  
         "lvl": 220,  
         "damage_type": "����",  
         "skill_name": "˭������",  
])
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query("character") == "�ĺ�����" ||
            me->query("character") == "���ռ�թ" ||
            me->query("character") == "������")
                return notify_fail("������Ը��ʺ������˽�����\n"); 

        if ((int)me->query("int") < 33) 
                return notify_fail("�����������ԶҲѧ�������콣����\n"); 

        if ((int)me->query("con") < 28)  
                return notify_fail("������ǲ��ʺ��������콣����\n"); 

        if ((int)me->query("max_neili") < 250)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("��Ļ����������̫ǳ��\n");

        if (me->query_skill("sword", 1) < me->query_skill("yitian-jian"))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������콣����\n");

        return 1;
}

mapping query_action(object me, object weapon) 
{
        int i, level; 
        level = (int) me->query_skill("yitian-jian", 1); 
         for (i = sizeof(action); i > 0; i--) 
                 if (level > action[i - 1]["lvl"]) 
                         return action[NewRandom(i, 5, level / 5)]; 
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/*
mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("yitian-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}
*/

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("����������������콣����\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("����������������콣����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{
         mixed result; 
         object weapon; 
         if (damage_bonus < 100)
         {
                 result =  ([ "damage" : damage_bonus / 2]);  
                 result += (["msg" : "$n"NOR""HIR"ֻ��һ����������ֻ��"NOR"$n"HIR"����Ǿ�¶��һ˿Ѫɫ��\n" NOR]); 
                 return result;  
         }

/*
         if (objectp(weapon) && (string)weapon->query("id") == "yitian jian") 
         {
         victim->receive_damage("qi", me->query_skill("yitian-jian") / 2, me); 
         victim->receive_damage("jing", me->query_skill("yitian-jian") / 5, me); 
         return WHT "$N�������콣����ʱ�����ʤ������֮��������Х������$n" 
                WHT "$nֻ����Ѫ���ڣ����ۡ����³�һ����Ѫ��\n" NOR; 
         }
*/

         if (damage_bonus > 100) 
         { 
                 result =  ([ "damage" : damage_bonus ]); 
                 result += (["msg" : "$n"NOR""MAG"ֻ��һ����������ֻ��"NOR"$n"MAG"Ѫð���ɣ��ѱ�$N�Ľ������ˣ�\n" NOR]);
                 return result; 
         } 
}


string perform_action_file(string action)
{
        return __DIR__"yitian-jian/" + action;
}
