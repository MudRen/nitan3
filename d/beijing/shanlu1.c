inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
�����ǻ�����ɽ·��ֻ��һ��������᫵�С����
LONG );
	set("exits", ([
		"northup" : "/d/beijing/shanlu2",
                "eastdown": "/d/beijing/zhuang1",
	]));
 	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
