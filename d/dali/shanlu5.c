//Room: /d/dali/shanlu5.c
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
	   "/d/dali/npc/wuliangdizi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/shanlu4",
	    "southeast"  : "/d/dali/shanlu6",
	]));
	setup();
	replace_program(ROOM);
}

