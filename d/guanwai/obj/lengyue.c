// lengyue.c ���±���
#include <weapon.h>

inherit BLADE;

#include <ansi.h>

void create()
{
	set_name(HIG "���±���" NOR, ({ "moon blade", "blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 1000000);
                set("no_sell", "��...�����չ����˵�...\n");
        	set("material", "steel");
        	set("long", "���Ǻ����洫�ı���������ɭɭ�������ޱȡ�\n" );
        	set("wield_msg", HIG "$N" HIG "ץ�𵶱�������ֻ����ǰ���һ"
			         "�����������ˣ�$N" HIG "�����Ѿ�����һ��$n"
			         HIG "��������ˮ����ת������\n" NOR);
        	set("unwield_msg", HIW "$N" HIW "������Х�����ип�����$n"
				   HIW "��ص��ʡ�\n");
	}
	init_blade(180);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{
        if (random(3) == 1 && me->query_skill("lengyue-shengong", 1) > 120)
        {
        victim->start_busy(1 + random(2));
        return WHT"$n��Ȼ����һ��͸�Ǻ��⣬��ʱ�侹����ס�ˣ���Ҳ�޷�������\n"NOR;
        }
        else
        {
        victim->receive_damage("qi", me->query_skill("lengyue-shengong, 1") / 10 * 4, me); 
        victim->receive_wound("qi", me->query_skill("lengyue-shengong, 1") /10 * 4, me); 
        return WHT"$n��Ȼ����һ��͸�Ǻ��⣬��ʱ������ѪҺ������Ҫ������!\n"NOR;
        }
}
