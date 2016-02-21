/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : dict_d.c
 * Author : Whatup@Revival World
 * Date   : 2000-00-00
 * Note   : ���뾫��
 * Update :
 *  o 2000-00-00 Ŀǰ�����ô���վ����ѯ http://www.ee.tku.edu.tw/~rexchen/
 *
 -----------------------------------------
 */
#include <ansi.h>
#include <net/socket.h> 
#include <socket_err.h>
#include <message.h>

string strs="";

// string simplex; /* ��ѯ�ĵ��� */
// object tu;/* ��ѶϢ����user���� */
mapping connects = allocate_mapping(0);
private void get_data(int);

void create() { }

void find_word(object user,string word)
{
        int err,fd;


        if(!user) return ;
        if(!word) return ;        

        /* ������·���� */
        fd = socket_create(STREAM, "read_callback","close_socket");

        if ( fd < 0 )
        {
                return;
        }

        err = socket_connect(fd,"163.13.132.61 80","read_callback","write_callback" );

        if( err!=EESUCCESS )
        {
                return;
        }

        connects[fd] = allocate_mapping(3);
        connects[fd]["data"] = "";
        connects[fd]["user"] = user;
        connects[fd]["simplex"] = word;

        return ;
}

int close_socket(int fd)
{
        socket_close(fd);
        get_data(fd);
}

void read_callback(int fd, mixed message)
{
        /* ��ÿ��ȡ�õ����ϴ�� strs �� */
        connects[fd]["data"] += message;
        return ;
}

void write_callback(int fd)
{
        string code="";
        code = connects[fd]["simplex"];
        /* ����ָ��ץȡ��ҳ���� */
        socket_write(fd,
            sprintf("GET /~rexchen/cdict/wwwcdict.cgi?word=%s\r\n"
                ,code));
        return ;
}

private void get_data(int fd)
{
        string str;
        if(sscanf(connects[fd]["data"],"%*s<pre>%s</pre>%*s",str)!=3)
        {
                tell_object(connects[fd]["user"], HIR"��ѯʧ��, ���Ժ����ԡ�\n"NOR);
                return ;
        }
        str = replace_string(str,connects[fd]["simplex"],HIY+connects[fd]["simplex"]+NOR);
        str = sprintf(HIC"����ѯ�ĵ���Ϊ : %s "NOR"\n%s\n%s",
            connects[fd]["simplex"],repeat_string("=",50),str);
        tell_object(connects[fd]["user"], str);

        return ;
}
string query_name()
{
        return "�����ֵ�ϵͳ(DICT_D)";
}

