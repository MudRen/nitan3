// SKILL liuyang-zhang.c
#include <ansi.h>
#include <combat.h>

inherit SKILL;

int baihong(object me, object victim, int damage);

mapping *action = ({
([	"action" : "$Nһ�С������۽𡹣����Ƶ�������֮�ϣ�����$n",
	"force" : 100,
        "attack": 2,
	"dodge" : 30,
        "parry" : 1,
	"damage": 5,
	"lvl"   : 0,
	"skill_name" : "�����۽�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������ƶ���������ɫ���أ�˫����ƮƮ������$n",
	"force" : 130,
        "attack": 8,
	"dodge" : 25,
        "parry" : 3,
	"damage": 30,
	"lvl"   : 20,
	"skill_name" : "�����ƶ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���б��·��ϼ������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 160,
        "attack": 12,
	"dodge" : 43,
        "parry" : 4,
	"damage": 35,
	"lvl"   : 30,
	"skill_name" : "��б��·��ϼ��",
	"damage_type" : "����"
]),

([	"action" : "$Nһ�С���������������$n��$l��������",
	"force" : 210,
        "attack": 15,
	"dodge" : 55,
        "parry" : 8,
	"damage": 50,
	"lvl"   : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�����һ���ͽ��ѡ���ֻ��һƬ��Ӱ����$n",
	"force" : 250,
        "attack": 22,
	"dodge" : 52,
        "parry" : 0,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "����һ���ͽ���",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ�С���ϼ���������$n",
	"force" : 300,
        "attack": 23,
	"dodge" : 65,
        "parry" : 11,
	"damage": 50,
	"lvl"   : 80,
	"skill_name" : "��ϼ������",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С����ղγ��֡���ֻ��һƬ��Ӱ����$n",
	"force" : 310,
        "attack": 28,
	"dodge" : 63,
        "parry" : 5,
	"damage": 80,
	"lvl"   : 100,
	"skill_name" : "���ղγ���",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ�ǡ���ϼ��Ѧᡡ�����$n��ͷ��",
	"force" : 330,
        "attack": 25,
	"dodge" : 77,
	"damage": 90,
        "parry" : 12,
	"lvl"   : 120,
	"skill_name" : "��ϼ��Ѧ�",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��������������������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 360,
        "attack": 31,
	"dodge" : 80,
        "parry" : 15,
	"damage": 100,
	"lvl"   : 140,
	"skill_name" : "���������",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ���������������˫��ͬʱ����$n��$l",
	"force" : 400,
        "attack": 32,
	"dodge" : 81,
        "parry" : 10,
	"damage": 130,
	"lvl"   : 160,
	"skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
        if ((int)me->query("str") < 30)
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("����ڹ���򲻹����޷��������ơ�\n");

	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷��������ơ�\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("liuyang-zhang", 1))
		return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������ɽ�����ơ�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, busy_time;
	//object target = offensive_target(me);
	object victim;
	string *limbs, limb, msg;

	level = (int)me->query_skill("liuyang-zhang", 1);
	victim = me->select_opponent();
	if (!victim)
	{
		for( i = sizeof(action); i > 0; i-- )
			if( level > action[i-1]["lvl"] )
				return action[NewRandom(i, 20, level/5)];
	}
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	busy_time = level/20;

	if( random(me->query_temp("lingjiu/baihong")) > 50 || me->query_temp("baihong_attack") ) 
	{
		switch( me->query_temp("baihong_attack") )
		{
			case 1: msg = "����$N����һ���������ƹ�$N�����ӣ�ֱ����$p$l";
				break;
			case 2: msg = WHT"˭֪$Nһ��δ�ߵڶ����������������ؾ����������糤��֮�Σ���������"NOR;
				break;
			default: msg = WHT"ͻȻ��$N�����ƿգ�����$n"+limb+"���������棬�����絶��ת��б��$p$l"NOR;
				break;
		}

		me->add_temp("lingjiu/baihong", -1); 
		me->add("neili", -30);

		return ([
			"action": msg,
			"force" : 380+random(120),
			"dodge" : 10,
			"damage": 120+random(80),
			"damage_type":"����",
			"post_action": (: baihong :)
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("���������������ɽ�����ơ�\n");

	me->receive_damage("qi", 61);
	me->add("neili", -57);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}

int baihong(object me, object victim, int damage)
{
	int level = (int)me->query_skill("liuyang-zhang", 1)/2;

	me->add_temp("baihong_attack", 1);

	if( damage == RESULT_DODGE && me->query_temp("baihong_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("baihong_attack") == 1 )
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		else me->delete_temp("baihong_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("baihong_attack");
	return 1;
}
