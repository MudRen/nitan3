// liuhe5.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������������㡣��(window)����Ũױ��Ĩ�����Ӻ�����������˽ǣ�
��ש���أ��������ܼ�ճ����Щ��������
LONG );
        set("exits", ([
            "down"  : "/d/hangzhou/liuhe4",
            "up"    : "/d/hangzhou/liuhe6",
        ]));
        set("objects", ([
            "/d/hangzhou/honghua/wei" :1,
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" &&
            objectp(present("wei chunhua", environment(me))))
            return notify_fail("���������һ�������о����������м��������������\n");
        return ::valid_leave(me, dir);
}
