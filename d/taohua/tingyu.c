// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�����ѽӽ��̲��ص����ģ�һ��������ʨ�Ĵ�ʯ����ˮ�ϣ���������
����׭--�����㡱�������Ϊ��������ʹ�ã�ʯ���Ѿ�ʮ�ֹ⻬�����а�
��ʢ�ţ�����������Ҷ�������ʯ������������һ��΢�����������
��Ҷٿٿ���죬��β��ɫ����Ϸ�ںɼ䡣�����������һ����������ͤ(t
ing)�������ƺ���·ͨ���ͤ��
LONG );

        set("item_desc", ([
                "ting" : "ͤ��һ�ң���ϡ���Կ������С��Խ�ͤ�����֡�\n"
		         "�㿴�����벻��̫Զ��Ӧ�ÿ������Ṧ����(fly)��ȥ��\n",
        ]));
        /*        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));
        */
	set("exits", ([
                "west"  : __DIR__"bibochi",
                "south" : __DIR__"zhulin3",
        ]));

	set("outdoors", "taohua");

	setup();

}

void init()
{
        add_action("do_jump", "fly");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "ting" )
                return notify_fail( "ʲô��\n");

        message_vision("$N�������Խ�ͤ��ȥ��\n", me);
        if ( me->query_skill("dodge",1) <= 50 ) {
                message_vision("$Nһ�������񣬡����̡�һ������ˮ�����һ�����ࡣ\n", me);
                message_vision("$N�������ƵĴӳ������������������Ĩ��Ĩ�졣\n", me);
        }

        if ( me->query_skill("dodge",1) > 50 ) {
                me->move(__DIR__"shijian");
                message("vision", me->name() + "����������ʯ���˹�����\n",environment(me), ({me}) );
        }

        return 1;
}
