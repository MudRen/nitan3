//Room: tuchangguan.c

inherit ROOM;

void create()
{
        set("short", "��潹�");
        set("long", @LONG
��û�����!�Ǻ�!
LONG);
        set("exits", ([ /* sizeof() == 1 */
        	"south" : "/d/changan/huarui6",
        ]));
        set("objects", ([
        	"/d/changan/npc/jinu" : 1,
        ]) );

	set("coor/x", -370);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
