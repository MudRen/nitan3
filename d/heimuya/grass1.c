inherit ROOM;
 
void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
������һƬ�ݵء��ݵض�����һƬĹ�ء�
LONG );
        set("exits", ([
            "east"    : "/d/heimuya/mudi",
            "south"    : "/d/heimuya/fen0", 
            "north"    :"/d/heimuya/grass2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "inn");    
        setup();
	replace_program(ROOM);
}
