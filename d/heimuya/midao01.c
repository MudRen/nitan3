// Room /d/heimuya/midao01.c
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
         "out"    : "/d/heimuya/house1",
         "east"   : "/d/heimuya/midao02",
     ]));
     set("no_clean_up", 0);
     setup();
     replace_program(ROOM);
}

