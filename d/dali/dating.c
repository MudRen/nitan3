//Room: /d/dali/dating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�������廪¥��ǰ�������쳣������������һ�������ȫ����ʯ�̵أ���
����䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ���������������ʳ�������ߡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/shizhe": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"   : "/d/dali/louti",
	    "out"     : "/d/dali/gudao",
	]));
	setup();
	replace_program(ROOM);
}

