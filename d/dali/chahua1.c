//Room: /d/dali/chahua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰��");
        set("long", @LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨԰�ڣ�����
��԰��ɫ��������ϲ���������߾ͽ�԰�ˣ�������һ���ⷿ���ϱ���һ���᷿��
��������Ϣ�ĵط���
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/bingqiku",
	    "south"  : "/d/dali/xiuxishi",
	    "east"   : "/d/dali/chahua2",
	    "west"   : "/d/dali/tingyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

