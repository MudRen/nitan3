// jingcisi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£�ԭ����������Ժ���ֽ��˽��¡�������������������ӵ��Ȼͦ���
����ɽ�������ͻص�����ϡ�
LONG );
        set("exits", ([
            "north"   : "/d/hangzhou/road16",
            "enter"   : "/d/hangzhou/jingci",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
