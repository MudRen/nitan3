// SN:;U5[f[[e:OC?cdFf
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 10:25:51 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(WHT "��֮��ʯ" NOR, ({ "WHT jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", WHT "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 16);
	set("enchase/SN", 6);
	set("enchase/level", 7);
	set("enchase/cur_firm", 85);
	set("enchase/wspe_data", ([
		"derive_times" : 7,
		"practice_times" : 7,
		"max_neili" : 4000,
		"add_poison" : 23,
		"str" : 8,
		"practice_times" : 7,
		"max_potential" : 400000,
	]));
	set("enchase/aspe_data", ([
		"learn_effect" : 7,
		"dex" : 8,
		"armor" : 800,
		"max_experience" : 400000,
		"effqi_recover" : 80,
		"con" : 8,
		"study_effect" : 7,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
