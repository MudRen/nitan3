//Room: /d/dali/baiyiminju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
        set("long", @LONG
�����Ǵ����һ���壬���ɢ���ڲ�ɽ���������������������ʯ���ݳɣ�
��ַ�񡣳��������죬�Ҽһ����������Ի�ľ�����ſڣ��ڴ��һ�����ġ���
ɽ����������Ұ���������ۻ��֡�
LONG );
	set("objects", ([
	   "/d/dali/npc/oldman": 1,
	   "/d/dali/npc/girl1": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/dahejieeast",
	]));
     set("no_fight",0);
	setup();
	replace_program(ROOM);
}

