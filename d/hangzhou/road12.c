// road12.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ
���־��󡣽ֶ�����һ������Ժ����Ժ�ﲻʱ�������ʵ�Ц����������Ǵ�����
�����޼��ﺼ�ݷֲ��ˡ�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road11",
            "south"     : "/d/hangzhou/road13",
            "east"      : "/d/hangzhou/shuyuan",
        "west"       : "/d/hangzhou/wjb_hzfb",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/likexiu" : 1,
            "/d/hangzhou/npc/qingbing" : 4,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
