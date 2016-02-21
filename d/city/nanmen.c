// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬�ٸ�
�ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц�����������ƺ����Ǻ���
����ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : "/d/wudang/wdroad1",
		"north" : "/d/city/nandajie2",
		"west"  : "/d/city/jiaowai8",
		"east"  : "/d/city/jiaowai7",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                "/d/city/npc/shisong" : 1,
        ]));
	set("coor/x", 0);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
