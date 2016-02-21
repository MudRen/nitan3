// fanchang.c ��
// by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, j, skill, damage;

        skill = me->query_skill("force");
        if( (int)me->query("neili") < skill * 3 )
                return notify_fail("�������������\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("shen") < 10000 )
                return notify_fail("��������Ҫ����Ķ���������ɫ����������ʩչ��\n");
                
        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( me->query_skill("buddhism", 1) < 100 )
                return notify_fail("���������ķ���δ��ȫ���򣬺���ʩչ�����󳪾�ѧ��\n");
                
        if( me->query_skill("yijinjing", 1) < 100 )
                return notify_fail("�����׽��δ��ȫ���򣬺���ʩչ�����󳪾�ѧ��\n");
        
        me->add("neili", -skill/2);
        me->start_busy(1);

        message_combatd(YEL"\n$N�������һ��������¶����һ��"BLINK+HIY"�����֡��ӡ���"YEL"�����������ƣ������˶�Ϊ֮һ��\n\n" NOR, me);

        if( intp(j = me->query_temp("yueyin")) 
        && me->query_skill("yijinjing", 1) > 200
        && me->query_skill("buddhism", 1) > 200 )
        {
                me->add_temp("apply/dex", j );
                me->add_temp("apply/defense", j*2 );
                me->clear_condition("no_perform");
                me->delete_temp("yueyin");
                message_combatd(HIW"$N�����˲Ϣ֮��������䣬�ָ������ǣ�\n\n"NOR, me);
        }
                
        ob = all_inventory(environment(me));
        
        for(i=0; i<sizeof(ob); i++) {
                if( !ob[i]->is_character() || !living(ob[i]) || ob[i]==me ) continue;
                if( skill < ob[i]->query_skill("force")/2 ) continue;
                if( intp(j = ob[i]->query_temp("yueyin")) 
                && me->query_skill("yijinjing", 1) > 200
                && me->query_skill("buddhism", 1) > 200 ){
                        ob[i]->add_temp("apply/dex", j );
                        ob[i]->add_temp("apply/defense", j*2 );
                        ob[i]->clear_condition("no_perform");
                        ob[i]->delete_temp("yueyin");
                        tell_object(ob[i], HIW"�������˲Ϣ֮��������䣬�ָ������ǣ�\n\n"NOR);
                        continue;
                }
                
                if( ob[i]->is_fighting() && !ob[i]->is_killing()){
                        if(ob[i]->query("shen") > 0 ){
                                ob[i]->remove_all_enemy();
                                message_vision("\n$N�ܵ�$n���У��������һԾ������սȦ�����ˡ�\n", ob[i], me); 
                                continue;
                        }
                        else if(ob[i]->query("shen") > -10000 && me->query("combat_exp") > ob[i]->query("combat_exp")){
                                ob[i]->remove_all_enemy();
                                ob[i]->add("shen", skill*10);
                                message_vision("\n$Nȫ��һ������а���Լ�������սȦ�����ˡ�\n", ob[i], me); 
                                continue;
                        }
                        else if( me->query("combat_exp") > ob[i]->query("combat_exp")*2){
                                ob[i]->remove_all_enemy();
                                message_vision("\n$N���һ������������$n�����ˣ����ǲ����д��д���ˡ�\n", ob[i], me); 
                                continue;
                        }
                }
              
                damage = skill * 2;
                if( random(skill) > ob[i]->query_skill("force")/2 && ob[i]->query("shen") < 0 ) {
                        ob[i]->receive_damage("jing", damage/2, me);
                        if(ob[i]->query("jing") < 10) ob[i]->set("jing", 10);
                        ob[i]->add("neili", -damage);
                        if(ob[i]->query("neili") < 20) ob[i]->set("neili", 20);
                        tell_object(ob[i], "���������һ��ȫ�����һ����亹��\n");
                }
                if( ob[i]->is_killing(me->query("id")) ){
                        if(random(2) == 1)
                                ob[i]->apply_condition("no_perform", 2+random(2)+ob[i]->query_condition("no_perform"));
                        else    ob[i]->apply_condition("no_exert", 2+ob[i]->query_condition("no_exert"));
                        tell_object(ob[i], "��һ�����ܾ���������һ��˵������ѹ�ȸУ�ʹ��е��ܲ������\n");
                        continue;
                }
                
                if( userp(ob[i]) && ob[i]->query("shen") < 0 && random(3) == 1) {
                        message_vision("$N���һ��������죡�ǵ�"+RANK_D->query_self_rude(ob[i])+"����\n", ob[i]); 
                        COMBAT_D->do_attack(ob[i], me, ob[i]->query_temp("weapon"), 1);
                }
                
        }
        return 1;
}

int help(object me)
{
        write(HIY"\n�׽֮������󳪡���"NOR"\n");
        write(@HELP
        ��գ�����֮�⣬���ٽ�ǧ������ת�����������Բ��������Խ��֮�ᣬ��
        �����壻�Խ��֮�����������á������ǽ�һ�����������֮�⳪������
        �з�ħ�񹦣��ܿ�����ħ��������־��ʹ����������
        
        Ҫ��  �׽�ȼ� 100 ���ϣ�
                �׽�ȼ� 100 ���ϣ�
                ���� 10000 ���ϣ�
                ������� 1500 ���ϣ�
                ����Ϊ�ڹ��ȼ��������ϡ�
HELP
        );
        return 1;
}

