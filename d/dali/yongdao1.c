//Room: /d/dali/yongdao1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��");
        set("long", @LONG
���������������������������ܵ����֣��紵����Ҷɳɳ����ʯ������
·�����࣬��������̲ݣ���׺��һ�ǰ���С������Χʮ�ְ�����Ψ��������
����һ����򶷵������������׾��Ļ���Խ���������С�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : "/d/dali/yongdao2",
            "northwest" : "/d/dali/liangong",
	    "south"     : "/d/dali/tingfang",
	]));
	setup();
	replace_program(ROOM);
}

