#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
������Ǿ��ǵĳ������ˣ���ǽ�Ͽ��š������š��������֡���������ͨ��
������������������֡����������������ǽ������ǵ�Ҫ������������վ���˹�
�����̲�ʮ�����ܡ�һ�������Ĵ�����Ŷ����������죬��������ǵ��ﾩ�ǵ�
������
LONG );
       set("exits", ([
              "east" : "/d/beijing/road1",
		"west" : "/d/beijing/chaoyang_dao2",
	]));

	set("objects", ([
		"/d/beijing/npc/ducha" : 1,
		"/d/beijing/npc/bing1" : 2,
	]));

	set("outdoors", "beijing");
	set("coor/x", 30);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}