/* *********************��·��ʱͨѶϵͳ***********************
*  
*                                                  By Whatup *
*                                               
* ����
:whatup_!whatup@mail2000.com.tw QUIT :Leaving...
����
:whatup_!whatup@mail2000.com.tw JOIN :#bitlbee
    :root!root@localhost.localdomain PRIVMSG #bitlbee :Question on MSN connection (handle yukang.tw@yahoo.com.tw):
    :root!root@localhost.localdomain PRIVMSG #bitlbee :The user whatup.tw@gmail.com (����-Ҩ��) wants to add you to his/her buddy list. Do you want to allow this?
    :root!root@localhost.localdomain PRIVMSG #bitlbee :You can use the yes/no commands to answer this question.

*                                     ==δ��ͬ�⣬�Ͻ�����==  *
**************************************************************/

/* ��ͷ���뵵 */
#include <ansi.h>
/* ����趨 */
#include <net/socket.h>
#include <net/socket_errors.h>

#define PING_TIME 240
#define TELL(x) CHANNEL_D->do_channel(this_object(),"sys", x);
#define BITLBEE_SERVER "62.75.129.41 7777"


inherit F_DBASE;

/* ��ʼ�趨 */
private mapping users = ([]);

private int process_identify(object me,string pass);
void process_who(int fd,string str);
protected void close_socket(int fd);
varargs void send_who(int fd,string id);
void send_ping();

/* �������� */
void create()
{
        set("channel_id", "ͨѶ����");
        seteuid(getuid());

#ifdef DEBUG
        TELL(sprintf("[%s]��ʼ��ɡ�", replace_ctime(time()) ));
#endif 

        call_out((:send_ping:),PING_TIME);
}

void send_ping()
{
        foreach(int fd,mapping m in users)
        {
                socket_write(fd,"PING\r\n");
        }
        call_out((:send_ping:),PING_TIME);
}

void remove()
{
        foreach(int fd,mapping m in users)
        {
                if(m["obj"])
                        tell_object(m["obj"],"���¸��� im ϵͳ�������µ��롣\n");
                socket_write(fd,"QUIT\r\n");
                socket_close(fd);
        }
}

void reset()
{
        foreach(int fd,mapping m in users)
        {
                if(!m["obj"]) {
                        close_socket(fd);                       
                        map_delete(users,fd);
                }
        }
}

/* ��ʼ���� */
void login_irc(object user)
{
        int err,fd;
        string id;
        id = user->query("id");
        if(!id)
        {
                tell_object(user,"��û�е��� ID ");
                return ;
        }
        fd = socket_create(STREAM, "read_callback","close_socket");
        if ( fd < 0 )
        {
                tell_object(user,"����ʧ�ܣ�����������û�п���������·�޷����ߡ�");
                return;
        }
        users[fd] = allocate_mapping(5);
        users[fd]["id"] = id;
        users[fd]["steps"]   = 0;
        users[fd]["obj"]   = user;
        users[fd]["list"] = allocate_mapping(1);
        user->set_temp("im_fd",fd);

        err = socket_connect(fd,BITLBEE_SERVER,"read_callback","write_callback" );
        if( err==EESUCCESS )
        {
#ifdef DEBUG
                TELL(sprintf("[%s] %s �ɹ�\���� Socket ,��ʼ׼������ irc.fd = %d",
                        replace_ctime(time()) ,id,fd));
#endif 
        }
        else
        {
#ifdef DEBUG
                TELL(sprintf("[%s]���� Socket ʧ��,�޷���������·����.",
                        replace_ctime(time()) ));
#endif 
                return ;
        }
        call_out((:process_identify:),3,user,crypt(id,id)[0..10]);
        return;
}

private int process_identify(object me,string pass)
{
        int fd = me->query_temp("im_fd");
        if( fd < -1 ) 
        {
                tell_object(me,"[IM Message]:����ʧ�ܣ����Ժ����ԣ�\n");
                return 1;
        }
        if(users[fd]["obj"] == me)
                socket_write(fd,"PRIVMSG #bitlbee :identify "+pass+"\r\n");
}

protected void write_callback(int fd)
{
TELL(sprintf("%d",fd));
        socket_write(fd,"NICK "+users[fd]["id"]+"\r\n");
        return ;
}

