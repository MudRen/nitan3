// quyuanfenghe.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
�߽�ͤԺ��ֻ���ٺ�һ��С鿡�������һ����(duilian)�� ��鿹ۺ���ֻ��
�ɻ����������������Զ���塣������������ӽ���Ͼ����������У���ⲻ��
��ʱͬ��������Ҷ����̣�ӳ�պɻ������졻��
LONG );
        set("exits", ([
            "out"    : "/d/hangzhou/quyuanbei",
        ]));
        set("item_desc", ([
            "duilian" :
"\n
        ��              ��
        ��              ��
        ��              С
        ��              ��
        ˮ              ��
        Ӱ              ��
        ��              ��\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
