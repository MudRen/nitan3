inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�ʹ����");
        set("long",
"�����ǻʹ��ڵĴ��������Ŀ�ƽ������ʱ��һЩ��Ů��̫�ྭ��\n"
"���㲻�Ҷ࿴�����ǿ�㳯ǰ�߰ɣ�ʡ�������������̲顣\n"
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north"    : __DIR__"cddian",
                "south"    : __DIR__"hgdadao5",
                "west"    : __DIR__"majiu",  
        ]));

        set("objects", ([

        ]));
          setup();
        replace_program(ROOM);
} 

