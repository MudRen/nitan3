#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <balance.h>

#define YINYANG "��" HIW "������" NOR "��"

 
int perform(object me, object target)
{
        string msg;
        int lvl;
        int ap, dp, dp1;
        int sub, damage;  

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yinyang-shiertian/zhen"))
                return notify_fail("����δ�������������磬����ʩչ" YINYANG "��\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YINYANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YINYANG "ֻ�ܿ���ʹ�á�\n");
                
        if (me->query_skill_mapped("force") != "yinyang-shiertian") 
                return notify_fail("��û�м���������תʮ������Ϊ�����ڹ����޷�ʹ��" YINYANG "��\n"); 

        if ((int)me->query("neili") < 2000)
	        return notify_fail("��������������޷�ʩչ" YINYANG "��\n");

        if (me->query("max_neili") < 5000)
	        return notify_fail("���������Ϊ��������ʹ��" YINYANG "��\n");

        if ((int)me->query_skill("force") < 500)
	        return notify_fail("����ڹ���򲻹�������ʩչ" YINYANG "��\n");

        if ((lvl = (int)me->query_skill("yinyang-shiertian", 1)) < 500)
	        return notify_fail("���������תʮ�����컹�����������޷�ʹ��" YINYANG "��\n");

        if (! living(target))
	        return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "����������תʮ�����죬����" HIB "��"
		     HIM "������" HIR "��" HIM "�����ȵ��ھ������ڶ�����"
		     HIM "����ɽ����֮�ƾ���$n" HIM "��\n" NOR, me, target);

        ap = ap_power(me, "force");   
		
        sub = 0;
        dp1 = 0;

        if (target->query_skill_mapped("force") == "yinyang-shiertian")
        {
	        sub = 3;
	        dp1 = target->query_skill("yinyang-shiertian", 1);
        } else 
        if (target->query_skill_mapped("force") == "taixuan-gong")
        {
	        sub = 3;
                dp1 = target->query_skill("taixuan-gong", 1) / 2;
        } else 
        if (target->query_skill_mapped("force") == "taiji-shengong")
        {
                sub = 3;
                dp1 = target->query_skill("taiji-shengong", 1) / 2;
        }else 
        if (target->query_skill_mapped("force") == "jiuyin-shengong")
        {
                sub = 1;
                dp1 = target->query_skill("jiuyin-shengong", 1);
        }else 
        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                sub = 2;
                dp1 = target->query_skill("jiuyang-shengong", 1);
        }

        //��һ�У���

        dp = dp_power(target, "dodge");

        if (sub == 1 || sub == 3)
                dp += dp1;
					  		
        message_sort(HIB "\n$N" HIB "������ǰһ�ƣ������ޱȵ�������ӿ������"
		     "�ƺ�����������һ��ס��\n" NOR, me, target);
                       
        if (ap * 2 / 3 + random(ap) > dp)
        {
	        damage = da_power(me, "force");
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(20),
					  HIB "$n" HIB "����$N" HIB "�����ѹ�����"
				          HIB "����������ͻȻ���ؿ�һ�𣬲��������п࣬"
                                          HIB "�ؿڴ�һ�ɺ�������ȫ���������ˡ�\n" NOR);
	        target->start_busy(3 + random(lvl / 500));
        } else
        {
                msg = CYN "$n" CYN "��$P" CYN "������ӿ���������׵�"
	              "������æ������Ų������������\n" NOR;
        }

        message_sort(msg, me, target);

        //�ڶ��У���

        dp = dp_power(target, "parry");

        if (sub == 2 || sub == 3)
	        dp += dp1;

        message_sort(HIR "\n$N" HIR "���ֽ����������ȵ��������ȼ�����"
		     HIR "����֮��ɢ����һ�ɽ�����ζ����\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = da_power(me, "force");
	        msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(40),
                                          HIR "$n" HIR "��æ������ˣ���Ȼ��Ⱪ�ǣ�"
					  HIR "ֻ��$n" HIR "����ײײ�����������������"
                                          "�ڵء���ü������������һ�ɽ�����\n" NOR);
        } else
        {
                msg = CYN "����$n" CYN "��͸$P" CYN "����֮�е���������"
	              "����㣬Ӧ�����硣\n" NOR; 
        }

        message_sort(msg, me, target);

	me->start_busy(3 + random(4));
	me->add("neili", -500 - random(200));
	return 1;
}

