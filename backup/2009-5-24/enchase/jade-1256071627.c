//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Sat May 23 11:10:46 2009
// jade.c ���

#include <ansi.h>
#include <armor.h>

inherit HEAD;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(HIG "���" NOR, ({ "jade" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIG "һ���͸���ε���䡣\n" NOR);
                set("value", 50000);
		set("unit", "��");
                set("armor_prop/per", 5);
		set("enchase/SN", 6);
		set("enchase/cur_firm", 96);
		set("enchase/wspe_data", ([
			"int" : 6,
			"derive_times" : 5,
			"research_times" : 5,
		]));
		set("enchase/aspe_data", ([
			"learn_times" : 5,
			"study_effect" : 5,
			"max_potential" : 300000,
		]));
		set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
