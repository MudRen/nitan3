// gushan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ͨ���������ǰ��ӭ��ʯ���Ͽ��С���ɽ������������֡�����ʰ����ɽ��
��ƽ̨�������߱��Ƿ���ͤ�����ϱ�����ƽ�����¡�������ͨ�������š�
LONG );
        set("exits", ([
            "westup"    : "/d/meizhuang/shijie",
            "east"      : "/d/hangzhou/pinghuqiuyue",
            "southup"   : "/d/hangzhou/gushanpingtai",
            "northwest" : "/d/hangzhou/xilingqiao",
            "northeast" : "/d/hangzhou/fangheting",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
