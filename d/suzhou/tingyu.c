// Room: /d/suzhou/tingyu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����������ݳ��ڵ�һ��Ψһ��һ������ˡ��������Ÿ��ָ������鼮��ʲ
ôС˵��������������������������������书�����ȵȵȵȡ�ֻ�뻨��������
�Ϳ�������Ҫ���顣
LONG );
//	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : "/d/suzhou/nandajie2",
	]));
	set("coor/x", 210);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

