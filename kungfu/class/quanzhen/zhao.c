// zhao.c ��־��
// By Lgg,1998.10

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;

string *bd_fighters = ({
	("/kungfu/class/quanzhen/wangzhi.c"),
	("/kungfu/class/quanzhen/shen.c"),
	("/kungfu/class/quanzhen/cui.c"),
	("/kungfu/class/quanzhen/chen.c"),
	("/kungfu/class/quanzhen/li.c"),
	("/kungfu/class/quanzhen/yin.c")
});

string ask_beidouzhen();

void create()
{
        set_name("��־��", ({"zhao zhijing", "zhao"}));
        set("gender", "����");
        set("age", 26);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֣�����һ�Ĵ������־���� \n"
                "����ò��������ü����ƺ�������һ˿�ƻ�����ɫ��\n"
		"����һ��������ˣ�������ȴ��Щɷ����\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);

        set_skill("force", 80);
        set_skill("quanzhen-xinfa", 80);
        set_skill("sword", 80);
        set_skill("quanzhen-jian",80);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("finger",80);
        set_skill("zhongnan-zhi", 80);
        set_skill("literate", 60);
        set_skill("taoism", 60);
        set_skill("array", 120);        
        set_skill("beidou-zhenfa", 120);

	map_skill("array","beidou-zhenfa");
        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        prepare_skill("finger", "zhongnan-zhi");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
 		"�������" : (: ask_beidouzhen :),
		"beidouzhen" : (: ask_beidouzhen :),                
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_beidouzhen()
{
	//string msg, name;
	string msg;
	object me = this_player();

	command("look "+me->query("id"));

	if (!me->query("family") || me->query("family/family_name") != "ȫ���" )
  	{
		msg = "�������������ȫ��̵Ľ�����������!";
		return msg;
  	}

	if( me->query_temp("asked_beidouzhen") )
	{
		msg="��ʲô��ʱ��һ���ͻῪʼ��ϰ��������󡹣�\n";
		return msg;
	}

	if( me->query_temp("pending/beidouzhen") )
	{
		msg="�ú���ϰ��������󡹣�\n";
		command("addoil " + me->query("id"));
		return msg;
	}

	if( query_temp("pending/beidouzhen") || query_temp("beidou_time") )
	{
		msg="û����������æ��\n";
		return msg;
	}

	if( query("eff_qi") < query("max_qi")/2 )
	{
		msg="û������ȫ��������\n";
		return msg;
	}

	if(query_temp("count")>=6)
	{
		msg="��ϧ�������ѹ��ˣ�\n";
		return msg;
	}

	if ( me->query_skill("quanzhen-jian",1) <60 || 
             count_lt(me->query("combat_exp",1), 50000) ||
	     me->query_skill("dodge") <60)
	{
		msg = "��ϧ"+me->query("name")+"�书̫�������ϰ��������󡹡�\n";
		return msg;
	}

	me->set_temp("asked_beidouzhen",1);
	msg = "�ã���������׼������һ������������ƶ��һ����ϰ��������󡹣�\n";
	set_temp("fighter/" + time(), me->query("id") );
	me->delete_temp("qz/bdgranted" );
	add_temp("count",1);

	command("halt");
	command("yun recover");

	remove_call_out("start");
	call_out( "start", 30+ random(30) );
	return msg;
}


int start()
{
	object me = this_object();
	object ob1,ob2,ob3,ob4,ob5,ob6,ob7,ob;
	object here = environment(me);
	mapping fighter;
	int i, *times,j;
	string arg;

	if( !(fighter = me->query_temp("fighter")) )
		return 0;

	times = keys(fighter);
	j = 0;

	for(i = 0; i < sizeof(times); i++) 
	{
		if( !( ob = present( fighter[times[i]],here) ) )
		{
			if( ( ob = find_player( fighter[times[i]]) ) )
			{
				tell_object(ob,"��־�������㣺���Ķ�ȥ�ˣ����úø�����ϰ�󷨣������Ҹ����ƽ����ˣ�\n");
				ob->delete_temp("asked_beidouzhen");
			}
			continue;
		}

		message_vision(HIY"$N����$n������׼����\n"NOR, me,ob);
		ob->delete_temp("asked_beidouzhen");
		ob->move("/d/quanzhen/dajiaochang");
		if (j==0) ob1=ob;
		else if(j==1)ob2=ob;
		else if(j==2)ob3=ob;
		else if(j==3)ob4=ob;
		else if(j==4)ob5=ob;
		else if(j==5)ob6=ob;
		else if(j==6)ob7=ob;
	  	j++;
	}

	command("halt");
	message_vision(HIY"$N���������ţ�\n"NOR, me);

	for( i = j;i<6;i++)
	{
		if(i==0){
			if( !(ob1 = present( "wang zhidan",here ) ) )
			{
				ob1=new( bd_fighters[i] );
				ob1->move(environment(me));
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob1);
			}
		}
		else if(i==1)
		{
			if( !(ob2 = present( "shen zhifan",here ) ) )
			{
				ob2=new( bd_fighters[i] );
				ob2->move("/d/quanzhen/dajiaochang");
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob2);
			}
		}
	  	else if(i==2)
		{
			if( !(ob3 = present( "cui zhifang",here ) ) )
			{
				ob3=new( bd_fighters[i] );
				ob3->move("/d/quanzhen/dajiaochang");
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob3);
			}
		}
	  	else if(i==3){
			if( !(ob4 = present( "chen zhiyi",here ) ) )
			{
				ob4=new( bd_fighters[i] );
				ob4->move("/d/quanzhen/dajiaochang");
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob4);
			}
		}
	  	else if(i==4)
		{
			if( !(ob5 = present( "li zhichang",here ) ) )
			{
				ob5=new( bd_fighters[i] );
				ob5->move("/d/quanzhen/dajiaochang");
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob5);
			}
		}
		else if(i==5)
		{
			if( !(ob6 = present( "yin zhiping",here ) ) )
			{
				ob6=new( bd_fighters[i] );
				ob6->move("/d/quanzhen/dajiaochang");
				message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob6);
			}
	  	}
	}

	arg = me->query("id") + "," + ob1->query("id") + "," + ob2->query("id") + "," +
		ob3->query("id") + "," + ob4->query("id") + "," + ob5->query("id") + "," +
		ob6->query("id");

	message_vision(HIG"$N���������������˵�����ã�ʱ���ѵ������ڿ�ʼ��ϰ��������󡹣�\n"NOR,me);

	"/d/quanzhen/dajiaochang"->do_beidouzhen2( arg );

	me->delete_temp("fighter");
	me->delete_temp("count");
}
