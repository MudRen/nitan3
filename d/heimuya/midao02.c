// Room /d/heimuya/midao02.c
// By haiyan

#include <room.h>
inherit ROOM;

void create()
{
     set("short", "�ص�");
        set("long", @LONG
����������̼������ܵ�ͨ������������书��Ϊ�����칦��Ϊ�����˴��ţ�
�ʽ��е��Ӷ��ڴ˵�������
LONG );
     set("exits", ([
         "west"    : "/d/heimuya/midao01",
         "east"    : "/d/heimuya/lwchang1",
         "south"   : "/d/heimuya/lwchang2",
         "north"   : "/d/heimuya/lwchang3",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

