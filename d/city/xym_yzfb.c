//xym_yzfb.c
#include <ansi.h>

inherit ROOM;

#define PLACE "yz"
#define TYPE  "good"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "���������ݷֶ�");
        set("long", @LONG
�����������������ݵķֶ档�ֶ����֣�ƻ��˳��������µ�һԱ�ͽ�����
��������ڷ����ǽ����һ������ (paizi)�����������˵���ң�����������ѡ
������ȥ��ɡ�
LONG);

        set("objects", ([
               "/d/city/npc/boss-zheng"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "south" : "/d/city/xym_yzdamen",
        ]));

	set("coor/x", -50);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
#include <bang_good.h>