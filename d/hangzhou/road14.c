// road14.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ
���־���������һ��԰�����˽���������ʮ�����֡���������ҽ�����࿪��ҩ
�̡�
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/road13",
            "southwest" : "/d/hangzhou/road15",
            "east"      : "/d/hangzhou/yaodian",
            "west"      : "/d/hangzhou/qingbomen",
        ]));
        set("objects", ([
            "/d/hangzhou/honghua/wen" :1,
            "/d/hangzhou/honghua/luo" :1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
