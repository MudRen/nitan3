//Room: /d/dali/shizilukou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʮ��·��");
        set("long", @LONG
���Ǵ�����ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ��ߴ���˷������಻
����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ���������Ը���������¥�ƣ�
���������־���פ�أ�����������ӡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/center",
	    "south"  : "/d/dali/southgate",
	    "east"   : "/d/dali/dahejieeast",
	    "west"   : "/d/dali/dahejiewest",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

