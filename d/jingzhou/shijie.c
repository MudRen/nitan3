inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ����ʯ������ʯ�ף���������ͨ��������Ժ����
������һƬ���̵����֡�
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
		"southdown" : __DIR__"zizhulin",
		"north" : __DIR__"shuyuan1",
	]));
	set("coor/x", -450);
	set("coor/y", -230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

