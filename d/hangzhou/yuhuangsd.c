// yuhuangsd.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
�������ɽ�����ɽ�£����Կ��������������˵���ǻʵۼ���ũʱ�׸�
�ļ��ɽ���и��ǹۣ�����Ƴ�������������һ�غͰ�ʯ��������������ͤ��
�������߸���һ����ɽ��·��
LONG );
        set("exits", ([
            "eastdown"  : "/d/hangzhou/shanlu7",
            "westdown"  : "/d/hangzhou/shanlu6",
        ]));
        set("objects", ([
            "/d/hangzhou/honghua/yu" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
