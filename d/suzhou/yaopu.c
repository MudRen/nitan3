// Room: /d/suzhou/yaopu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С��
����ɢ�������ġ�ҩ������ȴ���ڵ��ڡ�һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG );
//	set("no_clean_up", 0);
	set("exits", ([
		"south"  : "/d/suzhou/dongdajie2",
	]));
	set("objects", ([
		"/d/suzhou/npc/huoji" : 1,
	]));
	set("coor/x", 240);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

