// Room: /d/suzhou/shizilin.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "ʨ����");
        set("long", @LONG
��һ�߽�ʨ���֣��㲻��Ϊ��������԰�ֵ������������۷���ʨ���ֶ��϶�
ɽ��������ˮ�����С���ɽ������֮�ơ���ɽ���͵��֣�����������ʯ�����಻
�ϣ�����Ī�⡣���֮�䣬���������ɼ���������������Թ������ɵò�Ϊ֮��
̾���ѡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/yanyutang",
		"west"      : "/d/suzhou/nandajie1",
		"northeast" : "/d/suzhou/zhipoxuan",
	]));
	set("coor/x", 210);
	set("coor/y", -230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

