inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫾�
������ɽ��ɽ���ˡ�
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "eastup" : __DIR__"shanjiao",
                "south" : __DIR__"shulin1",                
        ]));
        setup();
        replace_program(ROOM);
}
