//Room: /d/dali/taiheju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�;�");
        set("long", @LONG
���Ǵ���������ľ�¥��¥����Щ�����С�ԣ��������˳���������·�ˡ�
¥����������
LONG );
	set("objects", ([
	   "/d/dali/npc/xiaoer2": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/center",
	    "up"    : "/d/dali/taiheju2",
	]));
	setup();
}

