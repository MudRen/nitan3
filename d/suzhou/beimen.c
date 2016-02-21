// Room: /d/suzhou/beimen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "����");
        set("long", @LONG
�������ݸ��ı����š�����ԶԶ�ɼ�����Ļ���ɽ��������ȥ�����̵��
��Ĳݺ������С�ӡ��ű߹ٱ��������һ�ݸ�ʾ(gaoshi)���ϱ�һ����ֱ�Ĺ�
����
LONG );
	set("outdoors", "suzhou");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : "/d/suzhou/road1",
		"south" : "/d/suzhou/beidajie2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 200);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n������\n";
}

