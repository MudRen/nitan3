// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ȫ������ɫ���񹹳ɣ�����������֦��ɵ���ͤ��ͤ�Ϻ��д��
������ͤ�����֡�ͤ��������ȫ�Ƕ���֮��õ����ˣ��ֳ������ƹ⡣
��֮ͤ�ಢ���������ô�����֦����̣�ֻ������������Ĺ����������
�������ޱȡ�
LONG );
        set("exits", ([
                "east"  : __DIR__"zhulin3",
                "south" : __DIR__"zhulin",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
