// shidao1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����½̽��ڰ������ܣ���������ɽ��������һ��ˮ̲֮ǰ��������һ
��ʯ��ͨ��ˮ̲��
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "westdown" : "/d/heimuya/xingxingtan",
            "south" : "/d/heimuya/shidao1",
        ]));
        set("objects", ([
            "/d/heimuya/npc/wangcheng" : 1,
            "/d/heimuya/npc/heiyiren" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
