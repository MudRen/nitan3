// SN:8Yj:oIA^lNB>FK:M
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:28:44 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(GRN "��֮��ʯ" NOR, ({ "GRN jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", GRN "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 18);
	set("enchase/SN", 8);
	set("enchase/level", 7);
	set("enchase/cur_firm", 99);
	set("enchase/wspe_data", ([
		"research_times" : 7,
		"add_fire" : 23,
		"practice_times" : 7,
		"study_effect" : 7,
		"ap_power" : 7,
		"derive_times" : 7,
		"reduce_age" : 7,
	]));
	set("enchase/aspe_data", ([
		"effqi_recover" : 80,
		"dp_power" : 7,
		"reduce_lighting" : 23,
		"reduce_lighting" : 23,
		"dex" : 8,
		"effqi_recover" : 80,
		"max_potential" : 400000,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
