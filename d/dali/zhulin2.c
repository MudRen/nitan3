//Room: /d/dali/zhulin2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
        set("long", @LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣������ڶࡣ�о���
��̨�������������������ס����£���׽�á�¹��С�ޣ��������������ɽ��
׽��Щ�����ޡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/lieshou": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/hexi",
	]));
	setup();
	replace_program(ROOM);
}

