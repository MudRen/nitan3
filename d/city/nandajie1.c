// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц����
���������������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ��
����һ����������һ�����ֵĹ㳡��������һ�ҵ��̣�ǽ�ϻ��Ÿ�����ġ�����
�֣���ϸ��������������ѹ�͵��ּۻ��۵���������������һƬ��������������
�����������ڶ��������š�һ��һʮ������Ǯ����ԭ�����Ƿ�Բǧ��֮������
һ�Ҷĳ���
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : "/d/city/dangpu",
		"south" : "/d/city/nandajie2",
		"west"  : "/d/city/duchang",
		"north" : "/d/city/guangchang",
	]));
	set("objects", ([
		"/d/city/npc/hunhun" : 1,
		"/d/city/npc/liumang": 4,
		"/d/city/npc/liumangtou" : 1,
		"/clone/npc/xunbu" : 1,
	]));

	set("coor/x", 0);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
