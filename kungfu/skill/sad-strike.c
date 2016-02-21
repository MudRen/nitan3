inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$Nһ�С�"HIW"�������"NOR"��̧ͷ���죬��������������һ��"
                   "���Լ�ͷ���տ��ĳ�������б�£��������ɻ�\n"
                   "�Σ���ɢ��������$n��$l",
        "force"  : 250,
        "attack" : 40,
        "dodge"  : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "�������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIG"��������"NOR"���ֱ��´������ް�������ʽ��"
                   "ͻȻ�������붯���������䡢˫��ͷ��������\n"
                   "�ر�������������ʽ����ײ��$n",
        "force"  : 260,
        "attack" : 45,
        "dodge"  : 45,
        "damage" : 25,
        "lvl"    : 10,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"�����ˮ"NOR"����������Ʈ����������ˮ������"
                   "ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬����\n"
                   "�빥$n",
        "force"  : 280,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 30,
        "lvl"    : 20,
        "skill_name" : "�����ˮ",
        "damage_type": "����"
]),

([      "action" : "$Nһ�С�"HIY"��������"NOR"�������ո���ͷ�������£��Ų���"
                   "�أ����������������$n��$l",
        "force"  : 300,
        "attack" : 55,
        "dodge"  : 55,
        "damage" : 35,
        "lvl"    : 40,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIR"��ʬ����"NOR"���߳�һ�š���һ�ŷ���ʱ�л��"
                   "㱣�����ԼԼ���������޵�����$n",
        "force"  : 330,
        "attack" : 60,
        "dodge"  : 60,
        "damage" : 40,
        "lvl"    : 60,
        "skill_name" : "��ʬ����",
        "damage_type": "����"
]),
([      "action" : "$N˫��ƽ�У�һ�С�"HIM"ӹ������"NOR"��û����ɵ�����$n��$l",
        "force"  : 360,
        "attack" : 70,
        "dodge"  : 65,
        "damage" : 45,
        "lvl"    : 80,
        "skill_name" : "ӹ������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"RED"������ʩ"NOR"��ͻȻ�������࣬ͷ�½��ϣ�����"
                   "���ӣ�һ������$n��$l",
        "force"  : 390,
        "attack" : 80,
        "dodge"  : 70,
        "damage" : 50,
        "lvl"    : 100,
        "skill_name" : "������ʩ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"YEL"�ľ�����"NOR"����ĿԶ���������鸡����ǰ�Ż�"
                   "������ȫ����ʽ����ѧ�и������޲��Ǻ�",
        "force"  : 420,
        "attack" : 90,
        "dodge"  : 75,
        "damage" : 55,
        "lvl"    : 120,
        "skill_name" : "�ľ�����",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"BLU"������ʳ"NOR"�������鸡�����缸�첻�Բ�˯��"
                   "�ĽŲ��ʲյ�Ϯ��$n�����ԣ����ƺ���ȭ��\n"
                   "��$n��$l",
        "force"  : 460,
        "attack" : 100,
        "dodge"  : 80,
        "damage" : 60,
        "lvl"    : 140,
        "skill_name" : "������ʳ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIC"�ǻ��չ�"NOR"�����Ҵ�����ʵʵ�Ĺ���$n��$l",
        "force"  : 490,
        "attack" : 110,
        "dodge"  : 85,
        "damage" : 65,
        "lvl"    : 160,
        "skill_name" : "�ǻ��չ�",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"CYN"��������"NOR"������������״������бб����$n��$l",
        "force"  : 520,
        "attack" : 125,
        "dodge"  : 90,
        "damage" : 90,
        "lvl"    : 70,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"MAG"���񲻰�"NOR"���������ݼ�ת��չ���ṦΧ��$n"
                   "�������ߣ���Ȼ�����������$n��$l",
        "force"  : 550,
        "attack" : 140,
        "dodge"  : 95,
        "damage" : 75,
        "lvl"    : 200,
        "skill_name" : "���񲻰�",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"WHT"��;ĩ·"NOR"������$n���ԣ����ƾٵ���ǰƽ"
                   "�ƶ�������������бб����$n��$l",
        "force"  : 570,
        "attack" : 150,
        "dodge"  : 100,
        "damage" : 80,
        "lvl"    : 220,
        "skill_name" : "��;ĩ·",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIY"����ľ��"NOR"��˫Ŀֱֱ�Ķ���$n�����嶯Ҳ��"
                   "��һ�µķ���$n",
        "force"  : 590,
        "attack" : 155,
        "dodge"  : 105,
        "damage" : 85,
        "lvl"    : 240,
        "skill_name" : "����ľ��",
        "damage_type": "����"
]),
([      "action" : "$N��ͷڤ�룬һ�С�"HIB"������ʧ"NOR"����������ƽƽ����$n"
                   "��$l",
        "force"  : 620,
        "attack" : 160,
        "dodge"  : 110,
        "damage" : 90,
        "lvl"    : 260,
        "skill_name" : "������ʧ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"��ͨ�˴�"NOR"��˫�ƻγ�ǧ����Ӱ��$n��������"
                   "��֮��",
        "force"  : 650,
        "attack" : 165,
        "dodge"  : 115,
        "damage" : 95,
        "lvl"    : 280,
        "skill_name" : "��ͨ�˴�",
        "damage_type": "����"
]),
([      "action" : "$N����ǰ��һ�С�"HIB"¹��˭��"NOR"���������ȣ��Կ������"
                   "һ��ת���Ѿ�ת����$n�������ָ����\n"
                   "��$n�Ĵ�׵Ѩ",
        "force"  : 680,
        "attack" : 170,
        "dodge"  : 120,
        "damage" : 100,
        "lvl"    : 300,
        "skill_name" : "¹��˭��",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
        // ���������� ---- ��Ȼ�����ߣ�Ψ�������

        if (me->query("gender") != "����") 
                return notify_fail("����᲻������˼��һ���˵����飬�޷�������Ȼ�����ơ�\n");

        if (me->query("character") == "�ĺ�����")
                return notify_fail("��һ����ɱ�����ˣ����û�ܽ�����Ȼ����ľ��硣\n");

        if (me->query("character") == "���ռ�թ")
                return notify_fail("��һ����ȥ���ˣ����û�ܽ���������Ȼ����ľ��硣\n");

        if (me->query("str") < 28)
                return notify_fail("������������㣬�޷�������Ȼ�����ơ�\n");

        if (me->query("int") < 24)
                return notify_fail("���������Բ��㣬�޷�������Ȼ�����ơ�\n");
                
        if ((int)me->query_str() < 45)
                return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ȼ�����Ʊ�����֡�\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬�޷�����Ȼ�����ơ�\n");

        if (me->query_skill("force") < 320)
                return notify_fail("���ڹ���Ϊ���㣬�޷�������Ȼ�����ơ�\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("��Ļ���ȭ�Ų�����죬�޷�����Ȼ�����ơ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("sad-strike", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷������������Ȼ�����ơ�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("sad-strike", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 160)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 160)
                return notify_fail("���������������Ȼ�����ơ�\n");

        me->receive_damage("qi", 150);
        me->add("neili", -155);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        mixed result;
        int j;
        
        j = me->query_skill("sad-strike", 1);
        if (damage_bonus < 50) return 0;
        
        if (random(20) >= 10 && ! victim->is_busy() && j > 140)
        {
                switch(random(3))
                {
                case 0 :
                        msg = YEL"$Ņͷ���죬��������������һ����ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ���£�\n"NOR;
                        msg += HIR"���$n����һ�С�������졹���ñ�˵����������վ���Ų�Ҳ�ǲ��ܡ�\n"NOR; 
                        victim->start_busy(2 + random(2));
                        break;
                case 1 :
                        msg = HIB"$N��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣡\n"NOR;
                        msg += HIR"���$n����һ�С������ˮ�������������ݺ��ξ��ˣ�����ײײ��\n"NOR;
                        victim->start_busy(3 + random(2));               
                        break;
                case 2 :
                        msg = HIG"ͻȻ��$N�����붯���������䡢˫��ͷ���������ر�������������ʽ������\n"NOR;
                        msg += HIR"���$n����һ�С��������С���������ȫȻ�������ľ��ء�\n"NOR;
                        victim->start_busy(4 + random(2));
                        break;               
                }         
                return msg;
        } else
        {
                result = ([ "damage" : damage_bonus ]);
                result += ([ "msg" : HIR "ֻ�������ۡ���һ����$n" HIR "�����һ�����Ѫ��\n" NOR]);
                
                return result;
        }
        
}

string perform_action_file(string action)
{
        return __DIR__"sad-strike/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("sad-strike", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}


string query_description()  
{
        return 
        "����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣����ñ����������ں���֮��������"
        "����֮�󣬳����ڹ�ѭ�򽥽�֮�⣬����޿��������������ռ�˼��С��Ů��"
        "����������������������Ȥ��һ���ں�����Ȼ���ã���������֮������ȭ���"
        "�ߣ���ʱ���ڹ�����ѵ���һ���־��߼�������������һ�ƣ�����̲��һֻ��"
        "����ı��Ǵ�÷��顣���ɴ���˼��������һ���������Ʒ���������Ѱ���书"
        "���죬����֮����ȫ��������һ����һʮ���С�����ƽ�ܹ�������ѧ���ҵ�ָ"
        "�㣬��ȫ���ѧ�����������ڹ��Ŀھ�����С��Ůѧ�á���Ů�ľ������ڹ�Ĺ"
        "�м����������澭����ŷ�����Ը�󡹦����ת���������߹���������Դ򹷰�"
        "������ҩʦ���Ե�ָ��ͨ�����｣��������һ��ָ֮�⣬��а����������ؤ��"
        "����ͨ����ѧ��������������Ĺ�ɵ���ѧ����������֮����辶����ʱ��"
        "���ͨ������׿Ȼ�ɼҡ�ֻ������ʣһ�ۣ����Բ��������仯ȡʤ����������"
        "����ѧͨ���෴�����������Ƴ�����Ϊ����Ȼ�����ơ���ȡ���ǽ��͡��𸳡�"
        "����һ�䡰��Ȼ�����ߣ�Ψ������ӡ�֮�⡣";
}
