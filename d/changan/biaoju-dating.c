//Room: biaoju-dating.c

inherit ROOM;

void create()
{
        set("short", "河洛镖局大厅");
        set("long", @LONG
厅堂中的陈设，全是十分精致的紫檀木家具，单是那扇巨大的八摺屏风，上
面镶了各色宝玉，砌成极其生动的八仙图，已是罕见的古物。上首一虎皮交椅，
上面坐着一个相貌威猛的汉子。
LONG );
        set("exits", ([
        	"north" : "/d/changan/biaoju-dayuan",
        ]));
        set("objects", ([
                "/quest/job/wang" : 1,
                 "/d/changan/npc/zong-biaotou" : 1,
        ]) );
        set("no_fight",1);

        set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
