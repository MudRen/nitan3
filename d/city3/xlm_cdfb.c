#include <ansi.h>

inherit ROOM;

#define PLACE "cd"
#define TYPE  "bad"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "�����ŷ�̳");
        set("long", @LONG
�����Ǻڵ���֯�����ŵĳɶ���̳������һ����ɭ�ֲ��ķ��䣬��������Ϊ
�������ֿ��£������������Ե���������������������̬���죬���˸о��·�
�����������һ�㡣ǽ�Ϲ��������ŵ������ƣ�paizi����
LONG );

        set("objects", ([
               "/d/city3/npc/boss-leng"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "out" : "/d/city3/qingyanggong",
        ]));

        setup();
}
#include <bang_bad.h>

