//Room: /d/dali/yangzong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
������ǿ�ڲ��Ĵ�����ôЩ����ľ۾�����ôЩ�����ǰ��ĵ�һ֧����
��Ҳ��ɽ���С��ƽԭ����������һƬ��ˮ��������������ط���΢ƫԶЩ����
���൱���ٵİ����������ڸ��������Ϸ��е�·ͨ����������
LONG );
	set("objects", ([
	   "/d/dali/npc/bshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westup"     : "/d/dali/shanlu8",
	    "northeast"  : "/d/dali/nongtian4",
	    "southup"    : "/d/dali/sanglin",
	    "southwest"  : "/d/dali/milin",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

