// suicide.c

#include <ansi.h>
#include <login.h>
inherit F_DBASE;
inherit F_CLEAN_UP;
private int slow_suicide(object me);
private int halt_suicide(object me);
int help(object me);

void create() 
{
	seteuid(getuid());
	set("name", "��ɱָ��");
	set("id", "suicide");
	set("channel_id", "Ͷ̥����");
}

int main(object me, string arg)
{
	object *inv;
	int *res;
	int i;
	int real_suicide=0;
	int is_member=0;
	
	if (me->is_busy())
		return notify_fail("����һ��������û��ɡ�\n");
	real_suicide=0;
	inv = deep_inventory(me);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (! userp(inv[i]) && ! playerp(inv[i])) continue;
		return notify_fail("�����ϻ��и�������أ��벻��Ҳ��ѽ��\n");
	}

	if (! arg)
	{
		write(HIR"�����Ӳ������С�\n"NOR);
		help(me);
		return 1;
	}
	arg=lower_case(arg);
	res=DATABASE_D->do_sql("select fee_time from users where id='"+me->query("id")+"'");
	is_member= (res[0] > 18)?1:0;
	switch(arg)
	{
		case "-f":
			real_suicide=(is_member)?0:1;
			break;
		case "-x":
			if(!is_member)
				return notify_fail("�Բ����㲻�ǽ��ѻ�Ա����Ȩʹ�� -x ѡ�\n");
			real_suicide=1;
			break;
		default:
			return help(me);
	}
	if(!real_suicide&&!is_member)
		return notify_fail("�Բ���ֻ�н��ѻ�Ա�ſ���ʹ��Ͷ̥���ܡ�\n");
	if(real_suicide)//��ɱģʽ
		write(ALERT("��ע�⣬������Ѿ�Ϊ����ʺŹ�������Ϸʱ�䣬$$��ɱ����ѹ����ʱ��һ�������$$")+
			HIR+"��ע�⣬������Ѿ�Ϊ����ʺŹ�������Ϸʱ�䣬��Զ��ɱ����ѹ�\n"+
			"���ʱ��һ�������\n"+NOR+
			"��ѡ����"+HIG+"��Զ����"+NOR+"����ɱ��ʽ�������������Ͻ���Զɾ���������\n"+
			"���������ȷ���Ļ���������ȷ�����룬�����������������˳���\n���������Ĺ������룺");
	else//Ͷ̥ģʽ
		write("��ע�⣬��ѡ����"+HIG+"����Ͷ̥"+NOR+"������Ͷ̥�����³�ʼ��������\n"+
			"���Ǳ��������Ӣ�������Ա�����͹���������ʱ���\n"+
			"���ϡ�"+HIR+"�����ؾ�����ʦ����Ϊ������ѡ������ֲ��ġ�\n"+NOR+
			"�����ȷ������������ȷ�Ĺ������룬����������������\n"+
			"���˳������������Ĺ������룺");
	input_to("check_password", 1, me, real_suicide);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("ad_password");
	if (! stringp(old_pass) || crypt(passwd, old_pass) != old_pass)
	{
		write(HIR "���������ע�⣬���������������롣\n");
		return;
	}

	tell_object(me, HIR "\n�����Ҫ"+((forever)?"��ɱ":"����Ͷ̥")+"�ˣ������ʮ��"
		    "���ڲ���ڣ�����Ĳ�������ˡ�\n\n" NOR);
	me->set_temp("suicide/time", time());
	me->set_temp("suicide/last", 0);
	me->set_temp("suicide/forever",forever);
	me->set_temp("suicide/from", query_ip_number(me));
	me->start_busy((: slow_suicide, me :),
	       (: halt_suicide, me :));
}

