//Room: /d/dali/xizhou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ϲ�ݳ�");
        set("long", @LONG
ϲ���������ǣ��Ǵ����ϲ���ǣ����ƴ��Ѽ����٣��ؾ��˻����ڣ���ó
�����٣��д��������������˽��ף��ɹ�������Ľ�����˿֯Ʒ��������Ƥë�ȣ�
������������ӡ�ȵĿ�����࣬ǰ����˿������˹������Զ��������
LONG );
	set("objects", ([
	   "/d/dali/npc/keshang": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/tianweijing",
	    "east"       : "/d/dali/kedian",
	    "southwest"  : "/d/dali/zhulin",
	    "south"      : "/d/dali/feilihu",
	]));
	setup();
	replace_program(ROOM);
}

