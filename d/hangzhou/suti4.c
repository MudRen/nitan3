// suti4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����������������ϣ�������ɴ��ȸ������һƬ�������յ̴�������Ϊ��
��ʮ��֮�ף���Ȼ�����鴫��������ѹ���ţ���������ɽ�š�����һƬ÷�֣���
���ƺ�����Ժ�䣬���������С�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti3",
            "south"     : "/d/hangzhou/suti5",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/liyuanzhi" : 1,
            "/d/hangzhou/npc/wuya" : 1,
            "/d/hangzhou/npc/maque" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
