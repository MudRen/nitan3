// shijie1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��խխ��ʯ�ף��������˲����
�С�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : "/d/heimuya/shandao2",
            "westup"   : "/d/heimuya/shijie2",
        ]));
        set("objects", ([
            CLASS_D("riyue") + "/fansong": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
