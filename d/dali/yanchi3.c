//Room: /d/dali/yanchi1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�سص̰�");
        set("long", @LONG
�����ǵ���ο;ۼ�֮������۷���������ʱʱ������ʤ����ˮ翰��ĵ�أ�
���͡���ɲ�ڵᲨ�����֡�������������ͣ�۹ٶɣ����Ƹ�ʫ������֮Ϊ��ͣ��
�̻᡻������Ķ��ֲʺ硢��ɽ���ꡢ������𸡢��ϼ���졢�鷫ԶӰ���޲���
�����������ܡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/guigongzi": 1,
	   "/d/dali/npc/enu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : "/d/dali/yanchi2",
	    "southeast" : "/d/dali/luojiadian",
	]));
	setup();
	replace_program(ROOM);
}

