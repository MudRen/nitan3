// qishang-quan.c -����ȭ
// modify by LONELY 2003
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l",
	"force" : 180,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ�",
	"force" : 220,
	"dodge" : 5,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "ľ�ѳ���",
        "damage_type" : "����"
]),
([	"action" : "$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���",
	"force" : 250,
	"dodge" : 15,
	"damage": 20,
	"lvl" : 70,
	"skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ��һʽ���𺣵�ɽ����˫ȭ���ջ��£��Ʋ��ɵ�",
	"force" : 290,
	"dodge" : 5,
	"damage": 30,
	"lvl" : 100,
	"skill_name" : "�𺣵�ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����һʽ�������������ȭ���¶��ϣ�����$n",
	"force" : 330,
	"dodge" : 10,
	"damage": 45,
	"lvl" : 120,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��һʽ������Ҳҡ�������$n����ǰ���",
	"force" : 350,
	"dodge" : 25,
	"damage": 60,
	"lvl" : 140,
	"skill_name" : "����Ҳ�",
        "damage_type" : "����"
]),
([	"action" : "$N���λ�λ������ȭ����һʽ���������ա�������˷�����ȭӰ",
	"force" : 370,
	"dodge" : 15,
	"damage": 75,
	"lvl" : 150,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ�����߽��ˡ�����Ȼ����$n��ǰ��",
	"force" : 390,
	"dodge" : 20,
	"damage": 100,
	"lvl" : 160,
	"skill_name" : "���߽���",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");

	if ((int)me->query_skill("force", 1) < 120)
		return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");

	if ((int)me->query("max_neili") < 1800)
		return notify_fail("���������Ϊ�������޷�������ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < 120)
                return notify_fail("��Ļ���ȭ����򲻹����޷�������ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("qishang-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���������޷��������������ȭ��\n");

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
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("�����������������ȭ��\n");

	me->receive_damage("qi", 55);
	me->add("neili", -61);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        mixed result;
        int lvl;
        int flvl;

        lvl  = me->query_skill("qishang-quan", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (random(lvl) > 80 && (int)me->query("neili") > 300 &&       
            victim->affect_by("qs_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                result = ([ "damage" : damage_bonus ]);
                me->add("neili", -200);
                
                switch(random(7))
                {
                case 0 :
                        msg = MAG"$N��������ʹ������ȭ�ܾ��еġ�"HIR"���ľ�"MAG"����˫ȭһ�ɸ���֮����$n��ȥ��\n"NOR;
                        break;
                case 1 :
                        msg = HIB"$N����һ��������ȭ��ʹ������ȭ�ܾ��еġ�"HIR"�˷ξ�"HIB"����˫ȭƮ��������$n��ʱ�о�һ������֮��ӭ�������\n"NOR;
                        break;
                case 2 :
                        msg = HIC"$N��ȭ����ʹ������ȭ�ܾ��еġ�"HIR"�ݸγ���"HIC"����˫ȭ�������ᣬ��$n��ȥ��\n"NOR;
                        break;
                case 3 :
                        msg = HIG"$N��������ʹ������ȭ�ܾ��еġ�"HIR"�����"HIG"����˫ȭ�����иգ����һ������֮������$n��ȥ��\n"NOR;
                        break;
                case 4 :
                        msg = HIY"$N��������ʹ������ȭ�ܾ��еġ�"HIR"��ʧ��"HIY"����˫ȭ����������������ֱ��$n��ȥ��\n"NOR;
                        break;
                case 5:
                        msg = HIM"$N��������ʹ������ȭ�ܾ��еġ�"HIR"���㱾�"HIM"������$n�ͳ�һ�ɺ��֮����\n"NOR;
                        break;
                case 6:
                        msg = HIR"$N���һ�����뷢���ţ�ʹ���������ܾ���������˫ȭ����������������ٱ������$n��\n"NOR;
                        break;
                }
                msg += HIW"$nֻ����$N��һȭ֮�й����߹ɲ�ͬ��������ðٶˣ���ԥ���ѱ������������ȫ����ʱ�������ص����ˡ�\n" NOR;  
                result += ([ "msg" : msg ]);
                return result;       
        }
}

void skill_improved(object me)
{
        object *ob;
        int i, skill;
        skill = me->query_skill("qishang-quan", 1);
        
        if (me->query("max_neili") < skill * 15 && skill < 200)
        {
                switch(random(5)){
                case 0 : 
                        tell_object(me, HIR"���ͷ����ѨͻȻһ����΢��ʹ���Ƿ������ˣ�\n"NOR);
                        me->add("max_neili", -random(100));
                        break;      
                case 1 : 
                        tell_object(me, HIR"����������ѨͻȻ��ʹ�ѵ����Ǹ������ˣ�\n"NOR);
                        me->add("combat_exp", -random(7000));
                        break;
                case 2 : 
                        message_vision(HIR"$N�������ˣ�ͻȻ���Դ󷢡��޷������ˣ�\n"NOR, me);
                        me->set_skill("qishang-quan", skill - 1);
                        break;
                case 3 : 
                        tell_object(me, HIR"���ϱ�����ѨͻȻһʱ�����ѵ������������ˣ�\n"NOR);
                        me->add("max_neili", -random(100));
                        break;
                case 4 : 
                        tell_object(me, HIR"��ͻȻ�������������������н�ľˮ�������У��޷������ˣ�\n"NOR);
                        me->set_skill("qishang-quan", skill-2);
                        break;
                }
                // me->unconcious();
        }
}
