#include <ansi.h>

inherit ROOM;

#define PLACE "bjw"
#define TYPE  "bad"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "�����ŷ�̳");
        set("long", @LONG
�����Ǻڵ���֯�����ŵı�����̳��û�뵽���õ������ŷ�̳����Ȼ������
����һ�������۵Ľ������棬���������ӽ��£��ʳǸ�����Ե�ʣ�����ķ�̳��
������أ����ҿֲ������е��������������һλ���޵�Ů�ӡ��Աߵ�ǽ�Ϲ���
һ�������ƣ�paizi����
LONG );

        set("objects", ([
               "/d/beijing/npc/boss-hu"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "up" : "/d/beijing/minju",
        ]));

        setup();
}
#include <bang_bad.h>

