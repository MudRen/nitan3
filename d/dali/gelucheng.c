//Room: /d/dali/gelucheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��³��");
        set("long", @LONG
�˳����������������θ����������³�����ݡ��²�������Ĵ󡣸�����ɽ
�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���ţ�򡣴�ȥ��������
����ɽ������ƽԭ�����д���
LONG );
	set("objects", ([
	   "/d/dali/npc/shanyang": 2,
	   "/d/dali/npc/muyangren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : "/d/dali/shanlin",
	    "south"      : "/d/dali/zhenxiong",
	    "east"       : "/d/dali/minadian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

