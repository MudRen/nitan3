#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�����ڳ������ϵ�һ��С·�ϣ��������ߣ��ͽ���������
���Ĵ�ɽ���ˣ����Ϸ�������С·����֪��ͨ�����
LONG);
        set("exits", ([
  		"east" :  __DIR__"shudao3",
  		"west" : __DIR__"shudao5",
   	]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        set("coor/x", -180);
	set("coor/y", -180);
	set("coor/z", -60);
	setup();
        replace_program(ROOM);
}

