inherit ROOM;

void create()
{
        set("short","���Ϸ�");
        set("long",@LONG
��������䵱ɽ���Ϸ塣ֻ�����������ͻأ�������ޱȣ�
���˶಻�ҷŵ��ڴ����ͷ羰��
LONG);
        set("exits", ([
                "northdown": __DIR__"sanlaofeng",
                "southup"  : __DIR__"hutouyan",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -350);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}