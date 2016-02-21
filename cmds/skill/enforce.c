// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

        if( !arg || (arg!="none" && arg!="max" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("ָ���ʽ��enforce|jiali <ʹ�����������˵�>|none|max\n");

	if( !me->query_skill_mapped("force") )
		return notify_fail("������� enable һ���ڹ���\n");

	if( arg=="none" )
		me->delete("jiali");
        else
        if( arg=="max" )
                me->set("jiali", (int)me->query_skill("force") / 2);
	else {
		if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
			return notify_fail("��ֻ���� none ��ʾ���������������ֱ�ʾÿһ���ü���������\n");
		me->set("jiali", pts);
	}

	write("Ok.\n");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enforce|jiali <ʹ�����������˵�>|none|max
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�

enforce none ���ʾ�㲻ʹ�������� 
enforce max ���ʾ��ʹ����������� 

See Also: enable
HELP );
        return 1;
}
