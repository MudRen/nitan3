inherit ROOM;

void create()
{
	set("short", "������Ժ");
        set("long", @LONG
���߽���Ժ��ӭ����һ����԰����԰�м�ɽˮ�أ��������ۡ���������һ
��޴��ޱȵ���䣬��Ȼ�������ѹ����ı��ˮ�ص����������˻��ݣ�������
�У���ľ֦Ҷï�ܣ��ڸ��˴���Ժ�ӣ��Ե���ɭ�ֲ�������һ��������ľ�Ƴ�
�ȣ�ͨ�������Ĵ�����
LONG );
	set("exits", ([
		"north" :  "/d/beijing/aofu_dating",
		"south" :  "/d/beijing/aofu_zoulang1",
	]));
	set("objects", ([
		"/d/beijing/npc/yuanding" : 1,
	]));

	set("coor/x", -50);
	set("coor/y", 350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
