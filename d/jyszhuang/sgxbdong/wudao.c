#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
string look_shibi();
void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG
�����Ѿ��ǻ�ɽ֮���ˣ���ɽ������ȥ��ɽ�����������λ������죬
���˺��������������һ��ʯ��(bi)����ͺͺ�ط������ۣ������¾���
��ɽ��������̨�����μӱ����������������ڴ˴�����һ�������
��������α����ȫ������������쿪ʼ�ˡ�
LONG );

        set("outdoors", "city");
        set("item_desc", ([
                "bi" : (: look_shibi :),   
        ]));

        set("objects", ([
        ])); 
        set("exits", ([
           "down"  : "/d/huashan/houzhiwangyu",
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
}

void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_break", "break");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","songxin");
        add_action("do_quit","yun");
        add_action("do_quit","learn");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian");
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_qu
it","jiao");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ڸ�ɶ����ѽ��ר�Ŀ�����ɣ�\n");
        return 1;
}
string look_shibi()
{
       return
HIW"\n����ϸ�Ĳ鿴��ʯǽ��һ��������������ʯǽ���ƺ��пն��Ļ�����\n"
+"�㲻������������������(break)����\n"NOR;
}

int do_break(string arg)
{
        object me=this_player();

        if (query("exits/enter"))
        return notify_fail("ǽ�ϵ�ʯ���Ѿ����ˡ�\n");

        if (!arg || (arg != "bi" && arg != "shi bi"))
        return notify_fail("��Ҫ��������ʲô��\n");

        if(me->query("neili")<me->query("max_neili")
           || me->query("neili")<2000)
        return notify_fail("����������������ӯ���޷���ʯ�ڣ�\n");
        message_vision(HIY"$N˫�����㹦�������һ�����͵ĳ�ʯ�ڻ�ȥ��\n"NOR,me);
        if(!me->query("zhuanshi/jineng"))
        message_vision(
        HIW"ֻ�����һ�����죬ֻ����ɽ��¡¡����ȵ�ҷɣ�\n"NOR,me);
        else
        {
        message_vision(
        HIW"ֻ������һ�����죬ʯ�ڻ����ش��ˣ�¶��һ����Ѩ��\n"NOR,me);
        set("exits/enter", __DIR__"dongkou.c");
        call_out("hole_close",5);
        }
        me->start_busy(5);
        me->set("neili",0);
        return 1;
}

int hole_close()
{
        message_vision(
        HIW"ֻ��ʯ��¡¡���죬��Ѩ�ֻ����ϱ��ˣ�\n"NOR,this_object());
        delete("exits/enter");
        return 1;
}

