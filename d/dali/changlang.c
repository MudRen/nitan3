//Room: /d/dali/changlang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
���������������ĳ��ȣ����߶��Ǵ�Բ�������ϼ�ɽС��Ӧ�о��У��Ե�ʮ
��������������һ���������ϱ���һ��СͥԺ��
LONG );
	set("objects",([
	    "/d/dali/npc/duanwuwei" : 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/tingfang",
	    "south"  : "/d/dali/tingyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

