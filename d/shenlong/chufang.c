// Room: chufang.c
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
�����������ĳ�����������Ŵ�Բ������Χ����ż������Ρ��������ĵ���
���������ò͡�
LONG );
	set("exits",([
	    "west" :__DIR__"zoulang",
            "east" :__DIR__"guoyuan",
	]));
	set("objects",([
		"/clone/food/jitui" : 3,
        __DIR__"obj/longxx.c" : 1,
		"/clone/food/jiudai" : 1,
        ]));

	set("resource/water", 1);
        set("no_fight", 1);
        setup();
	replace_program(ROOM);
}

