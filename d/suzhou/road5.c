// Room: /d/suzhou/road5.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
����������ݳ��ˡ����ϱ�ԶԶ��ȥ�������������׷���׺����������������
̫���ˡ�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north"     : "/d/suzhou/nanmen",
		"southwest" : "/d/yanziwu/hupan",
                "east"      : "/d/item/road1",
	]));
	set("coor/x", 200);
	set("coor/y", -260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

