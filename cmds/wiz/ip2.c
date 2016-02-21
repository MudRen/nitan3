/******** Written by ken@NT.  All rights reserved. ********/
//ip.c
/**********************************************************/
/* �÷��� ������(ip id)��ָ������֪�Է�IP����������ڵ��� */
/*        ���������ⲿ����convert_ip����������logind.c    */
/*        ���÷���������ob��һ����ң���ô���õķ�������  */
/*        "/cmds/adm/ip.c"->convert_ip(query_ip_number    */
/*        (ob)) �����ͻ᷵��һ���ַ������͵�ob�����ڵء�  */
/*                                                        */
/* ���¡� ���ݿ����/adm/etc/ipdata/ �ֱ�������������   */
/*        ��IP�����ļ����緢����δ֪IP���������и��¡�    */
/*                                                        */
/* ׼ȷ�� ׼ȷ����ȫȡ�������ݿ⣬������������ʵ��IP����  */
/*        �ģ�һ��IP���ĸ�IP������ɣ�A.B.C.D ���ҵ�IP��  */
/*        A�Σ��������/ipdata/����Ǹ��ļ��в��ң����� */
/*        ���˲��ҵ��ٶȣ�Ȼ�����query_ip_number(ob)�Ƿ� */
/*        �ں�IP1��IP2֮���Ǿͷ��غ���ĵ����������Ǿ�����*/
/*        һ�У������Ҳ��������δ֪������( by ken@NT )   */
/**********************************************************/

#include <ansi.h>
inherit F_CLEAN_UP;

#define IP_DIR "/adm/etc/ipdata/" // IP�������ŵ�λ��
#define EXT    ".ip" // ����IP�����ļ��ĸ�����

int help(object me);
int main(object me, string arg);

string convert_ip(string ip); // ���ⲿ���õĺ���

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string ip,output;
        object ob;

        if (!SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;
                
        if (!arg || sscanf(arg, "%s", ip) != 1)
                return help(me);

        seteuid(geteuid(me));
        ob = UPDATE_D->global_find_player(arg);
        if (objectp(ob))
        {
                ip     = query_ip_number(ob); // ���������ȡ��IP                               
                output = convert_ip(ip);
                UPDATE_D->global_destruct_player(ob, 1);
                write(output + "\n");
                return 1;
        }
        else
        {
                output = convert_ip(ip);
                write(output + "\n");
                return 1;
        }
}

string convert_ip(string ip)
{
        string  *ip_data_detail, *ip_data, *ip_detail;
        int a, b, c, d, i, count,  ipa, ipb, ipc, find = 0;
        
        if (!stringp(ip))
                return "";
        if (sscanf(ip, "%d.%d.%d.%d", a, b, c, d) != 4)
                return "";
        
        ip_detail = explode(ip, ".");
        // ��cut�����ĶΣ����IP= 127.0.0.1 ��ôip_detail[0] = 127                                 
        // ip_detail[1] = 0 ip_detail[2] = 0 ip_detail[3] = 1
        // ���ǵ�Ч�ʵ����⣬���ж�ip_detail[0]��ʲô���ٴ򿪶�Ӧ��IP�ļ�
        // ��ȻIP�ļ�Ҫ�Ⱦ�������(����ip_detail[0].ip����������IP�����Դ˿�ͷ)
        if (file_size(IP_DIR + ip_detail[0] + EXT) > 0)
        {
                ip_data = explode(read_file(IP_DIR + ip_detail[0] + EXT), "\n");
        }
        
        else if (file_size(IP_DIR + "0" + EXT) > 0)
        { 
                ip_data = explode(read_file(IP_DIR + "0" + EXT), "\n");
        }

        sscanf(ip, "%d.%d.%d.%d", a, b, c, d);
        // ��IPÿ��ǿ���Ա�Ϊ3���ַ������� 127.0.0.1 ���127.000.000.001
        ip_detail[0] = sprintf("%03d", a );
        ip_detail[1] = sprintf("%03d", b );
        ip_detail[2] = sprintf("%03d", c );
        ip_detail[3] = sprintf("%03d", d );
        
        ip     = implode(ip_detail, ".");
        sscanf(ip, "%d.%d.%d.%d", a, b, c, d); // ��IP���ִ������������
        ipb = d + (c * 1000) + (b * 1000000); // ��β���ε�IP��ӣ��������������

        count  = sizeof (ip_data);
        count  = count - 1;

        if  (ip == "127.000.000.001")
        {
                return "���ػ���";
                find = 1;
        }
        if (find != 1)
        {               
                for (i=0; i<=count; i++)
                {
                        ip_data_detail = explode(ip_data[i], "|");
                        if(strcmp (ip[0..2], ip_data_detail[0][0..2]) != 0 &&
                           strcmp (ip[0..2], ip_data_detail[1][0..2]) != 0)
                        continue; // ���IP�ĵ�һ����ȫ�����IP�ļ����IPͷһ����ִ���������
                        {                       
                                sscanf(ip_data_detail[0], "%d.%d.%d.%d", a, b, c, d);
                                ipa = d + (c * 1000) + (b * 1000000);
                                // ipa �Ǽ���IP1β���ε�IP��Ӻ��ֵ
                                sscanf(ip_data_detail[1], "%d.%d.%d.%d", a, b, c, d);
                                ipc = d + (c * 1000) + (b * 1000000);
                                // ipc ����IP2β���ε�IP��Ӻ��ֵ
                                // �����ҵ�IP����ipa �� ipc ֮��ģ���ִ���������
                                if (ipb <= ipa || ipb >= ipc)
                                continue;                       
                                {                       
                                        return ip_data_detail[2]; // ���ظ�IP�ĵ���
                                        find = 1;
                                        break;
                                }
                        }
                }
        }

        if (find == 0)
                return "δ֪����";

}

int help(object me)
{
write(@HELP
Written by ken@NT. All rights reserved.
E-mail: printken@yahoo.com.hk

��ʽ : ip <IP��ַ | �������>

HELP);
return 1;
}