protected void read_callback(int fd,mixed message)
{
        string str;
#ifdef DEBUG
        TELL(sprintf("[%s] %d,%s",
                replace_ctime(time()),fd,message ));
#endif DEBUG
        if(regexp(message ,"PING :PinglBee") ) //PING :PinglBee
        {
                socket_write(fd,"PONG\r\n");
        } 

        switch(users[fd]["steps"])
        {
        case 0:
                str = sprintf("USER %s %s %s :%s\r\n",users[fd]["id"],
                    users[fd]["id"],query_ip_name(users[fd]["obj"]),
                    users[fd]["obj"]->query("name"));
                socket_write(fd,str);
                break;
        case 1:
                str = sprintf("JOIN #bitlbee\r\n");
                socket_write(fd,str);
                break;
        case 2:
                str = sprintf("MODE #bitlbee\r\n");
                socket_write(fd,str);
                break;
        case 3:
                str = sprintf("WHO #bitlbee\r\n");
                socket_write(fd,str);
                str = sprintf("PRIVMSG #bitlbee :set charset=BIG5\r\n");
                socket_write(fd,str);
                break;
        default:

                {
                        string name,mail,msg,id;
                        //:whatup_!whatup@mail2000.com.tw PRIVMSG #bitlbee :whatup: test
                        foreach(string m in explode(message,"\r\n")) 
                        { 
                                if(sscanf(m,":%s!%s PRIVMSG #bitlbee :%s",name,mail,msg) == 3 )
                                {
                                        //:root!root@localhost.localdomain PRIVMSG #bitlbee :The user whatup.tw@gmail.com (����-Ҩ��) wants to add you to his/her buddy list. Do you want to allow this?
                                        if(sscanf(msg,"The user %s wants to add you to his/her buddy list. Do you want to allow this?",mail) == 1)
                                        {
                                                tell_object(users[fd]["obj"],"\n[IM Message]:"+mail+"��Ҫ����������ĺ���������ͬ��Ļ��� im yes����ͬ��Ļ����� im no��\n");
                                        }
                                        else if(sscanf(msg,"%s: %s",id,msg) == 2  && users[fd]["obj"]
                                            && id == users[fd]["id"])
                                                tell_object(users[fd]["obj"],sprintf(HIW HBBLU"%s �ü�ʱѶϢ������ : %s\n"NOR,
                                                        users[fd]["list"][name][4]+"("+users[fd]["list"][name][0]
                                                        +"@"+users[fd]["list"][name][1]+")\n["+name+"]",msg));
                                        else 
                                                switch(msg)
                                        {
                                        case "The nick is (probably) not registered":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:��һ��ʹ�øþ��飬�Զ�ע���ʺţ�\n");
                                                socket_write(fd,"PRIVMSG #bitlbee :register "+crypt(users[fd]["id"],users[fd]["id"])[0..10]+"\r\n");
                                                break;
                                        case "Incorrect password":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:�����������(��֪ͨϵͳ����Ա)��\n");
                                                break;
                                        case "YAHOO - Login error: Error 99 (Logged in on a different machine or device)":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:�������������Ե��� YAHOO��\n");
                                                break;
                                        case "MSN - Logged out: Someone else logged in with your account":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:�������������Ե��� MSN ��\n");
                                                break;
                                        case "YAHOO - Signing off..":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:��ǳ� YAHOO ��\n");
                                                break;
                                        case "MSN - Signing off..":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:��ǳ� MSN ��\n");
                                                break;
                                                //                            case "MSN - Logging in: Authenticated, getting buddy list":
                                        case "MSN - Logged in":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:MSN ����ɹ���\n");
                                                break;
                                        case "YAHOO - Logged in":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:YAHOO ����ɹ���\n");
                                                break;
                                        case "No accounts known. Use 'account add' to add one.":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:��ʹ�� im register msn ���� im register yahoo ע���ʺţ�\n");
                                                break;
                                        case "MSN - Login error: Error during Passport authentication":
                                                tell_object(users[fd]["obj"],"\n[IM Message]:MSN�������\n");
                                                break;
                                        default:
                                        }
                                }

                                // ��վѶϢ :paiting!paiting@hotmail.com JOIN :#bitlbee
                                if(sscanf(m,":%s!%s JOIN :#bitlbee",id,name) == 2)
                                {
                                        send_who(fd,id);
                                        tell_object(users[fd]["obj"],"\n[IM Message]:"+id+"������ ��\n");
                                        continue;
                                }
                                // ��վѶϢ :paiting!paiting@hotmail.com QUIT :Leaving...
                                if(sscanf(m,":%s!%s QUIT :Leaving...",id,name) == 2)
                                {
                                        map_delete(users[fd]["list"],id);
                                        tell_object(users[fd]["obj"],"\n[IM Message]:"+id+"������ ��\n");
                                        continue;
                                }
                                // ״�������� :root!root@rw.twku.net MODE #bitlbee +v paiting
                                if(sscanf(m,":root!root@rw.twku.net MODE #bitlbee +v %s",id) == 1)
                                {
                                        send_who(fd,id);
                                        continue;
                                }
                                // ״����away��æ¼ :root!root@rw.twku.net MODE #bitlbee -v paiting
                                if(sscanf(m,":root!root@rw.twku.net MODE #bitlbee -v %s",id) == 1)
                                {
                                        send_who(fd,id);
                                        continue;
                                }
                                if(sscanf(m,":%*s 352 %*s %*s %*s %*s %*s %*s %*s :%*d %*s") == 10) 
                                {
                                        process_who(fd,m);
                                } else 
                                if(sscanf(m,":%*s 352 %*s #bitlbee %*s %*s %*s %*s %*s :%*d %*s") == 9) 
                                {
                                        process_who(fd,m);
                                }


                        }
                }
        }
        users[fd]["steps"]++;   
}

