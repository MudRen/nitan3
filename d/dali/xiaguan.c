//Room: /d/dali/xiaguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�¹س�");
        set("long", @LONG
�¹سǣ�������β�ǣ�Ϊ���޷��������ƴ��Ѽ����١������ӱ���ɽ��´��
���ˮ�Ƴ��϶������˵ķ羰�续����ȥ�ϱ߲�Զ���Ǵ���ǣ�������̫�ͳǣ�
���е�·ͨ���������˸������������ġ�̨��Ϊ����Ҳ���������ġ�
LONG );
	set("objects", ([
	   "/d/dali/npc/tshangfan": 1,
	   "/d/dali/npc/wshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/cangshan",
	    "northwest"  : "/d/dali/cangshanzhong",
	    "south"      : "/d/dali/ershuiqiao",
	]));
	setup();
	replace_program(ROOM);
}

