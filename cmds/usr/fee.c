//��ѯ��Ϸ����ʱ������ֱ�Ӵ����ݿ�ȡ���ݣ�Ӧ�ý�ֹƵ����ȡ
//Write By JackyBoy@TOMUD 2001/5/15
#include <ansi.h>

inherit F_CLEAN_UP;

string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
string status_color(int current, int max);
string tribar_graph(int val, int eff, int max, string color);
int buy_monfee();
void verify_pass(string arg,object me,int c);

int main(object me,string arg)
{
	string *res;
	int onl,fee,monfee;
	string line;
	
	if (! arg|| !wizardp(me))
	{
		if(!wizardp(me)&&me->query_temp("last_query_fee") > time() - 60 )
			return notify_fail("�벻ҪƵ����ѯ������Ϣ!\n");
		me->set_temp("last_query_fee",time());
		arg=me->query("id");
	}
	arg = lower_case(arg);
	if(arg=="ת�·�" ||arg == "buy_monfee" ||arg == "���·�"  || 
		arg=="���·�" || arg=="buymonfee" ||arg=="buy monfee")
	{
		buy_monfee();
		return 1;
	}
	if(me->id(arg))
		me->save();
	seteuid(getuid(me));
	res=DATABASE_D->do_sql("select on_time,fee_time,subgy(f_dbase,'monfee') from users where id="+DB_STR(arg));
	line=" ��ע�⣬������Ǽ�ʱ������ܻ�����ʵ���������ƫ�\n";
	line+= HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR+
			" �û� "+HIR+arg+NOR+" �Ľ��Ѽ�ʹ��������£�\n";
	if(!res) line+="δ����ָ������("+arg+")���û����ϣ�\n";
	else
	{
		int i,j;
		sscanf(res[0]+"0","%d",onl);
		sscanf(res[1]+"0","%d",fee);
		onl/=10;fee/=10;
		i=onl%3600;
		onl/=3600;
		j=i%60;
		line += " �ۼƹ���ʱ�䣺 "+HIY+fee+NOR+" Сʱ\n";
		line += " �ۼ�ʹ��ʱ�䣺 "+HIY+(onl)+NOR+" Сʱ ";
		if(i) line+=HIY+(i/60)+NOR+" �� ";
		if(j) line+=(HIY+j)+NOR+" ��";
		if(onl>=fee)
			line += "\n �㹺�����Ϸʱ���Ѿ�ʹ�����ˣ�����ϵTomudС��http://www.tomud.com ����������Ϸʱ�䣡\n";
		else
			line += "\n ʹ������� " + tribar_graph(onl, fee, fee, HIY) + "\n";
		sscanf(res[2],"%*s%d%*s",monfee);
		if(monfee!=0)
			line += " ����·ѵ���ʱ��Ϊ��"+CHINESE_D->cctime(monfee)+"\n �����ʹ�������ڵ�����{"+HIY+"fee ���·�"+NOR+"}�����Ӱ���ʱ�䡣\n";
		else
			line += " ���δת���·ѣ������ʹ��{"+HIY+"fee ���·�"+NOR+"}����ת��Ϊ���¼Ʒѷ�ʽ��\n";
		if(fee==18)
			line+=ALERT("��ã��㻹δ�Դ������ɫ����ע�ᣡ�뼰ʱ����ע�Ṻ��ʱ�䣡$$δע��������� "+
				UNREG_IDLE+" ��δ���������ǽ�����䵵��!");
	}
	line += HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR;
	tell_object(me,line);
	return 1;
}

string status_color(int current, int max)
{
	int percent;

	if (max) percent = current * 100 / max;
	else percent = 100;

	if (percent > 100) return HIC;
	if (percent >= 90) return HIG;
	if (percent >= 60) return HIY;
	if (percent >= 30) return YEL;
	if (percent >= 10) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val * 25 / max) * 2 - 1]
		+ ((eff > val) ? blank_string[(val * 25 / max) * 2..(eff * 25 / max) * 2 - 1] : "") + NOR;
}

