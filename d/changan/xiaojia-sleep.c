//Room: xiaojia-sleep.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
û�����!�Ǻ�!
LONG);
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/xiaojiadt",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/yahuan" : 1,
        ]));

        set("coor/x", -340);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
