inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",RED"��������"NOR);
        set("long", @LONG
������Ǿ��ǵ�����������������Ĵ��š����ﾯ�����ϣ���ʱ�д����Ʒ�
�Ķ����ٱ���������������������ȥ�����������������������̫�ࡣ��������
�Ķ����ٱ��������ƻ��Ķ����㿴������㲻�������Ļ�����û��ǸϿ��뿪��
�á�[2;37;0m
LONG );
	set("exits", ([
		"south" : "/d/beijing/dongchang",
		"north" : "/d/beijing/dong_1",
	]));
	set("objects", ([
		"/d/beijing/npc/bing2" : 2,
		"/d/beijing/npc/taijian" : 1,
	]));
	set("no_fight", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("guan bing", environment(me))) && dir == "south")
		return notify_fail("�����ٱ����ֽ�����ס��\n\n");
	return ::valid_leave(me, dir);
}
