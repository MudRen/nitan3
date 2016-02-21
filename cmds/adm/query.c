// query.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string target;
        mixed result;
	mixed obj;
        string *flist;
        string *ffile;
        string arg1, arg2;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! me->is_admin())
                return 0;

	seteuid(getuid(me));

	if (! arg)
		return notify_fail("ָ���ʽ : query all | <���֮���ƻ���>\n" );
	target = arg;

        if (target == "all" || target == "ALL")
        {
                write(sprintf("Ŀǰ���ݿ��б���������У�%d �\n",
                              sizeof(DBASE_D->query_save_dbase())));
                return 1;
        }

        if (sscanf(arg, "%s %s", arg1, arg2) == 2)
        {
                if (arg1 == "cruise")
                {
                        ffile = ({ });
                        flist = get_dir("/data/item/cruise/"); 
                        for (int i = 0; i < sizeof(flist); i++) 
                        {
                                string file;
                                file = "/data/item/cruise/" + flist[i]; 
                                obj = get_object(file);
                                result = DBASE_D->query_object_data(obj);
                                result = result["store"];
                                for (int j = 0; j < sizeof(result); j++) 
                                {
                                        if (strsrch(result[j]["file"], arg2) > -1)
                                                ffile += ({ "/data/item/cruise/" + flist[i] });
                                }
                        }
                        write(sprintf("���ΰ��������к����ַ�(%s)��������£�\n%O\n", arg2, ffile));
                        return 1;
                }
        }
	obj = find_object(target);

	if (! objectp(obj)) obj = present(target, me);
	if (! objectp(obj)) obj = present(target, environment(me));
        if (! objectp(obj)) obj = resolve_path(me->query("cwd"), target);

	result = DBASE_D->query_object_data(obj);
        if (undefinedp(result))
                write("����������ݿ���û���κμ�¼��\n");
        else
                write(sprintf("�����(%O)��������ݣ�\n%O\n", obj, result));

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : query all | <���֮���ƻ���>

���ô�һָ����Բ�ѯһ�����(object)���������ݿ��еļ�¼��

�ο����ϣ�clear
HELP
    );
    return 1;
}
