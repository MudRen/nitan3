inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬����
�ľ���죬���ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ������
�����ƶ�Ρ�롣��ɲ���ڸ��ڴ���Ũ��֮�У�����ȴ��һƬ
��Ҷ���������Ͻ����±��ǹ����á�
LONG);
        set("objects", ([
                __DIR__"npc/boydizi" : 1,
                __DIR__"npc/girldizi" : 1,
        ]));
        set("exits", ([
                "east"   : __DIR__"milin1",
                "westup" : __DIR__"milin2",
        ]));
        set("outdoors", "emei");
	set("coor/x", -380);
	set("coor/y", -230);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}