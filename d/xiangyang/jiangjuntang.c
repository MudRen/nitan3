// Room: /d/xiangyang/jiangjuntang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����������");
        set("long", @LONG
�����ǽ������Ĵ��ã������������һ�����͵Ľ�������һ��ƣ����������
ս�չ��ģ�����������߰��ű����ܣ����Ϸ�������Ѫ����ӳ�żܺ��ս�죬��
��ҫ�ۡ����ཫ����������δϴ������־���������׳��
LONG );
	set("exits", ([
		"south" : "/d/xiangyang/jiangjunyuan",
	]));
	set("objects", ([
		"/d/xiangyang/npc/wang" : 1,
		"/d/xiangyang/npc/zuo" : 1,
		"/d/xiangyang/npc/pian" : 1,
		"/d/xiangyang/npc/ya" : 1,
		"/d/xiangyang/npc/pi" : 1,
	]));
	set("coor/x", -280);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

