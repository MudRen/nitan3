inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HIY"�еµ���"NOR);
        set("long",
"�����ǳеµ��ڣ�Ҳ�Ǵ��λʵۺ�����ٹ����µĵط������ڽ�̻�\n"
"�ͣ�ɷ����ΰ׳�ۣ�����������������϶��������λ��ڣ����������\n"
"�ڹ�Ů̫�࣬����ٹ���Ʒ���������ҡ�\n"
);

        set("indoors", "city2");
        set("no_fly",1);
        set("no_fight",1);
        set("have_quest",1);

        set("exits", ([
                "out"    : __DIR__"cddian",
        ]));

        set("objects", ([
           __DIR__"song/liu" : 1,
           __DIR__"npc/taijian"     : 2, 
        ]));
        setup();
        replace_program(ROOM);
}

