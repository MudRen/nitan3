//Room: /d/dali/southgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ�����������
����������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��ʯ������ݳɣ��߶���
�壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲����������������ˣ�
ż�����ʼ����μ����ɷ��ӡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/jiang": 1,
	   "/d/dali/npc/bing": 3,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/shizilukou",
	    "east"       : "/d/dali/xiaodao2",
	    "south"      : "/d/dali/shuangheqiao",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

