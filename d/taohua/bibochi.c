// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "�̲���");
	set("long", @LONG
�ƹ���ͬʯ����һ��ĺ��̷壬��һ����Ө��͸�������ĳ�ˮ����
�������ۻ�Ȫ��һΪ��Ȫ��һΪ��Ȫ�����Գ�ˮ��ů�������ļ����ԣ���
ˮ���ؼѣ������������κ���Ȫ������������Ǻ������֣�������ɫ
���������ܻ������д��������Ѵ�������ꡣ����˵�����пɿ˰ٶ��ġ�
�����ޡ����֡���������ԼԼ��һ�����ᣬ���濿�������Ĵ���һ������
��ʯ��
LONG );
	 set("exits", ([
                "southwest" : __DIR__"hanbi",
                "east"      : __DIR__"tingyu",
                "north"     : __DIR__"jingshe",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
