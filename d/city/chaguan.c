// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ����
���������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�����
�Ǹ������ڡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east" : "/d/city/nandajie2",
//                "up" : "/d/city/chashi",
	]));
	set("objects", ([
		"/d/city/npc/aqingsao" : 1,
	]));
	set("coor/x", -10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
        "/clone/board/player_b"->foo();
}