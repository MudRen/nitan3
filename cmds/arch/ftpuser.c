// ftpuser.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mixed ftp_sockets;
        string msg, stat ="";

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;
                
        if (! find_object(FTP_D))
                return notify_fail("���侫��(FTP_D)��δ������\n");

        ftp_sockets = FTP_D->query_sockets();

        if (! ftp_sockets || ! sizeof(ftp_sockets))
                return notify_fail("���侫��(FTP_D)Ŀǰû���κ�ʹ�������ߡ�\n");
                
        msg = sprintf("%-3s %-12s %-17s %-8s %-s\n", "FD", "�ʺ�", "����λ��", "״̬", "���ָ��"); 
        foreach(string fd, mixed val in ftp_sockets)
        {
                if (! undefinedp(val["retr"])) stat += "<������>";
                if (! undefinedp(val["stor"])) stat += "<�ϴ���>";
                msg += sprintf("%3d %-12s %-17s %-8s %s\n",
                        fd,
                        (val["login"] ? val["user"]:"(δ����)"),
                        val["address"],
                        stat, 
                        (val["lastcmd"] || "(��)"),
                );
        }
        tell_object(me, msg);
        return 1;
}

