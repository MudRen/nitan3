inherit ROOM;

void create()
{ 
        set("short", "�޼�����ǰ");
        set("long", @LONG
�������޼��������ܲ��Ĵ���ǰ�棬�޼�����������ֻ�Ƿ�����������ڣ�
��ʹ��ˣ���������Ҳ��ķ����Ȼ������һ�ۿ���ȥ���;������Ʋ�����
LONG );
        set("outdoors", "xiangyang");
        set("exits", ([
                "south" :  __DIR__"xiaorong1",
                "north" :  __DIR__"wjb_dating",
        ])); 
        set("objects", ([   
                __DIR__"npc/wjb-guard" : 2,   
        ]));
               
        set("coor/x", -260);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();            
}

int valid_leave(object me, string dir) 
{ 
        if (objectp(present("shou wei", environment(me))) && dir == "north") 
        {
           if (! me->query_temp("good_wjb") && me->query("bunch/bunch_name") != "�޼���")
               return notify_fail("����һ����ס�㣬�����ȵ������޼������������˵���������\n"); 
           else
           {
              me->delete_temp("good_wjb");
              return ::valid_leave(me, dir);
           }
        }
        return ::valid_leave(me, dir); 
} 

