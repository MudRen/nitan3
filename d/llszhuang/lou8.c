#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵڰ˲㣬������������Ѿ������˷��׳��������ɣ�\n"
"�����������֮����������Ͼ�Ľ��Ӱɣ��ó�����һ�з���Զ���ȥ�ɡ�\n"
"�˿̣������ͬ���֮��һֻɳŸ���������ɵ��������衣\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou9",
          "down": __DIR__"lou7",
        ]));
        set("no_magic", "1");

        set("objects", ([
            __DIR__"npc/kuangren1" : 1,
                ])
        );

        setup();
}


