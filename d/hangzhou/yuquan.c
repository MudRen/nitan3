// yuquan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
��Ȫ�½�����Ȫɽ�ϣ�ԭ�������¡��߽���Ȫ�£�ֻ�������м�
��ˮ��(pond)���������ǳ�����ɽ��·��
LONG );
        set("exits", ([
                "eastdown"  : "/d/hangzhou/road5",
                "north"  : "/d/hangzhou/quanbian-xiaojing",
        ]));

        set("item_desc", ([
                "pond": "���Ե�ʯ�����š�������Ȫ��������ż��Сˮ����ӿ������һ������\n",
        ]));

        set("objects" , ([
                "/d/hangzhou/npc/you-ke" : 1,
                "/d/hangzhou/npc/yuenv"  : 1,
        ]));

        set("outdoors", "hangzhou");

        setup();
        replace_program(ROOM);
}
