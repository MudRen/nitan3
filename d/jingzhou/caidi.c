inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
�㿴��һƬ�����͵Ĳ˵أ������˸��ָ����Ĳˣ��д�ͷ
�ˡ��ײˡ����Ĳˡ���
LONG);

	set("exits", ([
		"east" : __DIR__"whouyuan",
	]));

	set("coor/x", -480);
	set("coor/y", -170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

