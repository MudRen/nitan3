//ROM dating
inherit ROOM;
void create()
{
        set("short", "�����ô���");
        set("long", @LONG
���ǡ�������̡��µ������ã������õĴ�����һλ���߾��У������㱡�
LONG );
        set("exits", ([
            "north" : "/d/heimuya/chlang2",
            "east" : "/d/heimuya/tang",
        ]));
        set("objects",([
            CLASS_D("riyue") + "/jiabu": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
