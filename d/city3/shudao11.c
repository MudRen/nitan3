#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������������µ�����ϣ�����������Խ����ɽ����
���Խ����Ĵ�����ˣ�������ȥ�羰��������Ͽ����·ʮ����
᫣�ʱ����תʱ����ɽ��ʱ����Ҫ����ɭ�֡�
LONG);
        set("exits", ([
                "east" : __DIR__"sanxia3",
  		"west" : __DIR__"shudao12",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        set("coor/x", -290);
	set("coor/y", -180);
	set("coor/z", -40);
	setup();
        replace_program(ROOM);
}

