
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
���߽���һ��С�ݣ������С������һ��С���Ų��±��
�����ˡ����Ϻ����м���������������Ĵֲ�����ϴ�ĸɸɾ�
����
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"xiuxishi",
                "east" : __DIR__"xiaoting",
                "west" : __DIR__"yaofang",
        ]));

        set("objects", ([
                "/d/gumu/obj/fengjiang" : 3,
                __DIR__"obj/fengmi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
