#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIG+BLINK"������"NOR);
    set("long", @LONG
������ר��Ϊ���������(paimai)��Ʒ����ĵط���
LONG );
        set("no_fight",1);
    set("exits", ([
        "north"  : "/d/city/pm_road1",
        "out"  : "/d/city/kedian",
    ]));
    set("objects", ([
        "/d/city/npc/paimaishi" : 1,
    ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

