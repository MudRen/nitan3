// Room: /d/xiangyang/yaopu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ҩ��");
        set("long", @LONG
ҩ�̲���ȴ�쳣�����ࣻ�����ǹ�̨����̨�����Ǹ�����Ӽ��ٸ�С����
��һһ�ú�ֽ����ҩ�ĵ����ƣ������ݶ���ǽ������һ��ڵ׽��ֵ��Ҷд��
�����ֻش��������¼���������ڷּ�ո��չ����Ĳ�ҩ������һ��С��������
������ű�īֽ�⣬��������һλ�����С�һ�ɴ̱�ҩζ�������������䡣
LONG );
	set("exits", ([
		"north" : "/d/xiangyang/eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", -280);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
