inherit ROOM;
 
void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
������һƬ�ݵء��ݵ������ƺ��������磬���ߺ�����һ��С��԰��
LONG );
        set("exits", ([
            "west"   : "/d/heimuya/chufang1",
            "east"   : "/d/heimuya/hua1",
             "north" :"/d/heimuya/dating1",
             "south" :"/d/heimuya/grass1",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
