// baoshishan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯɽ");
        set("long", @LONG
��ʯɽ���Ǻܸߣ�ɽ�϶�����ʯ��ɽ·����һ��ͤ�ӡ�����ͤ����ͤǰ��
�����δ�ʯ���ٿո�����ɽ�ۣ�������ʯ���ֳ�����ʯ���������Ͼ͵��˱�������
�����±�ص�����ˡ�
LONG );
        set("exits", ([
            "northup"   : "/d/hangzhou/baoshuta",
            "southdown" : "/d/hangzhou/road8",
        ]));
        set("objects", ([
            "/d/hangzhou/obj/shitou": 1,
            "/d/hangzhou/obj/eluanshi": 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
