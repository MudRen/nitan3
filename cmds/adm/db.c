// db.c
// created by jjgod

inherit F_CLEAN_UP;

#include "/adm/etc/database.h"
#include <ansi.h>
#include <mudlib.h>

int help(object me);
protected void done_edit(object me, string sql);

int main(object me, string arg)
{
        string sql;
        string msg;
        mixed  ret, res, *arr;
        string db, tb, expr, col;
        int    i, j, n;
        int    cnum, lnum;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        // �޲������г����������������ݿ�
        if (! arg)
        {
                i = 1;
                msg = sprintf(HIC "%s(" HIW "%s" HIC ")�����ݿ��б�\n" NOR
                              HIW "�������ݿ�������������������������\n" NOR,
                              LOCAL_MUD_NAME(), upper_case(INTERMUD_MUD_NAME));

                while (sizeof(ret = DATABASE_D->db_fetch_row("SHOW DATABASES", i)))
                {
                        sql = sprintf("SHOW TABLES FROM %s", ret[0]);
                        msg += sprintf(CYN "   %-18s [ " WHT "%3d" CYN " ]\n" NOR, ret[0], 
                                       DATABASE_D->db_query(sql));
                        i++;
                }
                msg += sprintf(HIW "����������������������������������\n" NOR 
                               HIC "�������� " HIW "%d" HIC " �����ݿ⡣" NOR, i - 1);
        }
        // �г�ָ����Ϸ���ݿ�����ݱ�(��ʾ������)
        else
        if (arg == "-d" || sscanf(arg, "-d %s", db) && db == DATABASE)
        {
                i = 1;
                db = DATABASE;
                sql = sprintf("SHOW TABLES FROM %s", db);

                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + db + CYN " ������ݿ⡣\n" NOR);

                msg = sprintf(HIC "���ݿ�(" HIW "%s" HIC ")�����ݱ�\n" NOR
                              HIW "�������ݱ����������������������������Щ������Щ���\n" NOR, db);

                while (sizeof(ret = DATABASE_D->db_fetch_row(sql, i)))
                {
                        res = DATABASE_D->db_query(sprintf("SHOW COLUMNS FROM %s FROM %s", ret[0], db));
                        if (intp(res)) cnum = res;

                        arr = DATABASE_D->db_fetch_row(sprintf("SELECT COUNT(*) FROM %s", ret[0]));
                        if (sizeof(arr)) lnum = arr[0];

                        msg += sprintf(CYN "   %-30s [ " WHT "%2d" CYN " / " WHT "%4d" CYN " ]\n" NOR,
                                       ret[0], cnum, lnum);
                        i++;
                }
                msg += sprintf(HIW "��������������������������������������������������\n" NOR 
                               HIC "�����ݿ⹲�� " HIW "%d" HIC " �����ݱ�" NOR, i - 1);
        }
        // �г��������ݿ���ָ�����ݱ���ֶ���Ϣ
        else
        if (sscanf(arg, "-d %s", db))
        {
                i = 1;
                db = stringp(db) ? db : DATABASE;
                sql = sprintf("SHOW TABLES FROM %s", db);

                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + db + CYN " ������ݿ⡣\n" NOR);

                msg = sprintf(HIC "���ݿ�(" HIW "%s" HIC ")�����ݱ�\n" NOR
                              HIW "�������ݱ����������������������������Щ���\n" NOR, db);

                while (sizeof(ret = DATABASE_D->db_fetch_row(sql, i)))
                {
                        res = DATABASE_D->db_query(sprintf("SHOW COLUMNS FROM %s FROM %s", ret[0], db));
                        if (intp(res)) cnum = res;

                        msg += sprintf(CYN "   %-30s [ " WHT "%2d" CYN " ]\n" NOR,
                                       ret[0], cnum);
                        i++;
                }
                msg += sprintf(HIW "������������������������������������������\n" NOR 
                               HIC "�����ݿ⹲�� " HIW "%d" HIC " �����ݱ�" NOR, i - 1);
        }
        // �г���Ϸ���ݿ���ָ�����ݱ���ֶ���Ϣ
        else
        if (sscanf(arg, "-t %s", tb))
        {
                i = 1;
                sql = sprintf("SHOW COLUMNS FROM %s", tb);

                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + tb + CYN " ������ݱ�\n" NOR);

                msg = sprintf(HIC "���ݱ�(" HIW "%s" HIC ")�Ľṹ��\n" NOR
                              HIW "�����ֶ�������������������������������������Ϣ������������\n" NOR, tb);

                while (sizeof(ret = DATABASE_D->db_fetch_row(sql, i)))
                {
                        res = DATABASE_D->db_fetch_row(sprintf("DESC %s %s", tb, ret[0]));
                        res -= ({ ret[0] });
                        res = filter_array(res, (: $1 != "" :));

                        msg += sprintf(CYN "   %-24s [ " WHT "%s" CYN " ]\n" NOR, ret[0],
                                       implode(res, CYN " | " WHT));
                        i++;
                }
                msg += sprintf(HIW "����������������������������������������������������������\n" NOR 
                               HIC "�����ݱ��� " HIW "%d" HIC " ���ֶΡ�" NOR, i - 1);
        }
        // ���ձ��ʽ��ѯ�ƶ����ݱ����ƶ��ֶε�����
        else
        if (sscanf(arg, "-s %s %s", tb, arg) == 2)
        {
                sql = sprintf("SHOW COLUMNS FROM %s", tb);

                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + tb + CYN " ������ݱ�\n" NOR);

                // ָ�����ʽ
                if (sscanf(arg, "%s where %s", col, expr) == 2)
                {
                        i = 1;
                        sql = sprintf("SELECT %s FROM %s WHERE %s", col, tb, expr);

                        msg = sprintf(HIC "��ѯ(" HIW "%s" HIC ")�Ľ����\n" NOR
                              HIW "�����ֶ���������������������������������������������������\n" NOR
                              HIC "   %s\n" NOR
                              HIW "������������������������������������������������ѯ�������\n" NOR,
                              sql, col);

                        while (sizeof(ret = DATABASE_D->db_fetch_row(sql, i)))
                        {
                                msg += sprintf(CYN "   %" + (stringp(ret[0]) ? "s" : "O") + 
                                               "\n" NOR, ret[0]);
                                i++;
                        }
                        msg += sprintf(HIW "����������������������������������������������������������\n" NOR 
                                       HIC "�˴β�ѯ���� " HIW "%d" HIC " �����Ͻ����" NOR, i - 1);
                        if (! (i - 1))
                                return notify_fail(sprintf(CYN "��ѯ��" WHT "%s" CYN "\nû�еõ��κν�������"
                                                           "���Ƿ��޴��ֶλ���ʽ�������\n" NOR, sql));
                }
                // ��ָ�����ʽ
                else
                {
                        col = arg;
                        i = 1;
                        sql = sprintf("SELECT %s FROM %s", col, tb);

                        msg = sprintf(HIC "��ѯ(" HIW "%s" HIC ")�Ľ����\n" NOR
                              HIW "�����ֶ���������������������������������������������������\n" NOR
                              HIC "   %s\n" NOR
                              HIW "������������������������������������������������ѯ�������\n" NOR,
                              sql, col);

                        while (sizeof(ret = DATABASE_D->db_fetch_row(sql, i)))
                        {
                                msg += sprintf(CYN "   %" + (stringp(ret[0]) ? "s" : "O") + 
                                               "\n" NOR, ret[0]);
                                i++;
                        }
                        msg += sprintf(HIW "����������������������������������������������������������\n" NOR 
                                       HIC "�˴β�ѯ���� " HIW "%d" HIC " �����Ͻ����" NOR, i - 1);
                        if (! (i - 1))
                                return notify_fail(sprintf(CYN "��ѯ��" WHT "%s" CYN "\nû�еõ��κν�������"
                                                           "���Ƿ��޴��ֶλ������ݱ�Ϊ�ա�\n" NOR, sql));
                }
        }
        // ��ѯָ��һ���е�������Ϣ
        // ����ѯ
        else
        if (sscanf(arg, "-n %s where %s", tb, expr) == 2)
        {
                i = 1;

                // ׼��Ҫ��ѯ���к�
                n = me->query("db_last_query/" + tb) + 1;

                // ׼������Ϣ
                sql = sprintf("SHOW COLUMNS FROM %s", tb);
                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + tb + CYN " ������ݱ�\n" NOR);

                arr = ({ });
                while (sizeof(res = DATABASE_D->db_fetch_row(sql, i)))
                {
                        arr += ({ res[0] });
                        i++;
                }
                // ׼������Ϣ
                sql = sprintf("SELECT * FROM %s WHERE %s", tb, expr);
                j = DATABASE_D->db_query(sql);
                n = j < n ? j : n;
                ret = DATABASE_D->db_fetch_row(sql, n);

                // ��ʾ��Ϣ
                msg = sprintf(HIC "��ѯ(" HIW "%s" HIC ")�ĵ� " HIW "%d" HIC " �н����\n" NOR
                              HIW "�����ֶ����������������������������ֶ����ݩ���������������\n" NOR,
                              sql, n);
                cnum = sizeof(arr);

                if (! cnum || ! sizeof(ret))
                        return notify_fail(sprintf(CYN "��ѯ��" WHT "%s" CYN "\nû�еõ��κν�������"
                                                   "���Ƿ��޴��ֶλ���ʽ�������\n" NOR, sql));
                for (i = 0; i < cnum; i++)
                        msg += sprintf(CYN "  %-30s " WHT "%O\n" NOR, arr[i], ret[i]);

                msg += sprintf(HIW "����������������������������������������������������������\n" NOR 
                               HIC "���й��� " HIW "%d" HIC " ���ֶΡ�" NOR, cnum);

                // ׼����һ�β�ѯ
                me->set("db_last_query/" + tb, n);
        }
        // ��ǰ��ѯ
        else
        if (sscanf(arg, "-f %s where %s", tb, expr) == 2)
        {
                i = 1;
                n = me->query("db_last_query/" + tb) - 1;

                // ׼������Ϣ
                sql = sprintf("SHOW COLUMNS FROM %s", tb);
                if (! intp(DATABASE_D->db_query(sql)))
                        return notify_fail(CYN "û�� " WHT + tb + CYN " ������ݱ�\n" NOR);

                arr = ({ });
                while (sizeof(res = DATABASE_D->db_fetch_row(sql, i)))
                {
                        arr += ({ res[0] });
                        i++;
                }
                // ׼������Ϣ
                sql = sprintf("SELECT * FROM %s WHERE %s", tb, expr);
                n = n < 1 ? 1 : n;
                ret = DATABASE_D->db_fetch_row(sql, n);

                // ��ʾ��Ϣ
                msg = sprintf(HIC "��ѯ(" HIW "%s" HIC ")�ĵ� " HIW "%d" HIC " �н����\n" NOR
                              HIW "�����ֶ����������������������������ֶ����ݩ���������������\n" NOR,
                              sql, n);
                cnum = sizeof(arr);

                if (! cnum || ! sizeof(ret))
                        return notify_fail(sprintf(CYN "��ѯ��" WHT "%s" CYN "\nû�еõ��κν�������"
                                                   "���Ƿ��޴��ֶλ���ʽ�������\n" NOR, sql));
                for (i = 0; i < cnum; i++)
                        msg += sprintf(CYN "  %-30s " WHT "%O\n" NOR, arr[i], ret[i]);

                msg += sprintf(HIW "����������������������������������������������������������\n" NOR 
                               HIC "���й��� " HIW "%d" HIC " ���ֶΡ�" NOR, cnum);

                // ׼����һ�β�ѯ
                me->set("db_last_query/" + tb, n);
        }
        // ִ�� SQL ���
        else
        if (arg == "-e" || sscanf(arg, "-e %s", sql))
        {
                if (! stringp(sql) || sql == "")
                {
                        write(HIC "��������Ҫִ�е���䣺\n" NOR);
                        me->edit((: call_other, __FILE__, "done_edit", me :));
                } else
                done_edit(me, sql);
        }

        else return help(me);
        if (stringp(msg) && msg != "") me->start_more(msg);
        return 1;
}

