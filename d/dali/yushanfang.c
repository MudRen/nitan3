//Room: /d/dali/yushanfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ŷ�");
        set("long", @LONG
�����Ǵ�����ʹ������ŷ�������ĳ��߶��ǽ������ɵġ��ʵ۲�������Ҳ
��Ϣ���ˣ������ǳ��ȡ�
LONG );
	set("objects", ([
	    "/d/dali/npc/taijian": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : "/d/dali/hualang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

