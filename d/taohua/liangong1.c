// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ����(discuss <����> <����> )���� 

inherit ROOM;

#include "discuss.h"
//#include <ansi.h>

void create()
{
	set("short", "������");
	set("long", @LONG
�����һ������ӵ������������Ӷ��벿ɢ���ż������ţ�������Ӵ�
�����ɣ�������Ϣ�������ڹ�֮�á����벿��������ŷ�����ʮ���Եķ�
λ���󣬴������ϰ���Ŷݼ����á��������һЩ���顣
LONG );
	 set("exits", ([
		"east" : __DIR__"changlang",
	]));

	 set("objects", ([
		__DIR__"obj/tiexiao" : 1,
                "/clone/weapon/zhuxiao" : 1,
		__DIR__"obj/yijing4" : 1,
                "/clone/misc/bagua"   : 1,
                "/clone/misc/xiang"   : 1,
                "/d/taohua/obj/zhuxiao" : 1,
                "/d/taohua/obj/taojian" : 1,
	]));

	set("no_fight", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_discuss", "discuss");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
}

