//Room: xiaojia-pianting.c

inherit ROOM;

void create ()
{
        set ("short", "ƫ��");
        set ("long", @LONG
û�����!�Ǻ�!
LONG);
        set("exits", 
        ([ //sizeof() == 1
        	"south" : "/d/changan/xiaojiadt",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/yahuan" : 1,
        ]));

        set("coor/x", -340);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
