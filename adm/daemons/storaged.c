// leagued.c
/*
ÿ����һ��mapping
ÿ����һ����������������������Ź����ٸ���Ʒ
�����Ʒ������һ�����к�
���ݴ����к�ȡ����Ʒ
ԭ��������ܴ��
��������
���ô���Ҫ�����޸�

*/
#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

void create()
{
        mapping m;
        seteuid(getuid());
        restore();
        m=query_entire_dbase();
        if(!mapp(m)||undefinedp(m["data"]))
        {
                set("data",([]));
                save();
        }
}

void remove()
{
        save();
}

public void mud_shutdown()
{
        save();
}

public string query_save_file() { return DATA_DIR "storage"; }

//=================����ʵ�ֲ���=======================

int DoMonFee(object me,int mon)
{
        mixed res;
        int onl,fee,j;
        string arg,sql;
        arg=me->query("id");
        res=DATABASE_D->do_sql("select on_time,fee_time from users where id="+DB_STR(arg));
	if(!res)
	{
	        write("��ѯ������ѯ����Ϸ����Ա��\n");
	        return 0;
        }
	else
	{
		sscanf(res[0]+"0","%d",onl);
		sscanf(res[1]+"0","%d",fee);
		onl/=10;fee/=10;

		if(wizardp(this_player())) write("��Ŀǰ����Ϸ�������"+(fee-onl/3600)+"\n");
		
                if(fee - onl/3600 > (mon*150)+50  )
                {
                        sql="update users set fee_time=fee_time-"+150*mon+",endrgt=now() where id="+DB_STR(arg);
                        if ((DATABASE_D->do_sqlexec(sql))<1)
                        {
                                write("�۳�����ʧ�ܣ��뾡����ϵ��Ϸ����Ա����ԭ��\n");
                                return 0;
                        }
                        else
                        {
                                //�۳������ɹ�	                        
                                me->save();
                                //���´����ݿ�ȡ������֤�Ƿ�����Ѿ��ı�
	                       	res=DATABASE_D->do_sql("select fee_time from users where id="+DB_STR(arg));
	                       	sscanf(res[0]+"0","%d",j);
                                sql=sprintf("insert into reg_log (id,add_hours,new_fee_time,time) values (%s,%d,%d,now())",DB_STR(arg),-150*mon,j/10);
                                if(DATABASE_D->do_sqlexec(sql) < 1)
                                	log_file("mysql.log",ctime(time())+":"+sql);
                                write("�����Ϸ���Ѿ��۳���"+mon*150+"�㣡\n");
                        }
                }
                else
                {
                        write("�����Ϸ���Ѿ��������ڿ�ͨ�������ѣ�������ˣ����������"+(mon*150+50)+"��ſ��ԣ�����Ͽ�����ɡ�\n");
                        return 0;
                }
        }
        return 1;
}

int ExpireDate(string id)
{
        return query("data/"+id+"/expiredate");
}

int AccountOk(string id)
{
        return (ExpireDate(id)>=time());
}

int ExistAccount(string id)
{
        mapping m=query_entire_dbase();
        if(undefinedp(m["data"]))
        {
                set("data",([]));
                return 0;
        }
        return !undefinedp(m["data"][id]);
}

int CancelAccount(object me)
{
        mapping m;
        m=query("data/"+me->query("id"));
        if(!mapp(m))
        {
                write("�㻹û�п�����ѽ��\n");
        }
        else 
        {
                if(me->query_temp("sure_cancel")!=1)
                {
                    write("�ʻ�ȡ������Ҳ�����˻���ѵ�Ӵ��\n����㻹û��ã������ȰѶ�����ȡ�ߡ�\n(��ע�⣬�ٴ�����ȡ�����������ʾ����Ϣ)\n");
                    me->set_temp("sure_cancel",1);
                    return 1;
                }
                m=query("data/"+me->query("id")+"/objects");
                if(sizeof(m)==0)
                {
                        m=query("data/"+me->query("id"));
                        if(!mapp(m))
                        {
                            write("����ʻ�δ�ܳɹ�ȡ��������ϵ����Ա��\n");
                            return 1;
                        }
                        log_file("storage.log","cancel:"+me->query("name")+"("+me->query("id")+")ȡ�����ʻ������ͣ�"+m["typ"]+"\n");
                        delete("data/"+me->query("id"));
                        write("����ʻ��Ѿ��ɹ�ȡ����\n");
                }
                else
                {
                        write("ȡ���ʻ�ǰ�����Ƚ������Ʒȫ��ȡ������\n");
                }
        }
        return 1;
}
        
