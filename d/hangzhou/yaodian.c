// yaodian.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����һ����������ҩ�ã���ǽ����һ����ҩ�񡣼��������æ����������
�ش�С������ץҩ��ҩ��ǰ����һ�����ӣ�����һλ��������Ϊ�˰�����������
��ҽ�����ࡣ    ��̨�Ϸ��߹�һ��������(paizi).
LONG );
        set("exits", ([
            "west"      : "/d/hangzhou/road14",
        ]));
        set("no_fight",0);
        set("no_beg","1");
        set("objects", ([
            "/d/hangzhou/npc/huqingyu" : 1,
        ]));
        set("item_desc", ([
            "paizi" : "������۸���ҩƷ��\n"
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
