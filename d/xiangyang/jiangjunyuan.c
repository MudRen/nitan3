// Room: /d/xiangyang/jiangjunyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������Ժ");
        set("long", @LONG
�����ǽ������Ĵ�Ժ��ֻ������ʯ�̾͵ĵ���һ����Ⱦ���������Ź��ʵ�С
Ѿ��������ڲ�ϴ���ߵ����˺����ӣ���ʱ��ֵ�����ʿ�߹�����������ȥ����
�Կ����������Ĵ��á�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/xiangyang/jiangjungate",
		"north" : "/d/xiangyang/jiangjuntang",
	]));
	set("coor/x", -280);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

