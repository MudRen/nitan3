inherit ROOM;

void create()
{
        set("short", "������ջ");
        set("long", @LONG
���Ǿ��ǻ���·��ͷ�ڽֵ�һ�ҿ�ջ����ջ����ǰ������һ���ͻ���ɽ��
�޻������Ź��Ŷ�ԧ��������ϵ�ż���СС�Ļ�ͭ���塣΢���ӹ������巢��
����ö��Ķ����������к�����������ջ����
LONG );
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("objects", ([
                "/d/beijing/npc/xiaoer3" : 1,
        ]));
        set("exits", ([
                "north" : "/d/beijing/kediandayuan",
                "south" : "/d/beijing/fu_2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 330);
	set("coor/z", 0);
	setup();
//        "/clone/board/kedian2_b"->foo();
        replace_program(ROOM);
}
