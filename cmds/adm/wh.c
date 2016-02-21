#include <ansi.h>

inherit F_CLEAN_UP;

#define MR 15

int help();

int main(object me,string arg)
{
	string str;
	object env,*tmp=({});
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;
	if(!arg)
		return help();
	str=NOR "��ʼ����(���ֻ��"+MR+"���������)��\n";
	foreach(object ob in objects())
	{
		if(ob->id(arg) && sizeof(tmp)<MR)
			tmp+=({ob});
	}
	if(sizeof(tmp)<1)
		str+="û���������κν����\n";
	else	
		foreach(object ob in tmp)
		{
			env=environment(ob);
			if(objectp(env))
			{
				str+="\n����"+ob->name()+"("+ob->query("id")+") Դ�ļ� --- "+HIY+file_name(ob)+NOR"\n";
				str+=sprintf("--- %s(%s) Դ�ļ� --- "+HIY+"%s\n"NOR,
					stringp(env->name())?env->name():(stringp(env->short())?env->short():"����"),
					stringp(env->query("id"))? env->query("id"):"0",
					file_name(env)  );
				while(objectp(env=environment(env)))
					str+=sprintf(" �� %s(%s) Դ�ļ� --- "+HIY+"%s\n"NOR,
					stringp(env->name())?env->name():(stringp(env->short())?env->short():"����"),
					stringp(env->query("id"))? env->query("id"):"0",
					file_name(env)  );
			}
			else str+="\n�����޻������"+ob->name()+"("+ob->query("id")+") Դ�ļ� --- "+HIY+file_name(ob)+NOR"\n";
		}
	me->start_more(str);
	return 1;
}

int help()
{
	write("\n������wh <id>��������Ϸ��ָ��ID�Ļ������������ʾ15�������\n");
	return 1;
}