// SN:ECZJ:FMldc2DB1U@
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:25:10 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(MAG "��֮��ʯ" NOR, ({ "MAG jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", MAG "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 24);
	set("enchase/SN", 9);
	set("enchase/level", 7);
	set("enchase/cur_firm", 81);
	set("enchase/wspe_data", ([
		"learn_times" : 7,
		"ap_power" : 7,
		"derive_times" : 7,
		"reduce_age" : 7,
		"practice_effect" : 7,
		"int" : 8,
		"reduce_age" : 7,
	]));
	set("enchase/aspe_data", ([
		"effjing_recover" : 80,
		"dp_power" : 7,
		"parry" : 40,
		"dex" : 8,
		"reduce_lighting" : 23,
		"reduce_poison" : 23,
		"int" : 8,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
