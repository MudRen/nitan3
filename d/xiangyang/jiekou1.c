// Room: /d/xiangyang/jiekou1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ֿ�");
        set("long", @LONG
��Ϊ�����ʮ�ֽֿڣ����Էǳ����֡�С��С������������ߺ���ţ�������
�ǵ���Ʒ����Ȼ���������ɹž����ţ������������������˿���Ľ��ţ�������
����˾�ռ��ߡ�ϰ��Ϊ���ˡ�����������Ǻ�ͬ����������ǵ��ϰ���ס�����棬
�������������ʯ�̾͵Ĵ�֡�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : "/d/xiangyang/northroad1",
		"south" : "/d/xiangyang/westroad2",
		"west"  : "/d/xiangyang/hutong1",
		"north" : "/d/xiangyang/hutong2",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	set("coor/x", -320);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

