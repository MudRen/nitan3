//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Sat May 23 11:10:23 2009
// agate.c ���

#include <ansi.h>
#include <armor.h>

inherit HEAD;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(HIR "���" NOR, ({ "agate" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIR "һ�龧Ө��͸�İ���ɫ��觡�\n" NOR);
                set("value", 50000);
		set("unit", "��");
                set("armor_prop/per", 5);
		set("enchase/SN", 7);
		set("enchase/cur_firm", 99);
		set("enchase/wspe_data", ([
			"str" : 6,
			"int" : 6,
			"add_lighting" : 17,
		]));
		set("enchase/aspe_data", ([
			"practice_effect" : 5,
			"reduce_fire" : 17,
			"derive_effect" : 5,
		]));
		set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
