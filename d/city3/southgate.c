// Room: southgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
        set("long", @LONG
���ǳɶ��ϳ��ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)��һ����ֱ����ʯ�����������졣�ϱ��ǽ��⣬������˽�
�����ˡ������ǳ��
LONG );
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("no_fight",0);
	set("exits", ([
		"south"  : "/d/city3/nanheqiaos",
		"north"  : "/d/city3/southroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}
