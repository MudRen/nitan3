//Room: /d/dali/zhulou1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��¥��");
        set("long", @LONG
̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ������Ϊǽ����¥
�����൱���¡��²������ֻ���ĸ����Ӽܿյģ��ȿ�������Ȧ��ҲΪ�˷��ߡ�
һ������ͨ���ϲ�ķ��ᡣ
LONG );
	set("objects", ([
	   "/d/dali/npc/cow": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"   : "/d/dali/wuding",
	    "up"      : "/d/dali/zhulou2",
	]));
	setup();
	replace_program(ROOM);
}

