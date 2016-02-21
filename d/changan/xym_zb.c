#include <room.h>

inherit ROOM;

void create()
{ 
        set("short","��������ǰ");
        set("long", @LONG
�����������˳����ܶ�Ĵ��ţ�һ�����ӭ����չ�����顺�����񾡡��ĸ�
���֡�
LONG );
        set("outdoors", "yangzhou");
        set("exits", ([
                "south" :  __DIR__"dongan-dadao",
                "north" : __DIR__"xym_dating",
        ])); 
        set("objects", ([   
             __DIR__"npc/xym_guard" : 2,   
            ]));
               
        set("coor/x", -370);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();            
}

int valid_leave(object me, string dir) 
{ 
        if (objectp(present("shou wei", environment(me))) && dir == "north") 
        {
           if (! me->query_temp("good_xym1") && me->query("bunch/bunch_name") != "������")
               return notify_fail("����һ����ס�㣬�����ȵ��������������������˵���������\n"); 
           else
           {
              me->delete_temp("good_xym1");
              return ::valid_leave(me, dir);
           }
        }
        return ::valid_leave(me, dir); 
} 

