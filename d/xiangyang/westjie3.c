// Room: /d/xiangyang/westjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����ǰ׻����ţ�������һ��
��ʮ�ֽֿڣ�ֻ���������������ﲻ�����ϱ��Ǵ�У���������������ǵ�����Ӫ��
�������������洫�����α��Ĳ�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/westjie2",
		"west"  : "/d/xiangyang/westgate1",
		"south" : "/d/xiangyang/dajiaochang",
		"north" : "/d/xiangyang/bingying4",
	]));
	set("coor/x", -330);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

