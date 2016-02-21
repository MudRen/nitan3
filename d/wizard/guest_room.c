#include <ansi.h>
#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIY "��ʦ�����" NOR);
	set("long", @LONG
��������ʦ����ҽ����ĵط����������ʲô������Ҫ����ʦ��
�̣���������������(post)�������������ǣ�浽���ջ����Ѿ��ڰ�
���ļ�������ϸ˵������ʦ�ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�
һ����ҵ��������ϲ�ȥ��
LONG );

	set("exits", ([
		"up"        : __DIR__"wizard_room",
		"north"     : __DIR__"noname_room",
		"south"     : __DIR__"develop_room",
		"southeast" : "/d/city/wumiao",
        ]));

	set("no_fight", 1);
	create_door("southeast", "����", "northwest", DOOR_CLOSED);
	setup();
        "/clone/board/towiz_b"->foo();
}


int valid_leave(object me, string dir)
{
        if (dir == "up" && (! userp(me) || ! wizardp(me)))
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
