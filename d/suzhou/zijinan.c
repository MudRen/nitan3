// Room: /d/suzhou/zijinan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�Ͻ���");
        set("long", @LONG
����һ�����ݳ������������֣������������ͼ�Ħ����ۣ��ƺ���ע��ǰ��
���֮�ˣ��ұ�һ��������������ָ����һ��������廨���Ǻͺ�ڹ�������ͷ
�ϵ�һ������ĵ�������Ϻ�ɫ���ǡ���ڵ�ÿ���޺�������������������������
�����������˻������񳬺�����֮������������磬����̾Ϊ��ֹ��
LONG );
	set("objects", ([
		"/d/suzhou/obj/box" : 1,
		"/d/suzhou/npc/nigu1" : 1,
		"/d/suzhou/npc/nigu2" : 1,
	]));
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/beidajie2",
	]));
	set("coor/x", 190);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

