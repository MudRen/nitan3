// Room /d/heimuya/midao1.c
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
         "out"       : "/d/heimuya/house1",
         "southdown" : "/d/heimuya/midao2",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

