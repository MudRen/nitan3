#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ��������
�أ�������Ҷ��������������������Ķ����������ƺ���һ��
��ª��СԺ��
LONG );
        set("exits", ([
                "south" : __DIR__"xiaoyuan.c",
                "north" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/qingfeng": 1,
                CLASS_D("wudang") + "/mingyue": 1,
        ]));
        create_door("south", "����", "north", DOOR_CLOSED);
        set("outdoors", "wudang");
	set("coor/x", -370);
	set("coor/y", -330);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}