int OpenAccount(object me,string arg)
{
        mapping m;
        string id;
        int i,j,k,obcount;
        id=me->query("id");
        if(ExistAccount(id))
        {
            write("���Ѿ��������ˣ���ʹ��cw fee <������> ���⣡\n");
            return 1;
        }
        if(sscanf(arg,"%d",i)!=1)
            i=0;
        if(me->query_temp("yes_i_know")!=1)
        {
            me->set_temp("yes_i_know",1);
            write("�����ÿ�����Ϊ��\n����0\t��Ҫ100���ƽ�\n����1\t��Ҫ200���ƽ�\n����2\t��Ҫ��150����Ϸ��\n"
                "��ȷ�����Ѿ�֪�������ʷ�������ٴ����뿪�����������ʾֱ�ӿ�����\n");
            return 1;
        }
        switch(i)
        {
                case 0:
                        k=me->pay_money(1000000);
                        obcount=35;
                        break;
                case 1:
                        k=me->pay_money(2000000);
                        obcount=80;
                        break;
                case 2:
                        //����Ŀ۵�
                        if(k=DoMonFee(me,1))
                                obcount=500;
                        break;
                default:
                        k=0;
                        obcount=0;
        }
        if(k)
        {
                j=time()+86400*30;
                //��ʼ��һЩ����
                m=([
                        "cnt":0,
                        "typ":i,
                        "expiredate":j,
                        "max_obs":obcount,
                        ]);
                set("data/"+me->query("id"),m);
                log_file("storage.log","open:"+me->query("name")+"("+me->query("id")+")�����˵�"+i+"���ʻ���\n");
                write("��ϲ�㣬��Ŀ����Ѿ��ɹ�����Ĵ������Դ���"+obcount+"����Ʒ��������õ�"+CHINESE_D->cctime(j)+"Ϊֹ��\n");
                save();
                return 1;
        }
        else
        {
                if(i!=2)
                        write("�Բ������Ǯδ������������㹻��ǮȻ��ʹ��cw open 0 ��cw open 1��������\n"+i+" "+k);
                else
                        write("�Բ��������Ϸ�㲻�������������㹻����Ϸ��Ȼ��ʹ��cw open 2��������\n");
        }
        return 1;
}

void ListObject(object me)
{
        string k,res="��Ĵ�������У�\n";
        mapping m,om;
        int i,j;
        string id;
        id=me->query("id");
        if(!ExistAccount(id))
        {
                write("���ȿ�����\n");
                return ;
        }
        if(!AccountOk(id))
        {
                write("�������ѣ�\n");
                return ;
        }
        i=wizardp(me);
        m=query("data/"+id+"/objects");
        if(!mapp(m)||sizeof(m)<1)
        {
                write("�㻹û�д����ʲô��Ʒ��\n");
                return ;
        }
        j=0;
        foreach(k in keys(m))
        {
                om=m[k];
                j++;
                res+=sprintf("��%d����Ʒ ���%5s �� %20s(%10s) ������%d %s\n",j,k,om["name"],om["id"],om["num"],(i?om["file"]:""));
        }
        me->start_more(res);
}

void PutObject(object me,string arg)
{
        object ob;
        string file,id,key,str;
        mapping m;
        int i,j;
        id=me->query("id");
        if(!ExistAccount(id))
        {
                write("���ȿ�����\n");
                return ;
        }
        if(!AccountOk(id))
        {
                write("�������ѣ�\n");
                return ;
        }
         ob=present(arg,me);
        if(!objectp(ob))
        {
                write("û�з�����Ʒ"+arg+"��\n");
                return ;
        }
        file=file_name(ob);
        //ʲô������Ʒ���ܴ��أ�
        if(strsrch(file,"#")==-1 || ob->is_character() || living(ob))
        {
                write("�Բ��𣬸���Ʒ�����Դ��棡\n");
                return ;
        }
        if(ob->query("money_id"))
        {
                write("�Բ��𣬽�Ǯ�����Ա����棡\n");
                return ;
        }
        //����ж�ʳ���أ�
        if(mapp(m=ob->query_entire_dbase()))
        {
                if(!undefinedp(m["food_remaining"])||!undefinedp(m["food_supply"]))
                {
                        write("�Բ���ʳ�ﲻ���Դ��棡\n");
                        return ;
                }
        }

        key="data/"+id+"/";
        if(sizeof(query(key+"objects"))>=query(key+"max_obs"))
        {
            write("�Բ������Ѿ��洢��"+query(key+"cnt")+"����Ʒ�ˡ������ٴ洢����Ķ����ˡ�\n");
            return ;
        }
        
        str=ob->query("unit");
        if(!str) str="��";
        j=ob->query_amount();
        if(j<1) j=1;
        m=([
                "file":file,
                "name":ob->query("name"),
                "id":ob->query("id"),
                "unit":str,
                "num":j,
                ]);
        i=query(key+"cnt");
        i++;
        set(key+"cnt",i);
        set(key+"objects/"+i,m);
        destruct(ob);
        if(objectp(ob))
        {
                write("���󣡴���ʧ�ܣ�����ϵ����Ա��\n");
                set(key+"cnt",i-1);
                delete(key+"objects/"+i);
        }
        else
                write(m["name"]+"�Ѿ�������ˣ���ţ�"+i+" ��\n");
        //Ҳ��Ӧ��������������
        save();
        return ;
}

