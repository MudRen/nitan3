inherit ROOM;

void create()
{
        set("short", "���㼹");
        set("long", @LONG
���ǻ�ɽ�������յء����㼹����ֻ��һ����Լ��ʮ���ɣ�������ߵ�С��
ֱ��Է壬���Խ����������ƣ�����׵�Ͽ�ȣ�紵����ʹ��ƮƮ������
�ָ���ƽʱҲ����ð��Խ���˴���
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                "south"   : __DIR__"laojun",
                "northup" : __DIR__"houzhiwangyu",
        ]));
        set("objects", ([ 
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "huashan" );
        setup();
        replace_program(ROOM);
}

