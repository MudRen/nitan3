//Room: /d/dali/shuangheqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","˫����");
        set("long", @LONG
����һ����·�ڣ�����������ʯ��������˫���ţ����ſ�������Ϫ�ϣ��ű�
���Ǵ���ǣ��ɴ���ȥ��ͨ���Ϸ���ϲ�ݡ����ڵȳ���Ĺٵ�����ȥ�Ĳ�·ͨ��
������������Ϫ�ϰ����пɴ��廪¥��
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : "/d/dali/southgate",
	    "west"      : "/d/dali/luyuxi",
	    "south"     : "/d/dali/road4",
	    "southeast" : "/d/dali/road5",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

