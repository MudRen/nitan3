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
               "west"  : __DIR__"conglin4",
               "north"  : __DIR__"conglin2", 
        ]));

        setup();
} 

