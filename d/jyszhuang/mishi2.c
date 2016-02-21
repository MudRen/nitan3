// by Lonely

inherit ROOM;

int do_study(string arg);

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǹ�����µĵ������ҡ�������С��ȴҲ�����ȫ��
ʯ��ʯ�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ�
�����ƺ��ܾ���ǰ����������ס�������е�ʯ��(table)��ƽ
����һ�鱡����ʯ�壬����������Щʲô��
LONG
        );
        set("exits", ([
                "up" : __DIR__"mishi1",
                "south" : __DIR__"shanzhuang",
        ]) );
        set("objects", ([
        ]) );

        set("no_fight", 1);
        set("item_desc", ([
                "table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;

        me = this_player();

        if ( !arg || ( arg != "table" ) )
                return notify_fail("ʲô��\n");

       if (me->is_busy()) return notify_fail("������æ���أ�\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

        jing_cost = (-1) * random(2);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("�����ھ����޷����У�\n");

        me->add("jing", jing_cost);

        tell_object(me, "�㿪ʼר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n");
        if ( (int)me->query_skill("martial-cognize", 1) < 500)
        {
                me->improve_skill("martial-cognize", me->query_int() * 10);
                tell_object(me, "�����ʯ����ĥ��һ�ض����ƺ�����ѧ�����е㳤����\n");
        } else
        {
                me->improve_skill("martial-cognize", me->query_int() * 5);
                tell_object(me, "�����ʯ����ĥ��һ�ض����ƺ�����ѧ������΢�е㳤����\n");
        }
        me->start_busy(random(2));
        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && ! wizardp(me))
                return notify_fail("\nͻȻ֮�䣬ǰ��һ����ɭɭ�������ȵ���
�����������Ѱ���������ס��һǧ�꣬˭Ҳ�����������ҡ���һ���󵨹��������̾�������\n
��ֻ������ͷһ��������ֱ���£���Ҳ��ǰ�߲���һ����\n ");
        return 1;
}

