// Room: /d/xiangyang/southjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
�������������ϴ�ֵ���ͷ�����������ȸ���ţ����߷ǳ����֡�������Ϊ
�������ؾ��������������ı����̡�ʮ�������������ɹž����ַ�������������
����������һֱ�����ͣ�������������ǵ��ϱ�Ӫ���������������洫���ı�ʿ
�ǵĲ�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/tiejiangpu",
		"west"  : "/d/xiangyang/bingying3",
		"south" : "/d/xiangyang/southgate1",
		"north" : "/d/xiangyang/southjie2",
	]));
	set("coor/x", -290);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
