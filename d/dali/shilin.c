//Room: /d/dali/shilin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","·��ʯ��");
        set("long", @LONG
�����������洦�ɼ���ʯ���죬ʯ��Լ���ʯ��ͦ����������ʣ��������ˡ�
����ʯ���ܾۣ��罣��ſգ�çç�Բԣ�ٲȻһƬ�ֺ���εΪ׳�ۡ����Ӵ�ɽ֮
�л����ֱк���ɵ�ˮ���ƣ���ɽȪ��ۣ�������������
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : "/d/dali/changhu",
	    "south"    : "/d/dali/cangshan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

