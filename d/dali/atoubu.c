//Room: /d/dali/atoubu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ͷ��");
        set("long", @LONG
��ͷ�����������Ĳ��䣬�͸���������һ����Ҳ�������ġ�����ɽ�����ܣ�
����������ʽ�ɽ����������·ɥ������ɽ������������˵ȴ�Ǿ۱��裬ɽ��Ұ
�������ζ��
LONG );
	set("objects", ([
	   "/d/dali/npc/lieren": 1,
       "/clone/npc/walker.c":1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/lushui",
	    "westup"     : "/d/dali/gaolishan1",
	    "southeast"  : "/d/dali/yixibu",
	]));
	setup();
	replace_program(ROOM);
}

