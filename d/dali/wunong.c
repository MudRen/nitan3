//Room: /d/dali/wunong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ū��");
        set("long", @LONG
�˴��ѵ�����ı����������ɵ�����θ������������ģ��������ڸ�ɽ
�ϡ�����������ɽ֮�������ٲ�����ӿ�Ĵ�ɺӡ���İ����ɽʯ�ݳɣ������࣬
����ȫ�ǡ��˳ǲ�������ɽ�Ϸֲ���Щ������ӣ������˸���ţ���������
LONG );
	set("objects", ([
	   "/d/dali/npc/wshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : "/d/dali/daduhe",
	    "southdown"  : "/d/dali/shanlu1",
	    "east"       : "/d/dali/wumeng",
	]));
	setup();
	replace_program(ROOM);
}

