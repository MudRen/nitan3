// mishuchu.c
// By haiyan

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ִ��ı��������������μ�һ��һ�ȵ�����ʢ��һ�����֣���
ȡ�������֮���������ڴ�Ὺʼʱ�����ﱨ�����μ��н����µĽ�����ʿҲ��
�������ﹺ���Ʊ�μӾ��»��
LONG );
        set("exits", ([
                "north" : "/d/city/wudao1",
        ]));
        set("objects", ([
                "/clone/npc/missyu" : 1,
        ]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}

