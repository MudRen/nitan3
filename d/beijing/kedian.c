#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�ҹ�ģ��С�Ŀ͵꣬����İ���Ҳ�൱�ĳ¾ɺͼ�ª���͵���ϰ���
һ����ͷ����Ϊ���С��ĳɱ�С����ͷҲ��û�������˰�æ���͵������һ��
���������ڴ����͵�Ĺ�̨�Ϲ���һ������(paizi)��
LONG );
       set("exits", ([
		"east" : "/d/beijing/caroad_w1",
	]));
	set("item_desc", ([
		"paizi" : "����������бб��д�������֣�\n\n"
                        "                       ������\n\n",
	]));
	set("objects", ([
		"/d/beijing/npc/chenlaotou" : 1,
		"/d/beijing/npc/youren" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -70);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();

	replace_program(ROOM);
}
