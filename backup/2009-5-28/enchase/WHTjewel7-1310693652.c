// SN::XR8HE=9N`1:70:L
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 10:25:39 2009
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
	set("magic/power", 30);
	set("enchase/SN", 1);
	set("enchase/level", 7);
	set("enchase/cur_firm", 97);
	set("enchase/wspe_data", ([
		"learn_times" : 7,
		"con" : 8,
		"derive_times" : 7,
		"derive_times" : 7,
		"max_qi" : 800,
		"derive_effect" : 7,
		"add_magic" : 23,
	]));
	set("enchase/aspe_data", ([
		"avoid_cold" : 7,
		"max_jing" : 800,
		"avoid_fire" : 7,
		"practice_times" : 7,
		"dex" : 8,
		"avoid_poison" : 7,
		"practice_times" : 7,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
