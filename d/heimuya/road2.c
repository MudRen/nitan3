// road2.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ������·�ϡ�������һ��С�߸ڣ������ն񣬿��öϾ�����������
���Կ���ƽ���ݳǡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "southwest" : "/d/heimuya/road1",
            "east" : "/d/heimuya/pingdingzhou",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
