// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "�ɰ���");
	set("long", @LONG
�����ɰ���ÿ����ľ֮��������£�֦��������ӳ��̧ͷ��ȥ������
��Ҷ�������أ����Ʊ��գ�������ȴ���߳��㣬�˺����֡��治֪����Ȼ
���ͣ���������ż�á�����һ��С���������У�ָ�򱱷����������ƺ���
һ�����֡�
LONG );
	 set("exits", ([
                "north" : __DIR__"hanbi",
                "south" : __DIR__"songlin2",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
