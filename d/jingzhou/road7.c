#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","С·");
        set("long", @LONG
һ����᫵Ļ���С·��·���Ӳݴ��������߿��Կ�������
�Ĺٵ�����ȥ���һ�������ݡ�
LONG);
        set("exits", ([
  		"east" : __DIR__"road6",
  		"west" : __DIR__"guandao1",
  	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        set("coor/x", -390);
	set("coor/y", -200);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

