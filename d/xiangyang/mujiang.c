// Room: /d/xiangyang/mujiang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ľ����");
        set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶�������ֵ��������ľ��
��Ҳֻ������Щ��ǹ����ʲô�������Һ��ڡ����Ϻ�ǽ�����ҵضѷ���һЩľ����
ľ����ľ��ʲô�ģ����м�������ӣ�����һ���ľ�����ߡ�
LONG );
	set("exits", ([
		"north" : "/d/xiangyang/eastjie3",
	]));
	set("objects", ([
		"/d/xiangyang/npc/mujiang" : 1,
	]));
	set("coor/x", -260);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

