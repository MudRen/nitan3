// Room: /d/city/jiaowai1.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
        set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬������Ƣ��
���Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ����Ӱ�����ֶ��ˡ�
LONG );

    set("exits", ([
        "north" : "/d/city/dongmen",
        "south" : "/d/city/jiaowai2",
    ]));

    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
	set("coor/x", 40);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}