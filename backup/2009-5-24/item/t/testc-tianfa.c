// SN:IQ=0;48RoX=Z`HHQ
// ITEM Made by player(�Ŷ�С:testc) /data/item/t/testc-tianfa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 23 11:05:51 2009
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m�췣[2;37;0m", ({ "tianfa" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����֮��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��Ŷ�С(testc)
");
	set("value", 1);
	set("point", 526);
	set("material", "noname object");
	set("material_file", "/clone/item/noname");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
