// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ���ε�
�ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵļѻ�����
������¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ���
�ƾ͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"west" : "/d/city/beidajie2",
		"up" : "/d/city/zuixianlou2",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
        set("no_fight", 1);
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}