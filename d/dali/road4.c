//Room: /d/dali/road4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��·");
        set("long", @LONG
һ����ͨ�ϱ��Ĵ�·�����ɴ�������ϱ߽����Ĺٵ�����·���ϴ�������ï
�ܣ���Ƭ���ָ���ɽ�룬�˼���ƽ�ƽ̹����·��ֱ�������ű��ߵĴ���Ǻ���
�ߵ�ϲ�ݵȳ���
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/shuangheqiao",
	    "south"      : "/d/dali/tianweijing",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

