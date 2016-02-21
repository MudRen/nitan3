inherit ROOM;

void create()
{ 
        set("short", "�޼�����ǰ");
        set("long", @LONG
�������޼��ﺼ�ݷֲ��Ĵ���ǰ�棬�޼�����������ֻ�Ƿ�����������ڣ�
��ʹ��ˣ���������Ҳ��ķ����Ȼ������һ�ۿ���ȥ���;������Ʋ�����
LONG );
        set("outdoors", "hangzhou");
        set("exits", ([
                "east" :  "/d/hangzhou/road12",
                "west" : "/d/hangzhou/wjb_hzdt",
        ])); 
        set("objects", ([   
             "/d/hangzhou/npc/wjb-guard" : 2,   
            ]));
               
        setup();            
}

int valid_leave(object me, string dir) 
{ 
        if (objectp(present("shou wei", environment(me))) && dir == "west") 
        {
           if (! me->query_temp("good_wjb1") && me->query("bunch/bunch_name") != "�޼���")
               return notify_fail("����һ����ס�㣬�����ȵ������޼������������˵���������\n"); 
           else
           {
              me->delete_temp("good_wjb1");
              return ::valid_leave(me, dir);
           }
        }
        return ::valid_leave(me, dir); 
} 

