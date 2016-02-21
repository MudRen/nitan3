// Room : /d/city/kedian.c

#include <ansi.h>
#include <room.h>

inherit CREATE_CHAT_ROOM;

void create()
{
	set("short", "�����ջ");
	set("long", @LONG       
����������ոտ�ҵ�ľ����ջ���ϰ�����ǳ���¡������ۼ��Ŵ�
���Ľ������ˣ�����ÿ�춼�гɰ���ǧ�ĸ��ָ������˸������������
��Ŀ�Ķ���һ��������Ϊ����ձ����ֵľ���ɽׯ���������ﱾ����ң��
���̵ĵط������ھ���ɽׯ�ı����֣�����ܿ���γ���һ�����У����
��ջҲ������������¿�ҵ�ġ��������������������صķ������顣��
С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ��������˽�������С
����æӭ��ǰȥ����ջ�����ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
	);

	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
                "west" : __DIR__"shanlu",
                "north" : __DIR__"majiu",
		"up" : __DIR__"kedian2",
	]));

	setup();
	"/clone/board/kedian_b"->foo();
}

void init()
{ 
        object me = this_player();
        add_all_action(); 
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
