#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�ۻ�", ({"xiong huang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ۻ�,��˵�����ٶ���\n");
		set("value", 1000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	return notify_fail("���������ۻƲ��ܳԡ�\n");
}
