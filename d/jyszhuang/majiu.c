// Room: /city/majiu.c
// Modified by Lonely Nitan@Mud

#include <ansi.h>
#include <room.h>
inherit TRANS_ROOM; 

void create()
{
        set("short", YEL"���"NOR);
        set("long",
"���ǿ�ջ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����\n"
"ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ\n"
"�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������\n"
"һ����ۡ�ǽ�Ϲ���һ������(paizi)��\n"
);

        set("objects", ([
                "/clone/npc/mafu" : 1,
		"/clone/horse/zaohongma" : 1,
		"/clone/horse/huangbiaoma" : 1,
		"/clone/horse/ziliuma" : 1,

        ]));

        set("exits", ([
		"south" : __DIR__"kedian",
        ]));



        set("outdoors", "city");
        set("no_fight",  1);
        set("no_beg", 1);
        set("no_clean_up", 0);
        set("resource/water", 1);

        setup();
}
