#include <ansi.h>

inherit ROOM;

#define PLACE "hz"
#define TYPE  "bad"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", "С����");
        set("long", @LONG
�������С�������ں��ݵķֶ棬���￴���������ޱȣ�һֻ��ľ���ϰ���
�������ƵĶľߣ�����������Щ����ͷ����������һ�ɼ��㡢����ͺ���������
һ���ζ����һ����֪���ǵ�Ʀ��å�ľۼ��ء������ǽ�Ϲ��������ƣ�paizi����
LONG );

        set("objects", ([
               "/d/hangzhou/npc/boss-ma"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([
                "out" : "/d/hangzhou/guozhuang",
        ]));

        setup();
}
#include <bang_bad.h>

