inherit ROOM;

void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
������ʯ���ߵ�һ��С�Ե꣬��Щ�򵥵���ʳ��ר��׬��
Щ�ο͵�Ǯ��
LONG );
        set("exits", ([
                "west" : __DIR__"shiliang",
        ]));

        set("objects", ([
                "/d/city/npc/xiaoer2" : 1,
        ]));
	set("coor/x", -360);
	set("coor/y", -250);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}