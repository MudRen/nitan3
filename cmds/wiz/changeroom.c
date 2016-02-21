// To change a room's set
// Created by Lonely (06/19/2002)

inherit F_CLEAN_UP;
int do_one_room(object room, string arg, string i);
int main(object me, string arg)
{
	string str;
	string i;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! arg || sscanf(arg, "%s %s", str, i) != 2)
                return notify_fail("ָ���ʽ��changeroom ���� ֵ\n");
	do_one_room(environment(me), str, i);
	return 1;
}

int do_one_room(object room, string arg, string i)
{
	string file;
	string old;

        old = room->query(arg);

	reset_eval_cost();
	file = read_file(base_name(room)+".c");
	file = replace_string(file,"	set(\""+arg+"\", "+old+");\n","");
	file = replace_string(file,"	set(\""+arg+"\","+old+");\n","");
	file = replace_string(file,"	set(\""+arg+"\", \""+old+"\");\n","");
	file = replace_string(file,"	set(\""+arg+"\",\""+old+"\");\n","");
	file = replace_string(file,"setup",
	sprintf("set(\"%s\", %s);\n	setup",arg,i));

        if (write_file(base_name(room)+".c",file,1))
		write("Finished room "+ base_name(room) +"\n");
	return 1;
}

int  help(object  me)
{
write(@HELP
ָ���ʽ  :  changeroom ���� ֵ

�޸ķ������Ե�ָ�

�������ԭ���Ѿ��и����ԣ���ȷ��set("����",ֵ);֮ǰΪTab
����Ŀո񣬷�����ɾ��ԭ��������ʹ�ñ����

ʹ�ñ���������update hereˢ�£������ڸ÷����ٴ�ʹ��ʱ
����ɸ÷���������set("����",ֵ)��ԭ�򲻱�������

���ֵ��һ���ַ�����Ҫ�������ţ���changeroom ���� "ֵ"
����outdoors�����Կ�������ʹ�ã�

        changeroom outdoors "city"  

�ͻ��ڷ����setup();�����һ��set("outdoors", "city");
���ѷ����outdoors���Ը�Ϊcity��

HELP
        );
        return  1;
}
