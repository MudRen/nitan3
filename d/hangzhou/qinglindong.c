// qinglindong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ֶ�");
        set("long", @LONG
�ֽ��ϻ�����ֻ�����ҵ������ӣ�����������������С�𡣶��ڶ�����ϻ�
����һ�顺®���Ƿ�᡻�������Ͽ̻�ͷ�裬�м���������Ĳ�ᣬ���ҷ�����
�⣬���ͣ���������������������ɽ��·��С·���������򶫡�
LONG );
        set("exits", ([
                "eastup"    : "/d/hangzhou/cuiweiting",
                "westdown"  : "/d/hangzhou/feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
