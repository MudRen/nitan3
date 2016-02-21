inherit F_CLEAN_UP;
#include <mudlib.h>
#include <getconfig.h>
#include <ansi.h>
#include <command.h>
#define SCALE   (1.0/10.0)
#define STATUS  "ϵͳ�������д�У���Ϸ��������"

string memory_expression(int m);
string dotime();

int count_ppls();

void create() { seteuid(getuid(this_object())); }

string query_rusage_message()
{
        mapping networkstats = network_stats();
        return sprintf("�ѽ��� %d ���(%.2f/sec)���Ѵ��� %d ���(%.2f/sec)", 
                networkstats["incoming packets total"], 
                to_float(networkstats["incoming packets total"])/uptime(), 
                networkstats["outgoing packets total"], 
                to_float(networkstats["outgoing packets total"])/uptime());
}

int main(object me) 
{
        float value;
        mapping r;

        if (time() - me->query_temp("scan_time") < 10
           && ! wizardp(me))
                return notify_fail("�ȵȣ�ϵͳ�����С���\n");

        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

        write(NOR + WHT "\n\t\t         .__________ ϵ ͳ �� Ѷ __________.\n");
        write(NOR + WHT "\t\t ��������������������������������������������������\n");
        write(NOR + WHT "\t\t ��Ϸ��ʶ�����ƣ�  " + MUD_NAME + "\n");
        write(NOR + WHT "\t\t ����ϵͳ�İ汾��  " + __VERSION__ + "\n");
        write(NOR + WHT "\t\t ϵͳ������汾��  Nitan Mudlib Version 2.1\n");
        printf(NOR + WHT "\t\t CPU ʹ�ðٷֱȣ�  %f %% �������Ϸʹ����\n", value );
        write(NOR + WHT "\t\t CPU �ĸ���״����  " + query_load_average() + "\n");
        printf(NOR + WHT "\t\t ��ʹ�õļ����壺  %s bytes\n", memory_expression(memory_info()) );
        write(NOR + WHT "\t\t ����ʹ����������  " + sizeof( users() ) + "  ����������\n");
        write(NOR + WHT "\t\t ע��ʹ����������  " + count_ppls() + "  �����ڱ���Ϸע��\n");
        write(NOR + WHT "\t\t ��������������  " + sizeof( objects() ) + " �����\n");
        write(NOR + WHT "\t\t ������������Ѷ��  " + sizeof(heart_beats()) + " ��\n");
        write(NOR + WHT "\t\t �ӳٺ�������Ѷ��  " + sizeof(call_out_info()) + " ��\n");
        write(NOR + WHT "\t\t ϵͳ���ص���Ѷ��  " + query_load_average() + "\n");
        write(NOR + WHT "\t\t ѶϢ�������Ѷ��  " + query_rusage_message() + "\n");
        write(NOR + WHT "\t\t ����ִ�е�ʱ�䣺  " + dotime() + "\n");
        write(NOR + WHT "\t\t ��Ϸ���ڵ�״̬��  " + STATUS + "\n" NOR);
        write(NOR + WHT "\t\t ��Ϸ�� PK ����:   ÿ�첻���� 8 �ˣ�ÿ�˲����� 2 ��\n\n" NOR);

        me->set_temp("scan_time", time());

        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

string dotime()
{
        int t, d, h, m, s;
        string time;

        t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if (d) time = chinese_number(d) + "��";
        else time = "";

        if (h) time += chinese_number(h) + "Сʱ";
        if (m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��\n";

        return time;
}

int help() {

   write(@HELP
ָ���ʽ��mudinfo

���ָ�����ʾ�й���� Mud ��һЩϵͳ��Ѷ��

HELP
        );
         return 1;
}


