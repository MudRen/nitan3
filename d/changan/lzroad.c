inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�����������·������̫������һ����į�ĸо���·
������ɢɢ�ķֲ��ż�ƬС��أ�żȻҲ�ܿ��ü�һЩ���̡�����
һƬ�Ļļš�
LONG);
        set("exits",  ([
                "west" : "/d/lanzhou/dongmen",
                "east" : __DIR__"tulu2",
        ]));
        set("outdoors", "lanzhou");
        set("coor/x", -400);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
