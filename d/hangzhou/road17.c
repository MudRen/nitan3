// road17.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
���ϱ����ߣ������ǻ���Ȫ��������һ��ɽ·��
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road18",
            "south"     : "/d/hangzhou/qiantang",
            "west"      : "/d/hangzhou/hupaoquan",
            "east"      : "/d/hangzhou/kslu",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/tiao-fu" : 1,
            "/d/hangzhou/npc/chuyuan" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
