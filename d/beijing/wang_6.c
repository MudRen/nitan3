inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ��Ǿ��ǵĽ�ͨҪ���������֣������ڽִ���
һ�ҵ��̡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_8",
		"south" : "/d/beijing/wang_4",
		"west" : "/d/beijing/wang_5",
		"east" : "/d/beijing/dangpu",
	]));

	set("objects", ([
		"/d/beijing/npc/boy2" : 1,
	]));

	set("coor/x", 0);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
