// Room: /d/xiangyang/northjie.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�������������ţ��ϱ��Եú�
��æ��������һ��ݣ�һ�����顺�衻������ڷ��������ҡҷ�ţ�һ�ɹɲ���
��������������������ǵı���Ӫ���������������洫���Ĳ�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/chaguan",
		"south" : "/d/xiangyang/dingzi",
		"west"  : "/d/xiangyang/bingying1",
		"north" : "/d/xiangyang/northgate1",
	]));
	set("coor/x", -300);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

