#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "�׵۳�" NOR );
        set("long", @LONG
���ǰ׵۲��Ƽ䣬ǧ�ｭ��һ�ջ�������Գ���䲻ס��ǧ
���Թ�����ɽ��������������İ׵۳��ˣ�ң�����ܣ�ֻ����
ɽ��ˮ��һƬ��÷羰����������������������һ����ʿ�ĵ�
��ƾ�����ţ��ĳ���ӿ������������
LONG);
        set("exits", ([
  		"west" : __DIR__"shudao10",
		"east" : __DIR__"shudao9",
  
        ]));
        set("objects", ([
                "/d/beijing/npc/shiren" : 1,
                "/d/beijing/npc/shusheng1" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        set("coor/x", -240);
	set("coor/y", -180);
	set("coor/z", -40);
	setup();
        replace_program(ROOM);
}

