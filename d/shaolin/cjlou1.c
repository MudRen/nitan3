inherit ROOM;

void create()
{
        set("short", "�ؾ����¥");
        set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£�����
�˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ���������
��������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��
ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ�����
λ��ɮ��ִ�������ڱ�Ŀ��˼������(fangliang)�����ǻҳ���
LONG );
        set("exits", ([
                "down" : __DIR__"cjlou",
        ]));
        set("objects",([
                CLASS_D("shaolin") + "/hui-zhen" : 1,
                "/clone/book/wuji1" : 1,
                "/clone/book/wuji2" : 1,
                "/clone/book/wuji3" : 1,
        ]));
        set("item_desc", ([ /* sizeof() == 1 */ 
                "����" : "���������Խ��һ�ɶ�ߡ������ܲ�����(jump)��ȥ��\n", 
        ])); 
        setup();

        if (random(5) == 0)
                "/clone/book/wuji4"->move(this_object());
}

void init()
{
        add_action("do_hit", "hit");
        add_action("do_jump", "jump");
}

int do_hit(string arg)
{
        object ob, me = this_player();
        
        if ( arg == "huizhen" || arg == "zunzhe" || arg == "huizhen zunzhe" ) {
                ob = present("huizhen zunzhe", environment(me));
                ob->kill_ob(me);
                me->fight_ob(ob);
                tell_object(me,"��ͻȻ������ת��ڤڤ���ƺ��й������ڲ����������!\n");
                me->unconcious();
        
                return 1;
        }

        return 0;
}

int do_jump(string arg)
{
        string dir;
        object me=this_player();

        if( !arg || arg=="" ) 
        {
                write("����������ȥ��\n");
                return 1;
        }

        if( arg=="fangliang" ) {
                           write("�����������һ����,��ȻԾ��......\n");
                if((int)me->query_skill("dodge",1)>=50)
                          {write("��һʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽�����ϡ�\n");
                me->move(__DIR__"liang");
                return 1;}
                write("��ž����һ�����Դ�ײ���˷���,�ֵ���ԭ����ˤ�˸��Ľų��졣\n");
                me->add("jing",-100);
                me->add("qi",-100);
                me->add("eff_qi",-100);
                me->improve_skill("dodge", random(30));
                me->unconcious();
                return 1;
        }
}

int valid_leave(object me, string dir)
{
        object *ob;
        int i;

        if (dir != "down" ||
            ! present("huizhen zunzhe", environment(me)))
                return ::valid_leave(me, dir);

        ob = deep_inventory(me);
        for (i = 0; i < sizeof(ob); i++)
                if (ob[i]->id("shaolin wuji")) 
                        return notify_fail("����˵�����书�ؼ�ֻ���ڲؾ���"
                                           "����ϰ������Я�������\n");
        return ::valid_leave(me, dir);
}

