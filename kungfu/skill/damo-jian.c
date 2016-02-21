#include <ansi.h>
inherit SHAOLIN_SKILL;

mapping *action = ({
([      "action": "$Nʹһʽ��������Ե����������$w����΢�񣬻ó�һ���������$n��$l",
        "force" : 90,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 15,
        "lvl"   : 0,
        "skill_name" : "������Ե��",
        "damage_type": "����"
]),
([      "action": "$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w��������$n��$l��ȥ",
        "force" : 140,
        "attack": 50,
        "dodge" : 15,
        "parry" : 25,
        "damage": 30,
        "lvl"   : 40,
        "skill_name" : "��ȥ������",
        "damage_type": "����"
]),
([      "action": "$Nһʽ��������ɣԶ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
        "force" : 160,
        "attack": 60,
        "dodge" : 25,
        "parry" : 28,
        "damage": 40,
        "lvl"   : 80,
        "skill_name" : "������ɣԶ",
        "damage_type": "����"
]),
([      "action": "$N��������Ծ��һʽ���ֻط����᡹���������ּ�ת������ն��$n��$l",
        "force" : 180,
        "attack": 70,
        "dodge" : 20,
        "parry" : 35,
        "damage": 55,
        "lvl"   : 120,
        "skill_name" : "�ֻط�����",
        "damage_type": "����"
]),
([      "action": "$N����$w�й�ֱ����һʽ��ˮ��ͨ���š���������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 220,
        "attack": 80,
        "dodge" : 25,
        "parry" : 42,
        "damage": 60,
        "lvl"   : 130,
        "skill_name" : "ˮ��ͨ����",
        "damage_type": "����"
]),
([      "action": "$N����$wбָ���죬��â���£�һʽ������������������׼$n��$lбб����",
        "force" : 260,
        "attack": 85,
        "dodge" : 25,
        "parry" : 51,
        "damage": 70,
        "lvl"   : 140,
        "skill_name" : "����������",
        "damage_type": "����"
]),
([      "action": "$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��ǧ��һέȥ������$n��$l",
        "force" : 320,
        "attack": 90,
        "dodge" : 30,
        "parry" : 59,
        "damage": 75,
        "lvl"   : 150,
        "skill_name" : "ǧ��һέȥ",
        "damage_type": "����"
]),
([      "action": "$N���Ƶ�����һʽ�����Ķ���������$w�Ի���Ծ�����缲�������$n���ؿ�",
        "force" : 380,
        "attack": 95,
        "dodge" : 25,
        "parry" : 67,
        "damage": 90,
        "lvl"   : 160,
        "skill_name" : "���Ķ�����",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("damo-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ĵ�Ħ������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;       
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        int j, wt;
        object target;
        string *msg;

        level   = (int) me->query_skill("damo-jian",1);
        wt = me->query_temp("sl_weituo");
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

        msg = ({ 
                HIR"\n$N����Խ��Խ��������ͻ�죬���֮�䣬$n" +HIR"��ȫ�ǽ���������\n"NOR,
                HIY"\n$N���潣ת���ؽ����ӣ�һ������һ�������಻�����������������������ޱȡ�\n"NOR,
                HIC"\nԭ����Ħ���ߵľ��Ǹ���·�ӣ��˿�ȴ���������鶯֮�������Ƹ���������\n"NOR,
                HIW"\n��ʱ$N�Ľ���һ���Ƴ���Ȼ������Τ�ӷ�ħ�������ӵ������쾡�¡�\n"NOR,
        });

        if( wt > 1 && wt < 6 && !me->query_temp("weituo_attack")) {

                message_vision( msg[wt-2] , me, weapon);
                me->set_temp("weituo_attack", 1);
                for( j=0; j < wt-1; j++ )
                {
                        if (! me->is_fighting(target)) break;
                        me->add("neili", -50);
                        COMBAT_D->do_attack(me, target, weapon);
                }
                me->delete_temp("weituo_attack", 1);
                me->add_temp("sl_weituo", 1);

        }        

        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("���������������Ħ����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("���������������Ħ����\n");

        me->receive_damage("qi", 62);
        me->add("neili", -69);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"damo-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{ 
        object weapon;
        int i;
        
        if (me->query("neili") < 300 
        ||  me->query_skill_mapped("sword") != "damo-jian" 
        ||  ! objectp(weapon = me->query_temp("weapon")) 
        ||  weapon->query("skill_type") != "sword") 
                return 0; 
                
        if (me->query_temp("damo-jian/lian") ||
            me->is_busy())
                return 0;

        message_combatd(HIY "\n$N" HIY "���潣ת���ؽ����ӣ�һ������һ�������಻����"
                        "�������������������ޱȡ�\n" NOR, 
                        me, victim); 
                                             
        me->add("neili", -270); 
                       
        me->set_temp("damo-jian/lian", 1); 
        
        for (i = 0; i < 3; i++) 
        { 
                if (! me->is_fighting(victim)) 
                        break; 
                  
                if (! victim->is_busy() && random(2) == 1) 
                        victim->start_busy(1); 
        
                COMBAT_D->do_attack(me, victim, weapon, 0); 
        } 
        me->delete_temp("damo-jian/lian"); 
        
}
                        
