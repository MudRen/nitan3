inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ƕ���ɽ����һ���򵥵Ĳ�����϶���Щ�ϻ����ܶ�
��ɽ���οͶ���������Щ��ɽ��Ʒ��������и��ھ���������
���ª����ǡ�
LONG);
        set("outdoors", "emei");
        set("objects", ([
                __DIR__"npc/xiao-fan": 1,
        ]));
        set("exits", ([
                "west" : __DIR__"majiu1",
                "east" : __DIR__"qsjie2",
        ]));
	set("coor/x", -380);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}