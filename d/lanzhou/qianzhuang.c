inherit ROOM;

void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ������
���зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG);
        set("exits", ([
                "west" : __DIR__"nandajie1",
        ]));
        set("objects", ([
                __DIR__"npc/qian" : 1
        ]));

        set("coor/x", -500);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
