inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����ﶫ��
�����Ǳ����£������ּ�������һ�����
LONG);
        set("exits", ([
                "north" : __DIR__"bgs",
                "west"  : __DIR__"fhs",
        ]));
        set("outdoors", "emei");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -230);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}