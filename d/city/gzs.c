#include <room.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
�������½���һ�乤���ң���Ϊ�ϰ���ſ�������û�н���װ�ޡ�
LONG );
        set("no_fight",1);
    set("exits", ([
        "west"  : "/d/city/beimen",
    ]));
    set("objects", ([
        "/quest/npc/yao" : 1,
        "/d/city/npc/jpl" : 1,
    ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

