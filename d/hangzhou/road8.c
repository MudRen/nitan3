// road8.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
���򶫱ߺ����ϱߡ������߱����ϱ�ʯɽ��
LONG );
        set("exits", ([
            "east"      : "/d/hangzhou/road9",
            "northup"   : "/d/hangzhou/baoshishan",
            "southwest" : "/d/hangzhou/road7",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
