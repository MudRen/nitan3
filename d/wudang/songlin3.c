inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
        set("outdoors", "wudang");
        set("objects", ([
                "/clone/quarry/hou" : 1,
        ]));
        set("exits", ([
                "north"  : __DIR__"songlin1",
        ]));
	set("coor/x", -340);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}