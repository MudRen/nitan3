// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ������
�š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��������߾����ĵ�û�м������ˣ�
������������ͨ�����⡣�ϱ���һ����ݣ�������һ�������ûʵĴ�լԺ��
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/city/xidajie1",
		"south" : "/d/city/wuguan",
		"west"  : "/d/city/xidajie3",
		"north" : "/d/city/caizhu",
	]));

        set("objects", ([
                "/d/quanzhen/npc/youfang": 1,
	]));

	set("coor/x", -20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
