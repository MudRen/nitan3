
void init()
{
        add_action("do_cai","cai");
}

int do_cai(string arg)
{
        object me=this_player();
        object ob;
        object ob1;
        if ( (int)me->query_temp("caiyao")<1)
                return notify_fail("�������˷�ʱ���ˣ����߰ɡ�\n");

        if (!arg || arg != "yao")
                return notify_fail("��Ҫ��ʲô��\n");

        if ( me->is_busy() )
                return notify_fail("�����ң��ȱ𼱡�\n");
       
        if ( (int)me->query("jing")<40)
                return notify_fail("��̫���ˣ���Ϣ�°ɡ�\n");

        if ( (int)me->query("qi")<40)
                return notify_fail("��̫���ˣ���Ϣ�°ɡ�\n");

        if ( (int)me->query_temp("caiyao")==2)
                return notify_fail("�������֣���ȥ���˰ɡ�\n"); 

        message_vision("$Nſ�ڵ��ϣ��ɴ����۾��ڲݴ�����Ѱ��ҩ�ݣ�����©����Ŀ�ꡣ\n",me); 

        me->start_call_out((: call_other, __FILE__, "cai", me :), 3); 
        me->start_busy(4); 
        return 1;
}
 
int cai(object me)
{ 
        object ob;
        object ob1;        
        if (random(10)<7)
        {
        me->receive_damage("jing",10+random(20));
        me->receive_damage("qi",10+random(20));   
        message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);
        }

        if (random(20) ==1 && ! present("du she", environment(me))) 
        {         
        tell_room(environment(me),HIR"�ݴ���һ��ζ���ͻȻ���һ�����ߡ�\n"NOR );
        ob=new("/d/beijing/npc/liandan_dushe");
        ob->move(environment(me));
        }

   else if(random(20)==1 && ! present("du langzhong", environment(me))) 
        {         
        tell_room(environment(me),HIR"���Ӻ���ͻȻ����һ�������ɲ�����ӣ�����һ�Ѷ̵�����������\n"NOR );
        ob=new("/d/beijing/npc/liandan_langzhong");
        ob->move(environment(me));
        }
   else
        { 
        ob1 = new("/d/beijing/npc/dan/caoyao");
        ob1->move(me);
        me->receive_damage("jing",10+random(20));
        me->receive_damage("qi",10+random(20));
        me->add_temp("caiyao", 1);
        message_vision(HIG"$N���˰��죬���ڷ�������һ������������Ĳ����в�ͬ��
С������ؾ��˳�����\n"NOR,me); 
        }
        me->stop_busy();
        return 1;
       
}
