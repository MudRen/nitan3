//Room: /d/dali/feilihueast.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
        set("long", @LONG
��վ���������Ķ��������µ���·�ƺ��������ϱ��Ĵ�����������ֻ����
�۵�㣬���ǲ����̨���񷤡�·�߾����������֣�̨�ĵ���¥�����֡�����
��ȥ�Ĳ�·ͨ�����������Բ�����·����ֱ�����ڳǡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : "/d/dali/longkou",
	    "northwest"  : "/d/dali/feilihu",
	    "southwest"  : "/d/dali/hexi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

