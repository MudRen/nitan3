//Room: /d/dali/zhulou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","竹楼");
        set("long", @LONG
一间标准的台夷竹楼，四面墙壁皆是竹子，正中砌了一座正方形的灶台，其
内架置着铁炉。夷族传统席地而睡，是以屋内无床，沿墙摆有垫褥，屋舍内除了
石堆祭台外别无家具。
LONG );
	set("objects", ([
	   "/d/dali/npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"   : "/d/dali/zhulou1",
	]));
	setup();
	replace_program(ROOM);
}

