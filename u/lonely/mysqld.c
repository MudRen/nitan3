// mysql_d.c
// by JackyBoy. (Port to TinyMud).

inherit F_DBASE;

#include <mysql.h>

#undef DEBUG

#define REG_BONUS 18

class target
{
	string host;
	string user;
	mapping quest;
}

#ifdef STATIC_LINK
protected int db_handle = 0;
#endif

protected mixed *all_target = ({});
string *do_sql(string);
int do_sqlexec(string sql);

//The Functions "db_query" & "db_set" can only access these columns!
//I think: common global variables should be the static Type!
//By JackyBoy@XAJH 2001/3/28
//Port To UltralHell By JackyBoy@XAJH 2001/5/8
//db_save_all()ʱ����ĺü����ֶ�Ӧ�ô�DBASE�������������洢
nosave string *cols=({"id","name","pass","adm_pass","online","onl_time","fee_time","last_from","last_on",
						"last_off","endrgt","regtime","login_dbase","f_autoload","f_dbase","f_damage",
						"f_condition","f_attack","f_skill","f_alias","f_user"});
//ȷ���û���������ʱ�Ƿ�У�����ݺ� ��ʱ�ٴ�
int crc_status() { return query("crc_status");}
protected void chat(string msg)
{
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(),"sys",msg);
	log_file("mysql.log","chat() call:"+msg+"\n");
#endif
}

protected void init_target()
{
	if(!sizeof(all_others_db))
		return;

	foreach(string h, string u in all_others_db)
	{
		class target one;
		one = new(class target);
		one->host = h;
		one->user = u;
		one->quest = ([]);
		all_target += ({ one });
	}
}


protected void log_error(string func,mixed err)
{
	log_file("mysql.log",sprintf("%s ERROR ** %s\n%O\n",func,ctime(time()),err));
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
	mixed n;

	n = db_connect(DB_HOST, DATABASE, DB_USER);

	if(intp(n) && (n > 0))	// ���ӳɹ�
#ifdef STATIC_LINK
	{
		db_handle = n;
		chat("�Ѿ���MySQL���ݿ⽨�����ӣ����Ӻ��ǣ�"+n);
		return;
	}
#else
		return n;
#endif

	else
	{
		log_error("db_connect",n);
#ifdef STATIC_LINK
		call_out("connect_to_database",30);
		return;
#endif
		return 0;
	}
}

protected void close_database(int db)
{
	mixed ret;

	if(!intp(db) || (db < 1))
		return 0;

	ret = db_close(db);

	if(intp(ret) && (ret == 1))
		return;

	else
		log_error("db_close",ret);
}

protected void create()
{
	seteuid(ROOT_UID);
	set("channel_id","���ݿ�");
#ifdef STATIC_LINK
	connect_to_database();
#endif
	init_target();
	set("crc_status",1);
}

#ifdef STATIC_LINK
void remove(string id)
{
	close_database(db_handle);
}
#endif

int db_remove_player(string id) //�������Ӽ�¼��ֻ���޸��Ѿ��еļ�¼������ֶεĺ���ֵ
{
	int db;
	string sql;
	mixed ret;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return 0;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = "delete from users where id = '" + id + "'";
	chat("ִ��ɾ����䣡"+sql);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
		log_error("db_delete.db_exec", ret + "\n" + sql);
		return 0;
	}
	if(ret<1) return 0;
#ifndef STATIC_LINK
	close_database(db);
#endif
	return ret;
}

//Notes:db_query() & db_set() Write By JackyBoy for common MySQL access with LPC 2001/3/28
int db_set(string prop,mixed value,string id) //�������Ӽ�¼��ֻ���޸��Ѿ��еļ�¼������ֶεĺ���ֵ
{
	int db;
	string sql;
	mixed ret;

	if(member_array(prop,cols)==-1) return 0;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return 0;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	if(prop=="login_dbase" && (value==0 || !stringp(value) || sizeof(value)<2 )) return 0;
	//���ڲ�ͬ���͵�����Ӧ���в�ͬ�������ֶΣ������ͣ�MAPP������
	if (intp(value))
		sql = "update users set "+prop+"="+value+" where id='"+id+"'";
	else if( mapp(value) || arrayp(value))
		sql = "update users set "+prop+"="+SQLSTR(save_variable(value))+" where id='"+id+"'";
	else if( stringp(value))
		sql = "update users set "+prop+"="+SQLSTR(value)+" where id='"+id+"'";
	else
	{
		chat("���ݿ⺯��db_set�Ĳ���value���Ͳ���ʶ��");
		return 0;
	}
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
		log_error("db_set.db_exec",ret+"\n"+sql);
		return 0;
	}
	if(ret<1) return 0;
