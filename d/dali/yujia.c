//Room: /d/dali/yujia.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
        set("long", @LONG
���Բ�ר�����ԣ�����������������������һ����ͨ����¥���²�ͨ����
����Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵ�"��֯������¥����һ��
ľ�ܣ����������ŵ��㣬������ɹ��ɡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/funu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : "/d/dali/hexi",
	]));
	setup();
	replace_program(ROOM);
}

