inherit ROOM;

void create()
{
    set("short", "Ĺ��");
    set("long",@LONG
����ͨ��Ĺ�ҵ�ͨ����ͨ��ʮ�ֿ�������������һ�Ŵ�
���ҹ���飬�յ�����Ĺ����ͬ���硣Ĺ����ͷ����Ĺ�ҡ�
LONG);
        set("exits", ([
                "up"   : __DIR__"mudi",
                "down" : __DIR__"mushi",
        ]));
        set("objects", ([
                "/clone/book/luoshu" : 1,
                "/clone/book/hetu" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
