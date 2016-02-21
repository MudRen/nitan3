// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <localtime.h>

int check_count(object me, int count)
{
	int age, tmp1, tmp2, tmp, lvl, qmdj;
	mixed *local;

	age = (int)me->query("age");
  	local = localtime(((int)me->query("birthday") - 14 * 365 * 24 * 60) * 60);
  	tmp1 = (local[LT_YEAR] % 10 + local[LT_YEAR] % 12 + local[LT_MON] + local[LT_MDAY]) % 8;
  	tmp2 = (((local[LT_HOUR] + 1) % 24) / 2) % 8;
  	tmp = tmp1 * 8 + tmp2;
  	qmdj = me->query_skill("qimen-wuxing", 1);
	lvl = 1 + random(qmdj) / 20;	

        if (tmp == count) 
        {
	        if (me->query_temp("taohua/count") == 2080) 
	        {
                        tell_object(me, 
                                HIR "���ܾ���ͻȻ���ģ�������������ͷ��һ����ѣ......����һ����������ʧ�ˡ�\n\n" NOR);
	                if (! me->query("taohua_maze"))
	                {
		                me->add("int", 1);
		                me->set("taohua_maze", age);
		                me->delete_temp("taohua/count");
                                // me->move("/d/taohua/xiangzhong");
                                me->move("/d/taohua/mudi");
	                } 
                } else
	        {
		        tell_object(me, 
		                HIW "�����һ�飬�������������·�׹......�����ʶ����ģ������......\n\n" NOR);
	    	        me->unconcious();
		        me->delete_temp("taohua/count");
		        me->move("/d/taohua/enter_m");
	        }  
        } else 
        if (me->query_temp("/taohua/count") > 2100) 
	{
	        tell_object(me, 
	                HIW "������һ�������������������ܲ���һ�������Ũ��˲������ס......\n\n" NOR);
		me->unconcious();
		me->delete_temp("taohua/count");
		me->move("/d/taohua/enter_m");
        }

	return 1;
}

void remove_effect(object me, int level)
{
        me->add_temp("apply/int", -level);
        tell_object(me, HIB "������һ�����Ժ��пտյ������ƺ���ʲ�ᶫ���������ȥ��\n" NOR); 
}
