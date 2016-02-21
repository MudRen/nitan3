// import.c

#define IP_FILE "/adm/etc/ipdata7"

// #define IP_FILE "/adm/etc/ipdata2"
// #define IP_FILE "/adm/etc/ipdata3"

inherit F_CLEAN_UP;

#include <ansi.h>
#include "/adm/etc/database.h"

void resolve_data(string line);
int main(object me, string arg)
{
        int lines;
        int i;
        string line;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        lines = file_lines(IP_FILE);

        write(HIR "����ת��...\n\n" NOR);
        for (i = 1; i <= lines; i++)
        {
                line = read_file(IP_FILE, i, 1);
                line = line[0..<2];
                resolve_data(line);

                if (i % 100) reset_eval_cost();
        }
        write(HIR "\nһ��ת���� " + (i - 1) + " �� IP ���ݡ�\n" NOR);

        return 1;
}

void resolve_data(string line)
{
        string start, end, desc;

        if (sscanf(line, "%s_%s_%s", start, end, desc) == 3)
        {
                /*
                write(sprintf(CYN "INSERT INTO %s "
                              "VALUES (\"%s\", \"%s\", \"%s\")\n" NOR,
                              IP_TABLE, start, end, desc));
                */

                DATABASE_D->db_query(sprintf("INSERT INTO %s "
                                     "VALUES (\"%s\", \"%s\", \"%s\")",
                                     IP_TABLE, start, end, desc));
        }
}

int help()
{
        write(@TEXT
ָ���ʽ: import

���� IP �����ļ���
TEXT);
        return 1;
}

