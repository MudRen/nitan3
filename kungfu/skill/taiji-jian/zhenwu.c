// zhenwu.c �����а

#include <ansi.h>
#include <combat.h>

#define PFM_NAME        "�����а"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if ((int)me->query_skill("taiji-jian", 1) < 250)
                return notify_fail("���̫������������죬����ʹ�á�" + PFM_NAME + "����\n");
                                
        if ((int)me->query_skill("force", 1) < 250)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("���̫������Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");

        if (userp(me) && ! me->query("can_perform/taiji-jian/zhenwu"))
                return notify_fail("��û�о�����������ʦ��������㣬�޷�ʹ����ᡸ" +
                                    PFM_NAME + "���ľ��衣\n");
                                    
        if ((int)me->query("neili") < 2000)
                return notify_fail("��������������������ʹ�á�" + PFM_NAME + "����\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʹ�á�" + PFM_NAME + "����\n");

        msg = HIY "$N" HIY "��Ŀ���������ת��һ�г���̫������ġ�" HIW + PFM_NAME +
              HIY "������ʹ�������з��ӹ��棬����ƽ�����棬\nʵ��㼯�����֮���������"
              HIY "������" + weapon->name()+ "�û�������̫����Ȧ������ǵص�ѹ��$n��\n" NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");
        
        // ��ǿ ap
        if (weapon->name() == "���佣") ap += (30 + random(20));
        if (target->is_bad()) ap = ap * 3 / 2;
        // ���� ap
        if (me->is_not_good()) ap = ap / 2;
        if (me->is_bad()) ap = ap / 3;
        if (target->is_good()) ap = ap * 4 / 5;

        if (wizardp(me) && me->query("env/combat_test"))
        {
                tell_object(me, HIY "AP: " + ap + ". DP: " + dp + ".\n" NOR);
        }
        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = da_power(me, "sword");

                me->add("neili", -(damage * 1 + (random(2))));
//              tell_object(me, HIC "DAMAGE: " + damage + ".\n" NOR);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 85,
                                           HIR "\n$p" HIR "��$P���������壬��Ȼ�ŵù˲����мܣ�"
                                           "��һ�����ؿ���С���Ữ������\n��ʱ��Ѫ�ɽ���\n" NOR);
                me->start_busy(3);
        } else 
        {
                msg += WHT "\nȻ��$p" WHT "��Ȼ˿������Ϊ�⣬���赭д�Ľ�$P"
                       WHT "�Ľ��мܿ���\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target, 0, 1);

        return 1;
}

