#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵڶ��㣬¥���ڱ���ȫ�Ǿ����ıڻ����������ڿ϶�û\n"
"�й������͡���\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou3",
          "down": __DIR__"lou1",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/sunsanhui" : 1,
                ])
        );

        setup();
}

