inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
������ڵ��ܵ����������ɽ����Ϊ��ֱ����ԭ������ġ�
LONG);
        set("exits" , ([
                "east" : "/d/city/beidajie1",
                "up"   : __DIR__"neishi",
        ]));
        set("objects",([
                __DIR__"obj/shenshe" : 1 ,
        ]));
        
        setup();
        replace_program(ROOM);
}
