#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_use", "use");
}

void create()
{
	set_name("�ٻ����߸�", ({"baihua gao", "gao","baihua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "����һö���İٻ����߸ࡣ\n");
		set("value", 20000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int limit;
	int max_limit;

	limit = me->query_current_neili_limit();
	max_limit = me->query_neili_limit();
	if (me->query("max_neili") < limit)
	{
                me->add("max_neili", 10 + random(20));
        	me->set("neili", me->query("max_neili"));
		if (me->query("max_neili") > max_limit)
			me->set("max_neili", max_limit);
		
		message_vision(HIY "$N����һö�ٻ����߸࣬��Ȼ��ֻ��һ������֮��ֱ���ķ�...\n" NOR, this_player());
	}
	else
		message_vision(HIY "$N����һö�ٻ����߸࣬���Ǻ���ûʲô��.\n" NOR, this_player());

	destruct(this_object());
	return 1;
}

int do_use(string arg)
{

	object obj, weapon;
	object me = this_player();
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (!objectp(weapon = this_player()->query_temp("weapon")))
		return notify_fail("�����������²��аɣ�\n");

	message_vision(HIY "$Nȡ��һö�ٻ����߸࣬����Ĩ�ڱ��м�����֮��.\n" NOR, this_player());
	message_vision(HIY "$Nʹ�õİٻ����߸�ҩЧ��ʼ����.\n" NOR, this_player());
	obj=new("/d/shenlong/obj/usedgao");
	obj->move(this_player());
	destruct(this_object());
	return 1;
}
