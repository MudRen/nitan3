// liuzhuang1.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��ׯ��Ժ");
        set("long", @LONG
��������ׯ�Աߵ�Ժ�ӣ����ߵ����ﲻ����Щ���棬��Ȼ���˼�����������
��֮�˲��õ�����ľ�ˣ��Ա��м�����Ժ�Ҷ�ģ����������һ��ָ�ֻ��ŵĲ�֪
����˵Щʲô��
LONG );
        set("exits", ([
            "north" : "/d/hangzhou/liuzhuang",
        ]));
        set("objects", ([
                "/d/hangzhou/npc/jiading" : 2,
		"/clone/npc/mu-ren" : 3,
        ]));
        setup();
	replace_program(ROOM);
}

