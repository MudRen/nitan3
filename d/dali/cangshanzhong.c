//Room: /d/dali/cangshanzhong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ�в�");
        set("long", @LONG
�������ڲ�ɽ�в�ɽ�ߣ��˼���μ��գ�����ɽ�����ƣ��м�һ����᫲�ƽ
��ɽ·��·����Զһ������Ա���ƫ��������������¡¡ˮ��ңң���ţ�������
گ����--��ˮ����·�������������������ıؾ�֮;��ʱ�п��̹������ɴ���
�ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ���ǳ���ɽ��ɽ�ڡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/jianchuan",
	    "southwest"  : "/d/dali/cangshanlu1",
	    "southeast"  : "/d/dali/xiaguan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

