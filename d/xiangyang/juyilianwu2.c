// Room: /d/xiangyang/juyilianwu2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����Ǿ���������������ĵط����м���������ר�����µ����䣬�м�����
�ֱ������ڻ�����С����鶯�����紩������һ�㣬�㲻���������ۣ������
�����ڵ��ϵ������Ͽ���������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east" : "/d/xiangyang/juyiyuan",
	]));
	set("objects", ([
		"/clone/npc/tong-ren" : 3,
	]));
	set("coor/x", -330);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

