// feilong-cuff.c
// 华夏玩家felix的自创武功：飞龙神拳
// Modified by smallfish@huaxia Sep.1998
#include <ansi.h>

inherit SKILL;

string is_private_skill() {return "felix";}
int can_not_hubo() {return 1;}

mapping *action = ({
([      "skill_name":    "招式一",
        "action":  "$N左腿在前，右腿在后，双掌用力向$n的$l挥去",
        "dodge" : 95,
        "damage": 210,
        "force" : 360,
        "attack": 140,
        "parry" : 90,
        "lvl"   : 0,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "招式二",
        "action":  "$N左脚离地，身体向前旋转一百八十度，右腿像疾风扫落叶般扫向$n的$l",
        "dodge" : 105,
        "damage": 220,
        "force" : 370,
        "attack": 145,
        "parry" : 95,
        "lvl"   : 160,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "招式三",
        "action":  "$N右手虚晃一招，左肘从意想不到的角度冲向$n的$l",
        "dodge" : 115,
        "damage": 240,
        "force" : 390,
        "attack": 155,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "招式四",
        "action":  "$N右脚凌空一踢，晃出一片无影腿，霎那间向$n的$l一连踢出五脚",
        "dodge" : 115,
        "damage": 260,
        "force" : 410,
        "attack": 155,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "招式五",
        "action":  "$N凌空高高跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
        "dodge" : 115,
        "damage": 300,
        "force" : 450,
        "attack": 155,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力不够，没有办法练飞龙神拳。\n");

    if( (int)me->query_skill("martial-cognize",1) < 300 )
        return notify_fail("你的武学修养不够，没有办法练飞龙神拳。\n");

    if( (ob = me->query_temp("weapon")) || 
        (ob = me->query_temp("handing")) )
        return notify_fail("你只有空着双手才能修炼拳法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="cuff" || usage=="parry";
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
    level   = (int) me->query_skill("feilong-cuff",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("你的体力不足以练习飞龙神拳。\n");

    if ((int)me->query("neili") < 60 )
        return notify_fail("你的内力不够，没有办法练习飞龙神拳。\n");

    me->receive_damage("qi", 50);
    me->add("neili", -50);

    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feilong-cuff/" + action;
}
