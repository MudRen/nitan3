inherit ROOM;

void create()
{
        set("short", "���鸮����");
        set("long",
"�����Ǿ������鸮���ţ��������˽������ɼ��������Ϊ���²��ͺ�\n"
"��֮�����ˣ��ſ��������ҽ��������������ȻҲû�������㣬������֡�\n"
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "west" : __DIR__"ydmen",
                "east" : __DIR__"ssfu",
        ]));

        set("objects", ([
  
        ]));

        setup();
        replace_program(ROOM);
}


