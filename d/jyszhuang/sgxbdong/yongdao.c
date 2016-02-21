#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", YEL"�ܶ�"NOR);
        set("long", @LONG
�������Ϲ����������ܶ������е���ɭ֮�����أ���������ɱ���ܲأ�
�Բ�������ʱ����ɱ��֮������������С��Ϊ�    
LONG );
        set("indoors", "city");
        set("exits", ([
                "northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
        ]));
        set("no_fly",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if(present("wei shi",environment(me)))
        return notify_fail(HIY"�����ʿŭ�ȵ������������˭Ҳ�����ܣ�\n"NOR);
        if (random(30) > 14) 
        me->add_temp("mark_yongdao/steps",1);
        if (random(30) < 10)   
        me->add_temp("mark_yongdao/steps",-1); 
        if (me->query_temp("mark_yongdao/steps") <= -6)
        {
        call_out("go_inside",1,me);
        me->delete_temp("mark_yongdao/steps");
        return 1;
        }  
        if (me->query_temp("mark_yongdao/steps") >= 6)
        {
        call_out("go_out",1,me);
        me->delete_temp("mark_yongdao/steps");
        return 1;
        }
        if (random(10) > 7)
        new(__DIR__"npc/killer")->move(environment(me));  
        return ::valid_leave(me, dir);
}
int go_out(object me)
{
        write("��Ȼ�㷢����ǰһ������֪�������������˻�ɽ����֮�ϡ�\n");   
        me->move(__DIR__"wudao");
        return 1;
}

int go_inside(object me)
{
        write("���۵ð���������߳����ܶ���\n");       
        me->move(__DIR__"dongkou");
        return 1;
}

