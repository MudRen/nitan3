
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��ǰ���Ǹ����Ž��صĴ�ȣ��컨������������ӳ����������������
������ܸ�ɽ���ƣ��ƺ�ب��������δ���˼�����������ѩ����ƣ��վ�
���ͣ������޷���Ԯ���롣
LONG );
        set("objects", ([ 
                __DIR__"npc/monkey" : 2,
        ]));
        set("exits", ([ 
                "west" : __DIR__"kunlun11",
                "north" : __DIR__"kunlun12",
        ]));
        set("outdoors", "kunlun");
        setup();
        replace_program(ROOM);
}
