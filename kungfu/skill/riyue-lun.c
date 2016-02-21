#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С������ơ����������е�$w��$n��$l��ȥ",
        "force"  : 120,
        "attack" : 27,
        "dodge"  : -10,
        "parry"  : 40,
        "lvl"    : 0,
        "damage" : 62,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$Nʹһ�С���ɽ���ơ���˫��һ�����趯����$w��$n��$l��ɨ",
        "force"  : 160,
        "attack" : 38,
        "dodge"  : -20,
        "parry"  : 45,
        "lvl"    : 35,
        "damage" : 66,
        "damage_type" : "����",
        "skill_name"  : "��ɽ����",
]),
([      "action" : "$Nʹһ�С���΢�ơ����͵�һ�����������¶�������$n��$l",
        "force"  : 200,
        "attack" : 43,
        "dodge"  : -20,
        "parry"  : 47,
        "lvl"    : 70,
        "damage" : 70,
        "damage_type" : "����",
        "skill_name"  : "��΢��",
]),
([      "action" : "$Nʹһ�С������ơ����������֮��$wɨ��$n��$l",
        "force"  : 240,
        "attack" : 51,
        "dodge"  : 5,
        "parry"  : 50,
        "lvl"    : 100,
        "damage" : 75,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$Nʹһ�С�Բ���ơ���$w������֮����ֱ��$n��$l",
        "force"  : 280,
        "attack" : 55,
        "dodge"  : -10,
        "parry"  : 55,
        "lvl"    : 120,
        "damage" : 80,
        "damage_type" : "����",
        "skill_name"  : "Բ����",
]),
([      "action" : "$NԾ���գ�ʹһ�С����ػ��ơ����߾�$w����$n��$l",
        "force"  : 320,
        "attack" : 61,
        "dodge"  : 10,
        "parry"  : 60,
        "lvl"    : 140,
        "damage" : 85,
        "damage_type" : "����",
        "skill_name"  : "���ػ���",
]),
([      "action" : "$Nʹһ�С�׽���ơ���б������$w����$n��$l",
        "force"  : 360,
        "attack" : 65,
        "dodge"  : -15,
        "parry"  : 68,
        "lvl"    : 150,
        "damage" : 95,
        "damage_type" : "����",
        "skill_name"  : "׽����",
]),
([      "action" : "$N��һ��������ʹ�����Լ��项��$wɨ��$n��ͷ��",
        "force"  : 400,
        "attack" : 70,
        "dodge"  : -20,
        "parry"  : 75,
        "lvl"    : 160,
        "damage" : 110,
        "damage_type" : "����",
        "skill_name"  : "�Լ���",
]),
});

string  *msg = ({
        CYN"��������ֻ$w"CYN"�Ի����������������Ʋ���������$n"CYN"һ��֮�ʣ�$w"CYN"�����˳�ȥ��"NOR,
        MAG"���������У�$w"MAG"��ת������ײ��$n"MAG"����$p"MAG"��Ҫ����ʱ��ȴ�ƹ�$n"MAG"�ɵ�������"NOR,
        MAG"$w"MAG"���������������ɻأ�����$n"MAG"����Ȧ�ӣ����ߺ��ͣ�������б����������Ҳ���������죬�Թ����˾����ŵ��ۻ����ң����񲻶�"NOR,
        YEL"һ����С���ˣ�������Ȼ��$w"YEL"�����һ��������$n"YEL"ײȥ��������ţ���������ɵ�"NOR,
        HIB"ֻ��$w"HIB"����$n"HIB"�����·��ɣ�$w"HIB"��Ծ�鶯�����������������Ƶ����������絶���Ҫ��$n"HIB"��������"NOR,
        HIR"ͻȻ��������𣬼�������$w"HIR"������ײ�����ֹ�һ���ϲ�����$n��ȥ"NOR,
        HIG"������$n"HIG"��ǰ���ģ��͵���$p"HIG"ӭͷ���£������ַ���һ�֣�һ��һ�ͣ��������죬����$n"HIG"$l"NOR,
        HIW"������Х���У�����ֻ$w"HIW"��ֱ�ɡ���б�ɡ������������׹������������ʱ��$n"HIW"��ȫ����·�ѱ�����"NOR,
        HIC"�͵���$w"HIC"��$n"HIC"$l�����£���$p"HIC"����ж��֮ʱ��$w"HIC"��ͻȻ�Ϸɻ���������$p"HIC"��$l"NOR,
        HIM"��$w"HIM"�����ҵ���$n"HIM"ȴ������ͷ�����������һһ��������$w"HIM"���糤�����۾�һ�㣬��Ȼ�����ɵ���$n"HIM"$l"NOR,
        HIG"����ɭɭ���˵�����$w"HIG"����������ζ��������������죬�ڲ���գ�۵�˲Ϣ�䣬ҫĿ�ĵ���������������������⣬Ѹ����ƥ�Ļ�$n��"NOR,
        MAG"�����ٴκ�Χ���ϵ羫âΧ��$n"MAG"�������������䣬ǧ����Ӱ��ӳ��һ��������ѣĿ��ͼ������ͼ�������ˣ�����һƬ����ε���ɫѩ����"NOR,
});

