//  Written by ZHANG TIANSHI(Lonely 2007/10/15)	Sat May 23 11:09:51 2009
// magate.c ��֮���

#include <ansi.h>
#include <armor.h>

inherit HEAD;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(HIR "��֮���" NOR, ({ "magic agate" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "һ����˸�������â�İ���ɫ��解�"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("value", 200000);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "fire");
                set("magic/power", 15 + random(16));
                set("armor_prop/per", 8);
		set("enchase/SN", 8);
		set("enchase/cur_firm", 88);
		set("enchase/wspe_data", ([
			"research_effect" : 7,
			"add_poison" : 23,
			"dex" : 8,
			"derive_times" : 7,
			"max_experience" : 400000,
		]));
		set("enchase/aspe_data", ([
			"effjing_recover" : 80,
			"effjing_recover" : 80,
			"reduce_magic" : 23,
			"practice_times" : 7,
			"avoid_magic" : 7,
		]));
		set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
