//Room: /d/dali/shanlu4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
        set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·���Լ��ɼ�
һЩ����Ĵ���ɽ·���������š�
LONG );
	set("objects", ([
	   "/d/dali/npc/shennongdizi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/shanlu2",
	    "southwest"  : "/d/dali/shanlu5",
	]));
	setup();
	replace_program(ROOM);
}

