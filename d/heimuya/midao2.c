// Room /d/heimuya/midao2.c
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
         "northup"   : "/d/heimuya/midao1",
         "southdown" : "/d/heimuya/midao3",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

