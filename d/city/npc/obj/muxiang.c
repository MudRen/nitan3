// muxiang.c ��ľ��

inherit ITEM;

int is_muxiang() { return 1; }

void create()
{
	set_name("��ľ��", ({ "da muxiang", "muxiang"}));
	set_weight(20000);
	set_max_encumbrance(2000000000);
	// set_max_carryitems(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������Ľ��ʵʵ�Ĵ�ľ�䣬���滹������һ�ű�ǩ��\n���ľ�������Դ��200����Ʒ��\n�����ʹ�� idlabel ָ���޸�ľ���ID��\n�����ʹ�� namelabel ָ���޸�ľ������֡�\n��Ҫ��ľ�������߰�������֣���������ܵ����ֿ��ܵĳͷ���\n");
		set("value", 10000);
	}
}

int is_container() { return 1; }