#ifndef STATIC_LINK
	close_database(db);
#endif
	return ret;
}
//ֻ�򵥵���
mixed db_query(string prop, string id)
{
	int db;
	string sql,*res;
	mixed ret;
	
	if(member_array(prop,cols)==-1 && prop!="count(*)") return 0;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return 0;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif
	sql = "select "+prop+" from users where id='"+id+"'";
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		log_error("db_query.db_exec",ret);
		return 0;
	}
	if(ret<1) return 0;
	res = db_fetch(db,1);
#ifndef STATIC_LINK
	close_database(db);
#endif
	chat("��ѯ"+id+"��"+prop+"�����ֶ�ֵ�����أ�"+save_variable(res[0]));
	return res[0];
}

int db_new_player(object ob,object user)
{
	int db,n;
	string sql;
	mixed ret;
	mapping my,myob;
	
	myob=ob->query_entire_dbase();
	my=user->query_entire_dbase();

	if(!stringp(my["id"]) || (my["id"] == "")
	|| !stringp(my["name"]) || (my["name"] == ""))
	{
		chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
		return -1;
	}

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return -1;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database())) return -1;
#endif

	//���ж����ݿ����Ƿ��Ѿ��и����¼
	//fee_time�����������޸ģ��ʲ��洢��
	sql = "insert into users set id='"+my["id"]+"',";
	sql+="name="+SQLSTR(my["name"])+",pass="+SQLSTR(myob["password"])+",adm_pass="+SQLSTR(myob["ad_password"])+",online=1";
	sql+=",onl_time=0,regtime=now(),fee_time="+REG_BONUS;
	sql+=",login_dbase="+SQLSTR(save_variable(myob));
	sql+=",f_dbase="+SQLSTR(save_variable(my));
	
	chat("�������ݿⴴ���ʺţ�\n");
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		chat("���ݿ�洢ʧ��!!!");
		log_error(sprintf("db_save_all(%s).db_exec",my["id"]),ret);
		return -1;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

int db_restore_all(object user)
{
	int db,n;
	string sql,*res;
	mixed ret;
	mapping my;
	object myob;
	
	myob=user->query_temp("link_ob");
	my=user->query_entire_dbase();

	if(!mapp(my) || !stringp(my["id"]) || (my["id"] == "")
		|| !stringp(my["name"]) || (my["name"] == ""))
	{
		chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
		return -1;
	}

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return -1;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database())) return -1;
#endif

	sql = "select login_dbase,f_autoload,f_dbase,f_damage,f_condition,f_attack,f_skill,f_alias,f_user from users where id='"+my["id"]+"'";
	
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		chat("���ݿ�洢ʧ��!!!");
		log_error(sprintf("db_query_all(%s).db_exec",my["id"]),ret);
		return -1;
	}
	if(ret<1) return 0;
	res = db_fetch(db,1);
	if(sizeof(res)<1) n=0;
	else
	{
		string login_dbase,f_autoload,f_dbase,f_damage,f_condition,f_attack,f_skill,f_alias,f_user;
		n=0;
		login_dbase=res[n];
		f_autoload=res[n+1];
		f_dbase=res[n+2];
		f_damage=res[n+3];
		f_condition=res[n+4];
		f_attack=res[n+5];
		f_skill=res[n+6];
		f_alias=res[n+7];
		f_user=res[n+8];
		user->set_dbase(restore_variable(f_dbase));
		user->set_autoload_info(restore_variable(f_autoload));
		user->set_CONDITION(restore_variable(f_condition));
		user->set_ALIAS(restore_variable(f_alias));
		user->set_ATTACK(restore_variable(f_attack));
		user->set_ghost(restore_variable(f_damage));
		user->set_SKILL(restore_variable(f_skill));
		user->set_USER(restore_variable(f_user));
		if(objectp(myob)) myob->set_dbase(restore_variable(login_dbase));
		n=1;
	}
	
