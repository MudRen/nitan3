// room: liang.c

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","�����");
        set("long", @LONG
����ڽ�����ϣ��ܼ���յ����ӽ�����ߣ�������ĬĬ΢Ц��
LONG );
        set("exits", ([
                "down" : "/d/xueshan/hongdian",
        ]));       
        set("objects", ([
                "/d/xueshan/obj/klguan" : 2,
                "/d/xueshan/obj/rtlian" : 2,
                "/d/xueshan/obj/lubo" : 2,
        ]));
        set("cost", 1);
        setup();
}



