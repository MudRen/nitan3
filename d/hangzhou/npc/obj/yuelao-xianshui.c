// wine.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(MAG"������ˮ"NOR, ({"yuelao xianshui","xianshui"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��˵�����������Ƶ���������ȥ���Ա�����Ե������������\n");
		set("unit", "ƿ");
		set("value", 10000);
		set("no_get", "1");
		set("max_liquid", 5);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": HIW"��ˮ"NOR,
		"remaining": 5,
		"supply": 15,
		"drunk_apply": 3,
	]));
}
