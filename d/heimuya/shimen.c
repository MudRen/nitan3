// shimen.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�ߵ�һ����ʯ��ǰ��ֻ�����Կ������д��֣������ǡ��ĳ���¡���������
������Ӣ����������Ͽ��š����¹������ĸ�����֡�
LONG );
        set("outdoors", "heimuya");
        set("objects", ([
            CLASS_D("riyue") + "/zhang2": 1,
        ]));
        set("exits", ([
            "eastdown" : "/d/heimuya/shijie2",
            "westup"   : "/d/heimuya/up1",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
