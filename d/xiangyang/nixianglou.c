// Room: /d/xiangyang/nixianglou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����¥");
        set("long", @LONG
��������û�в�֪��������¥���ġ����ǿ�սʱ�ڣ���������ȴ�࣬����̸
��Ҳ�������ⷴ����¡��¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ�
�׾ƾ͸�·ȥ�ˡ�¥������������ս�ڼ䣬���н�Լ������ӻ�����ûɶ���⣬
ֻ�ù��ˡ�
LONG );
	set("exits", ([
		"west" : "/d/xiangyang/southjie2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/xiaoer2" : 1,
	]));
	set("coor/x", -280);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

