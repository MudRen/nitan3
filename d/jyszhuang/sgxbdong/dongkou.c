#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIY"�Ϲ��������"NOR);
        set("long", @LONG
�������Ϲ�ʱ������һ�����ض�Ѩ��ڣ���˵����������Ϲ�ʱ������������
���������������Щ��ѽѽ�ģ���֪������ʲô���ء�    
LONG );
        set("indoors", "city");
        set("exits", ([
        "north":   __DIR__"dong1",
        "south":   __DIR__"dong2",
        "west":    __DIR__"dong3",
        "east":    __DIR__"dong4",
        "out":    __DIR__"yongdao",  
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
        replace_program(ROOM);
}

