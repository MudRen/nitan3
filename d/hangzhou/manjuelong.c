// manjuelong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����¤");
        set("long", @LONG
ɽ·����һ��С���䣬�������ܹ𻨳��֡�ÿ�������ʢ����Ʈ�����
����Ϊ����ѩ���硻��������ˮ�ֶ�������ʯ�ݶ���
LONG );
        set("exits", ([
                "westup"    : "/d/hangzhou/shuiledong",
                "eastdown"  : "/d/hangzhou/shiwudong",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

