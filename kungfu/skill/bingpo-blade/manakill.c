// made by cii for snow
#include <command.h>
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
       string msg;
       int ski_value, max_lv;
       ski_value= random(me->query_skill("bingpo-blade",1));
       max_lv=me->query_skill("bingpo-blade",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ħ��ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
  
/*
        if( me->query_skill_mapped("blade")!="bingpo-blade" )
         return notify_fail("��û��װ�����ƺ����� \n");
*/
   if( me->query_skill("bingpo-blade",1)<100 )
         return notify_fail("��ı��ƺ������ɲ��㡣 \n");

   if( me->query_skill("blade",1)<100 )
         return notify_fail("��ĵ��������á� \n");
   if(me->query("neili")<1000)
         return notify_fail("�������������\n");
   if( target->is_busy() )
      return notify_fail(target->name() + "Ϊ�˶�����ɱ��,Ŀǰ���Թ˲�Ͼ!\n");
msg = HIY "$N�Բм���,��Ѫ��ת����ɱ����\n
            ����$N���Ϸ���һ��ǿ���ɱ������\n
    ��$N����ɱ���𽥵ؾۼ���˫��,��˫�����γ�����ħ����\n
            $Nٿ�ش��һ������ħ �� ɱ����\n\n" NOR;

     if( ski_value +50 < random(max_lv) && me->query("combat_exp")>2000000){
     msg += HIR BLINK "$NͻȻ��ͷһ��������ֻ��$N�������һ��Ѫ����$n��ȥ����\n
����ħ��ɱ֮
            ����ɱ�� ��ħ Ѫ �� ɱ��\n\n
$n�⵽ǰ��δ�еĴ��,��$NҲ���˲��ᡣ\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") / 20 + 3);
     target->receive_damage("qi",target->query("max_qi")*70/100);
     me->receive_damage("qi",me->query("qi")*30/100);
     me->add("neili",-50);  
     }
   else if( ski_value < 20 ){
      msg +="$N������ת����ɱ��������,�Ե��˺���Ӱ�졣\n";
      me->receive_damage("qi",me->query("qi")*1/100);
      me->add("neili",-50); }
     
    
    else if( ski_value <  70 ){
     msg += HIM "��һ�� ��ħ���޳���\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 1);

     me->add("neili",-me->query("max_neili")*2/10);    }
    
    else if( ski_value <  90 ){
     msg += HIG "�ڶ��� ����ħɷ��\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 1);
 
     me->add("neili",-me->query("max_neili")*3/10);    }
     
     else  if( ski_value < 100 ){
     msg += HIC "������ ���̻�ħ��\n\n$n�ܵ��˺�,�������á�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 1);

     me->add("neili",-me->query("max_neili")*4/10);  }

     else if( ski_value <  120 ){
     msg += HIB "������ ����ħ������\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 1);

     me->add("neili",-me->query("max_neili")*5/10);    }

     else if( ski_value <  140 ){
     msg += HIW "������ ����ħ�ƿա�\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 2);

     me->add("neili",-me->query("max_neili")*6/10);    }


     else if( ski_value <  160 ){
     msg += CYN "������ ��Ⱥħ���衻\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 2);

     me->add("neili",-me->query("max_neili")*7/10);    }

     else if( ski_value <  180 ){
     msg +=  YEL "������ ���켫ħɱ��\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 2);

     me->add("neili",-me->query("max_neili")*8/10);    }

     else if( ski_value <  200 ){
     msg += BLU "�ڰ��� ����ħ�����꡻\n\n$n�ܵ��˺�,�������ã�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 2);

     me->add("neili",-me->query("max_neili")*9/10);    }

     else                    {
     msg += RED "�ھ��� ����ħ��תҵ��\n\n$n�ܵ��˺�,�������á�\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") /100 + 2);
 
     me->add("neili",-me->query("max_neili")*9/10);  }

     message_vision(msg, me, target);
        return 1;
}
