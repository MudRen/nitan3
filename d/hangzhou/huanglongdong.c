// huanglongdong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
һ��ɽ�ţ����򽻴䣬���ж��졣ʯ�ڶ�����̦�۳��̣�������֮����һС
�壬���⣺���������须��
LONG );
        set("exits", ([
            "south"     : "/d/hangzhou/shanlu8",
        ]));
        set("objects", ([
            "/clone/beast/dushe" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

