//room1.c

inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
�����ǰ���ɽ���ӵ������ҡ��м����������µ�ľ������������
LONG );
        set("exits",([
                "out" : __DIR__"fang",
        ]));

        set("objects",([
                "/clone/npc/mu-ren" : 4,
        ]));

        setup();
}
