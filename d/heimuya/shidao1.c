// shidao1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����У��м����һ����Լ��ߵ�ʯ��������ʯ����ǽ��һ·�϶�����
�½�ͽģ�����������߶�����������·�˶����ܼ��ӡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "east" : "/d/heimuya/guang",
            "north" : "/d/heimuya/shidao2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
