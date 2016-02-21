// huntian-qigong.c
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "jiaohua-neigong";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("huntian-qigong", 1);
        return lvl * lvl * 15 * 9 / 100 / 200;
}

int valid_learn(object me)
{
        if (me->query_skill("force", 1) < 30)
                return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ����������\n");

	    return 1;
}

int practice_skill(object me)
{
	    return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"huntian-qigong/" + func;
}
mapping heal_msg(object me)
{
        return ([
                "start_self"     : HIW + BLK "�㻺�������������Ⱥ����������칦��������ȫ��\n" NOR,
                "start_other"    : HIW + BLK + me->name() + "����������ͷ����ʱð����������ͷ�������£�ȫ��������ѡ�\n" NOR,
                "finish_other"   : WHT "����"+ me->name() + "����һ��쳱ӿ�ϣ��㼴��ȥ���ֳɻҰף������ף��ױ���ת�����Σ�վ��������\n" NOR,
                "unfinish_other" : HIW + BLK + me->name() + "�۾���������һ�ߣ�����һ̲��Ѫ��վ��������\n" NOR,
        ]);
}

mapping exercise_msg(object me)
{
        return ([
                "apply_short"   : "�����⣬���۷��衣",
                "start_self"    : "���������£�˫��ƽ����˫ϥ��Ĭ��ھ�����ʼ��������ķ���\n",
                "start_other"   : me->name() + "�������������£�˫��ƽ����˫ϥ���촽΢΢���������ϵ����ۿ�ʼ�Ķ�������\n",
                "halt_self"     : "����ɫһ����Ѹ��������վ��������\n",
                "halt_other"    : "ֻ��" + me->name() + "��ɫһ�������˿�����վ��������\n",
                "finish_self"   : "�������뵤�������ת�����������չ���˫��̧��վ��������\n",
                "finish_other"  : "ֻ��" + me->name() + "˫��̧��վ��������������������������\n"                
        ]);
}

