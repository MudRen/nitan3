// Room: /d/suzhou/road4.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ�������ͨ��ɽ
�¡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : "/d/suzhou/hanshansi",
		"east"      : "/d/suzhou/road3",
                "west"      : "/d/zhongzhou/dongmeng",
	]));
	set("coor/x", 140);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

