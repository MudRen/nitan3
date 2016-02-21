// Room: /d/suzhou/dongdajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ���ֵ����죬��������
�ݳ���һ�����ֺŵĵ��̣�������һ��С��ͬ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/dongdajie2",
		"north"     : "/d/suzhou/hutong1",
		"south"     : "/d/suzhou/dangpu",
		"southwest" : "/d/suzhou/baodaiqiao",
		"northwest" : "/d/suzhou/canlangting",
	]));
	set("objects", ([
		"/d/suzhou/npc/kid" : 1,
	]));
	set("coor/x", 210);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

