// SN:dSVdYSLbC65P;7G7
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:31:57 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(RED "��֮��ʯ" NOR, ({ "RED jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", RED "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 17);
	set("enchase/SN", 9);
	set("enchase/level", 7);
	set("enchase/cur_firm", 81);
	set("enchase/wspe_data", ([
		"max_neili" : 4000,
		"max_neili" : 4000,
		"research_times" : 7,
		"add_poison" : 23,
		"practice_times" : 7,
		"add_cold" : 23,
		"research_times" : 7,
	]));
	set("enchase/aspe_data", ([
		"study_effect" : 7,
		"derive_times" : 7,
		"reduce_cold" : 0,
		"defense" : 40,
		"avoid_poison" : 7,
		"reduce_fire" : 23,
		"learn_times" : 7,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
