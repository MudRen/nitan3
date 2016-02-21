//Code of Shenzhou
//coding by Slow
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me);
void checking(int del_time,object me);

int exert(object me, object target)
{
          int lv;

          if (!me->query("canewhua"))  return notify_fail("�㻹û�õ������󷨵��洫��\n");

          /*
          if (me->query("family/family_name") != "������")
                  return notify_fail("�������������ɵĶ��ž�ѧ��\n");
          */

          if (environment(me)->query("no_fight") && file_name(environment(me)) !="/d/city/biwu_dating")
                  return notify_fail("�����ﲻ�����û����󷨡�\n"); 

          lv = (int)me->query_skill("huagong-dafa", 1);
 
          if( target == me) target=offensive_target(me);
          if( !target ) target = offensive_target(me);
          if( !target ) target = me->select_opponent();

          if( me->query_temp("newhua") )
                    return notify_fail("���Ѿ�ʩչ���������ˣ�\n");


          if( me->query_skill("huagong-dafa", 1) < 360 )
                    return notify_fail("��Ļ����󷨻��δ����\n");

          if( me->query_skill_mapped("force") != "huagong-dafa")
                    return notify_fail("������ʹ���ڹ����ǻ����󷨣��޷�ʩչ������\n");

          if( me->query("neili") <= 3000 )
                  return notify_fail("�������������ʩչ�����󷨣�\n");

          if( me->query("jingli") <= 900 )
                  return notify_fail("��ľ���������ʩչ�����󷨣�\n");

          if( me->query_skill_mapped("sword") == "pixie-jian" ||
              me->query_skill_mapped("parry") == "pixie-jian" ||
              me->query_skill_mapped("dodge") == "pixie-jian" )
          return notify_fail("��а�����뻯���󷨵�����������㣣��޷�ͬʱʩչ�����󷨺ͱ�а������\n");
          if(me->is_busy())
                  return notify_fail("����æ����,û�취ʩչ������! \n");

message_vision(
HIB"$NͻȻ��ɫ������������Ц��������Ȼ�ӿ�������һ˫������ú������졣\n"
HIG"ֻ��$NԽ��Խ���������ߣ������󷨼���������������$N����ֻ���ۣ������ķ緫��\n"
HIB"�Ĵ���������������������һ�ɹ���ӿ���ȵ����ˡ�\n" NOR, me, target ); 


          me->set_temp("newhua",(int)me->query_skill("huagong-dafa", 1)/20+10);
          call_out("checking", 1, 1, me); 
          return 1;
}


void checking(int del_time,object me)
{
          int num,ap,dp,dmg,the_time;
         int exp_div;
          object target;

          if (!me || !me->query_temp("newhua")) return;
          target = me->query_temp("offensive_target");
          num=(int)me->query_temp("newhua");

          if( me->query_skill_mapped("sword") == "pixie-jian" ||
              me->query_skill_mapped("parry") == "pixie-jian" ||
              me->query_skill_mapped("dodge") == "pixie-jian" )
          {
                  me->delete_temp("newhua");
                  message_vision(HIY "\n$N�ñ�а�����뻯���󷨵�����������㣣�����ͬʱʩչ�����󷨺ͱ�а��������\n"NOR, me);;
                  return;
          }
          me->set_temp("newhua",me->query_temp("newhua")-del_time);
          if( wizardp(me) )  tell_object(me,sprintf("<����ʱ�仹ʣ%d��>\n",num));
          if( num<1 ) 
          {
                  message_vision(YEL"$N����������֧�������ѽ��ѷ��ӵ����µġ������󷨡������ջص��\n"NOR, me);
                  me->delete_temp("newhua");
                  return;
          }
          if( !target ) target = offensive_target(me);
          if( !target || !target->is_character() || !me->is_fighting(target) )
          {
                  call_out("checking", 1, 1, me); 
                  return;
          }


          if( !living(me) || me->is_ghost()  )
          {
                  remove_effect(me);
                  return;
          }

        if (me->query("combat_exp") > 10000000)
                exp_div = 10000;
        else
                exp_div = 1000;
          ap = me->query("combat_exp")/exp_div;
          ap += me->query_skill("force");
          ap += me->query("kar")*50;
          ap += me->query_skill("poison",1)*2;
          dp = target->query("combat_exp")/exp_div;
          dp += target->query_skill("force");
          dp += target->query("kar")*50;
          dp += target->query_skill("dodge",1)*2;

          if (random(16)>7)
          {
                  if(ap > (dp/2 + random(dp)))
                  {
                          message_vision( 
HIR "$n�ոտ���$N��ֻ����һ�������ޱȵ���������Ҫ���Լ������ȥ����æ�˹�������\n"
CYN "$N���һ�����������ڵ�˫����ץס$n�����Ŵ�Ѩ��$n������費�ɷ��������ҽС�\n" NOR, me, target ); 
                          tell_object(target, HIR "��ͻȻ����ȫ�����������Ʊ�ӿ��������֫��������Ҳʹ����������\n" NOR); 
                          tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR); 
                        dmg=(int)me->query_skill("force")*3 +random(1+(int)me->query_skill("force"));
                          target->receive_damage("qi", dmg, me ); 
                          target->receive_wound("qi", dmg/2+random(dmg/2), me); 
                          me->add("qi", (int)me->query_skill("force") ); 
                          COMBAT_D->report_status(target);
                          target->start_busy(random(3));
                          if( !target->is_killing(me) ) target->kill_ob(me);
                  }
         }
         else
         {
                  message_vision( 
HIB"��������"+HIW+"����"+HIB+"��$N�İٻᡢ����̫��Ѩ��������а�ֱ��ü�ġ�\n"
HIB"$N��ͷ����������һ������֮����ͻȻ����һת���ۿ���仯��������Ӱ����Ӱ������������צ��$nץȥ��\n"
HIB"$N��ɫԽ�����������ϵ�����������Ĺĵ�֮�·����̶������ŵ�$n�ķ����ң����Ʋ��ɵü�����������\n"
HIW"$N��$n�������ƣ���Хһ������������˫�������¸�ǽһ�����˹�ȥ��$nֻ�ø��ȴ������Ѩ��¶���š�\n" NOR, 
                           me, target ); 
                  if(ap > (dp/2 + random(dp)))
                  {
                           message_vision( 
                              HIR "$N�پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������\n\n" NOR, 
                              target ); 
                           tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR); 
                           if ((int)target->query("neili") > (int)me->query_skill("force")*2) 
                           { 
                                   target->add("neili", -(int)me->query_skill("force")*2 ); 
                                   me->add("neili", ((int)me->query_skill("force"))); 
                           }else{ 
                                   me->add("neili", ((int)me->query_skill("force"))/2); 
                                   target->set("neili", 0); 
                           } 
                  }
                  if( !target->is_killing(me) ) target->kill_ob(me);
        }
        the_time = 3+random(3);
        call_out("checking", the_time, the_time, me); 
        return;
}

void remove_effect(object me) 
{
        if (!me) return;
        me->delete_temp("newhua");
        me->start_busy(1);
}

