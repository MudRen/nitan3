// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

int do_tanzhi();
void create()
{
	set("short", "��ָ��");
	set("long", @LONG
�����������һ�������ߵ㣬�Ӹ����£�ȫ�����۾����۵ס��ϱ���
����������һЩ��ͺͺ����ʯ�����汱�涼�ǻ�������ɫ�ͷף�������ͷ��
ֻ������ͷ���ۻ����嶥��һ��ʯ���������������֡���ָ�塱��������
һ��ʯ��������֮��������׭����Ȼ��ĥ���٣�������ϡ�ɱ档ϸ��֮
��ԭ���ǡ������������֡�
LONG );
	 set("exits", ([
                "enter" : __DIR__"qingyin",
                "southdown" : __DIR__"shanlu2",
        ]));
        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

