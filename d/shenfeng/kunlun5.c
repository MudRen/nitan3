// Room: room64.c
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����������ֻ�з紵���Σ�������ɣ����Ӳ��죬ע��Ⱥɽ�����˲�
����Ȼ����˼��֮���飡��ǰ����ֻ��һ�����ң����پ��£����¿�����
���絶�����ƾ���ӿ������ס�
LONG );
        set("exits", ([
                "north" : __DIR__"kunlun4",
        ]));

        set("outdoors", "kunlun");
        setup();
}

void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me, room;
        me = this_player();
        
        if (! arg || arg != "down") 
                return notify_fail("��Ҫ��������\n");      
                    
        message_vision("$N��ԥ��һ�£�����������������ȥ��\n", me);

        if ((int)me->query_skill("dodge", 1) < 400) 
        {
                message("vision", me->name() + "��������׹ȥ���������׶༪����!\n", environment(me), ({me}));
                if (! room = find_object(__DIR__"kunlun8"))
                        room = load_object(__DIR__"kunlun8");
                me->move(room);
                message("vision", "�飡��һ���˵���������\n", room, ({me}));
                me->set_temp("die_reason", "���¾���ˤ����");
                me->die();
                return 1;
        }

        if (random(100) > 50)
        { 
                if (! room = find_object(__DIR__"kunlun8"))
                        room = load_object(__DIR__"kunlun8");
        } 
        else
        {
                if (! room = find_object(__DIR__"kunlun9"))
                        room = load_object(__DIR__"kunlun9");
        }

        me->move(room);
        message("vision", "�飡��һ���˵���������\n", room, ({me}));
        return 1; 
}

