//Room: /d/dali/tingyuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ͥԺ");
        set("long", @LONG
����������������ͥԺ���м�һ��Сˮ̶������������಻֪���Ļ�����ֻ
ϲȵ�ڻ����б�����ȥ�����Ա���ƬС���֣���Ӱ�·���ʯ��ʯ�ʣ�����������
�����塣
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/shijing",
	    "east"  : "/d/dali/chahua1",
	    "north" : "/d/dali/changlang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