void GetObject(object me,string arg)
{
        string kid,*ks,id;
        string res="";
        object ob;
        mapping m;
        int i,ok=0;
        id=me->query("id");
        if(!ExistAccount(id))
        {
                write("���ȿ�����\n");
                return ;
        }
        if(!AccountOk(id))
        {
                write("�������ѣ�\n");
                return ;
        }
         if(!arg||arg=="")
        {
                write("��Ҫȡ��ʲô��Ʒ��\n");
                return ;
        }
        arg=lower_case(arg);
        kid="data/"+id+"/objects";
        m=query(kid);
        if(sizeof(m)<1)
        {
                write("��ʲô��Ʒ��û�д����ţ���������ʲô��\n");
                return ;
        }
        ks=keys(m);
        for(i=0;i<sizeof(ks);i++)
        {
                if(ks[i]==arg || m[ks[i]]["id"]==arg)
                {
                        m=m[ks[i]];
                        ok=1;
                        break;
                }
        }
        if(ok)
        {
                res=m["file"];
                sscanf(res,"%s#%*s",res);
                ob=new(res);
                if(objectp(ob))
                {
                        ob->set_amount(m["num"]); 
                        if(ob->move(me))
                        {
                                write("��Ӵ����ȡ����"+m["name"]+"("+m["id"]+") ��\n");
                                //write("��Ӵ����ȡ����"+ob->query("name")+"("+ob->query("id")+")��\n");
                                delete(kid+"/"+ks[i]);
                                //Ҳ��Ӧ��������������
                                save();
                                return;
                        }
                        else
                        {
                                write("������������Ʒ���ɹ��أ��޷�ȡ������Ʒ��\n");
                        	return;
                        }
                }
        }
        write("ȡ����Ʒ��������cw get <��Ʒ���>����ſ���cw listָ��鿴��\n");
        return ;
}

int DoFee(object me,string arg)
{
    int mon,k,i;
    string id=me->query("id");
    mon=1;
    if(!ExistAccount(id))
    {
            write("���ȿ�����\n");
            return 1;
    }
    if(AccountOk(id))
    {
            write("�㻹û��Ҫ���ѣ���ĵ���ʱ����"+CHINESE_D->cctime(query("data/"+id+"/expiredate"))+"\n");
            return 1;
    }
    if(arg)
        sscanf(arg,"%d",mon);
    if(mon<1) mon=1;
    if(mon>3)
    {
        write("�Բ���һ������������£�\n");
        return 1;
    }
    switch(i=query("data/"+id+"/typ"))
    {
            case 0:
                    k=me->pay_money(1000000*mon);
                    break;
            case 1:
                    k=me->pay_money(2000000*mon);
                    break;
            case 2:
                    //����Ŀ۵�
                    k=DoMonFee(me,mon);
                    break;
            default:
                    k=0;
    }
    if(k)
    {
            int expiredate=query("data/"+id+"/expiredate");
            expiredate+=86400*30*mon;
            set("data/"+id+"/expiredate",expiredate);
            log_file("storage.log","open:"+me->query("name")+"("+me->query("id")+")Ϊ��"+i+"���ʻ�����"+mon+"���£�\n");
            write("��ϲ�㣬��������Ѿ��ɹ���������õ�"+CHINESE_D->cctime(expiredate)+"Ϊֹ��\n");
            save();
            return 1;
    }
    else
    {
            if(i!=2)
                    write("�Բ������Ǯδ������������㹻��ǮȻ��ʹ��cw fee <������> ���������ѣ�\n"+i+" "+k);
            else
                    write("�Բ��������Ϸ�㲻�������������㹻����Ϸ��Ȼ��ʹ��cw fee <������> �����ѣ�\n");
    }
    return 1;
}

int ShowHelp()
{
        string helpstr=
        "help              ��ȡ��������Ϣ\n"
        "fee <����>        Ϊ��������ѣ����Ƿ������Ȳ�Ƿ�ѡ�����Ϊ������\n"
        "open <0-2>        ���财����ʻ����ڸ������Ĳ���0-2�ֱ�������ֲ�ͬ�����÷�ʽ\n"
        "cancel            ȡ���Լ��Ĵ�����ʻ���������Ƚ��������Ʒȫ��ȡ������ſ�ȡ��\n"
        "list              �г��Լ��Ĵ�����ﶼ��Щʲô��Ʒ\n"
        "put <��ƷID>      �����ϵ�ĳ����Ʒ�ŵ�����������ʲô�����Դ�ŵģ�\n"
        "get <���|��ƷID> ���������ĳ����ŵ���Ʒȡ����\n"
        ;
        write(helpstr);
}
