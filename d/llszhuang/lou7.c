#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ��߲㣬���ڴ˴����������ּ���ժ���ǳ��ĸо�����\n"
"�������ס������ֱ����Ҫ�������Ϊһ�塣\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou8",
          "down": __DIR__"lou6",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/wangbashuai" : 1,
                ])
        );

        setup();
}

