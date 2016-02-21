//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Mon May 25 14:57:57 2009
// mcrystal.c ��֮ˮ��

#include <ansi.h>
#include <armor.h>

inherit HEAD;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(HIM "��֮ˮ��" NOR, ({ "magic crystal" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "һ����˸�������â�ķ�ɫˮ����"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("value", 200000);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 15 + random(16));
                set("armor_prop/per", 8);
		set("enchase/SN", 8);
		set("enchase/cur_firm", 83);
		set("enchase/wspe_data", ([
			"add_fire" : 23,
			"attack" : 40,
			"study_times" : 7,
			"da_power" : 7,
			"attack" : 40,
		]));
		set("enchase/aspe_data", ([
			"research_times" : 7,
			"max_potential" : 400000,
			"reduce_fire" : 23,
			"reduce_lighting" : 23,
			"learn_times" : 7,
		]));
		set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
