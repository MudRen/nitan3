// Room: /d/suzhou/zhenshi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ");
        set("long", @LONG
��ɽ������һ���ʯ����ʯ�������������ʯ���ഫ������ɮ�����ڴ���ʯ
�ľ���������ʯ��Ϣ����ʯ�����������ģ�����ơ�����ʯ���������С�������
Ц��Ե���Ĵ�˵����������ԧ��ʯ��������ʯ��ʵϵ��ӿɽ���
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"     : "/d/suzhou/shijianshi",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", 190);
	set("coor/y", -170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

