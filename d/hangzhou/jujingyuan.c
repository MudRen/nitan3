// jujingyuan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�۾�԰");
        set("long", @LONG
����԰�У�ֻ���������ô������������У����˲��ٱ��ҡ�������ů֮ʱ��
�������ǧ������˿�����̽��벻ʤ������ʫ���������ġ��Һ���׽Կ�ã�
��ô����෢�ӡ����ݵ�ǡ���ô����������岨�ţ����������������š�
LONG );
        set("exits", ([
            "east"      : "/d/hangzhou/qingbomen",
            "northeast" : "/d/hangzhou/liulangqiao",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/jian-ke" : 1,
            "/d/hangzhou/npc/honghua2" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
