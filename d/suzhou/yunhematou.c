// Room: /d/suzhou/yunhematou.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�˺���ͷ");
        set("long", @LONG
�������˺���ͷ�����ǳ�͢����Ҫ����ˮ½�ؾ�֮�����˺���������ֻ����
���󣬼��䷱æ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : "/d/suzhou/xidajie1",
	]));
	set("coor/x", 180);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

