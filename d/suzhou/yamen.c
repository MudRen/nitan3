// Room: /d/suzhou/yamen.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ݸ���");
        set("long", @LONG
���϶������������������һ���������������������ϸ������ǽ������һ
�����ң�������顺����������ĸ���������Ĵ��֡����ྲ�����رܡ�������
�������ࡣ֪���������İ����������飬ʦү�����ں�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"  : "/d/suzhou/xidajie1",
	]));
	set("objects", ([
		"/d/suzhou/npc/feng": 1,
		"/d/suzhou/npc/shiye": 1,
		"/d/suzhou/npc/yayi": 4,
	]));
	set("coor/x", 190);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
