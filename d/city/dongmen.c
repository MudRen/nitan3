// Room: /city/dongmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż��Źٸ�
��ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ����
ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣�����Ī
�⡣�����ǳ��������һƬïʢ�������֡�
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/taishan/yidao",
		"north" : "/d/city/ml1",
		"south" : "/d/city/jiaowai1",
		"west" : "/d/city/dongdajie3",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
                "/d/city/npc/jpl2": 1,
	]));

	set("coor/x", 40);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
