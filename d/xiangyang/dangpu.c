// Room: /d/xiangyang/dangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š��񺽵��̡��ĸ����ֵ�
���ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���һ��ȥ����һ��ѹ�ֺͱ�
��ĸо�����̨����ϰ���ͷҲ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�黨
ľ����(paizi) ���ݽַ���˵���浱�̸��ļۻ�����������ҴӲ��ʻ���������
���˻���ʲô���գ���������ܲ���
LONG );
        set("item_desc", ([
                "paizi" : "��ƽ����\n
sell        �� 
buy         ��
pawn        ��
expiate     ��
value       ����
",
        ]));

	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"north" : "/d/xiangyang/westjie1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/qiuhang" : 1,
	]));
	set("coor/x", -300);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

