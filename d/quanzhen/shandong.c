#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
������ȫ��̿�ɽ��ʦ���������˾��޵�ɽ�������䲻��
��ȴ���õú������£����ƴ��˼ҵĿ���һ��������������
�Ÿ���(hua)�����β輸���ܾ��¡�
LONG);
        set("exits", ([
                "out" : __DIR__"xiaolu3",
        ]));
        set("item_desc", ([
        	"hua": YEL "\n������һ�������ʿ�ı�Ӱ��������ʲô��"
                       "ò�����е���һ��\nָ���죬�������š�" HIR "��"
                       "������" NOR + YEL "�������֡�\n" NOR,
        ]) );

        set("objects", ([
                CLASS_D("quanzhen") + "/wang" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_ketou", "ketou");
}


int do_ketou(string arg)
{
        object paper, me = this_player();
        int level1, level2, level3;

        if (me->is_busy()) return notify_fail("������æ���ء�\n");

        message_vision("$N��������������ǰ�������Ϲ���������������λ����������ͷ��\n", me);
        // me->receive_damage("qi", random(30));
        me->start_busy(1);

        if ( me->query("qi") <= 50 )
	        write("��ֻ����������Щ�������ġ�\n");
        if ( me->query("qi") <= 30 )
	        write("�����������ת���ƺ����ϱ�Ҫ��ȥ��\n");

        if ( !(me->query("family/family_name")=="ȫ���") ) 
                return 1;

        level1 = me->query_skill("xiantian-gong", 1);
        level2 = me->query_skill("taoism", 1);
        level3 = me->query_skill("quanzhen-jian", 1);

        if ( level1>300 && level2>300 && level3>300 && random(50) == 1 && !me->query_temp("quanzhen/shentong_paper") ) 
        {
	        paper=new(__DIR__"obj/shentong_paper");
                if ( !paper ) return 1;

                add("paper_count", -1);
                me->set_temp("quanzhen/shentong_paper", 1);

                message_vision(HIG"$N�����������ص�һ�ģ����ѵı��Ϻ�Ȼ���˿�����¶��һС��˿�\n"NOR,me);
                write("����ϸ�Ľ�˿����һ����������������ļ����������ķ����ƺ�������\n");
                write("��һ����У���ȴ������¡�\n");
                message_vision("$N��æ�������պá�\n",me);
                paper->move(me, 1);
        }

        return 1;
}
