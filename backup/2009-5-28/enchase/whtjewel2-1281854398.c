// SN:S2QQCN?@HA72`ObD
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 10:17:01 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(wht "��ʯ" NOR, ({ "wht jewel2" }));
	set_weight(50);
	set("unit", "��");
	set("long", wht "һ���������ľ�����ʯ�������쳣��\n" NOR );
	set("value", 100000);
	set("enchase/SN", 5);
	set("enchase/level", 2);
	set("enchase/cur_firm", 82);
	set("enchase/wspe_data", ([
		"reduce_age" : 2,
		"learn_times" : 2,
	]));
	set("enchase/aspe_data", ([
		"str" : 3,
		"avoid_fire" : 2,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
