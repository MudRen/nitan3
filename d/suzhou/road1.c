// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ�
LONG );
	set("outdoors", "suzhou");
	set("max_room", 5);
	set("exits", ([
		"south"     : "/d/suzhou/beimen",
		"southwest" : "/d/suzhou/huqiu",
		"northwest" : "/d/guiyun/shanlu2",
	]));
	set("coor/x", 200);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
}

