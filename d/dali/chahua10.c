//Room: /d/dali/chahua10.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨Է");
        set("long", @LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ�������Ǹ��еĲ軨Է��
������Ʒ�Ͼ��ڴˣ��������Է�軨���Ļ�ŭ�ţ�����һ����ϲ��һ����ʵ�ڲ�
֪���ı��軨����Щ��
LONG );
	set("objects", ([
	   "/d/dali/obj/chahua2": 1,
	   "/d/dali/obj/chahua3": 1,
	   "/d/dali/obj/chahua6": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/chahua7",
	]));
	setup();
	replace_program(ROOM);
}

