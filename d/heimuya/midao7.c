// Room /d/heimuya/midao7.c
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
         "northwest" : "/d/heimuya/midao6",
         "out"       : "/d/city/yaopu",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

