// duanqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������������������ķ�ˮ���ϡ�����ͤ�����䣬��ӳ����������֮�¡�
��ɽ��ˮ����������������������������������������ľ�ɫ���ڶ����Ͽ�
���������ɽ�ͺ�����ķ�⡣ÿ��ѩ�ᣬվ����ͷ��ֻ��һ�ж������ϰ�ѩ��
������¥�ĺ�ɽ��ò��������ʮ��֮һ�ġ����Ų�ѩ��������񻰡����ߴ�����
�İ���������ɾ����������ġ�
    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ�����
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/road9",
            "west"      : "/d/hangzhou/baiti",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/poorman" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
