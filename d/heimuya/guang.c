//ROM

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ��ɽ�ȣ�������ֲ�Ų�ƺ�������ǡ�������̡��������á�������
һ����ɽ��ʯ����
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "east" : "/d/heimuya/linjxd1",
            "southup" : "/d/heimuya/dating3",
            "west" : "/d/heimuya/shidao1",
        ]));
        set("objects",([
            "/d/heimuya/npc/kid" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
