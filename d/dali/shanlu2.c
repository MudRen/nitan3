//Room: /d/dali/shanlu2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
        set("long", @LONG
һ��ɽ·���������ï�ܵ����ֺ����಻���Ĵ�ɽ����·���Լ��ɼ�һЩ
����Ĵ�������һƬ��ɽ�������ƣ�ɽ�߰�ѩ�������겻������·������ɽ��
һ����·���ϱ������š�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : "/d/dali/shanlu3",
	    "south"     : "/d/dali/shanlu4",
	    "northup"   : "/d/dali/nianhuasi",
	    "westup"    : "/d/dali/biluoxueshan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

