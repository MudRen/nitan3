// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ������ĸ��壬�����Ѵ��СС��ͣ���������Ҵ�������һ��
�󴬴�β���ʣ���������������ý�̻Իͣ������´���õģ���ȴԶ
Զͣ��һ�ԣ���֪��ʲô�á������м����ư�ˮ��æ��æȥ������Ը���㡣
LONG );

        set("outdoors", "taohua");

        set("exits", ([
                "east" : __DIR__"shucong",
		"north" : __DIR__"enter_m",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        setup();
        replace_program(ROOM);
}
