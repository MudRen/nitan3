// /guanwai/baihe2.c

inherit ROOM;

void create()
{
        set("short", "�׺�С��");
        set("long", @LONG
�����ǳ���ɽ�µ�һС��������ɪɪ�����˲���������
LONG );
        set("exits", ([
                "north"  : __DIR__"baihe",
                "east"   : __DIR__"haigang",

        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}

