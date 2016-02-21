#include <room.h>

inherit ROOM;

void create()
{ 
        set("short", "������ǰ");
        set("long", @LONG
�����������˳ɶ��ֲ��Ĵ���ǰ�棬�����˵ĳɶ��ֲ�����λ�ü��ã���ӳ
����ɽ��ˮ֮�䡣����һ����߷��Ľ��������˾���һ�������ƴ������֮�䡣
          
LONG );
        set("outdoors", "chengdu");
        set("exits", ([
                "west" :  "/d/city3/eastroad3",
                "east" : "/d/city3/xym_cddt",
        ])); 
        set("objects", ([   
             "/d/city3/npc/xym-guard" : 2,   
            ]));
               
        set("coor/x", -400);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();            
}

int valid_leave(object me, string dir) 
{ 
        if (objectp(present("shou wei", environment(me))) && dir == "east") 
        {
           if (! me->query_temp("good_xym2") && me->query("bunch/bunch_name") != "������")
               return notify_fail("����һ����ס�㣬�����ȵ��������������������˵���������\n"); 
           else
           {
              me->delete_temp("good_xym2");
              return ::valid_leave(me, dir);
           }
        }
        return ::valid_leave(me, dir); 
} 

