#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ı����");
        set("long", @LONG
���������ı���ֵľ�ͷ����ʯ��������൱�������ֵ��ϵ���������������
��������Ϣ�����߽ӵ�����֣�ת����ͨ�����ı���ֽӾ��ǵ���������֡�
LONG );
       set("exits", ([
		"east" : "/d/beijing/di_4",
		"south" : "/d/beijing/shi_2",
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
