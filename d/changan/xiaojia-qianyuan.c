//Room: xiaojia-qianyuan.c

inherit ROOM;
void create ()
{
        set ("short", "����ǰԺ");
        set ("long", @LONG
û�����!�Ǻ�!
LONG);
        set("exits", 
        ([ //sizeof() == 2
        	"west" : "/d/changan/liande-dadao5",
        	"east" : "/d/changan/xiaojiadt",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/guanjia" : 1,
        ]));

        set("outdoors", "changan");
        set("coor/x", -350);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
