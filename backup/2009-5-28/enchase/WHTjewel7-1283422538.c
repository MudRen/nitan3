// SN:[STe;Db[WYVJY6Dc
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 13:23:37 2009
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
	set("magic/power", 19);
	set("enchase/SN", 3);
	set("enchase/level", 7);
	set("enchase/cur_firm", 92);
	set("enchase/wspe_data", ([
		"max_qi" : 800,
		"practice_effect" : 7,
		"damage" : 800,
		"add_fire" : 23,
		"add_cold" : 23,
		"derive_effect" : 7,
		"max_neili" : 4000,
	]));
	set("enchase/aspe_data", ([
		"unarmed_damage" : 800,
		"max_experience" : 400000,
		"avoid_magic" : 7,
		"derive_effect" : 7,
		"con" : 8,
		"unarmed_damage" : 800,
		"avoid_magic" : 7,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
