// Room: path2.c
// Date: Feb.14 1998 by Java

inherit BUILD_ROOM;
string look_gaoshi();
void create()
{
	set("short", "Ϫ��С·");
        set("long", @LONG
ϪԴת��������ˮ���������������ǰ��վ�ڲ����ձ�ǰ������佻�Ϫ����
����Ư׹����Ů���佻�ʱ�ڣ�����һ����ζ�����߾��ǡ���������լ���ٻ�
̶��ׯ���ĶŸ������ˡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
		"north"  : "/d/city3/caotang",
		"south"  : "/d/city3/path1",
	]));
        set("max_room", 4);
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
}
