inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",RED"��������"NOR);
        set("long", @LONG
������Ǿ��ǵ�����������������Ĵ��š����ﾯ�����ϣ���ʱ�д����Ʒ�
�������ٱ���������������������ȥ�����������������������̫�ࡣ��������
�������ٱ��������ƻ��Ķ����㿴������㲻�������Ļ�����û��ǸϿ��뿪��
�á�[2;37;0m
LONG );
	set("exits", ([
		"south" : "/d/beijing/xichang",
		"north" : "/d/beijing/di_2",
	]));
	set("objects", ([
		"/d/beijing/npc/bing3" : 2,
		"/d/beijing/npc/taijian" : 1,
	]));
	set("no_fight", 0);
	set("coor/x", -40);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("guan bing", environment(me))) && dir == "south")
		return notify_fail("�����ٱ����ֽ�����ס��\n\n");
	return ::valid_leave(me, dir);
}