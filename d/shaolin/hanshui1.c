#include <ansi.h>
#include <room.h>
inherit RIVER;

void create()
{
        set("short", "��ˮ�ϰ�");
        set("long", @LONG
��ǰ��һ�����η����Ĵ� (river)���������������۾�
���������ɴ���������������һ�����������̯����Ҿͽ���
���ڰ��ߣ���������֧һ��ľ�壬���ϰ����˻�������ĺ���
���㡣��ȥ��Զ�����������Ϻӿڡ�
LONG);
        set("arrive_room", "/d/shaolin/hanshui2");
        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("objects", ([
                __DIR__"npc/chuanfu1" : 1,
        ]));

        set("outdoors", "nanyang");
        set("coor/x", 0);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
}
