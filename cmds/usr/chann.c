//��ѯ��Ϸ����ʱ������ֱ�Ӵ����ݿ�ȡ���ݣ�Ӧ�ý�ֹƵ����ȡ
//Write By JackyBoy@XAJH 2001/5/15
#include <ansi.h>

inherit F_CLEAN_UP;

mapping channels;
string *chann;
string cmdhelp=
"ѡ�������ʽ��<"HIR"Ƶ��"HIG">   <"HIR"����"HIG">\n"+
"����Ƶ��Ϊ��������ú�ʹ�õ�Ƶ����Ӣ����������"HIC"chat"HIG","HIM"rumor"HIG"��\n"+
"������Ϊ"HIR"public"HIG","HIR"main"HIG"����"HIR"none"HIG"�����У�\n"+
HIR"public"HIG"��ʾ����Ƶ��������Ϣ��ʾ��������Ϣ����\n"+
HIR"main  "HIG"��ʾ����Ƶ��������Ϣ��ʾ������Ϣ������\n"+
HIR"none  "HIG"��ʾ��Ƶ���رգ����ٽ���Ƶ����Ϣ\n"+
"��Ҳ��������"HIR"exit"HIG"�˳�����ѡ����������"HIR"help/?"HIG"��ȡ����Ϣ��\n";

int do_chan(string,object,int);
int show_main(object);

int main(object me,string arg)
{
        channels=CHANNEL_D->query_chann();
        chann=keys(channels);
        //����ʦ�͹��˵���Щ��ʦƵ������
        if(!wizardp(me)) chann -= ({"wiz","sys","debug"});
        chann -= ({"shout"});
        
        if(arg)
                return do_chan(arg,me,1);
        show_main(me);
        return 1;
}

int show_main(object me)
{
        string *tuned_ch,s,str,state;
        
        tuned_ch = me->query("channels");

        str=me->name()+"��Ƶ������Ϊ��\n"HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR;
        str+=sprintf(HIC" %-10s        %-8s         %-8s\n\n","Ƶ������","Ƶ������","Ƶ��״̬");
        foreach(s in chann)
        {
                if( !pointerp(tuned_ch) || !sizeof(tuned_ch) ) state=HIG"�ر�";
                else if(member_array(s,tuned_ch)==-1) state=GRN"�ر�";
                else if(me->query("chann/"+s)) state=HIC"������";
                else state=HIY"��������";
                str+=sprintf(WHT"[%-10s]       [%-8s]        %-8s\n",s,channels[s]["name"],state);
        }
        str+="\n"HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR;
        str+="����������("HIY"help"NOR"��������"HIY"exit"NOR"�˳�)��";
        write(str);
        input_to( (: do_chan :) ,me);
        return 1;
}


void open_ch(object me,string verb)
{
        string *tuned_ch;
        if (! pointerp(tuned_ch = me->query("channels")))

                me->set("channels", ({ verb }));
        else if (member_array(verb, tuned_ch) == -1)
                me->set("channels", tuned_ch + ({ verb }));
}

int do_chan(string arg,object me,int once)
{
        string ch,cmd;
        int tmp;
        
        if(!arg)
        {
                write("\n����������("HIY"help"NOR"��������"HIY"exit"NOR"�˳�)��");
                input_to( (: do_chan :) ,me);
                return 1;
        }               
        arg=lower_case(arg);
        arg=me->remove_leading_space(arg);
        while(strsrch(arg,"  ")!=-1) arg=replace_string(arg,"  "," ");
        switch(arg)
        {
                case "?":
                case "help":
                        //��ʾ������Ϣ
                        write(HIG+cmdhelp+NOR);
                        break;
                case "q":
                case "quit":
                case "exit":
                        write(HIG"�˳�Ƶ�����ó��򡣡���\n"NOR);
                        once=1;break;
                default:
                        //���г�����
                        tmp=0;
                        if(sscanf(arg,"%s %s",ch,cmd)==2)
                        {
                                switch(cmd)
                                {
                                        case "public":
                                                if(member_array(ch,chann)!=-1)
                                                {
                                                        open_ch(me,ch);
                                                        me->delete("chann/"+ch);
                                                        write(HIG"�����" + channels[ch]["name"] + "Ƶ����\n"NOR);
                                                }
                                                else write(HIG"Ƶ������û��"+HIY+"ch"+HIG+"���Ƶ����\n"NOR);
                                                break;
                                        case "main":
                                                if(member_array(ch,chann)!=-1)
                                                {
                                                        open_ch(me,ch);
                                                        me->set("chann/"+ch , 1);
                                                        write(HIG"�����" + channels[ch]["name"] + "Ƶ����\n"NOR);
                                                }
                                                else write(HIG"Ƶ������û��"+HIY+"ch"+HIG+"���Ƶ����\n"NOR);
                                                break;
                                        case "none":
                                                if(member_array(ch,chann)!=-1)
                                                {
                                                        me->set("channels",me->query("channels") - ({ch}) );
                                                        write(HIG"��ر���" + channels[ch]["name"] + "Ƶ����\n"NOR);
                                                }
                                                else write(HIG"Ƶ������û��"+HIY+"ch"+HIG+"���Ƶ����\n"NOR);
                                                break;
                                        default:
                                                tmp=1;
                                }
                        }
                        else tmp=1;
                        if(tmp)
                                write(HIG+cmdhelp+NOR);
        }
        if(!once) show_main(me);
        return 1;
}

int help()
{
        write(@HELP
ָ���ʽ : chann                         (�˵�ģʽ)
           chann    <���>             (ֱ��ָ��)

���ָ�����������������Ƶ����Ϣ����ʾ���رջ�����ʾλ�á�
��ʾλ����main�������ڣ���public��������Ϣ���ڣ�����ѡ��
���λ������Ϊû�У�none�������ʾҪ�رո�Ƶ����

�����ʽΪ��<Ƶ��> < main | public | none>
Ƶ��Ϊ��Ҫ���в�����Ƶ�����ƣ�������ŵ���none��ʾҪ�رո�
Ƶ��������main��ʾҪ��Ƶ��������Ϣ��ʾ�������򴰿ڣ����
��public����ʾ��������Ϣ���򴰿ڡ�

ֱ��ָ��������ģʽ���ӣ�
chann chat none    ���� �˲���Ϊ��chatƵ���ر�
chann chat main    ���� �˲�������chatƵ������ʾ��������
chann rumor public ���� �˲������ڹ������ڴ�rumorƵ��
HELP );
    return 1;
}