private int slow_suicide(object me)
{
	object link_ob, *inv;
	int t, i;

	if (! objectp(me))
		return 0;

	t = time() - me->query_temp("suicide/time");
	if (t < me->query_temp("suicide/last"))
	{
		me->delete_temp("suicide/");
		return 0;
	}

	if (t < 30)
	{
		if (t - me->query_temp("suicide/last") < 5)
			return 1;

		tell_object(me, HIR "\n�㻹��" + chinese_number(30 - t) +
			    "������ϸ����(" HIC "haltֹͣ" HIR ")��\n" NOR);
		me->set_temp("suicide/last", t / 5 * 5);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if (! link_ob || ! interactive(me)) return 0;

	log_file("static/suicide",
		 sprintf("%s %s commits a suicide from %s\n",
			log_time(), log_id(me),
			me->query_temp("suicide/from")));

	seteuid(getuid());
	
	// add by Shure@tomud.com
	inv = deep_inventory(me);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (! userp(inv[i]) && ! playerp(inv[i])) continue;
		tell_object(me, HIR"�����ϻ��и�������أ��벻��Ҳ��ѽ��\n"NOR);
		return 0;
	}
        	
	if(me->query_temp("suicide/forever"))
	{
		//������ɱ
		write("\n�ðɣ�������:)��\n\n");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s��ɱ�ˣ��Ժ�����Ҳ������������ˡ�",
			me->name()));
		tell_room(environment(me), me->name() +
			"�������ǰ�������̣�������ʧ��...\n"+REM0(me), ({me}));
		message("system",REM2(me),users());
		UPDATE_D->remove_user(me->query("id"));
	}
	else
	{
		//����Ͷ̥
		object ob,user;
		string *res;
		mapping my=me->query_entire_dbase();
		ob=me->query_temp("link_ob");//�϶��ܷ�����ȷOB
		user=LOGIN_D->make_body(ob);
		res=DATABASE_D->do_sql("select fee_time from users where id='"+me->query("id")+"'");
		
		//Ӧ�ñ��������
		user->set("name",my["name"]);
		user->set("id",my["id"]);
		user->set_name(my["name"],({my["id"]}) );
		user->set("str", 14);
		user->set("dex", 14);
		user->set("con", 14);
		user->set("int", 14);
		user->set("per", 20);
		user->set("type", my["type"]);
		user->set("gender", my["gender"]);
		user->set("onl_time",my["onl_time"]);//��¼�Ѿ�ʹ�õķ���
		user->set_temp("fee_time",res[0]);//��¼�ܷ���
		user->set("age",my["age"]);
		if(my["monfee"]>0) user->set("monfee",my["monfee"]);

		user->set("surname",my["surname"]);
		user->set("purename",my["purename"]);
		user->set_temp("link_ob",ob);
		ob->set_temp("body_ob",user);
		//��ʾ��Ϣ
		tell_room(environment(me),me->query("name")+"ͻȻ�����ڵأ�����Խ��ԽС��ʹ����֡�һ���ۣ���Ȼƾ����ʧ�� ... ...\n");
		CHANNEL_D->do_channel(this_object(),"rumor","��˵"+me->query("name")+"("+me->query("id")+")���ȥ�ˡ���ɱ����Ͷ̥ȥ�ˡ�\n");
		if(exec(user,me)) //������Ȩת�Ƶ�user�ϡ�
		{
			write("����Ͷ̥�ɹ���\n");
			log_file("static/suicide_f",ctime(time())+" "+me->name()+"("+me->query("id")+") ����Ͷ̥�ɹ���\n");
		}	
		else
			log_file("static/suicide_f",ctime(time())+" "+me->name()+"("+me->query("id")+") ����Ͷ̥ʧ�ܣ�\n");
		user->setup();
		UPDATE_D->clear_user_data(me->query("id"), "all"); //����������
		destruct(me); //�ݻپ����
		//�����¼�¼
		LOGIN_D->init_new_player(user);
		UPDATE_D->check_user(user);
		//DATABASE_D->db_new_player(ob,user);
		user->move(REGISTER_ROOM);//�ƶ���ע�ᴦ����Ͷ̥
		user->set("startroom",REGISTER_ROOM);
		user->save();

	}
	return 0;
}

private int halt_suicide(object me)
{
	tell_object(me, HIG "�������"+(me->query_temp("suicide/forever")?"Ѱ��":"����Ͷ̥")+"����ͷ��\n" NOR);
	me->delete_temp("suicide");
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: suicide [-f]

��ע�⣬������Ѿ�Ϊ����ʺŹ�������Ϸʱ�䣬
��ɱ����ѹ����ʱ��һ�������
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
 
suicide    : ��ʾ����
suicide -f : �ǻ�Ա�����ô�ѡ����ȫ��Ĩȥ
             �Լ������ϡ�����Ա�ô����
             ���ǽ���һ������������Ͷ̥��
             ��Ա����Ӣ�����ƣ��Ա���Ϸ
             ʱ�䣬����Ƚ��õ����档
suicide -x : ��Աר��ѡ������������Ľ�
             ��Ա������Ĩ�����������Ϸʱ
             ��Ҳ��Ĩȥ��������ʹ�á�����
             �����Դ���Ϊ����������κβ�
             �ȴ�ʩ����ұ����Լ��е��ɴ�
             �������κ���ʧ�� 
������ѡ�� :)
 
HELP );
	return 1;
}
