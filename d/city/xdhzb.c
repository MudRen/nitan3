#include <ansi.h>

inherit ROOM;

#define PLACE "yz"
#define TYPE  "bad"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "С���������ܲ�");
        set("long", @LONG
������С���������ܲ�������ķ����ﴫ����ߺ������ĶĲ�����
С���������ݱ��ص�һ���ڰ��������������ϴ��ó��ɵ��������ڴ�
�����������е�Ʀ��å֮�󣬴�����С���ᣬ��Զ���պ������ĵ�ͷ
�ߡ��ڷ����ǽ����һ������(look paizi)������С�������ң���
��������ѡ������ȥ��ɡ�
LONG );

        set("objects", ([
               "/d/city/npc/boss-ju" : 1,
               "/d/city/npc/toumu"   : 2,
        ]));

      set("no_fight",1);

        set("exits", ([
                "out" : "/d/city/shulin1",
        ]));

        setup();
}
#include <bang_bad.h>