#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

int db_save_all(object user)
{
	int db,n;
	string sql;
	mixed ret;
	mapping my,myob;
	object link_ob=user->query_temp("link_ob");
	if(objectp(link_ob)) myob=link_ob->query_entire_dbase();
	my=user->query_entire_dbase();

	if(!stringp(my["id"]) || (my["id"] == "")
	|| !stringp(my["name"]) || (my["name"] == ""))
	{
		chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
		return -1;
	}

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return -1;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database())) return -1;
#endif

	//���ж����ݿ����Ƿ��Ѿ��и����¼
	//fee_time�����������޸ģ��ʲ��洢��
	sql = "update users set ";
	sql+="name="+SQLSTR(my["name"]);
	if(objectp(link_ob)&&mapp(myob))
	{
		if(sizeof(myob["password"]))
			sql+=",pass="+SQLSTR(myob["password"]);
		if(sizeof(myob["ad_password"]))
			sql+=",adm_pass="+SQLSTR(myob["ad_password"]);
		sql+=",login_dbase="+SQLSTR(save_variable(myob));
	}
	if(my["onl_time"]>0)//��Ϊ�Ѿ�Ų�Ƶ�onl_time�Ʒ���
		sql+=",online=1,onl_time="+my["onl_time"]+",save_time=now()";
	else
	{
		sql+=",online=1,onl_time="+my["mud_age"]+",save_time=now()";
		//my["onl_time"]=my["mud_age"];��ΪҪ���¼���sec_id���������ﲻ��������
	}	
	sql+=",f_autoload="+SQLSTR(save_variable(user->query_autoload_info()));
	sql+=",f_dbase="+SQLSTR(save_variable(my));
	sql+=",f_damage="+SQLSTR(save_variable(user->is_ghost()));
	sql+=",f_condition="+SQLSTR(save_variable(user->query_CONDITION()));
	sql+=",f_attack="+SQLSTR(save_variable(user->query_ATTACK()));
	sql+=",f_skill="+SQLSTR(save_variable(user->query_SKILL()));
	sql+=",f_alias="+SQLSTR(save_variable(user->query_all_alias()));
	sql+=",f_user="+SQLSTR(save_variable(user->query_USER()));
	sql+=" where id='"+my["id"]+"'";
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
		chat("���ݿ�洢ʧ��!!!"+sql);
		log_error(sprintf("db_save_all(%s).db_exec",my["id"]),ret);
		return -1;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}


//�������ݿ�������м�¼������еĻ� By GuanYun
string *do_sql(string sql)
{
	int db;
	string *res;
	mixed ret;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return 0;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif
	
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		log_error("do_sql.db_exec",ret);
		return 0;
	}
	if (ret==0) return 0;     		//add by guanyun
	//ֻ��������
	res = db_fetch(db,1);
	
#ifndef STATIC_LINK
	close_database(db);
#endif
	return res;
}

//********************* add by guanyun 2001-03-29 **************************
// ���ظ��� : ����(-2:���Ӵ���-1:���ݴ���)������ΪӰ���������
int do_sqlexec(string sql)
{
	int db;
	int ret;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return -2;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return -2;
#endif
	
	if(!intp(db_exec(db,sql)))
		ret=-1;
	else
		ret=db_affected(db);
	
#ifndef STATIC_LINK
	close_database(db);
#endif
	return ret;
}

//********************* end add by guanyun 2001-03-29 **********
//�������ݿ�������м�¼������еĻ� By JackyBoy 2001-6-7
mixed * do_sqls(string sql)
{
	int db;
	mixed *res=({}),tmp;
	mixed ret;

#ifdef STATIC_LINK
	if(!db_handle)
	{
		chat("���ݿ�ʧȥ���ӡ�");
		return 0;
	}
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif
	
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		log_error("do_sql.db_exec",ret);
		return 0;
	}
	if (ret==0) return 0;
	//Ҫ����������
	//res=allocate(ret);
	for(int i=0;i<ret;i++)
	{
		tmp=db_fetch(db,i+1);
		res += ({ tmp });
	}
	
#ifndef STATIC_LINK
	close_database(db);
#endif
	return res;
}
