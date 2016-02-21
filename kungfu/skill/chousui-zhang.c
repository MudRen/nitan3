#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "force" : 180,
        "attack": 49,
        "dodge" : -30,
        "parry" : -37,
        "dmage" : 32,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "force" : 230,
        "attack": 56,
        "dodge" : -22,
        "parry" : -34,
        "dmage" : 47,
        "damage_type": "����"
]),
([      "action": "$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
        "force" : 260,
        "attack": 61,
        "dodge" : -20,
        "parry" : 10,
        "dmage" : 60,
        "damage_type": "����"
]),
([      "action": "$Nһ���ֽУ�˫��Ю��һ���ȳ�֮������$n��$l",
        "force" : 380,
        "attack": 79,
        "dodge" : 17,
        "parry" : 36,
        "dmage" : 65,
        "damage_type": "����"
]),
([      "action": "$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n",
        "force" : 420,
        "attack": 81,
        "dodge" : 27,
        "parry" : 21,
        "dmage" : 75,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "sanyin-zhua";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 50)
                return notify_fail("��Ļ����������㣬�޷��������ơ�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("����Ʒ��������㣬�޷��������ơ�\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ̫�����޷��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("choushui-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ĳ����Ʒ���\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (present("huo yan", environment(me)))
        {
                if (random(me->query_skill("strike")) > 250 && me->query("neili") > 1000) 
                {
                        me->add("neili", -100);
                        return ([
                                "action": BLU "$N��ɫ�ҵ������ִ򿪷��٣������´����������ϣ�������ҧ��⣬" HIR "һ����"
                                "Ѫ���������ȥ��\n�ǻ������һ����" HIW "�漴��Ϊ������$N�͵����Ӽ���������"
                                "�ݰ���ת��ʮ���Ȧ�ӣ�\n" HIR "�����������������Ѷ��ز��𣬱���һ����ǽ����$nѹ��ȥ" NOR,
                                "force" : 450,
                                "dodge" : 100,
                                "parry" : 100,
                                "weapon": "����",
                                "attack": 200,
                                "damage_type": "����"]);
                }
                if (random(me->query_skill("strike")) > 215 &&
                    me->query("neili") > 800) 
                    {
                        me->add("neili", -75);
                        return ([
                                "action": HIG "$N������ȣ�������ʢ���̻�ͻȻ����һ��" 
                                          HIR "����Ļ�����$n���������\nʹ�����ͣ�ȥ����죬" 
                                          HIG "ֻ��һ���̵Ļ����ڿ��й�µµ��Ѹ��ת��" NOR,
                                "force" : 420,
                                "dodge" : 90,
                                "parry" : 90,
                                "weapon": "����",
                                "attack": 180,
                                "damage_type": "����"]);
                }
                if (random(me->query_skill("strike")) > 180 &&
                    me->query("neili") > 600) 
                {
                        me->add("neili", -50);
                        return ([
                                "action": HIR "$N����һ����һ�ɾ���ֱ�������֮�У�"+HIG+"�������ֳַ�һ��ϸϸ���̻𣬱���һ��ˮ�߰㣬\n"
                                          HIW "$N����Ӷ������ɾ����Ϯ$n����" NOR,
                                "force" : 400,
                                "dodge" : 80,
                                "parry" : 80,
                                "weapon": HIG "�̻�" NOR,
                                "attack": 150,
                                "damage_type": "����"]); 
                }
                if (random(me->query_skill("strike")) > 150 &&
                    me->query("neili") > 500) 
                {
                        me->add("neili", -20);
                        return ([
                                "action": HIR "$N�漴����б�ĳ�һ��"+HIG+"�̻�"+HIR+"��$n��ȥ���������ڣ�"+HIG+"����һ����ɫ���ߺ��Կռʣ�����ڶ���\n"
                                          HIR "��ɫ�������ޣ�"+BLU+"���ǹ��죬��â��˸����"+HIG+"��ӳ��$nͷ���Ա�"NOR,
                                "force" : 400,
                                "dodge" : 80,
                                "parry" : 80,
                                "weapon": HIG"�̻�"NOR,
                                "attack": 120,
                                "damage_type": "����"]); 
                }
                
                if (random(me->query_skill("strike")) > 120 &&
                        me->query("neili") > 400 ) {
                        me->add("neili", -10);
                        return ([
                                "action": HIR "$NͻȻ��˫ü����һ��������ʳָ�����㣬������������������죬"+HIG+"��������𻨣���������һ�㣬\n"
                                          "��$N���������£��ִ�����Ϯ��$n������Ѹ��֮��" NOR,
                                "force" : 400,
                                "dodge" : 80,
                                "parry" : 80,
                                "attack": 100,
                                "weapon": "��",
                                "damage_type": "����"]);
                }
        }        
        level = (int) me->query_skill("chousui-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("������������������ơ�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -55);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chousui-zhang", 1);
        flvl = me->query("jiali");

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("xx_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                // �����ǳ����Ƶ� perform sandu �е�ɢ������ת�����
                if (me->query_skill("poison", 1) < 101) 
                        me->set("body_poison", me->query_skill("poison", 1) + 1); 
                if (me->query_skill("poison", 1) > 100) 
                        me->set("body_poison", me->query_skill("poison", 1) + 10); 
                //  ɢ������
                return HIW "$n" HIW "ֻ��һ�󼫺����ĵ����𣬿���������$N" HIW "���ϵľ綾��\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"chousui-zhang/" + action;
}
