// /d/city/tianbaoge.c
// by Lonely

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�챦��");
        set("long", @LONG
����ԭ�Ǳ���һ��������꣬��õ����ϰ徭Ӫ���ƶ����ա��ڴ�
֮��������ĳ��ְ��������¹�������棬����֪Ϊ���ְ����ˡ����һ
λ���̽��˵����£�װ����һ���������¿�ҵ�ˡ���˵�����������֮�⣬
�����ṩһЩ�µķ���
LONG );

        set("exits", ([
                "south" : __DIR__"xidajie3",
        ]));
        
        set("objects", ([
                "/clone/npc/publisher" : 1,
        ]));

        set("no_fight", 1);
        set("no_sleep", 1);
        set("day_shop", 1);
        
	set("coor/x", -30);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}
