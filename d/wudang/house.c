inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
����һ��С���ݣ���������һ��ũ�ҵķ��ӡ�����򵥵�
����Щ�Ҿߣ�ǽ�������Щũ�ߡ���������һ�������ź�һ��
С���������˳����������ɫ���ŵ������㡣
LONG);
        set("exits", ([
                "north" : __DIR__"wdroad6",
        ]));
        set("objects", ([
                "/d/village/npc/oldwoman" : 1,
                "/d/village/npc/kid" : 1,
        ]));
        set("coor/x", -300);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


