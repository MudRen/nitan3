#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ����㣬���н��ߣ�����ķ羰��ס��á�\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou4",
          "down": __DIR__"lou2",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/lisicui" : 1,
                ])
        );

        setup();
}

