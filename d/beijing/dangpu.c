inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����һ�������ھ���������������ߵĵ��̡���ҵ��̹�ģ���󣬵�������
��������ƽ���ƣ����ǵİ������ֽ������ʱ������Ѷ����õ��������䵱��һ
����߸ߵ�ľ�ƹ�̨���������ǰ����̨�ϰ���һ������ (paizi)����̨������
���̵��ϰ壬һ˫�������۾��������´������㡣
LONG );
	set("no_fight", 1);
	set("no_beg",1);
        set("item_desc", ([
                "paizi" : "��ƽ����\n
sell        �� 
buy         ��
pawn        ��
expiate     ��
value       ����
",
        ]));

	set("objects", ([
		"/d/beijing/npc/dangpuzhang" : 1,
	]));
	set("exits", ([
		"west" : "/d/beijing/wang_6",
	]));

	setup();
	replace_program(ROOM);
}

