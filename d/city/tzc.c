#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY+BLINK"��ս��̨"NOR);
        set("long", HIC@LONG
������ר���������������ս����̨��
LONG );
        set("no_drift", 1);
        set("no_clean_up", 0);
        set("exits",([
                "down" : "/d/city/guangchang",
        ]));

        setup();
        replace_program(ROOM);
}

