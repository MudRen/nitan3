// Room /d/heimuya/midao6.c
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
         "northdown" : "/d/heimuya/midao5",
         "southeast" : "/d/heimuya/midao7",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

