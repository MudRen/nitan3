#include <ansi.h>

inherit F_CLEAN_UP;

int help();

int main(object me,string arg)
{
	string cmd,*res;
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;
	if(!arg)
		return help();
	if(sscanf(arg,"%s %s",cmd,arg)!=2)
	{
		write("��������\n");
		return help();
	}
	
	cmd=lower_case(cmd);
	if(cmd!="select")
		return notify_fail("��ʱ����ִ�г���select�����SQL��ѯ��\n");
	log_file("sqlcmd","\n"+ctime(time())+me->name()+"("+me->query("id")+")ִ����SQL��ѯ��\n"+cmd+" "+arg);
	res=DATABASE_D->do_sql(cmd+" "+arg);
	if(arrayp(res)&&sizeof(res))
		write("SQL��ѯ���ؽ����\n"+save_variable(res)+"\n");
	else
		write("SQL��ѯ�޷��ؽ����\n");
	return 1;
}

int help()
{
	write(NOR+"\nSQL��ѯ������԰棡Written By JackyBoy\n\n"+
		"�����﷨��"+HIG+"sql <SQL���> \n"+NOR
		"Ŀǰֻ֧��"+HIR+"select"+NOR+"��ѯ��\n");
	return 1;
}