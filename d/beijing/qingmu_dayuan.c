#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
һ���Ӳݴ������ĺ�ԺԺ�ӣ���Ժ������һ��������ĺ�ͬ�������Ǽ��䷿
�ݣ�����Ҳ����ô�ƾɡ�Ժ�к������˵ĵ���һЩʯ����������Ѱ�����ս�����
�����ġ�һ������վ�ڴ�Ժ�����У����ӵ����Ķ����㡣
LONG );
       set("exits", ([
                "north" : "/d/beijing/qingmu_men",
                "south" : "/d/beijing/qingmu_fang2",
                "east" : "/d/beijing/qingmu_fang1",
                "west" : "/d/beijing/qingmu_fang3",
        ]));
        set("objects", ([
                CLASS_D("yunlong") + "/xuanzhen" : 1
        ]));
        set("outdoors", "beijing");
        set("coor/x", -60);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

