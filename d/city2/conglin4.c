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
                "west"  : __DIR__"syuanmen1",
                "east"  : __DIR__"conglin3",
        ]));

        setup();
} 

