// liuhed.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ʮ���㡣��(window)����Ũױ��Ĩ�����Ӻ�����������˽ǣ�
��ש���أ��������ܼ�ճ����Щ��������������������ߴ���������ȥ��������
�������۵ס�
LONG );
        set("exits", ([
            "down"  : "/d/hangzhou/liuhec",
        ]));
        set("objects", ([
            "/d/hangzhou/honghua/chen" :1,
            "/d/hangzhou/npc/qianlong" :1,
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);

}
