//Room: /d/dali/chahua2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
        set("long", @LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨԰�У�����
��ǧ�죬���涷�������ش�ˬ������һ��Сʯ�ʣ��ʺ��������У���ҷˮ�棬��
������һ����������
LONG );
	set("objects", ([
	   "/d/dali/obj/chahua1": 1,
	   "/d/dali/npc/huanu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/chahua1",
	    "northeast"  : "/d/dali/chahua3",
	    "southeast"  : "/d/dali/chahua4",
	]));
	setup();
	replace_program(ROOM);
}

