// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻�������
�ǽ������Ǽ��ˡ�������ȥ�������������׷���׺����������������̫���ˡ�
LONG );
	set("exits", ([
		"south" : "/d/suzhou/qzroad3",
		"north" : "/d/suzhou/qzroad1",
		"east"  : "/d/suzhou/jiaxing",
		"west"  : "/d/yanziwu/hupan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

