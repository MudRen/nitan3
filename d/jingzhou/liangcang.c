inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǿ��������ˣ����϶��������������װ���ǰ�
�ȴ���֮�����ʳ��
LONG);
	set("exits", ([
		"west" : __DIR__"lcmen",
	]));

	set("coor/x", -430);
	set("coor/y", -230);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

