//Room: /d/dali/tingfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
������������������������������ʮ�ֿ�������˵��������������ܼ򵥣�
���м�������̫ʦ�Σ����ϰ����˸��ָ�����ɽ�軨��
LONG );
	set("objects",([
	    CLASS_D("dali")+"/guducheng": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/yongdao1",
	    "west"   : "/d/dali/chufang",
	    "east"   : "/d/dali/shufang",
	    "south"  : "/d/dali/changlang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

