inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "ɽ´");
        set("long",
"���������������ɽ´��Ҳ�������ɹž��ӵıؾ�֮·����·����
������ʮ�����ߣ����Ƕ��ڳ����Ĵ����˵�����������ߵ�·�������Ѿ�
���˼�ƽ�������ˡ�"
);
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
               "south"  : __DIR__"conglin2",
               "north"  : __DIR__"shanlu",
        ]));

        setup();
} 

