//Room: /d/dali/hongsheng4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ʥ����");
        set("long", @LONG
�����Ǻ�ʥ�����ڲ�������ǽ���϶����з��裬�����÷�������������ģ
ӡש�������������󣬺��Ŀ��������ĵġ����ڷ��������䡻��
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "down"     : "/d/dali/hongsheng3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

