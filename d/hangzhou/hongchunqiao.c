// hongchungqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�鴺��");
        set("long", @LONG
��������Կ�������ʮ��֮һ��˫�����(scenery)�� ���ͨ�򱱱ߣ�����
������ͨ�������µ�·��
LONG );
        set("exits", ([
            "southwest"     : "/d/hangzhou/road3",
            "north"         : "/d/hangzhou/road4",
        ]));
        set("item_desc", ([
        "scenery" : 
"˫�壬�ϸ߷�������֮���ϣ����߷�������֮�������ϱ�ңң��ԣ�
ֻ��������գ�˫����������籡��֮�У���Ũ�򵭣�ʱ��ʱ�ޣ���
��Ʈ�ƣ����������������\n",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

