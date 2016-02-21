// replace.c
// Writed by Lonely

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	//string file, str, pattern, replace, *pats;
	string file, str, pattern, replace;
        //object ob;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        seteuid(geteuid(me));

        if (sscanf(arg, "%s of %s to %s", pattern, file, replace) != 3)
                return notify_fail("ָ���ʽ : replace <ԭ�ַ���> of <����> to <�滻�ַ���>\n");

        file = resolve_path(me->query("cwd"), file);

        if (file_size(file) < 0)
                return notify_fail("û�����������\n");
        
        if (! SECURITY_D->valid_read(file, me, "read"))
                return notify_fail("��û��Ȩ�޲鿴����ļ���\n");

        replace = replace_string(replace, "\\t", "\t"); 
        replace = replace_string(replace, "\\n", "\n"); 
        replace = replace_string(replace, "\"\"", ""); 

        str = read_file(file);

        /*
        pats = explode(pattern," ");
        foreach(string str1 in pats) {
                str = replace_string(str, str1, replace);
        }
        */
        str = replace_string(str, pattern, replace);

        rm( file );
        if(  write_file(file, str,1) )
                write(" �滻�ɹ���\n");
        else write("ʧ�ܡ���\n");       
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : replace <������>

���ָ������XXXXX��

see also: cat
HELP );
        return 1;
}
