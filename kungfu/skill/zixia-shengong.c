// Created by Lonely (06/04/2002)
// zixia-shengong.c ��ɽ ��ϼ��

inherit FORCE;

#include <ansi.h>

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_force(string force) 
{
        return 1; 
}

int query_neili_improve(object me) 
{
        int lvl; 
        lvl = (int)me->query_skill("zixia-shengong", 1); 
        return lvl * lvl * 20 * 15 / 100 / 200; 
}

int valid_learn(object me)
{
        int i, t, level;
        
        level = (int)me->query_skill("zixia-shengong", 1);
        
        if (level <= 100)
                for (i = 1; i < level / 10; i++)
                        t *= 2;
        
        if (me->query("gender") == "����" && level > 49)
                return notify_fail("�����޸����ԣ���ϼ�����Ѹ���һ��¥��\n");

        if ((int)me->query_skill("zixia-shengong", 1) >= 45 
        &&  (int)me->query_skill("huagong-dafa", 1) >= 100
        &&  (int)me->query_int() < 100 )
                return notify_fail("���ܸ����а���ڹ�ǣ������ϼ��ˮ�����ݣ�������������Ѹ���һ��¥��\n");

        if (level <= 100)
        {
                if (level > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (level - 100) * 1000)) 
                        return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�\n");
        }
        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("��ϼ��ֻ����ѧ(learn)�������������ȡ�\n"); 
}

string exert_function_file(string func)
{
        return __DIR__"zixia-shengong/" + func;
}

mapping heal_msg(object me)
{
        return ([
                "apply_short"  :  "���������������֡�",
                "start_self"    : MAG "��͵���������ʹ��ϼ�����ˣ���Ϣ�������ƣ�����ģ����񽬣������أ�ߵ��������ͨ�������硣\n" NOR,
                "start_other"   : MAG + me->name() + "�͵�������������������ʼ�˹����ˡ�\n" NOR,
                "finish_self"   : MAG "�������ϼ�����˶�ʱ��һ��������������ת�ް��������Ѿ�ƽ��������վ��������\n" NOR,
                "finish_other"  : MAG "����"+ me->name()+ "ͷ����������������������ʢ����Ȼ��һ����Х��վ��������\n" NOR,
        ]);
}

mapping exercise_msg(object me)
{
        return ([
                "apply_short"  : "˫����������������������֡�",
                "exercise_msg" : MAG "���˹�������Ϣ�������ƣ�����ģ����񽬣������أ�ߵ��������ͨ�������硣\n" NOR,
                "start_self"   : MAG "����Ϣ�������������������ִ�������֮�ϣ�����ǰ���˸�������������Ϣ���߸���������\n" NOR,
                "start_other"  : MAG + me->name() + "����������������������������һ��������\n" NOR,
                "halt_self"    : MAG "������һ��������Ϣѹ�ص��˫��һ��վ��������\n" NOR,
                "halt_other"   : MAG + me->name() + "����һ������˫��һ��վ��������\n" NOR,
                "finish_self"  : MAG "�㽫��Ϣ����һ�����죬ֻ�е�ȫ��̩ͨ��������ů���ģ�˫��һ�֣�����վ��������\n"NOR,
                "finish_other" : MAG + me->name() + "��������������ȥ��վ��������\n" NOR,
        ]);
}

