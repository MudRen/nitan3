//Room: /d/dali/shanlu3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
        set("long", @LONG
һ����ɽ·���Ѵ�����ï�ܵ�ɭ���У��򶫲�Զ�ɴ�����������--����ǣ�
��ȥ�������ɽ�����ڽӽ��������ģ�����·�������൱ƽ��������ɽ����᫣�
��·�������ѡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : "/d/dali/shanlu2",
	    "east"    : "/d/dali/northgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

