// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// beiming-shengong.c ��ڤ��

#include <ansi.h>;
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }
int valid_force(string force) { return 1; }

int query_neili_improve(object me)  
{
        int lvl; 
        
        lvl = (int)me->query_skill("beiming-shengong", 1); 
        return lvl /10 * lvl /10 * 28 * 15 / 10 / 20;  
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("beiming-shengong", 1);
        
        if (me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ���������������������ı�ڤ�񹦡�\n");
                
        if ((int)me->query("con") < 24) 
                return notify_fail("���˰ɣ���������ǲ��ã���ǿѧ�ˡ�\n"); 
        
        if ((int)me->query("int") < 30)
                return notify_fail("���˰ɣ����������Բ��ã���ǿѧ�ˡ�\n"); 
                
        if (me->query_skill("force", 1) <= lvl)
                return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
                
        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("��ڤ���޷��򵥵�ͨ����ϰ������\n");
}

string exert_function_file(string func)
{
        return __DIR__"beiming-shengong/" + func;
}

int difficult_level()
{
        return 400;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int jiali;

        if ((int) me->query_skill("beiming-shengong", 1) < 80 ||
            ! living(me))
                return;

        if ((jiali = ob->query("jiali")) < 1)
                return;

        ap = ob->query_skill("force") + ob->query_skill("dodge");
        dp = me->query_skill("force") + me->query_skill("dodge");
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage ]);

                switch (random(3))
                {
                case 0:
                        result += ([ "msg" : HIM "$N" HIM "ֻ��������ԴԴ��к"
                                             "�����ɵô��һ����\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIM "$N" HIM "ֻ���÷�����������"
                                             "��ʯ���󺣣���֪���١�\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : HIM "$N" HIM "��ס�߶�����������"
                                             "ֻ����$n���ƺ���������\n" NOR ]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage, int damage_bonus, int factor)
{
       // int percent,force1,force2,dodge1,dodge2,lv1,lv2;
       int force1,force2,dodge1,dodge2,lv1,lv2;

        force1 = victim->query_skill("force"); 
        force2 = me->query_skill("force"); 
        dodge1 = victim->query_skill("dodge"); 
        dodge2 = me->query_skill("dodge"); 

        lv1= force1*dodge1;
        lv2= force2*dodge2;

        lv2 = lv2*3/2;
        if ((int)victim->query_skill("beiming-shengong",1)>100
         && !me->query_temp("weapon")
         && me->query("max_neili")>500
        && lv1/2 + random(lv1) > lv2 )
        {
                victim->add("max_neili", 1*(5+((int)victim->query_skill("beiming-shengong",1)/100)));
                me->add("max_neili", -1*(5+((int)victim->query_skill("beiming-shengong",1)/100)));

                if (victim->query("max_neili") > (int)victim->query_skill("force") * (int)victim->query("con") * 2 / 3 * 2)
                        victim->set("max_neili",victim->query_skill("force") * (int)victim->query("con") * 2 / 3 * 2);

                return ([ "msg": HIR "$N��������һ�����У�ȴ����ֻ��Ϣ��һ����һ��������$n���˹�ȥ��\n" NOR ]);
        }
        
        return damage;
}
