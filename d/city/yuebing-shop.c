
// yuebing-shop.c
// smallbear 03.9.9

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ܼ��±���");
        set("long", @LONG
�������ܴ��ϰ忪���±��ꡣ�ܼ��±������������������򲻵�����ӱ�±���
�ַ����ｫ�����±�����˿�ӯ�š�
LONG );
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room","1");
        set("valid_startroom","1");

        set("objects", ([ 
                "/d/city/npc/xiongsan"     : 1, 
               
        ])); 

        set("exits", ([
                "south" : "/d/city/dongdajie3",
        ]));
	set("coor/x", 30);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

