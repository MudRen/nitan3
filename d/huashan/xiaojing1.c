// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "��ɽС��");
	set("long", @LONG
���ǻ�ɽ��ɽ��һ��С�����˼�����������Ұ�������������飬Ҫ��
�����˴��죬˭Ҳ�벻�����ﾹȻ����С����
LONG );

	set("outdoors", "huashan");

        set("exits", ([ /* sizeof() == 1 */
  	        "north":__DIR__"taogu",
        ]));

        setup();
        replace_program(ROOM);
}
 
