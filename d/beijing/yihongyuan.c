inherit ROOM;

void create()
{
	set("short", "����Ժ");
        set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ��һ���Ӿ���������
��ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�������������������Ů�˷�վ��
�Զ��㷢����Ц��һ���������æ��ǰ�к����ˡ���¥�ϴ���������������ε�
������
LONG );
	set("exits", ([
		"west" : "/d/beijing/wang_8",
	]));

	set("objects", ([
                "/d/beijing/npc/laobaopo" : 1,
                "/d/beijing/npc/piaoke" : 1,
                "/d/beijing/npc/jinv" : 2,
	]));

	set("coor/x", 10);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
