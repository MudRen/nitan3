inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�������");
        set("long",
"������ͨ�����ξ��ǵ����������������ս��ֹ���Եø���ػ���\n"
"����ʱ����������ƥ�ɱ�����������һ�����̣���;��ʱ�����˴�����֣�\n"
"��������ͣ���ĺá�\n"
);
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : __DIR__"yidao2", 
                "west"  : __DIR__"yidao2",
        ]));

        setup();
}

void init()
{
        object me=this_player();

        if (! me->is_busy())
        me->start_busy(random(1));


        if( me->query_temp("yidao/mark_steps") > 11 )
        {
         me->move(__DIR__"yidao3");
         me->delete_temp("yidao");
         tell_object(me,YEL"һ·�糾����֮�������Ѿ�������ǰ��......\n"NOR);
         return;
        } 

        if( me->query_temp("yidao/mark_steps") < -11 )
        {
         me->move(__DIR__"yidao1");
         me->delete_temp("yidao");
         tell_object(me,YEL"һ·�糾����֮�������Ѿ�������ǰ��......\n"NOR); 
         return;
        }

        tell_object(me,YEL"�����ӱޣ�һ·�ɳ��������......\n"NOR);

}

int valid_leave(object me,string dir)
{
        object dadao,*env;
        int i,flag;
  
        env=all_inventory(environment(me));   
        flag=0;

        for(i=0;i<sizeof(env);i++)
        {
         if(objectp(env[i]) && env[i]->query("id")=="jiangyang dadao"
            && env[i]->query("killer")==me->query("id") )
         flag=1;
        }

        if ( me->query_temp("warquest/purchase") && random(12)>10 )
        {
                dadao=new(__DIR__"npc/dadao");
                dadao->set_from_me(me);
                dadao->set_temp("warquest/party","meng");
                dadao->move(environment(me));
                dadao->kill_ob(me);
                me->kill_ob(dadao);
        return notify_fail("��Ȼ��·�ߴ�����ɱ��һ·����\n");
        } else
        if(flag)
        return notify_fail("���������ס�����ȥ·��\n");

       if( dir == "east" )
       me->add_temp("yidao/mark_steps",-random(2));
       if(  dir == "west" )
       me->add_temp("yidao/mark_steps",random(2));
       return ::valid_leave(me,dir);
}

