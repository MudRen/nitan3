// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�Һ������������ʮ�ߡ��˸��ˡ�������˶��ˮ�����ڴ�ͷ��βæ
��æȥ��
LONG );

	set("valid_startroom", 1);
	set("outdoors", "taohua");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



