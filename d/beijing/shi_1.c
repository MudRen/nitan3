#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���ı����");
        set("long", @LONG
�����Ǿ��ǵ������ϴ�֣���ʯ������·��ͨ�ϱ���������ש������ͬҲ��
��������ϡ��ֵ��ϵ����������������Ϸ��Ӿ��ǵ���������֣����������ı�
��֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/shi_2",
		"south" : "/d/beijing/bei_3",
                "west" : "/d/beijing/minju",
	]));
	set("objects", ([
		"/d/beijing/npc/liumang" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
