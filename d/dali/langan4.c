//Room: /d/dali/langan4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����в�");
        set("long", @LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ��Լ�������
�е��������Ҽһ������������谸����в�����෿����Ϊ���������ݿ�����
��һ����ɴ����
LONG );
	set("objects", ([
	   "/d/dali/npc/fangshanu": 1,
	   "/d/dali/obj/fangshaji": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"      : "/d/dali/langan3",
	]));
	setup();
	replace_program(ROOM);
}

