#include <ansi.h>

inherit ROOM;

#define PLACE "ca"
#define TYPE  "good"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "�����˳����ܶ�");
        set("long", @LONG
�������������ڳ������ܲ�����������ûʲô������װ�Σ�һ���������ӡ�
�����Ϸ��߸ߵ�������һ�����������֮�����ĸ���ͻ͵Ĵ��֡����µ�̫ʦ��
�϶�����һλ���ϵ��������ӣ���ؾ��ǳ��������ɴ󵱼ҡ��������һ������
�����˾����Ĵ�����ǽ�Ϲ���һ��������(paizi)��������������쵽��������
LONG );

        set("objects", ([
               __DIR__"npc/boss-cheng"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "south" : __DIR__"xym_zb",
        ]));

        set("coor/x", -370);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
#include <bang_good.h>

