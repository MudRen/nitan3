//Room: /d/dali/buxiongbu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���۲�");
        set("long", @LONG
����������·���ǰ��ĵ�һ֧--Щôͽ���۾ӵĵط����˵ؽ�ƫԶ������Ҳ
��������һƬ����������ƺ�������ɽ��ˮ�㣬ɣ���ܲ�������һƬСƽԭ��
��Щũ��˼�ɣ���࣬��˿������񸾶��÷�˿֯�顣
LONG );
	set("objects", ([
	   "/d/dali/npc/bshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : "/d/dali/banshan",
	    "east"   : "/d/dali/yangcanfang",
	    "south"  : "/d/dali/xingyunhu",
	    "north"  : "/d/dali/nongtian5",
	]));
	setup();
	replace_program(ROOM);
}

