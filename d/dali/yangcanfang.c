//Room: /d/dali/yangcanfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���Ϸ�");
        set("long", @LONG
����һ�������ĸ�����ӣ��˼��²�ȴû��ţ����������ϯΧס����һ
�����ݣ���������������̣�������һЩɣ�ϡ�һλ���Ĺ������������ʵ�ɣҶ
ι��ɣ�ϡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/yangcannu": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/buxiongbu",
	]));
	setup();
	replace_program(ROOM);
}

