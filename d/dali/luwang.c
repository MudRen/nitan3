//Room: /d/dali/luwang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","³����");
        set("long", @LONG
���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�����һ����
��ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ�����������������ɼ���ׯ�ͳ���
LONG );
	set("objects", ([
	   "/d/dali/npc/tshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : "/d/dali/feilihu",
	    "east"    : "/d/dali/yulin",
	    "south"   : "/d/dali/shuitian",
	    "north"   : "/d/dali/zhulou3",
	]));
	setup();
	replace_program(ROOM);
}

