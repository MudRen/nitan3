//checkobj  ��ѯ��Ʒ�ֲ�
// Smallfish@Huaxia

inherit F_CLEAN_UP;

string check_room(string file);
string check_obj(string file);
string base_environment(object ob);

int main(object me,string arg)
{
        string file,info;
        object ob;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        seteuid(geteuid(me));
        if (!arg)
                return notify_fail("ָ���ʽ��checkobj <��Ʒ�ļ�>|<�����ļ�>\n");

        file = resolve_path(me->query("cwd"), arg);
        if (file_size(file) < 0)
        {
                ob = present(arg, me);
                if (! ob) ob = present(arg, environment(me));
                if (! ob) return notify_fail("û�����������\n");
                file = base_name(ob) + ".c";
        }

        if (!objectp(ob = load_object(file)))
                return notify_fail("�޷�����" + file + "������Ʒ��\n");

        if (ob->is_character())
        {
                if (!userp(ob))
                        destruct(ob);
                return notify_fail("����һ��������Ʒ��\n");
        }

        if ((int)ob->query_max_encumbrance() == 100000000000)   //�Ƿ���
                info = check_room(file);
        else
                info = check_obj(file);

        if (clonep(ob))
                destruct(ob);

        me->start_more(info);

        return 1;
}

string check_room(string file)
{
        object room;
        mapping ob_list, ob;
        string *list;
        int i,have_living;
        string msg,base_env,info;

        room = load_object(file);

        if (!room)
                return "���" + file + "����\n";

        msg = "����һ�����䣺" + file + "�����ƣ�" + room->short() + "\n";
        msg += "------------------------------------------------------------------------\n";
        ob_list = room->query("objects");
        if( !mapp(ob_list) ) 
        {
                msg += "�������û���κ���Ʒ��\n";
                return msg;
        }

        have_living = 0;
        if( mapp(ob = room->query_temp("objects")) )
        {
                list = keys(ob);
                for (i = 0;i <sizeof(list);i++)
                {
                        if (!ob[list[i]])
                                continue;
                        if (ob[list[i]]->is_character())
                                continue;
                        if (!environment(ob[list[i]]))
                                continue;
                        base_env = base_environment(ob[list[i]]);
                        msg += "�����Ʒ��" + ob[list[i]]->short() + "����" + base_env + "��\n";
                        have_living = 1;
                }
        }

        if (!have_living)
                msg += "�������Ŀǰû�л����Ʒ��\n";

        list = keys(ob_list);

        for (i = 0;i < sizeof(list);i++)
        {
                msg += "------------------------------------------------------------------------\n";
                info = check_obj(list[i]);
                if (!info) continue;
                msg += info;
        }

        if (clonep(room))
                destruct(room);

        return msg;
}

string check_obj(string file)
{
        object ob,*ob_list;
        string msg,base_env,*list;
        int i,count;
        mapping obj_env;

        ob = load_object(file);
        if (!ob)
                return "���" + file + "����\n";

        if (ob->is_character())
        {
                if (clonep(ob))
                        destruct(ob);
                return 0;
        }

        msg = "��Ʒ��" + file + "�����ƣ�" + ob->short() + "\n";

        if (clonep(ob))
                destruct(ob);

        ob_list = children(file);

        if (!sizeof(ob_list))
        {
                msg += "����ļ�û���κθ�����Ʒ��\n";
                return msg;
        }

        obj_env = ([]);
        for (i = 0;i < sizeof(ob_list);i ++)
        {
                if (!ob_list[i])
                        continue;
                if (!environment(ob_list[i]))
                        continue;
                base_env = base_environment(ob_list[i]);
                if (undefinedp(obj_env[base_env]))
                        obj_env[base_env] = 1;
                else
                        obj_env[base_env] += 1;
        }

        count = 0;
        list = keys(obj_env);
        for (i = 0;i < sizeof(list);i++)
        {
                msg += sprintf("%-20s:%d\n",list[i],obj_env[list[i]]);
                count += obj_env[list[i]];
        }

        msg += "�ܹ�" + chinese_number(count) + "����Ʒ��\n";

        obj_env = 0;
        return msg;
}

string base_environment(object ob)
{
        int i = 0;
        object env;
        env = environment(ob);
        while(objectp(env) && clonep(env) && !env->is_character())
        {
                i ++;
                if (i > 20) break;
                if (environment(env))
                        env = environment(env);
                else
                        break;
        }
        if (!env)
                return "��֪���ĵط�";
	if (!clonep(env) || env->is_chat_room())
                return env->short() + "(" + base_name(env) + ")";
        else
                return env->name(1) + "(" + env->query("id") + ")";
}

int help(object me)
{
write(@HELP
ָ���ʽ : checkobj <��Ʒ>|<����>

��ѯָ������Ʒ�ֲ������
�����ѯ���䣬����ʾ�������й�����Ʒ�ķֲ������
HELP
    );
    return 1;
}
