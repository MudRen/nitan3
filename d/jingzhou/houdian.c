inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����ǹص���ĺ����жѷ����㡢������ǽ�ϵ�
ᣲ����������µġ�
LONG);
	set("exits", ([
		"north" : __DIR__"houmen",
		"south" : __DIR__"guanmiao",
	]));

	set("coor/x", -480);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

