// Room: /d/fuzhou/puxian.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "����ƽԭ");
	set("long", @LONG
����������ƽԭ�ϡ�����������ģ����̳��ܣ�������
�Ǹ��ݸ����ˡ����Ͼͽ������ϡ�
LONG );
	set("exits", ([
		"north" : __DIR__"zhongzhou",
                "south" : "/d/quanzhou/beimen",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 150);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

