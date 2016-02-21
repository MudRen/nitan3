// This is player's own perform (Write by Lonely@nt2)
// Create by ��ݶ(Xiaot) at Fri Mar 10 11:48:11 2006
// ��豹���(guizhen)

#include <ansi.h>
#include <combat.h>

#define PFM "��" HIW "��豹���" NOR "��"

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

        if (! me->query("can_perform/" + "daojian-guizhen" + "/" + "guizhen"))
                return notify_fail("�㻹û���ܵ�����ָ�㣬����������" PFM "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (member_array("sword", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("����ʹ�õ��������ԣ�����ʩչ" PFM "��\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "ֻ�ܿ���ʹ�á�\n");             
        }
        
        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("��" + to_chinese("daojian-guizhen") + "������죬����ʩչ" PFM "��\n");

        if (member_array("sword", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("sword") != "daojian-guizhen")
                        return notify_fail("��û��׼��" + to_chinese("daojian-guizhen") + "������ʩչ" PFM "��\n");
        }
        
        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$NͻȻ�������ס��ߵ����ᣬ�����ǽ��������ǵ������򲻱䣬�ó�һƬ���⽣Ӱ����$n����׽��,���ǵ������ռ�ɱ�С���豹��桱��" + "\n" + NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");
         
        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = da_power(me, "sword") * 3;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 100, HIM "ֻ��$nһ���ҽУ��ؿڸ�����һ���޴�Ŀ��ӣ���Ѫ��ӿ�����" + "\n" NOR);
                me->add("neili", -200);
                me->start_busy(1);
                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p���Ʋ�������ˣ����ձܹ�$P�����ɱ�У����������У������ѿ���һ������ӣ�" + "\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
                
        message_sort(msg, me, target);
        return 1;
}

