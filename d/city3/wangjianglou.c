// Room: wangjianglou.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����¥");
        set("long", @LONG
����¥�����������������Ľǣ�������˽ǣ��������ߣ��̽Ƿ���������
�������������ϣ�Զ�����Ϻӣ�������棬�ۻ���ʵΪʤ����¥�����⣬��
��ǧ�����죬ÿ�������뵣��������䣬�����������������ǡ�¥ǰѦ�ξ�����
˵��ΪѦ��Ưϴһ�ֺ�ɫʫ�������ǧ��: �޲��ž������أ���ɫ�ż�����䡣
��Ҳ����һ��Ů�Ĵ�����Ψһ����
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "northwest"  : "/d/city3/eastroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
