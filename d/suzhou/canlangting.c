// Room: /d/suzhou/canlangting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ͤ");
        set("long", @LONG
����ͤ�����ݵı�����ϲ࣬��Ϊ����������ţ�ʹ����Ů���ٶ�ϲ������
����ͥɢ������ͤ�з�����ȥ������һƬ���̵Ĳ�ƺ��ͤ����Ȼ���ʴ�֮�У���
������������ƿƣ������ܿ����ܣ�ͤ�ϵĶ��Һ�ʯ���ϵ����(lian)ʹ�˸���
ϲ�����
LONG );
	set("outdoors", "suzhou");
	set("item_desc", ([
		"lian" :
"������±��޼� ��ˮԶɽ������\n",
	]));
	set("exits", ([
		"southeast" : "/d/suzhou/dongdajie1",
		"southwest" : "/d/suzhou/xidajie1",
		"north"     : "/d/suzhou/beidajie1",
		"south"     : "/d/suzhou/baodaiqiao",
                "east"      : "/d/suzhou/hong-damen",
	]));
	set("objects", ([
		// "/adm/npc/hongniang" :1,
	]));
	set("coor/x", 200);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

