// road15.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�����������������������
���߸���һ����������ϱ��������ɽ��ɽ·��
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/road14",
            "southwest" : "/d/hangzhou/yuhuangsj",
            "west"      : "/d/hangzhou/road16",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