#ifdef DEBUG
void socket_write(int fd,mixed message)
{
        int i;
        TELL(sprintf(HIR"[%s] %d,%s"NOR,
                replace_ctime(time()),fd,message ));
        i = efun::socket_write(fd,message);
        switch(i)
        {
        case EEFDRANGE:       TELL("����ֵ (descriptor) ������Χ��"); break;
        case EEBADF:          TELL("��Ч������ֵ��"); break;
        case EESECURITY:      TELL("��ͼΥ����ȫ��"); break;
        case EENOADDR:        TELL("socket δָ��λַ��"); break;
        case EEBADADDR:       TELL("λַ��ʽ�����⡣"); break;
        case EENOTCONN:       TELL("socket ��δ���ӡ�"); break;
        case EEALREADY:       TELL("�������ڽ����С�"); break;
        case EETYPENOTSUPP:   TELL("��֧Ԯ�������̬��"); break;
                //        case EEBADDATA:       TELL("�ͳ������Ϻ���̫�ೲ״��� (nested level)��"); break;
        case EESENDTO:        TELL("sendto �����⡣"); break;
        case EEMODENOTSUPP:   TELL("��֧Ԯ�� socket ��̬��"); break;
        case EEWOULDBLOCK:    TELL("��������ͣ�� (block)��"); break;
        case EESEND:          TELL("�ͳ� (send) �����⡣"); break;
        case EECALLBACK:      TELL("�ȴ��غ� (callback) �С�"); break;
        default:

        }
}
#endif

protected void close_socket(int fd)
{
        if(users[fd]["obj"])
                users[fd]["obj"]->delete_temp("im_fd");

        map_delete(users,fd);
        socket_close(fd);
#ifdef DEBUG
        TELL(sprintf("[%s] %d,���߽���",
                replace_ctime(time()),fd ));
#endif
}

void send_command(int fd,mixed message)
{
        socket_write(fd,message+"\r\n");
#ifdef DEBUG    
        TELL(sprintf("[%s] %d,%s",
                replace_ctime(time()),fd,message ));
#endif
}
// ���� irc ����ʹ����
varargs void send_who(int fd,string id)
{
        if(undefinedp(id))   socket_write(fd,"WHO #bitlbee\r\n");
        else    socket_write(fd,"WHO "+id+"\r\n");

}
void process_who(int fd,string str)
{
        string id,ip,status,nick,name;
        //:rw.twku.net 352 whatup #bitlbee whatup 218-184-22-55.cm.dynamic.apol.com.tw rw.twku.net whatup H :0 С����
        if(sscanf(str,":%*s 352 %*s #bitlbee %s %s %*s %s %s :%*d %s",
                id,ip,name,status,nick) == 9) 
                users[fd]["list"][name] = ({ id,ip,name,status,nick});
        //:rw.twku.net 352 whatup whatup_ whatup mail2000.com.tw rw.twku.net whatup_ H :0 ���-��˭Ҫ gmail �ʺţ�����һ��-.
        //:%*s 352 %*s %*s %s %s %*s %s %s :%*d %*s
        if(sscanf(str,":%*s 352 %*s %*s %s %s %*s %s %s :%*d %s",
                id,ip,name,status,nick) == 10) 
                users[fd]["list"][name] = ({ id,ip,name,status,nick});
}

int process_send_msg(object me,string who,string msg)
{
        int fd = me->query_temp("im_fd");
        if(undefinedp(users[fd]) &&
            !undefinedp(users[fd]["list"][who]))
                return notify_fail("[IM Message] ��ʱѶϢ�ϵĺ�������û������ˣ�\n");
        socket_write(fd,"PRIVMSG #bitlbee :"+ who + ":"+msg+"\r\n");
        {
                string *n = users[fd]["list"][who];
                tell_object(me,sprintf(HIW HBBLU"���ü�ʱѶϢ���� %s : %s\n"NOR,
                        n[4]+"("+n[0]+"@"+n[1]+")\n["+who+"]",msg));
        }
        return 1;
}

int del_account(int fd,string protocol) 
{
        // Ҫ�����ߣ�����ɾ��
        socket_write(fd,"PRIVMSG #bitlbee :account off "+protocol+"\r\n");
        socket_write(fd,"PRIVMSG #bitlbee :account del "+protocol+"\r\n");
}

int register_account(int fd,string protocol,string account,string passwd)
{
        socket_write(fd,"PRIVMSG #bitlbee :account add "+protocol+" "+account+" "+passwd+"\r\n");
        socket_write(fd,"PRIVMSG #bitlbee :account on "+protocol+"\r\n");
}

mapping query_users(){ return users; }
