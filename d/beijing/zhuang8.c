#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
        set("long", @LONG
���������������ȣ��Ĵ��ڳ����ġ�
LONG );
    set("exits", ([
	"north" : "/d/beijing/zhuang9",
	"south" : "/d/beijing/zhuang5",
    ]));
    set("objects", ([
	"/d/shenlong/npc/dizi": 1,
    ]));
    set("outdoors", "beijing");
    setup();
    replace_program(ROOM); 
}
