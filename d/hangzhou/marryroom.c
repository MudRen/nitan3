// marry_room.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
��������վ�ڷ�����������Ӻ��ϵĺ���ׯ���ˮƾ�������ű��̵ĺ��棬
���Ƕ����ˡ�
LONG );
        set("exits", ([
            "east" : "/d/hangzhou/road10",
        ]) );

        set("no_fight",1);
        setup();
}

