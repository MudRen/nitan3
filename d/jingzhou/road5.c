#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ɽ����ľï�ܣ�������䣬���ϸ������������ɽϪ��ˮ
���������紵��ҳ����������ͬһ�״���Ȼ���������������
LONG);
        set("exits", ([
  		"northeast" : __DIR__"qingshan1",
  		"west" : __DIR__"road6",
	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");
        set("coor/x", -370);
	set("coor/y", -200);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

