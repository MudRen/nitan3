// road4.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ������·�ϡ�������ɽ���ؽ磬�����ͽ���ӱ��ˡ��������ﲻ��
̫ƽʱ�ڣ����ǿ���߰ɡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : "/d/heimuya/road1",
                "southwest" : "/d/heimuya/dukou1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
