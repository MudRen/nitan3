// Room: /d/suzhou/dongdajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ����������سǹ�
����ߺ������������һ�����ֺŵ�ҩ�̣��ϱ��Ǵ����̣�����������������Զ��
��������
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/dongmen",
		"north"     : "/d/suzhou/yaopu",
		"south"     : "/d/suzhou/datiepu",
		"west"      : "/d/suzhou/dongdajie1",
		"northwest" : "/d/suzhou/hutong3",
	]));
	set("coor/x", 240);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

