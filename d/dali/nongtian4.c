//Room: /d/dali/nongtian4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
        set("long", @LONG
һƬ�ٺ��ĵ�����������ˮ���﹡�ܸߣ��Ҹ�����Թ��߶��������
�����൱�����ˮ��������گ��ˮ���㣬�Ӻ��ڶ࣬��Ȼ��ɽ�ص��������Ҳ��
�����⡣��ȥ������Щ������ӡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/nongfu2": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southwest" : "/d/dali/yangzong",
	    "east"      : "/d/dali/dalangan1",
	]));
	setup();
	replace_program(ROOM);
}

