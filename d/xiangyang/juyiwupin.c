// Room: /d/xiangyang/juyiwupin.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
        set("long", @LONG
���Ǿ���ݵĶѷŸ��ָ�����Ʒ�ķ��䡣�����Ķ����������������������
������������ַַ�������Ʒ��
LONG );
	set("exits", ([
		"northwest" : "/d/xiangyang/juyihuayuan",
	]));
	set("objects", ([
		"/d/xiangyang/npc/wuxiuwen" : 1,
	]));
	set("coor/x", -310);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

