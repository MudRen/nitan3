// Room: /d/xiangyang/bingying1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
        set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������е�
�������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѳ������
�ܡ����������������ȫ���ɴ��۾������㡣
LONG );
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"east" : "/d/xiangyang/northjie",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pian" : 1,
		"/d/xiangyang/npc/zuo"  : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -310);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

