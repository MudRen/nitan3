// Room: /d/xiangyang/eastjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ����ʮ�ֽֿڡ���
��������������㳡�������������سǴ�����ĸ�ۡ���ţ�ֻ���Ƕ��ر�ɭ�ϣ�
�����˵�һ���ǲ��ܽӽ��ġ�����Ʈ��һ���Ƶ�ҩ�㣬�ޣ�ԭ����һ��ҩ�̡�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/eastjie2",
		"west"  : "/d/xiangyang/guangchang",
		"south" : "/d/xiangyang/yaopu",
		"north" : "/d/xiangyang/jiangjungate",
	]));
	set("coor/x", -280);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

