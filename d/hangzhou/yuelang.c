// yuelang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������������ǡ��������ա��ĸ����֡���������������ɵ�������
����������š����Һ�ɽ�������ߵ���ͨ�����أ������ǳ�ȥ��·��
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/yuefen",
            "south"     : "/d/hangzhou/road6",
        ]));
        set("objects" , ([
            "/d/mingjiao/npc/chengchaofeng" : 1,
            "/d/hangzhou/npc/honghua2" :2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
