// Room: /d/suzhou/zhipoxuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "Ҿ��ָ����");
        set("long", @LONG
��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ˵���дʫ����֮
��������ȡ���䡺ǰҾ®ɽ��һ����㡻�͸����ġ�Цָͥǰ�ء���ʫ�⡣����
��������ɫ��ƾ����������Ŀʯ����ᾣ��Ű��֦���ƣ�������Դ��ʮ�˾���
֮�ơ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : "/d/suzhou/shizilin",
	]));
	set("coor/x", 220);
	set("coor/y", -220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

