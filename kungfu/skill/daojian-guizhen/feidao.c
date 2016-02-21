// This is player's own perform (Write by Lonely@nt2)
// Create by ������(Mount) at Tue Apr 11 12:13:09 2006
// �ּ��ɵ�(feidao)

#include <ansi.h>
#include <combat.h>

#define PFM "��" HIW "�ּ��ɵ�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int attack;

        if (! me->query("can_perform/" + "daojian-guizhen" + "/" + "feidao"))
                return notify_fail("�㻹û���ܵ�����ָ�㣬����������" PFM "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (member_array("blade", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("����ʹ�õ��������ԣ�����ʩչ" PFM "��\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "ֻ�ܿ���ʹ�á�\n");             
        }
        
        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("��" + to_chinese("daojian-guizhen") + "������죬����ʩչ" PFM "��\n");

        if (member_array("blade", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("blade") != "daojian-guizhen")
                        return notify_fail("��û��׼��" + to_chinese("daojian-guizhen") + "������ʩչ" PFM "��\n");
        }
        
        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N����$nһ����𣺡����ҵľ��У���С����ĸ�ķɵ���������˵�꣬�������е�������$n���˹�ȥ�����ƺ����·���ȴ�ǰ���������������" + "\n" + NOR;

        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");
         
        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = da_power(me, "blade") * 3;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 100, HIM "$n�����������꣬�ļ�����˰������ʽ��һʱ���޷��ƽ⣬���̸�ͨ��͸����" + "\n" NOR);
                me->add("neili", -200);
                me->start_busy(1);
                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p����$Pһ�ۣ������С�������ҵġ��������˺���ʩչ����ſʽ�������������һ����" + "\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
                
        message_sort(msg, me, target);
        return 1;
}

