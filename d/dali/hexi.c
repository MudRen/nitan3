//Room: /d/dali/hexi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
���������������ϣ�ס���ǰ�޼�������Բ�����޼����̨�ģ�������˸���
�غ�������⣬��Ҫ�Բ���Ϊ�����ٺ����������������߲�Զ�����洬�����
С��ͷ���ϱ�ɽ���в���Ұ�ޣ����Բ������Ӿ���ǰȥ���ԡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/tshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/feilihueast",
	    "west"       : "/d/dali/yujia",
	    "north"      : "/d/dali/feilihusouth",
	    "south"      : "/d/dali/zhulin2",
	]));
	setup();
	replace_program(ROOM);
}

