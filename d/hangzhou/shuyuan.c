// shuyuan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����Ժ");
        set("long", @LONG
��Ժ������һ�ҡ������Ժ������Ժ��������λ���ߣ�����������ʫ���ԡ�
�������Ե�����������ֽ�ͱ�ī��
LONG );
        set("exits", ([
            "west"      : "/d/hangzhou/road12",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
