inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������򸮵ĺ�Ժ��Ժ������һ�øߴ��������������ա�
������һ��С�ţ�������һƬ�����͵Ĳ˵ء�
LONG);
	set("exits", ([
		"south" : __DIR__"dayuan",
		"west" : __DIR__"caidi",
	]));

	set("coor/x", -470);
	set("coor/y", -170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

