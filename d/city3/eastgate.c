// Room: eastgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
        set("long", @LONG
���ǳɶ������ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)��һ����ֱ����ʯ���������������졣�����ǽ��⣬һƬ
ƽƽչչ��ƽԭ��⣬���ǲ����츮֮�������ơ������ǳ��
LONG );
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : "/d/city3/fuheqiaoe",
		"west"  : "/d/city3/eastroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}
