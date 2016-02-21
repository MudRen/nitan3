#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
    "ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
    "$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
    "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
    "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�$N��һ�����˸��ա�\n",
    "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
    "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge" || usage == "move");
}

int valid_learn(object me)
{
        if ((int)me->query_skill("dodge", 1) < 80)
                return notify_fail("������Ṧ��Ϊ���ޣ��������������ݡ�\n");

        if (me->query("max_neili") < 800)
                return notify_fail("��������Ϊ̫ǳ���������������ݡ�\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("tiyunzong", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 20;
        if (lvl < 150) return 30;
        if (lvl < 200) return 50;
        if (lvl < 250) return 70;
        return 80;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 70 )
                return notify_fail("�������̫���ˣ������������ݡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ�������ϰ�����ݡ�\n");

        me->receive_damage("qi", 58);
        me->add("neili", -55);
        return 1;
}

/*
mixed valid_damage(object ob, object me, int damage, object weapon) 
{
        mixed result; 
        int ap, dp, mp; 

        if ((int)me->query_skill("tiyunzong", 1) < 100 || 
            ! living(me)) 
                return; 

        mp = ob->query_skill("martial-cognize", 1); 
        ap = ob->query_skill("force") + mp; 
        dp = me->query_skill("dodge", 1) / 2 + 
             me->query_skill("tiyunzong", 1); 

        if (ap / 2 + random(ap) < dp) 
        {
                result = ([ "damage": -damage ]); 
                switch (random(3)) 
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "һ�С��׺׳��졹���������ϱ�ֱ���������࣬" 
                                            "$N��ȻʧȥĿ�꣬����ʧ�֣�\n" NOR]); 
                        break; 
                case 1:
                        result += (["msg" : HIC "$n" HIC "һ�������ӷ���������ݳ�����֮Զ��" 
                                            "$Nһ��ʧ�֣�����֮����¶������\n" NOR]); 
                        if (! ob->is_busy())
                        ob->start_busy(random(2)); 
                        break; 
                default: 
                        result += (["msg" : HIC "$n" HIC "ʹ��������չ�᡹����һ��ƮȻ�ݳ���" 
                                            "��Ȼ��������������ŵء�\n" NOR]); 
                        break; 
                }
                return result; 
        } else 
        if (mp >= 100) 
        {
                switch (random(3)) 
                {
                case 0: 
                        result = HIY "$n" HIY "һ�С��׺׳��졹���������ϱ�ֱ���������࣬" 
                                 "����$N" HIY "���Կ���$n����ͼ��\n" NOR;  
                        break; 
                case 1: 
                        result = HIY "$n" HIY "һ�������ӷ���������ݳ�����֮Զ��" 
                                 "$N���̸������ֻ���ֱ�룬��Ϯ$n��\n" NOR;  
                        break; 
                default: 
                        result = HIY "$n" HIY "ʹ��������չ�᡹����һ��ƮȻ�ݳ���" 
                                 "ͻȻ����$N�ٶȸ��죬Ҳ�ȵȺ��ڴˣ�\n" NOR;  
                        break; 
                }
                COMBAT_D->set_bhinfo(result); 
        }
}
*/
string perform_action_file(string action)
{
      return __DIR__"tiyunzong/" + action;
}
