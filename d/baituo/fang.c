inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ���ɽ���ӵ��������������м������䣬�������ҡ�
������������������գ����Բ��������˴����
LONG);
        set("exits",([
                "west" : __DIR__"liangong",
                "1"    : __DIR__"room1",
                "2"    : __DIR__"room2",
                "3"    : __DIR__"room3",
        ]));

        set("objects",([
                __DIR__"npc/trainer" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
