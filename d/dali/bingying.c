//Room: /d/dali/bingying.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ӫ");
        set("long", @LONG
�������С��ȴ���Ӿ���������Ȼ���˱�����־������������֮�ߣ����ϴ�
�����뱱���γ��޺ͣ�����������£�����ˣ�������ս�¡����ǳ��������Ӫ��
Ϊ����ĵ�ϵ��װ�������޲�������ԭ�ط�����ʿ�������Դ�����������������
������
LONG );
	set("objects", ([
	   "/d/dali/npc/bing": 2,
	   "/d/dali/npc/weishi1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/dahejiewest",
	    "west"   : "/d/dali/majiu",
	]));
	setup();
	replace_program(ROOM);
}

