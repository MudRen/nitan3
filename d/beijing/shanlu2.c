inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
�����ǻ�����ɽ·��ֻ��һ��������᫵�С��������������̣����˾��ñ�
�����쬵ġ�
LONG );
	set("exits", ([
		"westup"    : "/d/beijing/shanlu3",
		"southdown" : "/d/beijing/shanlu1",
	]));
 	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
