// Room: gbdixiaoshi.c
// by aji

inherit ROOM;
void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
���߽���һ��С�ݡ�����ǽ�ڶ�����������ɣ�������һ���޼ʵ����֡���
������Ρ����̾�Ϊ���ơ���һ���˱Ƕ����Ĺ�����ζ��ȴ�Ե��������ŵ�����
����롣
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : "/d/city/gbandao"
        ]));
	set("objects", ([
		"/d/city/obj/zhubang": 1,
		"/d/city/obj/gourou": 1,
		"/d/city/obj/jiudai": 1,
		"/d/city/obj/jitui": 1
	]));

        set("valid_startroom", 1);
        set("sleep_room", 1);
	set("coor/x", 50);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();

        (CLASS_D("gaibang") + "/hong")->come_here();
}

void reset()
{
        ::reset();
        (CLASS_D("gaibang") + "/hong")->come_here();
}