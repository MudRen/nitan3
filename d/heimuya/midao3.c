// Room /d/heimuya/midao3.c
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
         "northup"   : "/d/heimuya/midao2",
         "southeast" : "/d/heimuya/midao4",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

