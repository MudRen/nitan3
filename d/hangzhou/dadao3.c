// dadao3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�غ����");
        set("long", @LONG
һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ��ˡ�������
������֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰��������ϱ����졣
LONG );
        set("exits", ([
            "south"     : "/d/hangzhou/road19",
            "north"     : "/d/hangzhou/dalu1",
            "west"      : "/d/hangzhou/liuzhuang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
}
