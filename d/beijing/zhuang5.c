#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "ׯ������");
        set("long", @LONG
����һ�������ͨ���������䡣���ߵ�������Ů�����֮������������
LONG );
    set("exits", ([
	"east" : "/d/beijing/zhuang6",
	"west" : "/d/beijing/zhuang7",
	"north" : "/d/beijing/zhuang8",
        "south" : "/d/beijing/zhuang3",
    ]));
    set("objects", ([
	"/d/shenlong/npc/dizi": 2,
        "/d/shenlong/npc/zhang3": 1,
    ]));
    set("outdoors", "beijing");
    setup();
    replace_program(ROOM); 
}
