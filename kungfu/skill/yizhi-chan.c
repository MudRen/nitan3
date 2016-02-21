// yizhi-chan.c һָ��
#include <ansi.h>
inherit SHAOLIN_SKILL;

mapping *action = ({
([      "action": "$N˫ָ��£��һʽ�������������������ϣ�������һǰһ�����$n���ظ���",
        "force" : 340,
        "attack": 75,
        "dodge" : 35,
        "parry" : 55,
        "damage": 22,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action": "$N���ƻ��أ�һʽ��������ա���������ָǰ���˸��뻡���͵�һ"
                  "˦������$n��$l",
        "force" : 370,
        "attack": 70,
        "dodge" : 10,
        "parry" : 45,
        "damage": 15,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action": "$N����������һʽ�����Ź�ɡ���˫��ʳָ�˲������һ����������"
                  "��$n��ȫ��ҪѨ",
        "force" : 360,
        "attack": 72,
        "dodge" : 10,
        "parry" : 52,
        "damage": 15,
        "skill_name" : "���Ź��",
        "damage_type" : "����"
]),
([      "action": "$N��ϥ������һʽ�����ޱߡ���������ȭ���⣬����Ĵֱָ����ң"
                  "ң����$nһ��",
        "force" : 380,
        "attack": 68,
        "dodge" : 5,
        "parry" : 48,
        "damage": 20,
        "skill_name" : "���ޱ�",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_combine(string combo) { return combo == "banruo-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��һָ��������֡�\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ���򲻹����޷�ѧһָ����\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷���һָ����\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("yizhi-chan", 1))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷����������һָ����\n");

    return 1;
}

string query_skill_name(int level)
{
        return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("����������ϰ��\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("�������������һָ����\n");

        me->receive_damage("qi", 62);
        me->add("neili", -68);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yizhi-chan/" + action;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("yizhi-chan", 1);

        if( level == 180 && ! me->query("sl/con"))
        {
                me->add("con", 1);
                me->set("sl/con", 1);
                tell_object(me, "���һָ���Ͱ�����ѧ�����ɣ��������ĸ��ǡ�\n");
        }
        /*
        if ((string)me->query("family/family_name") == "������")
        {
                if( !(level % 10) && level >= (int)me->query_skill("hunyuan-yiqi", 1) )
                {
                        me->improve_skill("hunyuan-yiqi", (level - 5), 1);
                        tell_object(me, "����һָ�������������������Ļ�Ԫһ������Ϊ��\n");
                }
        }
        */
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() )
        {
                result = ([ "damage" : damage_bonus ]);
                result += ([ "msg" : HIR "���������ݡ�һ�����죬һ�ɾ���ֱ͸$n��ǰ�أ�\n" NOR ]);
                return result;
        } 
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yizhi-chan", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
