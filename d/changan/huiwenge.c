//Room: huiwenge.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "���ĸ�");
       set ("long", 
"����һ����֡����������һ���ŵ�����������������ط���һЩ���ᣬ\n"
"���ڻ������ż��軨���ݲݣ�������䣬�������£�����������Ŀ�������Ϳ���\n"
"����һ�����:\n"
HIB"         ��ɽ�о���Ϊ·\n"
"         ѧ�����Ŀ�����\n"NOR );

        set("exits", 
        ([ //sizeof() == 1
                "west" : "/d/changan/yongtai-dadao3",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/shuchi" : 1,
        ]));

        set("no_clean_up", 0);
        set("coor/x", -430);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
