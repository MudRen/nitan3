// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zong.c

#include <ansi.h>

void remove_effect(object me,int count);

int perform(object me, object target)
{                               
        int improve;

        if( userp(me) && ! me->query("can_perform/tiyunzong/zong") )    
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ�����־�����\n"); 
  
        if( (int)me->query_skill("tiyunzong",1) < 120 )
                return notify_fail("��������ݲ�����죬����ʹ�á����־�����\n");
                
        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("���̫���񹦵ȼ�����������ʹ�á����־�����\n");  
                
        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("����ڹ����ԣ�����ʹ�á����־�����\n");
                
        if( (int)me->query_dex() < 28 )
                return notify_fail("�����̫�ͣ�����ʹ�á����־�����\n");
      
        if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á����־�����\n");
      
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó������־�����\n");   
    
        if (me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("�����ڼ�����������ʹ�á����־���������\n");  
                                                                                               
        if( me->query_temp("zong")   )
                return notify_fail("������ʹ�������ݵ�������������־�����\n");
       
        message_combatd(HIY"$NͻȻ����һ������һ̧���͵İθ����ɣ����Ƹվ���˫�������߳���" +
                        "�������������������������������£�\n" NOR, me);
      
        improve = (int)me->query_dex() * 2;
        me->add_temp("apply/defense", improve);
        me->set_temp("zong",improve);  
        me->add("neili", -(350-(int)me->query_skill("tiyunzong",1)/10));            
        call_out("remove_effect", 1, me, improve);
        return 1;
}

void remove_effect(object me, int count)
{
        int improve;
        if( !me ) return;
        if( !intp(improve = me->query_temp("zong"))) return;
        if( !me->is_fighting()
        ||  count < 1)
        {
                me->add_temp("apply/defense", - improve);
                me->delete_temp("zong");
                tell_object(me, HIY"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
                tell_room(environment(me), HIY + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n"NOR,  ({ me })); 
                return;
        }
        call_out("remove_effect", 1 , me ,count -1);
}

int help(object me)
{
        write(WHT"\n�����ݡ��ݡ��־���"NOR"\n");
        write(@HELP
        �䵱�Ṧ��������ν�������֣������Ṧ�޳����ң��ٵ�֮ʱʹ�����ݡ���
        ����������������������Լ����Ṧ��Ч�ȼ�������ʤ������ѻ��ʡ�
        
        Ҫ��  �����ݵȼ� 120 ���ϣ�
                ̫���񹦵ȼ� 120 ���ϣ�
                �����Ṧ�ȼ� 120 ���ϣ�
                ���� 600 ���ϣ�
                ������ 28 ���ϡ�
HELP
        );
        return 1;
}

