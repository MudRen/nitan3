// Room: eastroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ����������سǹ�
����ߺ�������������񶼴�����Ǳ�һ���ྲ��ԭ������Ϊ�ᶽ������ͷ���ϱ�
��һ����ֱ�Ĵ����
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"  : "/d/city3/eastgate",
	    "west"  : "/d/city3/shuduroad1",
	    "north" : "/d/city3/eastroad1",
	    "south" : "/d/city3/eastroad3",
	]));
	set("objects", ([
	    "/d/city/npc/liumangtou" : 1,
	    "/d/city/npc/liumang"    : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -410);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
