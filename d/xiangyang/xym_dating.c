#include <ansi.h>

inherit ROOM;

#define PLACE "xy"
#define TYPE  "good"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "�����������ܶ�");
        set("long", @LONG
���������������������ܲ�����������ûʲô������װ�Σ�һ���������ӡ�
�����Ϸ��߸ߵ�������һ�����������֮�����ĸ���ͻ͵Ĵ��֡����µ�̫ʦ��
�϶�����һλ���ϵ��������ӣ���ؾ��ǳ��������ɴ󵱼ҡ��������һ������
�����˾����Ĵ�����ǽ�Ϲ���һ��������(paizi)��������������쵽��������
LONG );

        set("objects", ([
               "/d/xiangyang/npc/boss-cheng"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "south" : "/d/xiangyang/xym_zb",
        ]));

        setup();
}
#include <bang_good.h>

