

#include <ansi.h>
inherit ROOM;
void create()
{ 
        set("short","����");
       set("long", @LONG
�����������ص����һ��СС�����ҡ�
LONG );
    
        set("exits", ([
                  "down" : __DIR__"midao12",
        ]));             
        set("objects",([
                CLASS_D("mingjiao") + "/cheng" : 1,
        ]));
        setup();
}

