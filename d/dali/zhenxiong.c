//Room: /d/dali/zhenxiong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�������������ľ۾����ģ�������������Ĵ󲿣������ģ����а͵ĵ顢��
�ۡ��͸���������������һ��ʯ��С�ǣ��˿ڲ��࣬����ɢ�������Ӹ���������
����Ҫ��һЩ���̺ͼ�������
LONG );
	set("objects", ([
	   "/d/dali/npc/muyangnu": 1,
	   "/d/dali/npc/wshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : "/d/dali/badidian",
	    "north"      : "/d/dali/gelucheng",
	    "northeast"  : "/d/dali/minadian",
	    "east"       : "/d/dali/titian1",
	    "west"       : "/d/dali/wuyiminju3",
	]));
	setup();
	replace_program(ROOM);
}

