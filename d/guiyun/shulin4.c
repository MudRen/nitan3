// Room: /guiyun/shulin4.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shanlu1",
		"west"  : __DIR__"shulin3",
	]));
	set("objects", ([
		__DIR__"npc/dabei" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}