// Room: /d/mingjiao/mishi.c
// Date: Java 97/04/9

inherit ROOM;

#include <room.h>

void create()
{
	set("short", "ʯ��");
        set("long", @LONG
���ʯ�Ҽ��󣬶��ϴ������飬������Ȼ��ʯ�������˼�����ͻ�����µ���
�������á����������·���δ�þ����ŵó���һ��һŮ���߽��������ã�ֻ����
Ů������ץ��һ������������ذ�ף��������Լ��ؿڡ�
LONG );
	set("exits", ([
		"south" : __DIR__"midao0",
		"up"    : __DIR__"neishi",
	]));
	set("objects", ([
		__DIR__"obj/yangdt" : 1,
		__DIR__"obj/yangfr" : 1,
	]));
	set("no_clean_up", 0);
	set("xin_count", 1);
	setup();
        create_door("south", "ʯ��", "north", !DOOR_CLOSED);
}

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	object me;

	me = this_player();		
	message_vision("$N�ϵع����������������Ź�ǰ���������ؿ��˸�ͷ��\n", me);
	if (query("xin_count") > 0 )
	{
		add("xin_count", -1);
		new(__DIR__"obj/yixin")->move(this_object());
                new("/clone/book/qiankun_book")->move(this_object());
		tell_object(me, "ͻȻ��̧�ۿ����Ź����棬��һЩ��������"
                            "���˿���ԭ����һ���ź�һ����Ƥ��\n");
	}
	return 1;
}
void reset()
{
        ::reset();
        set("xin_count",1);
}
