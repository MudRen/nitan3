//Room: /d/dali/tusifu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��˾��");
        set("long", @LONG
��˾���ǵ��ش�����Ϯ��˾���ϵ����ţ�һ�����ϵ�שľ�������ͥ�Ӹ�
���£�ׯ�ϼ�ʵ����ǰ�ǿ���ʯ�ף��е����������ƣ����ݹ���̨��ռ��Լ��
��Ķ���������������������������᷿��
LONG );
	set("objects", ([
	   "/d/dali/npc/datusi": 1,
	   "/d/dali/npc/shicong": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : "/d/dali/tusimentang",
	    "south"  : "/d/dali/dahejiewest",
	]));
	setup();
	replace_program(ROOM);
}

