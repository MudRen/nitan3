// SN:TdWM6NgLTH:30Xc\
//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Wed May 27 10:24:44 2009
#include <ansi.h>
inherit ITEM;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(WHT "��ʯ" NOR, ({ "WHT jewel2" }));
	set_weight(50);
	set("unit", "��");
	set("long", WHT "һ���������ľ�����ʯ�������쳣��\n" NOR );
	set("value", 100000);
	set("enchase/SN", 1);
	set("enchase/level", 2);
	set("enchase/cur_firm", 95);
	set("enchase/wspe_data", ([
		"max_qi" : 300,
		"derive_effect" : 2,
	]));
	set("enchase/aspe_data", ([
		"dex" : 3,
		"learn_effect" : 2,
	]));
	set("wear_msg", HIC "$N" HIC "����ذ�$n"HIC "����ͷ�ϡ�\n" NOR);
	set("remove_msg", HIC "$N" HIC "����ذ�$n"HIC "��ͷ��ժ��������\n" NOR);

	setup();
}

int query_autoload(){ return 1; }
