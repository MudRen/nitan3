//ROOM: xiaohuayuan.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
        set("long", @LONG
�ӻ谵�ĵص��г������㷢���Լ�����������һ�������µ�С��԰�У���÷
�������ɴ�أ����õ��ľ߽��ģ�����ȥ��һ�侫��С�ᡣ
LONG );
        set("exits", ([
            "south" : "/d/heimuya/didao6",
            "enter" :"/d/heimuya/xiaoshe",   
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
