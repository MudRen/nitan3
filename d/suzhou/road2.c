// Room: /d/suzhou/road2.c
// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ���Ȼ�ǳ��⣬��
�Ǿ�ɫ���ˣ�������һ����ס����
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : "/d/suzhou/road3",
		"east"  : "/d/suzhou/ximen",
	]));
        set("max_room", 4);
	set("coor/x", 160);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
}
