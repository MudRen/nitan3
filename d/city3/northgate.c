// Room: northgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
        set("long", @LONG
���ǳɶ������ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)��һ����ֱ����ʯ���������졣������ȥ��һƬ�����͵�
��Ұ�������ҡҷ�ĸ��������񡣳��ű����йٱ���ϸ�̲�����˵ȡ�
LONG );
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("no_fight",0);
	set("exits", ([
		"south"  : "/d/city3/northroad2",
		"north"  : "/d/city3/fuheqiaon",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}

