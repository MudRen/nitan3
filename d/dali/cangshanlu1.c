//Room: /d/dali/cangshanlu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽɽ·");
        set("long", @LONG
�˴������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£���ǰ��һ������Ա����϶�����
�ڴ�����������ȥ����ˮ������ӿ���Ļ��Ӱ�������һ�����˵ĺ��졣����
ǡ����壬�Ӵ���խ���ӹ��ϲ���������ֻ�����������������������˰���һ
�ô����ϣ��ƿ���Ԯ������
LONG );
	set("objects", ([
	   "/d/dali/npc/lieren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : "/d/dali/cangshanzhong",
	    "west"       : "/d/dali/heshang",
	]));
	setup();
	replace_program(ROOM);
}

