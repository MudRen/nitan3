// Room: /d/suzhou/xidajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ������
�š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��������߾����ĵ�û�м������ˣ�
������������ͨ�����⡣�ϱ�������ۣ�������һ�����á�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/xidajie1",
		"west"      : "/d/suzhou/ximen",
		"north"     : "/d/suzhou/shuchang",
		"south"     : "/d/suzhou/xuanmiao",
	]));
	set("coor/x", 180);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

