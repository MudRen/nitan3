//Room: /d/dali/zonglichu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
        set("long", @LONG
��������������̫���������֮������������������þ������������ܰ�
�˺ܶ�軨�����涷�ޡ��軨�Ǵ���������������˶���Ҳ���Ӱ��мӡ�
LONG );
	set("objects", ([
	    "/d/dali/obj/shanchahua": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/sikong",
	    "south"  : "/d/dali/wfdating",
	    "east"   : "/d/dali/sima",
	    "west"   : "/d/dali/situ",
	]));
	setup();
	replace_program(ROOM);
}

