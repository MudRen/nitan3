// Room: /d/suzhou/tielingguan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
�سʳ����Σ�שʯ�ṹ�����е������¥Ϊ�½�������صش�ˮ½Ҫ�壬�ǵ�
¥���ȿ����������ܷ�����������ԫ���˺ӡ�ʯ������ɵ����Ϲ��£���ʱ��
Ϊ�˷����ϵֿ����ŵ����ܡ�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/suzhou/fengqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 3,
	]));
	set("coor/x", 140);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

