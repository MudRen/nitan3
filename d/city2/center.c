inherit ROOM;

void create()
{
        set("short", "����㳡");
        set("long",
"����������������㳡���ˣ�������ǻʹ������ˣ�һ���Ѱ������\n"
"�����ҵ�����ȥ�����������ﻹ���൱�����֣���ͷ���յģ���Ϸ�Ķ���\n"
"���ڴˣ��γ�һ�󾰹⡣\n"
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"ydmen",
                "south" : __DIR__"nandajie2",
        ]));

        set("objects", ([
//                "/d/city2/npc/flowerg" :    1,   
        ]));

        setup();
        replace_program(ROOM);
}