protected void done_edit(object me, string sql)
{
        mixed ret, *res;
        string msg;

        if (! sql || sql == "")
        {
                tell_object(me, HIC "��ȡ�������롣\n" NOR);
                return;
        }
        if (sql[<1..<0] == "\n") sql = sql[0..<2];
        msg = sprintf(HIC "���(" HIW "%s" HIC ")��ִ�н����\n" 
                      HIW "����������������������������������������������������������������"
                      "��������������\n" NOR, sql);
        if (! ret = DATABASE_D->db_query(sql))
        {
                msg += CYN "û�еõ��κο�����Ϣ��\n" HIW "��������������������������������"
                       "����������������������������������������������\n" NOR;
        } else
        if (stringp(ret))
        {
                msg += sprintf(HIR "������Ϣ��" NOR WHT "%s\n" NOR
                               HIW "��������������������������������������������������������"
                               "����������������������\n" NOR, ret);
        } else
        {
                res = DATABASE_D->db_all_query(sql);
                msg += sprintf(WHT "%O\n" NOR
                               HIW "��������������������������������������������������������"
                               "����������������������\n" NOR, res);
        }
        tell_object(me, msg);
        return;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: db [ -d [ ���ݿ��� ] ] |
             [ -t <���ݱ���> ] |
             [ -s <���ݱ���> <�ֶ���> [ where <���ʽ> ] ] |
             [ -n <���ݱ���> where <���ʽ> ] |
             [ -f <���ݱ���> where <���ʽ> ]
             [ -e [ <SQL ���> ] ]

��ָ��������Ϸ���ݿ�Ĺ��������ʹ�� -d �����г����ݿ��
���ݣ�-t �г�����Ϸ���ݿ�����ݱ�����ݡ�-s ��������������
�������ָ�����ʽ���У�����ָ�����ʽ������ʾ�˱������е�
�С� ���ǵ� mud ����ʾ�����⣬�������ָ���ֶ�����Ҳ����ֻ
��ͬʱ��ʾ���н��һ���ֶε���Ϣ�����������һ���������
�ֶε���Ϣ������ʹ�� -n ��������ѯ���� -f ������ǰ��ѯ��

������Ϸ�����ݿ����ӵ�Ч�����⣬��ָ��ṩ�Է���Ϸ���ݿ�
�Ĳ�����
HELP);
        return 1;
}
