// yuhuangshan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ");
        set("long", @LONG
ɽ����һ��Сͤ������ͤ�������ο͵�ɽǰ����ɽ�ᶼ�ڴ�СЪ��ɽ·����
�������ϡ�������һ����·��
LONG );
        set("exits", ([
            "eastup"  : "/d/hangzhou/shanlu6",
            "west"    : "/d/hangzhou/road18",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
