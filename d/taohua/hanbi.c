// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "���̷�");
	set("long", @LONG
���̷�ʵ������һ��˶�������̫��ʯ�壬���������࣬��Ϊ�ر���
����̦������ͨ����̣��ʶ����������̡����ݴ�˵�����ǻ�ʯ��������
����Ʒ�����������������µ����Ʒ��ʨ�ӷ����й�֮���޲�����ԭַ��
�����ݣ����ҩʦ���˷���ԭ�����ݣ���ҩʦ�ŷ�ټ����������֮������
������ʹ���˲�����Ƨ������֮�С�
LONG );
        set("exits", ([
                "south" : __DIR__"songlin3",
                "northeast" : __DIR__"bibochi",
        ]));

        /*
        set("objects", ([
                "/d/taohua/npc/shagu" : 1,
        ]));
        */

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{

        if( (me->query("family/master_name") != "��Ӣ")
        && (me->query("family/master_name") != "��ҩʦ")
        && (!me->query_temp("shagu_pass"))
        && present("sha gu", this_object()) )
        return notify_fail("\nɵ��ɵЦ�˼������쿪˫��һ����˵����Ҫ��ȥ��������һ����ɣ������˶������ң������ˣ�\n");

        return ::valid_leave(me, dir);
}
*/
