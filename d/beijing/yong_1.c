#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ڶ���");
        set("long", @LONG
���ڶ�����һ�������Ĵ�֣�Ҳ�Ǳ��������ҵĵضΡ�һ����������ʯ���
���д�����������ͷ���졣�����Ǿ����������ķ����š�������һ�Һ����Ĵ�
�ĳ�����ʱ�������洫��һ���󲻿�������������ϱ��ǻ�Ӣ��¥���ھ����У�
Ҳ����С�������ġ�
LONG );
	set("exits", ([
		"south" : "/d/beijing/huiying",
		"north" : "/d/beijing/duchang",
		"east" : "/d/beijing/yong_2",
		"west" : "/d/beijing/tianqiao",
	]));
	set("objects", ([
		"/d/beijing/npc/dipi" : 1,
		"/d/beijing/npc/boy1" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

