#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ���㣬���Ѿ��������������󼰵ĸ߶ȣ��Ӵ�������\n"
"��ȥ��Զ����ҵƻ��뷱�����ԣ�����ɽׯ���ȴ��һƬ��ڣ���ʱ��\n"
"��������������\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou6",
          "down": __DIR__"lou4",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/wuliupo" : 1,
                ])
        );
       setup();
}

