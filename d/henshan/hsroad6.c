inherit ROOM;

void create()
{
        set("short", "�ּ���");
        set("long", @LONG
������һ���ּ����������������ѡ��������Ǻ��Ͼ��ڡ�
�����Ǻ�����·���пɹ�·����Ϣ��С��ͤ��
LONG);
        set("outdoors", "hengyang");

        set("exits", ([
                "east"   : __DIR__"chating",
                "north"  : __DIR__"hsroad7",
                "south"  : __DIR__"hsroad5",
        ]));

        set("coor/x", -40);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
