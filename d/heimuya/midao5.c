// Room /d/heimuya/midao5.c
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
         "north"     : "/d/heimuya/midao4",
         "southup"   : "/d/heimuya/midao6",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

