// shenxing-baibian.c ���аٱ�

// written by That
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
     "$nһʽ��������ˮ�������㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
     "$nһʽ��Ǳ��ҹ�С�����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
     "$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
     "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
     "$nһʽ���貨΢��������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
     "$nһʽ�����ϲ�¥�������ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
     "$nһʽ�����ӳ�ˮ��������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
     "$nһʽ�����·ת�������������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
     "$nһʽ�������ﲨ��������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
     "$nһʽ�����ӻ�ͷ��������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
      if((int)me->query("qi") < 50 )
           return notify_fail("�������̫���ˣ����������аٱ䡣\n");

      if((int)me->query("neili") < 30 )
           return notify_fail("�������̫���ˣ����������аٱ䡣\n");

      me->receive_damage("qi", 40);
      me->add("neill", -14);
      return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("shenxing-baibian", 1) < 50 ||
            ! living(me))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("shenxing-baibian", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                 result += (["msg" : HIC "$n" HIC "ʩչ���аٱ䣬�����ϣ�һת��䣬����˷�Ʈ����������$n����Ӱ��\n" 
                                    HIC "$N" HIC "�����޴룬ͷ�Է��裬ֻ�������涼��$n����Ӱ����������������ա�\n" NOR]);
                return result;
        }
}
