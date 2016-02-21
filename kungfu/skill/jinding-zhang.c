#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "skill_name" : "������̩" ,
        "action": "$N����΢�Σ�һ�С�������̩�������������$nֻ����һ��ů��Ϯ��$l",
        "force" : 100,
        "dodge" : 10,
        "lvl"   : 0,
        "damage_type" : "����",
]),
([      "skill_name" : "��������" ,
        "action": "$N˫�ֱ�ã���ָ�ᵯ��һ�С��������项��������·������ʮ����ץ��$n��$l",
        "force" : 120,
        "dodge" : 10,
        "lvl"   : 20,
        "damage_type" : "����",
]),
([      "skill_name" : "�����" ,
        "action": "$N����ǰ��������ٿ��������ͷ�һ�С�����ơ�����ץ��$n��$l",
        "force" : 150,
        "dodge" : 15,
        "lvl"   : 30,
        "damage_type" : "����",
]),
([      "skill_name" : "������ɳ" ,
        "action": "$N����Ȧת�����$n�����֣������Ƴ���һ�С�������ɳ�����͵ػ���$n���°�",
        "force" : 200,
        "dodge" : 25,
        "lvl"   : 40,
        "damage_type" : "����",
]),
([      "skill_name" : "�׶�����" ,
        "action": "$N�������ף�һ�����ȣ���$nһ㶼䣬����һ�С��׶���������ֱ��$n��$l",
        "force" : 100,
        "dodge" : 10,
        "lvl"   : 50,
        "damage_type" : "����",
]),
([      "skill_name" : "�𶥷��" ,
        "action": "$N˫��ƽ����ȭ��һ�С��𶥷�⡹ʩ������Ӱ���أ��ѱ���ʵ���Ʒ��Ѿ�Ϯ��",
        "force" : 200,
        "dodge" : 15,
        "lvl"   : 70,
        "damage_type" : "����",
]),
([      "skill_name" : "���Ľ�ħ" ,
        "action": "$Nһ������ׯ�ϣ�ʹ�������Ľ�ħ����������磬����$nƯ�Ʋ���",
        "force" : 230,
        "parry" : 20,
        "dodge" : 20,
        "lvl"   : 80,
        "damage_type" : "����",
]),
([      "skill_name" : "����˻�" ,
        "action": "$N˫�ۼ��裬��Ϊ�����Ӱ��һ�С�����˻ġ�����ǵ�Ϯ��$nȫ�������Ѩ",
        "force" : 260,
        "parry" : 5,
        "dodge" : 30,
        "lvl"   : 100,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "tiangang-zhi" || combo == "jieshou-jiushi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");

        if (me->query_skill("force") < 50)
                return notify_fail("����ڹ���򲻹��������������ơ�\n");

        if (me->query("max_neili") < 150)
                return notify_fail("�������̫�����޷��������ơ�\n");

        if (me->query_skill("strike", 1) < me->query_skill("jinding-zhang", 1))
                return notify_fail("��Ļ����Ʒ�̫��޷���������Ľ����ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, jiali;
        int level   = (int) me->query_skill("jinding-zhang",1);
        mapping px_info;
        object victim, ob;

        // lasting effects of piaoxue
        ob = me->select_opponent();

        px_info = me->query_temp("piaoxue/usage_info");
        victim = me->query_temp("piaoxue/target");

        if ( objectp(victim) && ob == victim ) {
            jiali=me->query("jiali");
            if (jiali > px_info["neili_damage"]) 
                jiali = px_info["neili_damage"];
            if (ob->query("neili") > 0) {
                message_vision(HIY "\n$n����͸$P��������ʵ��ֻ�ô����������ȫ������������\n" NOR, me, victim);
                ob->add("neili", -jiali);
            } else {
                message_vision(HIY "\n$nһ�������᲻��������$P�Ʒ�ɨ�У��������ģ��������¡�\n" NOR, me, victim);
                ob->receive_damage("qi", jiali, me);
            }
        }

        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                {
                        a_action = action[NewRandom(i, 20, level / 5)];
                        break;
                }
        a_action["force"] += level / 10;
        a_action["dodge"] += level / 10;
        a_action["parry"] += level / 10;
        a_action["damage"] += level / 10;
        return a_action;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������ϰ�����ơ�\n");

        if (me->query_skill("jinding-zhang", 1) < 100)
                me->receive_damage("qi", 30);
        else
                me->receive_damage("qi", 45);

        me->add("neili", -48);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}
