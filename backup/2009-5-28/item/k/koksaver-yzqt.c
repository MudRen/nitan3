// SN:X73R2SaKCYYbYfha
// ITEM Made by player(����ȫ��:koksaver) /data/item/k/koksaver-yzqt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 26 11:17:00 2009
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mһ������[2;37;0m", ({ "yzqt" }));
	set_weight(3500);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����֮��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
ָ��Ե�Ͽ���һ��С�֣�����ȫ��(koksaver)
");
	set("value", 6100000);
	set("point", 390);
	set("material", "noname object");
	set("material_file", "/clone/item/noname");
	set("wear_msg", "[33m$N[33mװ��[1;33mһ������[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;33mһ������[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
