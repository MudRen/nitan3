//Room: /d/dali/milin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�˴�ɽ����խ����ľ�ر�ï�ܣ�ɽ��̤������С�����ݺύ�����ľ�ڵ���
���ţ���·�߲�ͣ���õ�������·������˳��ǰ����������ɽ������������ʱ��
�����޾��ߣ�ż�����ܿ��������Ŀ�ȸ�ɹ���
LONG );
	set("objects", ([
	   "/clone/beast/qingshe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/yangzong",
	    "southup"    : "/d/dali/shanjian",
	]));
	setup();
	replace_program(ROOM);
}

