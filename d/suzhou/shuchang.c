// Room: /d/suzhou/shuchang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�鳡");
        set("long", @LONG
���߽��鳡�����������������ֵģ������ﶼ������ģ�����ǰ����һλ˵
��������������ȥ����ʮ�꣬��������һ����壬���ھ۾������˵������--��
��ҽ�������Ҳ�𽥱���������������������е����ǲ�ʱ�ķ�����̾�ͺȲ�����
ʱ��ʱ��ͭ��������ȥ��
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"  : "/d/suzhou/xidajie2",
	]));
	set("objects", ([
		"/d/suzhou/npc/gongzi": 1,
	]));
	set("coor/x", 180);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