//�������ֻ��this_player()���в���������һ��Ҫע�ⲻҪ��ͼ���������ˣ�
int buy_monfee()
{
        //����ֹˢ���жϣ���Ϊ�ò���ֱ���漰�����ݿ����
        object me=this_player();
        me->save();
	if(!wizardp(me)&&me->query_temp("last_query_fee") > time() - 300 )
	{
		write("�벻ҪƵ������ת�����������ټ�������!\n");
		return 1;
        }
	me->set_temp("last_query_fee",time());
	if(me->query("doing")=="scheme")
	{
		write("�Բ��𣬼ƻ�ʱ���ܽ������������");
		return 1;
	}
	write("��������Ĺ������룬��ȷ�ϴ˴β�����");
	input_to("verify_pass",me,0);
	return 1;
}

void verify_pass(string arg,object me,int c)
{
        string sql;
        int onl,fee;
        mixed res;
	mapping m=me->query_entire_dbase();
	string my_pass;
	object lkob=me->query_temp("link_ob");
	if(!objectp(lkob))
	{
		write(ALERT("�Բ�����������ɫ״̬���ԣ������ҹ���Ա������һ�°ɣ�"));
		return ;
	}
	my_pass=lkob->query("ad_password");
	if(arg=="quit"||arg==""||arg=="exit")
	{
		write("���˳���ת�·ѵĲ�����\n");
		return ;
	}
	if(crypt(arg, my_pass) != my_pass)
	{
		if(c>2)
		{
			write(ALERT("�Բ�����ȷ����û�Ǵ�������������԰ɣ�"));
			return ;
		}
		write(ALERT("�������벻�ԣ�(��س�������exit�����˳�ת�·Ѳ���)")+"\n��������Ĺ�����������֤������");
		input_to("verify_pass",me,++c);
		return ;
	}
	arg=m["id"];
	res=DATABASE_D->do_sql("select on_time,fee_time from users where id="+DB_STR(arg));
	if(!res) write("��ѯ������ѯ����Ϸ����Ա��\n");
	else
	{
		int i,j;
		sscanf(res[0]+"0","%d",onl);
		sscanf(res[1]+"0","%d",fee);
		onl/=10;fee/=10;
		i=m["monfee"]-time();
		if(i<0) i=0;
		i/=86400;//���»��ж����죡
		write("�㽻������Ϸ����"+fee+"������"+(fee-onl/3600)+"\n");
                if(fee - onl/3600 > 318 && i<120 )
                {
                        sql=sprintf("update users set fee_time=fee_time-300,endrgt=now() where id="+DB_STR(arg));
                        if ((DATABASE_D->do_sqlexec(sql))<1)
                        {
                                write("�۳�����ʧ�ܣ�δ�ܳɹ������·ѣ��뾡����ϵ��Ϸ����Ա����ԭ��\n");
                                return ;
                        }
                        else
                        {
                                //�۳������ɹ�	                        
	                        if(m["monfee"]>time())
                                        m["monfee"]+=86400*30;//����������·ѣ������·��ϼ�
                                else
                                        m["monfee"]=time()+86400*30;
                                me->save();
                                //���´����ݿ�ȡ������֤�Ƿ�����Ѿ��ı�
	                       	res=DATABASE_D->do_sql("select fee_time from users where id="+DB_STR(arg));
	                       	sscanf(res[0]+"0","%d",j);
	                       	write("300����Ϸ��۳��ɹ��������㽻������Ϸ����"+j/10+"\n");
	                       	write("���·ѳɹ����·������ӳ��� "+CHINESE_D->cctime(m["monfee"])+"������"+(i+30)+"�� ��\n");
                                sql=sprintf("insert into reg_log (id,add_hours,new_fee_time,time) values (%s,%d,%d,now())",DB_STR(arg),-300,j/10);
                                if(DATABASE_D->do_sqlexec(sql) < 1)
                                	log_file("database",ctime(time())+":"+sql);
                        }


                }
                else
                {
                	if(i>=120)
                		write("�Բ�����Ŀǰ�Ѿ���������£�ʣ��"+i+"�죡���ˣ����������ֻ������£�");
                	else
                        	write("��ĵ����Ѿ��������·��ˡ���ȷ�ϻ���318����Ϸ�㡣\n");
                }
	}
}
int help()
{
	write(@HELP
ָ���ʽ : fee
           fee <��������>                   (��ʦר��)

���ָ�������ʾ���ָ������Ľ��������
���ѵ���Ϣ�������ҳ [http://www.tomud.com] ��

HELP );
    return 1;
}

