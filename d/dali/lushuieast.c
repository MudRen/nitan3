//Room: /d/dali/lushuieast.c
//Date: June. 29 1998 by Java

inherit BUILD_ROOM;
void create()
{
	set("short","����ˮ�ӹ�");
        set("long", @LONG
������һ��Ƭ�ӹȴ��ڱ���ѩɽ�͸���ɽ֮�䣬�ɶ���ˮ��ˢ���ɣ����Ƶ�
�ݣ�����������ů���۾��˴����������ˡ����������غӹȿ�����һЩ���
����ɽ�����ܣ����Ӷ�������ԡ����Ž��µ�����ֱ��һ�������ӡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westdown"   : "/d/dali/badidian",
	    "eastup"     : "/d/dali/biluoxueshan",
	]));
        set("max_room",3);
	set("no_clean_up", 0);
	setup();
}

