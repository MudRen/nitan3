// shitou.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIW"��ʯͷ"NOR, ({ "shi tou"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "����һƽƽ�����Ĵ�ʯͷ��\n");
        set("value", 0);
        set("material", "stone");
		set("wield_msg", "$N����һ��$n׼��ս����\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_hammer(1);
	setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
	object obj, me;

	if (!arg || (arg != "stone" && arg != "shi tou"))
		return notify_fail("ʲô��\n");

	me = this_player();
	if (me->query("neili") < 500)
		return notify_fail("�㹦�����㣬���ܻ�ʯ�ɷۣ�\n");
	message_vision(HIW"$N�������������������ʯͷ��ȥ��\n"NOR,me); 
	write(HIW"ֻ���á��ء���һ����ʯͷ��������飡\n"NOR);
	obj = new("/d/taohua/obj/shizi2");
	obj->move(me);
	me->add("neili", -(100+random(100)));
	destruct(this_object());
	return 1;
}
