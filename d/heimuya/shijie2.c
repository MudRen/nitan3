// shijie2.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
Խ���ϣ�ɽ��Խ���ͣ��м��ʯ��Խխ������һ�����ߣ�����������������
Լ����һ��ʯ�š�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : "/d/heimuya/shijie1",
            "westup"   : "/d/heimuya/shimen",
        ]));
        set("objects", ([
            CLASS_D("riyue") + "/zhaohe": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
