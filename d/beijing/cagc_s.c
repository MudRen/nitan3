#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����ֹ㳡");
        set("long", @LONG
������ǳ����ֹ㳡�ˣ������ֹ㳡�Ǿ����������֡������ҵĵضΡ��Ϸ�
��һ�����ź�綫�����������ӻ������Ϸ���ܽ����������˵Ⱦ۾ӵ����ڡ���
���Ĵ�����ϱ���ͷ���졣���Ϸ�������ΰ�ķ����ž��Ǳ������������������
ʤ������̳�ˣ�����̳�����Ϸ��������������ţ�ͨ�����⡣��������Կ�����
����Զ����һ�¶¸ߴ�ĳ�ǽ����������찲�Ź㳡�ˡ�
LONG );
       set("exits", ([
		"south" : "/d/beijing/tianqiao",
		"north" : "/d/beijing/tiananmen",
	]));
	set("objects", ([
		"/d/beijing/npc/maiyi1" : 1,
		"/d/beijing/npc/xianren" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

