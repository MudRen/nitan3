inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"�����������ǻʹ��ڵ�����࣬�����Ÿ��ؽ���������������̫��\n"
"��æ�Ÿ�����ϴ��������ϡ�\n"
);
        set("indo0rs", "city2");
        set("no_fly",1);

        set("exits", ([
                "east" : __DIR__"hgdadao6",
        ]));

        set("objects", ([
                __DIR__"npc/zyma" :    1,
        ]));
                       
        setup();
}       

void init()
{
        object me = this_player();
        object ma;
        if (interactive(me) && me == WAR_D->query_marshal())
        {
                if (! objectp(ma = present("shizi ma", me))
                &&  ! objectp(ma = present("shizi ma", environment(me))))
                {
                        ma = new("/d/city2/npc/zyma");
                        ma->move(environment(me));
                }
        }
}
