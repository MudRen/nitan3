// SN:IL0:_Hk`LW5BL39?
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:27:38 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(CYN "��֮��ʯ" NOR, ({ "CYN jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", CYN "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 15);
	set("enchase/SN", 1);
	set("enchase/level", 7);
	set("enchase/cur_firm", 85);
	set("enchase/wspe_data", ([
		"add_poison" : 23,
		"add_magic" : 23,
		"max_neili" : 4000,
		"study_times" : 7,
		"attack" : 40,
		"ap_power" : 7,
		"reduce_age" : 7,
	]));
	set("enchase/aspe_data", ([
		"reduce_fire" : 23,
		"reduce_cold" : 0,
		"reduce_poison" : 23,
		"practice_times" : 7,
		"int" : 8,
		"max_jingli" : 4000,
		"max_jingli" : 4000,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
