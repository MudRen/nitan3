// Room: /city/dangpu_cc.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "���̴��ؼ�");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)����̨���������ϰ壬һ˫������
�������´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "��ƽ����\n
sell        �� 
buy         ��
redeem      ��
value       ����
",
	]));

	setup();
	replace_program(ROOM);
}
