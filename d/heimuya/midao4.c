// Room /d/heimuya/midao4.c
// By haiyan

#include <room.h>
inherit ROOM;

void create()
{
     set("short", "�ص�");
        set("long", @LONG
����������̼������ܵ�ͨ�����Ǻ�ľ������ԭ����ȡ����ϵ�Ľݾ���
LONG );
     set("exits", ([
         "northwest" : "/d/heimuya/midao3",
         "south"     : "/d/heimuya/midao5",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

