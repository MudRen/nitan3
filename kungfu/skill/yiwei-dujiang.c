// yiwei-dujiang.c һέ�ɽ�
// by Lonely

#include <ansi.h>

inherit SKILL; 

string *dodge_msg = ({
        "ֻ��$nһ��[��������],˫��һǰһ��,�ƽ�����,��$Nһ㶼����˹�����\n",
        "����$nʹ��[���ѵ�ˮ],�ż�վ��,���ζ��������,�������\n",
        "$nһ��[���ط���],������ת,ɲ�Ǽ���ԭ��ת���߰�ʮȦ,ͻȻ������һ��,ԭ��ת����,ȴʹ$N���˿ա�\n",
        "����$nһ��[�׾Թ�϶],����΢��,����ֱ��,���$N������\n",
        "ȴ��$nʹ��[������Ӱ],��ԭ������һ������,����㵽��һ�ߡ�\n",
        "$n����һ��,[���Ӵ���],����ƽƽ�ӳ�,�ڿ�������һ���������Ρ�\n",
        "$nһ�С�����ֱ�ϡ������λ���һ�����̣��Է�����˼���ٶȱܿ���$N��һ�С�\n",
}); 

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{ 
        if ((int)me->query("dex") < 25 || (int)me->query("int") < 25) 
               return notify_fail("������������һέ�ɽ�����С��Ū�����ȡ�\n"); 
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me)
{
        if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˣ�������һέ�ɽ�����\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˣ�������һέ�ɽ�����\n");
                
        me->add("neili", -30);
        me->receive_damage("qi", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yiwei-dujiang/" + action;
}

int query_effect_dodge(object victim, object me)
{
        int lvl;

        lvl = me->query_skill("yiwei-dujiang", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 100;
        if (lvl < 280) return 150;
        if (lvl < 350) return 200;
        return 250;
}

int difficult_level()
{
        return 300;
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{
        mixed result; 
        int ap, dp, mp; 

        if ((int)me->query_skill("yiwei-dujiang", 1) < 100 || 
            ! living(me)) 
                return; 

        mp = ob->query_skill("martial-cognize", 1); 
        ap = ob->query_skill("force") + mp; 
        dp = me->query_skill("dodge", 1) / 2 + 
             me->query_skill("yiwei-dujiang", 1); 

        if (ap / 2 + random(ap) < dp) 
        {
                result = ([ "damage": -damage ]); 
                switch (random(3)) 
                {
                case 0:
                        result += (["msg" : HIY "$n" HIY "һ�С����ѵ�ˮ�����ż�����һ�㣬����������" 
                                            "��ʱ,$Nһ��ʧ�֣�\n" NOR]); 
                        break; 
                case 1:
                        result += (["msg" : HIY "$n" HIY "һ�����׾Թ�϶��������һ�࣬����һ�ݣ�"                                            
                                            "$N��Ȼһ�й�ȥ���Ѿ��ղ�סȥ�ƣ�\n" NOR]); 
                        if (! ob->is_busy())
                                ob->start_busy(random(2)); 
                        break; 
                default: 
                        result += (["msg" : HIY "$n" HIY "ʹ�������Ӵ��֡�����һ��ƽƽ�ӳ���" 
                                            "һ��ת��������¡�\n" NOR]); 
                        break; 
                }
                return result; 
        } else 
        if (mp >= 100) 
        {
                switch (random(3)) 
                {
                case 0: 
                        result = HIY "$n" HIY "һ�С����ѵ�ˮ�����ż�����һ�㣬����������," 
                                 "����$N" HIY "���Զ���$n����ͼ����ռ���Ȼ���\n" NOR;  
                        break; 
                case 1: 
                        result = HIY "$n" HIY "һ�����׾Թ�϶��������һ�࣬����һ�ݣ�" 
                                 "$Nš����ϣ�ȫ������$n��\n" NOR;  
                        break; 
                default: 
                        result = HIY "$n" HIY "ʹ�������Ӵ��֡�����һ��ƽƽ�ӳ���"                                 
                                 "$N��Ц����������һ�����ߴ���ȥ����ղ���$n��\n" NOR;  
                        break; 
                }
                COMBAT_D->set_bhinfo(result); 
        }
}


