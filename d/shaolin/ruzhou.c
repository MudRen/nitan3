inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮
һ����ɽ��
LONG );
	set("exits", ([
		"west"  : "/d/songshan/taishique",
		"north" : "/d/beijing/road10",
		"south" : __DIR__"yidao3",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "ruzhou");
	set("coor/x", 0);
	set("coor/y", 130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
