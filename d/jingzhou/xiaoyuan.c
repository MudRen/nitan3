inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
������һ���ľ��Ļ������ڣ�ż���������������д�����
��������У�԰�������Ÿ�ʽ���������滨�ݡ����̾գ���
�����ž顢ĵ������
LONG );
        set("outdoors", "jingzhou");
	set("exits", ([
		"out" : "/d/jingzhou/zizhulin1"
	]));
	set("objects",([
		"/d/jingzhou/obj/lvju" : 3,
	]));

	set("coor/x", -450);
	set("coor/y", -250);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

