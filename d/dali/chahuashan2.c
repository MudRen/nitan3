//Room: /d/dali/chahuashan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
        set("long", @LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ���󲿷��Ƿ�Ʒ����ż
��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���ǵ����ţ����߲�Զ�ǳ�ǽ��
LONG );
	set("objects", ([
	   "/d/dali/obj/shanchahua": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : "/d/dali/chahuashan3",
	    "south"     : "/d/dali/chahuashan4",
	    "east"      : "/d/dali/chahuashan5",
	    "westdown"  : "/d/dali/chahuashan1",
	]));
	setup();
	replace_program(ROOM);
}

