//Room: /d/dali/dianchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
        set("long", @LONG
������ܵ�ɽ����������ɽϵ������ɽ���Ķ�֧�������£��ܳ�����ɽ����
��С��ʮ��ɽ�塣���������ɽ���£�ɽ��ˮ���������Ӱ��������Ȼ��ͼ����
��صġ��᡻�������м��Ǵ���ӣ���˾��Ǩ�ġ�ʷ�ǡ��������д������أ���
�Ŵ�������һ���������Ĳ������ƣ�������ء�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : "/d/dali/dasenlin",
	    "south"   : "/d/dali/yanchi1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

