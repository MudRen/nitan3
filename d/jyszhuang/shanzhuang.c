// jyszhuang.c
// by Lonely

inherit ROOM;

void create()
{
        set("short", "����ɽׯ");
        set("long", @LONG
������Ǿ���ɽׯ��
LONG
        );
        set("no_clean_up", 0);

        set("exits",([
                "east" : __DIR__"zhanchang/exit",
                 "west" : "/d/dragon/spiritgate", 
        ]));
        set("objects", 
                ([ //sizeof() == 1
        ]));
        setup();
        replace_program(ROOM);
}


