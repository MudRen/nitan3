// shiwudong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ʯ�ݶ�");
        set("long", @LONG
ɽ·����ʯ�ݶ���ʯ�ݶ��������ж������������������ߴ�����ྻ������
�Ͽ���խ��״�縡�ݡ����ϱ㵽������¤��ɽ·�ľ�ͷ����һ���ɱ����ϵĴ����
LONG );
        set("exits", ([
                "westup"    : "/d/hangzhou/manjuelong",
                "east"      : "/d/hangzhou/road18",
        ]));
	switch(random(1)){
	case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
                                  "/d/xingxiu/npc/spider" : 1,
                                  "/clone/worm/changaoxie": 1,
                                  "/d/xingxiu/npc/centipede" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
/*
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
*/
        }
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