int valid_enable(string usage)
{
	return usage == "hammer" || usage == "parry";
}

int valid_learn(object me)
{
        /*
        if (me->query("str") < 32)
                return notify_fail("�������������㣬�������������ַ���\n");
        */

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("hammer", 1) < 100)
                return notify_fail("��Ļ��������������������������ַ���\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("riyue-lun", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������ַ���\n");

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
        string str, message;        
        level = (int) me->query_skill("riyue-lun",1);
        
        if (! userp(me) && weapon)
        {
                if (weapon->query("id") == "jin lun") 
                        str = "����";
                else if (weapon->query("id") == "yin lun") 
                        str = "����";
                else if (weapon->query("id") == "fa lun") 
                        str = "����";
                else str = weapon->name();
                message = msg[random(sizeof(msg))];
                message = replace_string(message, "$w", str);
                switch(str)
                {
                case "����" : 
                        message = HIY+message+NOR; break;
                case "����" : 
                        message = HIW+message+NOR; break;
                case "����" : 
                        message = HIC+message+NOR; break;
                default : break;
                }
                return ([
                        "action" : message,
                        "damage" : 200,
                        "damage_type" : random(2)?"����":"����",
                        "dodge" : 100,
                        "parry" : 100,
                        "attack": 200,
                ]);
        }        
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("������������������������ַ���\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������������ַ���\n");

        me->receive_damage("qi", 62);
        me->add("neili", -68);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        //  object master;   
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if (weapon1 && me->query_skill("riyue-lun", 1) > 150 && me->query("jiali")
        &&  me->query("neili") > 1000 
        &&  random(10) >= 5 && (string)weapon->query("skill_type") == "hammer"
        &&  me->query_skill_mapped("parry") == "riyue-lun")
        {
                message_combatd(HIW"$N�ֱ۱�����ʩչ�������־���"+weapon->name()+
                                HIW"̽�������һ����ס��$n"+weapon1->name()+HIW"��\n"NOR, 
                                me, victim);

                if (random(me->query_str()) > victim->query_str())
                {           
                        me->add("neili", -100);
                        message_combatd(HIG+me->query("name")+"�˾�������$n�۹ǿ���һ������Щ�ͱ����ϣ���ʹ֮����һ�ɣ�"+
                                        weapon1->name()+HIG"�����˹�ȥ��\n"NOR, me, victim);
                        weapon1->unequip();
                        weapon1->move(me);
                } else 
                if (random(me->query_str()) > victim->query_str() / 2)
                {           
                        me->add("neili", -50);
                        message_combatd(HIG+me->query("name")+"�˾�������$N���������ļ������������ھ�ʹ��"+
                                        weapon1->name()+HIG"���ַɳ���\n"NOR, victim);
                        weapon1->unequip();
                        weapon1->move(environment(victim));
                } else
                if (victim->query_temp("shield"))
                {           
                        me->add("neili", -50);
                        message_combatd(HIY"$N����ǰ�壬"+weapon1->name()+HIY"ֱ�̹�ȥ������"+
                                        victim->query("name")+"�����������û��˿�ȥ��\n"NOR, victim);
                }

                else    message_combatd(HIY"$N����ǰ�壬"+weapon->name()+HIY"ֱ��"+victim->query("name")+"��"+
                                        victim->query("name")+"������죬"+weapon->name()+HIY"һ�����ѣ��������˿�ȥ��\n"NOR, 
                                        victim);
        }
}

