// Room: /d/city/jiaowai7.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
        set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬������Ƣ��
����̤��Զ���ʱ�⡣
LONG );
    set("exits", ([
        "east" : "/d/city/jiaowai6",
        "west" : "/d/city/nanmen",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}