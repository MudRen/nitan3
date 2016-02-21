//liangyi-jian.c ���ǽ���

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "��������",
    "action" : "$N���⽣â������һ�С��������ء�������$w�����´󿪴��أ�
һ����������$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N����Ȧת��һ��"+(order[random(13)])+"������������"NOR"������$wƽչ�´��һ�����Ữ��$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "Ԩ����ǳ",
    "action" : "$N��������������������������$wʹ��һʽ"+(order[random(13)])+"��Ԩ����ǳ��"NOR"����$n��
$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "ˮ�����",
    "action" : "$N������ָ��������ת��һ��"+(order[random(13)])+"��ˮ����ơ�"NOR"ֱȡ$n��$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�ƺ�����",
    "action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+(order[random(13)])+"���ƺ����¡�"NOR"����������,����$n��$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���ѵ�ׯ",
    "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"+(order[random(13)])+"�����ѵ�ׯ��"NOR"ԾԾ����Ʈ��$n��$l",
    "force" : 120,
    "dodge" : 125,
    "damage" : 320,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+(order[random(13)])+"���������ǡ�"NOR"������
����֮�ƣ�����$n��$l",
    "force" : 110,
    "dodge" : 115,
    "lvl" : 0,
    "damage" : 400,
    "damage_type" : "����"
]),
([      "name":   "��ϵ�̳�",
    "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+(order[random(13)])+"����ϵ�̳���"NOR"����
���ϴ���$n��$l",
    "force" : 150,
    "dodge" : 135,
    "damage" : 400,
    "lvl" : 0,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("qinqi-shuhua", 1) < 100 && (int)me->query_skill("xuantian-wuji", 1)<150 )
                return notify_fail("��ı����ڹ����̫ǳ��\n");
        return 1;
}
 mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
        if (random(level) > 240 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
        return ([
        "action":HIC"$N��ɫ���أ�����$w"NOR+HIY"һ�٣�������ת��$w"+HIY"�Ͻ�âͻʢ��
                   ����Ĭ������籩���ش���$n��$l��"NOR,
        "force" : 500,
        "dodge" : 140,
        "parry" : 140,
        "damage": 900,
        "weapon": HIY"���"NOR,
        "damage_type":  "����"
]);
}
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("����������������ǽ�����\n");
    me->receive_damage("qi", 40);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
       j = me->query_skill("liangyi-jian", 1);
       k = me->query_skill("qinqi-shuhua",1);
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "liangyi-jian"
        && j > random(victim->query_skill("dodge",1))){
          switch(random(3)){
            case 0 :
               msg = HIW"$Nʩչ����·�����ƺƵ������Ϭ���ޱȣ�\n"NOR;
               msg+= HIW"$n�������ˣ�ȫ���мܣ��������У�\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N����$n�ɿ����ת��һ�������̳��ü�ʮ����\n"NOR;
               msg+= HIW"$n�����ֲ������һ�����飬��һ����ʵ������ͣ�¹��ƣ������Ż���\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N��۵糸������$n���ܣ�������������ֱ�����㲻��صķ���һ�㣡\n"NOR;
               msg+= HIW"$n����$Nת��תȥ����Ū���ۻ����ң�ҡҡ��׹��\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}

