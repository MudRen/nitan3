//Room: liande-dadao3.c

inherit ROOM;

void create ()
{
        set ("short", "连德大道");
        set("long", @LONG
城内街道，与南北三条并行的大街，和东西的二条主街互相交错而成。五条
大街在这清朗的夜初，却见人来车往，灯火通明，别有一番热闹。其他小街横巷，
则依这些主街交错布置，井然有序。
LONG );
        set("exits",([//sizeof() == 2
        	"south" : "/d/changan/dongan-daokou",
        	"north" : "/d/changan/liande-dadao2",
        ]));

        set("outdoors", "changan");
        set("coor/x", -360);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
