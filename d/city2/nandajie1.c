inherit ROOM;

void create()
{
        set("short", "�����Ͻ�");
        set("long",
"�������ϴ���ˣ�������һ�ҵ��̣�ǽ��д��һ�����ġ������֣�\n"
"��ϸ��������������ѹ�͵��ּۻ��۵�������������һ��Ǯׯ����ʱ����\n"
"Ǯ�������Ķ�������\n"
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"nandajie2",
                "south" : __DIR__"chengmen",
        ]));  
        set("objects", ([
//                "/d/shaolin/npc/tiao-fu" : 1,
//                "/d/city2/npc/xiaofan" : 1,
        ]));

        setup();
  }
