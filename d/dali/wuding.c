//Room: /d/dali/wuding.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�䶨��");
        set("long", @LONG
������̨�ķ�֧¬¹�����������θ����������������䶨���⻹ϽԪı��»
�����򡣴��򲻴�����ɽ����������Եø������ġ�¬¹���˵���¥��ɢ��
���������С�
LONG );
	set("objects", ([
	   "/d/dali/npc/guniang": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/zhulou1",
	    "northeast"  : "/d/dali/zhulin",
	    "west"       : "/d/dali/qingzhulin",
	    "south"      : "/d/dali/nongtian1",
	]));
	setup();
	replace_program(ROOM);
}

