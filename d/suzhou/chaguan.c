// Room: /d/suzhou/chaguan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�������������һ���ź��ſ���
�ǣ���̨������һλ�ϰ�����ڵ������̡�
LONG );
	set("resource/water", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : "/d/suzhou/nandajie1",
	]));
	set("objects", ([
		"/d/suzhou/npc/lady2" : 1,
	]));
	set("coor/x", 210);
	set("coor/y", -220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

