// Room: /d/xiangyang/jiekou2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ֿ�");
        set("long", @LONG
��Ϊ�����ʮ�ֽֿڣ����Էǳ����֡�С��С������������ߺ���ţ�������
�ǵ���Ʒ����Ȼ���������ɹž����ţ������������������˿���Ľ��ţ�������
����˾�ռ��ߡ�ϰ��Ϊ���ˡ�������С��ͬ����������ǵ��ϰ���ס�����棬��
�����������ʯ�̾͵Ĵ�֡����߾��Ǵ����������޼����ܲ���
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
                "east"  : "/d/xiangyang/xiaorong1",
		"south" : "/d/xiangyang/eastroad2",
		"west"  : "/d/xiangyang/northroad2",
		"north" : "/d/xiangyang/xiaorong2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/kid" : 1,
		"/d/village/npc/seller" : 1,
	]));
	set("coor/x", -270);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

