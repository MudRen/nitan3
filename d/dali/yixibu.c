//Room: /d/dali/yixibu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ϫ��");
        set("long", @LONG
��Ϫ��Ҳ���������������Ĳ��䡣���ﴦ���µأ������в���ũ���ũҵ
�����Ҫ�����ָ���������񾭳�Ǩ�㣬��������˼�������⣬�������ݶ�
�ܼ�ª��
LONG );
	set("objects", ([
	   "/d/dali/npc/shaonu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : "/d/dali/atoubu",
	    "south"      : "/d/dali/wuyiminju4",
	    "east"       : "/d/dali/biluoshan",
	]));
	setup();
	replace_program(ROOM);
}

