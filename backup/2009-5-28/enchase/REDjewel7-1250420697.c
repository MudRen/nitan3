// SN:lLn5lXJiT<>8A>?G
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:35:19 2009
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
	set("magic/power", 22);
	set("enchase/SN", 2);
	set("enchase/level", 7);
	set("enchase/cur_firm", 91);
	set("enchase/wspe_data", ([
		"study_times" : 7,
		"max_experience" : 400000,
		"add_magic" : 23,
		"study_times" : 7,
		"con" : 8,
		"damage" : 800,
		"practice_effect" : 7,
	]));
	set("enchase/aspe_data", ([
		"max_experience" : 400000,
		"dodge" : 40,
		"derive_times" : 7,
		"reduce_cold" : 0,
		"max_potential" : 400000,
		"avoid_lighting" : 7,
		"armor" : 800,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
