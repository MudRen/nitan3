//Room: /d/dali/wumeng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ɴ���");
        set("long", @LONG
������ɽ�Ļ��£������˰�ʯȥ�����������޳�һ������״��ƽ̨�����
�ֱ��ڸ���ƽ̨�ϣ��������ӣ�������ʯ��Χǽ�����е�·Ҳ��ʯͷ�̳ɡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : "/d/dali/wunong",
	    "east"    : "/d/dali/caopo",
	    "north"   : "/d/dali/wuyiminju1",
	    "south"   : "/d/dali/wuyiminju2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

