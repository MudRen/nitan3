#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����᫵Ļ���С·��·���Ӳݴ���������ֻ����
���������������ٵ�����������һ����ɽ��ɽ����ľï�ܡ�
LONG);
        set("exits", ([
  		"east" : __DIR__"road5",
  		"west" : __DIR__"road7",
	]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");
        set("coor/x", -380);
	set("coor/y", -200);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

