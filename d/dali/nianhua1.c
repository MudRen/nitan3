//Room: /d/dali/nianhua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�黨�º�Ժ");
        set("long", @LONG
��ٲ����£�ֻ���ö����������࣬���ƴӺ�Ժ��������ʱ֮�䣬ֻ�б���
�������⾲���С���̤ʵ����Ժ����Ҷ���߽���Ժ����վ��ͥ�У��ۼ�ͥ��һ��
��������һƬ��Ҷ�������䣬����ȫ����
LONG );
	set("objects", ([
//	   "/d/dali/npc/huangmei": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "out"  : "/d/dali/nianhuasi",
	]));
	setup();
	replace_program(ROOM);
}

