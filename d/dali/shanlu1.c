//Room: /d/dali/shanlu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ·");
        set("long", @LONG
�����ڴ���ɽ���һ����·�ϡ��˼�����������ڣ��������ߣ���ɽ�����
��ƽ��������ɼ���ѩ��������ظ�ԭȺɽ������һ·��Խɽ��ֱͨ�����ϴ���
����ɽ����Щ�����˵Ĵ��䡣
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : "/d/dali/wunong",
	    "south"      : "/d/dali/jianchuankou",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

