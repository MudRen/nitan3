inherit ROOM;

void create()
{
        set("short", "ԭʼɭ��");
        set("long", @LONG
���߽�ԭʼɭ�֣�ֻ����Χ����ããȫ�ǲ������������
���գ����ܹ��ߺܰ����ֲ��嶫������������˭������������
��ȥ�ˡ��Һõ�����������ʱ��������һ��·�����򣬾���
�������޳Ե�������ҲҪ�����ζ�����
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"yunnan3", 
                "north"  :__DIR__"yunnan1",
        ]));
        set("objects", ([
                "/clone/worm/huabanzhu" : 1,
        ]));
        set("resource/quarry", ([
            "/clone/quarry/lang" :  50,
            "/clone/quarry/jizi" :  50,
            "/clone/quarry/yang" :  50,
            "/clone/quarry/laohu" :  50,
            "/clone/quarry/zhang" :  50,
            "/clone/quarry/hou" :  50,
            "/clone/quarry/xiniu" :  10,
            "/clone/quarry/xiang" :  10,
            "/clone/quarry/lang3" :  5,
            "/clone/quarry/gou2" :  10,
            "/clone/quarry/gou3" :  5,
            "/clone/quarry/yang2" :  50,
            "/clone/quarry/yang3" :  5,
        ]));
        setup();
        replace_program(ROOM);
}

