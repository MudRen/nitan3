inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
        return 1;
        return force == "xiantian-gong" ||
               force == "quanzhen-xinfa"  ||
               force == "duanshi-xinfa";
}

int query_neili_improve(object me)
{
    	int lvl;

    	lvl = (int)me->query_skill("kurong-changong", 1);
    	return lvl * lvl * 15 * 15 / 100 / 200;
}

int valid_learn(object me)
{
        int nb, nk;
        int lvl = (int)me->query_skill("kurong-changong", 1);
        
        if (me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ���������������������Ŀ���������\n");

        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");
                
        nb = (int)me->query_skill("buddhism", 1);
        nk = (int)me->query_skill("kurong-changong", 1);
        
        if (nb < 120 && nb <= nk)
                return notify_fail("��������ķ���Ϊ�������޷���������Ŀ���������\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"kurong-changong/" + func;
}
