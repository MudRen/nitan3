//Room: /d/dali/shijing.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʯ��");
        set("long", @LONG
�����ڴ������������е�ʯ���ϡ�·�߳�ľ���죬΢��ϰϰ��ʮ����ˬ��·
����һ������͸����С����ˮ�����㣬ӳӰ��䡣����ͨ���������������Ǹ�
��԰��
LONG );
	set("objects", ([
	   "/d/dali/npc/xianhe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : "/d/dali/tingyuan",
	    "west"  : "/d/dali/wfdating",
	]));
	setup();
	replace_program(ROOM);
}

