// road3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������߱�ֲ���ɣ���Ŀ�Դ䣬�ȸ���ѩ������Ϊ������ѩ�ɡ�����������
�鴺�š��������ϱ㵽�������¡��ϱ���һ����·��
LONG );
        set("exits", ([
            "southup"     : "/d/hangzhou/huangniling",
            "southwest"   : "/d/hangzhou/road2",
            "northeast"   : "/d/hangzhou/hongchunqiao",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
