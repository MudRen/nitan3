// by Lonely

#include <ansi.h>
void remove_effect(object me,int count);

int exert(object me)
{
/*
        if ( !me->is_fighting())
                return notify_fail("��ֻ����ս����ʹ�á���ղ������񹦡���\n");
*/

        if( (int)me->query_skill("yijinjing", 1) < 400 )
                return notify_fail("����׽�ڹ���Ϊ�������޷�ʹ�á���ղ������񹦡���\n");

        if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("�����ڹ��С���ղ������񹦡���\n");

        if( (int)me->query_con() < 40 )
                return notify_fail("��ĸ���̫�ͣ������޷�ʹ�á���ղ������񹦡���\n");
 
        if( (int)me->query("neili") < 1000 )
                return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á���ղ������񹦡���\n");   
    
        if( (int)me->query("max_neili") < 3800 )
                return notify_fail("���������Ϊ��ô�����ʹ�á���ղ������񹦡���\n");   
        
        if( me->query_temp("jingang"))
                return notify_fail("�������������أ�\n");
                                                                                                
        if( me->query_temp("sl/jiuyang"))
                return notify_fail("���������á����־����񹦡���\n");
       
        message_combatd(HIY"\n$NͻȻ����һ������Ŀ¶�ȹ⣬���΢Ц��������ת����ʹȫ�����±����������ǡ���ղ������񹦡���\n\n" NOR, me);
        me->start_busy(1);

        me->set_temp("jingang", 1);
        me->set_temp("nopoison", 1);
        me->add_temp("apply/armor", me->query_skill("yijinjing", 1)/2); 
        me->add("neili", -500);  
          
        call_out("remove_effect", 1, me, me->query_skill("yijinjing", 1)/2+20);
      
        return 1;
}

void remove_effect(object me, int count)
{
        if( !me) return;
        if (count < 0)
        {
                me->delete_temp("nopoison");
                me->delete_temp("jingang");
                me->add_temp("apply/armor", - me->query_skill("yijinjing", 1) / 2);
                message_vision(HIR"\n$N˫�ֺ�ʮ��ɢȥ��������ȫ�����µġ���ղ������񹦡���\n"NOR, me);    
                return;
        }
        else {
                call_out("remove_effect", 1, me,count -1);
        }
}

int help(object me)
{
        write(HIY"\n�׽֮����ղ������񹦡���"NOR"\n");
        write(@HELP
        ��գ�����֮�⣬���ٽ�ǧ������ת�����������Բ��������Խ��֮�ᣬ��
        �����壻�Խ��֮�����������á���ղ�������Ϊ���ֵ�һ�����������
        �Ϊ����ʹ���塢���������ڣ�ѭ�򽥽�����֮�Ժ㣬���ܵ�����ħ��
        ����������
        
        Ҫ��  �׽�ȼ� 200 ���ϣ�
                ���� 40 ���ϣ�
                ������� 3800 ���ϣ�
                ���� 1000 ���ϡ�
HELP
        );
        return 1;
}

