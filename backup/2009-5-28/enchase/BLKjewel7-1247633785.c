// SN:Nin5Z?WAAM<5nBPZ
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:27:01 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(NOR "��֮��ʯ" NOR, ({ "BLK jewel7" }));
	set_weight(50);
	set("unit", "��");
	set("long", NOR "һ����˸�������â�ı�ʯ�����˸е�һ������ļ¡�\n" NOR );
	set("value", 200000);
	set("can_be_enchased", 1);
	set("magic/type", "magic");
	set("magic/power", 15);
	set("enchase/SN", 7);
	set("enchase/level", 7);
	set("enchase/cur_firm", 97);
	set("enchase/wspe_data", ([
		"da_power" : 7,
		"max_qi" : 800,
		"con" : 8,
		"add_magic" : 23,
		"research_times" : 7,
		"derive_times" : 7,
		"study_times" : 7,
	]));
	set("enchase/aspe_data", ([
		"avoid_fire" : 7,
		"max_experience" : 400000,
		"derive_times" : 7,
		"max_experience" : 400000,
		"reduce_lighting" : 23,
		"avoid_magic" : 7,
		"max_jingli" : 4000,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
