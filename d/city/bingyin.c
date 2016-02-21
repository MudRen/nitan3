// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������е�
�������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ������
�ܡ����������������ȫ�����ĵ������Χ�˹��������ƿ�����̫��ϱ���һ
����(men)��
LONG );
	set("item_desc", ([
		"men" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"south" : "/d/city/bingqiku",
		"north" : "/d/city/bingyindamen",
	]));
	set("objects", ([
		"/d/city/npc/shi" : 1,
		"/d/city/npc/wujiang" : 2,
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	create_door("south", "����", "north", DOOR_CLOSED);
	set("coor/x", -10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
