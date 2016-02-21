//                ��׼��������ʾ��                                   |
// ��ĳ��Ϸ��д�ɣ������ƺ�Ӧ����ԭ������Ϊ��С����ʱ���� ����
// ԭ���ܾ���ȷΪ������Ϸ֮�䷶����һ����Ҫ��װ�ģ��м���ͼ������Ϸ��


// ����Ϸ�� hanghai_master.c (��γ��) ֧����Ҫָ�
// by naihe  2003-06-19  ��ï��

#include <ansi.h>

inherit ROOM;

#define MST		__DIR__"hanghai_master"		// ��γ�ǣ���Ϸָ����֧��


void create()
{
	set("short", HIC"��С����ʱ���� ��Ϸ��"NOR);
	set("long", "
***********************************************
              ��С����ʱ����

    ��ӭ���� С����ʱ�� ��Ϸ��������һ������
С��Ϸ��������Ϸ�����Ȥ��ͬʱ���ཫ�ܹ��õ�
һ��������MUD���������ʹ�����

    ������Ϸ��         game start
    �κ�ʱ���˳���Ϸ�� game over

    BY �κ�(naihe)    --2003.06.19
***********************************************
\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("valid_startroom", 1); // �������ֱ�Ϊ�������߷��� �� ��ʼ����
	set( "cost", 0 );

	set("exits", ([
            "out":  "/d/city/advice/advice",
	]));

	setup();
}

void init()
{
	add_action("do_game", "game");
}

int do_game(string arg)
{
	object me = this_player(), mst_obj;

	if( !arg || arg != "start" )
		return 0;

// "game over" �Ȳ������� MST ������С�


	if( me->query_temp("hanghai_gameing") )
                return notify_fail("����������Ϸ�У�\n");

	if( file_size( MST + ".c" ) < 1 )
                return notify_fail("����Ϸ��ͣ���ţ�\n");

	write("\n========= ���Ժ�����ִ�в������� ==========\n\n");

	mst_obj = new( MST );

	mst_obj->new_game(me);
	mst_obj->move(me);

	return 1;
}



int valid_leave(object me, string dir)
{
	if( me->query_temp("hanghai_gameing") )
		return notify_fail("��������Ϸ�У������뿪��\n");

	return ::valid_leave(me, dir);
}
