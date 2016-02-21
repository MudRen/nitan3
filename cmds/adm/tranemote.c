//tranemote.c
//Made by jason@pkuxkx
//FreeWare
#define ERROR "ָ���ʽ��tranemote emote ��Դemote�ļ�\n"
inherit F_SAVE;
string source_file="";
mapping emote=([]);
string query_save_file()
{
        return source_file;
}
int main(object me,string arg)
{
        mapping old_emote=([]);
        string ee,file,*key,*key2;

           if (! SECURITY_D->valid_grant(me, "(admin)")) 
              return 0; 
        if(!arg||arg=="")
                return notify_fail(ERROR);
        if(sscanf(arg,"%s %s",ee,file)!=2)
        {
                return notify_fail(ERROR);
        }
        if(file_size(file+".o")<=0)
                return notify_fail("��emoteԴ�ļ�����\n" );
        source_file=file;
        if(!restore())
        {
                return notify_fail("emoteԴ�ļ��޷�Restore��\n");
        }
        old_emote=emote;
        if(!mapp(old_emote)||sizeof(old_emote)<=0)
        {
                return notify_fail("emoteԴ�ļ��޷�Restore��\n");
        }
        source_file="/data/emoted";
        if(!restore())
        {
                return notify_fail("emoteĿ���ļ�����\n");
        }
        if(!mapp(emote)||sizeof(emote)<=0)
        {
                return notify_fail("emoteĿ���ļ��޷�Restore��\n");
        }
        key=keys(old_emote);
        if(wizardp(me)&&wizhood(me)=="(admin)")
        {
                int unit=0;
                string nowtime;
                if(ee=="-All")
                {
                        nowtime=""+time();
                        cp("/data/emoted.o","/data/emoted.o."+nowtime);
                        key2=keys(emote);
                        shout("Emote �ļ�ת���С�������\n");
                        for(int i=0;i < sizeof(key);i++)
                        {
                                reset_eval_cost();
                                if(member_array(key[i],key2)!=-1) continue;
                                if(!mapp(old_emote[key[i]])) continue;
                                EMOTE_D->set_emote(key[i],old_emote[key[i]]);
                                write(key[i]+"\n");
                                unit++;
                        }
                        write("Emote �ļ� "+file+" ת������/data/emoted.o�ɹ���\
n");            
                        write("һ����"+chinese_number(unit)+"��emoteת���ɹ���\n
");
                        write("����emote����Ϊ"+"/data/emoted.o."+nowtime+"\n");
                        log_file("tran_emote",getuid(me)+"ת�� "+file+" �е�Emot
e���뵱ǰEmote�С�
\n"+
                        "ʱ�䣺"+ctime(time())+"\n"+
                        "����emote����Ϊ"+"/data/emoted.o."+nowtime+"\n");
                        return 1;
                }
        
        }
        ee=lower_case(ee);
        if(member_array(ee,key)==-1)
        {
                return notify_fail(ee+" �������� "+file+"��\n");
        }
        if(!mapp(old_emote[ee]))
        {
                return notify_fail(ee+" ����һ���Ϸ���emote��\n");
        }
        if(!undefinedp(emote[ee]))
        {
                return notify_fail(ee+" ������Ŀ��emote�ļ��У����ܸ��ǡ�\n");
        }
        EMOTE_D->set_emote(ee,old_emote[ee]);
        write("Emoteת�� "+ee+" �ɹ���\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ��tranemote emote ��Դemote�ļ�
����Դemote�ļ��е�ָ��emote���뵱ǰemote�ļ��С�
��ʽ����tranemote -All ��Դemote�ļ�
����Դemote�ļ������е�ǰemote�ļ���û�е�emote���롣
ͬʱ����ǰemote�ļ���ʱ�䱸�ݡ�
HELP
        );
        return 1;
}

