inherit ROOM;

void create()
{
        set("short", "��ͤ԰");
        set("long", @LONG
������һƬ��ľ������԰�֡�԰�ֵ��ϱ����߷ֱ������
�����˼Һ������б̲����������ߴ����������������𡣴Ӵ�
������ͤ������������ֵ���
LONG
        );
        set("objects", ([
	]));

        set("no_clean_up", 0);
        set("exits", ([
		"east" : __DIR__"longting",
		"west" : __DIR__"wroad3",
	]));

        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
