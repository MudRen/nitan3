// maojiabu.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "é�Ҳ�");
        set("long", @LONG
·���Ը��ż���С���������ſ�һλ�ϴ�������ι��������С������׷����
Ϸ���������ϻ����롣�����Ƕ���ɽ��
LONG );
        set("exits", ([
            "southwest"   : "/d/hangzhou/tulu1",
            "northup"     : "/d/hangzhou/huangniling",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/boy" : 1,
            "/d/hangzhou/npc/oldwoman" : 1,
            "/d/hangzhou/npc/camel" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
