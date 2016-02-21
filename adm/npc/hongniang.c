// llm 99/06/04 �޸�2000.09
// updated by lonely 11/03
// hongniang.c ����

#include <ansi.h>

#define MARRY_RING      "/clone/misc/wedding-ring.c"
#define RING_DIR        "/data/item/ring/"

inherit NPC;

int waiting(object ob);
int do_name(string target);
int do_chase(object ob);
int do_ok(object ob);
int meipo_waiting(object ob, object me, object obj);
int ready_marry(object ob, object me, object obj);
int wait_marry(object ob, object me, object obj);
int start_marry(object ob, object me, object obj);
int do_back(object ob);
int do_bai(string arg);
int ask_baitang();

void create()
{
	set_name("����", ({ "hong niang", "hongniang", "marriage witness" }));
	set("long", 
		"����һ�����úܺÿ���С���������"
                "���Ĵ��۾�͸��һ˿���\n");
	set("gender", "Ů��");
	set("age", 18);
	set("str", 200);
	set("combat_exp", 1000);

        set("inquiry", ([
                "���": "Ҫ��飿�ҿ���Ϊ������ý���������˶�������ô��",
                "���": "������ң������Ҳ��æ��������������Ŷ��һ�շ��ް��ն��",
                "����": (: ask_baitang :),
        ]));

	setup();
        seteuid(getuid());
}

void init()
{
   	add_action("do_bai", "��");
	add_action("do_name", "��");
	add_action("do_name", "qing");
}

int accept_object(object me, object ob) 
{
   	if (! ob->query("money_id") || ! me->query("couple/id") || 
   	    ! me->query_temp("ask_money"))
     		return notify_fail("��������Ц���������������г��кȲ���ʲô���������û�ȥ�ɣ���\n");

  	if (ob->value() < 10000000)
	      	return notify_fail("����������üͷ˵������Ǯ̫���˰ɣ�1000 gold������ǽ����ô����£����پͲ����ˡ���\n");
	      
	message_vision("����ӹ�Ǯ��$N˵������λ" + RANK_D->query_respect(me) + "�ҿ�û׬���Ǯ��������һ�Ҫ����ϲ�á���\n"
   		       "Ҫ���ˡ����а���磬�㲻���һ�������һ��ģ������һ����԰��㷢������\n"
         	       "��������롮�� <ĳ�˵�����>������\n", me);
	this_object()->set_temp("marry/money", me->name());  
	command("say ���ȸ�������Ҫ��(qing)��Щ�˰ɣ�������������ѣ���ô��׼������(ask hong niang about ����)�ɣ�");
  	return 1;
}

int do_name(string target)
{
	object me, ob, dest, *all;
	int i;
	me = this_player();
	ob = this_object();
	all = users();
                  
   	if (query_temp("marry/money") != me->name())
   	{
   		message_vision(name() + "Ц�����ص��������Ҫ��һ��Ǯ��ඣ�" 
   			       "Ҫ 1000 gold������Ǯ���ҿ�û�����죡\n", me);
   		return 1;
   	}
   	
	if (me->is_busy())
		return notify_fail("����˵��������æ����ٺ���˵���ɣ���\n");
		
	if (ob->is_fighting() || me->is_fighting())
		return notify_fail("����˵����������û���򣡡�\n");
		
	if (! living(ob))
		return notify_fail("�㻹������취�Ѻ�����Ѱɡ�\n");
		
	if ((string)ob->query_temp("marry/money") != (string)me->name())
      		return notify_fail("����б��б�㣺������û��Ǯ����\n");
      		
	if (ob->query("waiting_target"))
		return notify_fail("����ЦЦ˵������Ҫ�����ҵ�Сϲȵ�ǻ�û�зɻ����أ���\n");
		
	if (! target || target == " ")
		return notify_fail("������һ�����д�˼����ʣ���������˭���μ���Ļ��񣿸�������(��)�����֣���\n");
		
	for (i = 0; i < sizeof(all); i++)
	{
		if (target == all[i]->name() || target == all[i]->query("id"))
			dest = all[i];
	}
	
	if (! dest)
		return notify_fail("��������㣺�����ź�����������������ڲ�����Ϸ�У���\n");
		
	if (dest->is_ghost())
   		return notify_fail("������ϧ�صظ����㣺����������֪����Ҫ������Ѿ����ˣ�����ڰ�˳�㣡��\n");
   		
	ob->set("waiting_target", dest->query("id"));
	ob->set("me_name", me->query("name"));
	ob->set("me_id", me->query("id"));
	message_vision(HIG "����һ��ϲ����д�ϼ����֣�˫��һ�ģ��Ӷ��Ⱦͷɳ�һֻСϲȵ������ϲ����\n"
   		       "���㶵�һ������ʧ��������ˡ�\n" NOR, me);
	call_out("do_chase", 1, ob);
	return 1;
}

int do_chase(object ob)
{
	object dest, obj;
	dest = find_player(ob->query("waiting_target"));

	if (! objectp(dest) || ! environment(dest))
	{
		call_out("waiting", 0, ob);
		return 1;
	}
	
	message_vision(HIY "�����ͻȻ�ɹ���һֻ��ϲȵ������$N��ͷ�������ŵ�һ��ϲ��ݸ�$N��\n" NOR, dest);
        obj = new("/adm/npc/obj/xitie"); 
   	obj->set("name", HIR + (string)ob->query("me_name") + "(" + (string)ob->query("me_id") + ")" + "�Ľ������" NOR);
	obj->move(dest);
	call_out("do_ok", 0, ob);
	return 1;
}

int waiting(object ob)
{
	object dest;
	dest = find_player(ob->query("waiting_target"));

	if (objectp(dest) && dest->is_ghost())
	{
		ob->delete("waiting_target");
		call_out("do_ok", 1, ob);
		return 1;
	}
	remove_call_out("waiting");
	call_out("waiting", 60, ob);
   	return 1;
}

int do_ok(object ob)
{
	message("vision", "ͻȻ������ϲȵ�Ӵ���ɽ��������ں������ԣ�����Ц���еظ��Ż�ϲȵ��ͷ��\n"
		"˵���������ղ��Ѿ����͵��ˣ���������˭���������˾Ϳ�ʼ�����������(ask hong niang about ����)�ɣ���\n", 
		environment(), ob);
  	ob->delete("waiting_target");
	ob->delete("me_name");
	ob->delete("me_id");
	return 1;
}

int ask_baitang()
{
	object me, obj, 
	
	ob = this_object();
	me = this_player();
	
        if (query_temp("marry/money") != me->name() || ! mapp(me->query("couple")))
	{
		tell_object(me, "�����Ի󲻽�Ŀ����㣡\n");
		return 1;
	}
		
        if (! (obj = present(me->query("couple/id"), environment(me))))
        {
                tell_object(me, "��İ��²��ڰ���\n");
                return 1;
        }
	
        message("vision", MAG "\n����Ǻ�Ц�������Ǿͺã��Ǿͺã������ҵ����ߵ���Ե����׼�����ðɣ���\n"
                "˵�꣬����һŤһŤ���߽��˶��ߵĴ��á�\n" NOR, me, obj);    
   		
   	ob->move("/d/suzhou/yinyuan-tang");
	call_out("meipo_waiting", 1, ob, me, obj);
	return 1;
}

int meipo_waiting(object ob, object me, object obj) 
{
	if (ob->query_temp("wait_time") == 200)
	{
		say("�����ɻ��˵������С����������Ҳ�������ѵ�������Ե�޷ݣ�����������ȡ���գ�\n"
      		    "������ǰ�׬��1000 gold�ˣ��ǺǺ�...��\n\n");
		call_out("do_back", 0, ob);
      		return 1;
	}
	if (environment(ob) == environment(me) && environment(ob) == environment(obj))
   	{                                                
      		ob->delete_temp("wait_time");
   		call_out("ready_marry", 1, ob, me, obj);
   	}
	else
   	{
		if (environment(ob) == environment(me) && environment(ob) != environment(obj))
		{
			if (random(10) == 0)
				say("\n�����ʵ�����" + me->name() + "����ȥ����" + obj->name() +
				    "��ô�����������ѵ���Ը���ˣ�\n");
			ob->add_temp("wait_time", 1); 
			call_out("meipo_waiting", 1, ob, me, obj);
		}
   		else if (environment(ob) != environment(me) && environment(ob) == environment(obj))
		{                                            
			if (random(10) == 0)
				say("\n�����ʵ�����" + obj->name() + "����ȥ����" + me->name() +
				    "��ô�����������ѵ���Ը���ˣ�\n");
			ob->add_temp("wait_time", 1);
			call_out("meipo_waiting", 1, ob, me, obj);
		}
		else
      		{
	   		ob->add_temp("wait_time", 1);
			call_out("meipo_waiting", 1, ob, me, obj);
      		}
   	}
	return 1;
}

int ready_marry(object ob, object me, object obj)
{
	object room;

	if (! (room = find_object("/d/suzhou/yinyuan-tang")))
		room = load_object("/d/suzhou/yinyuan-tang");

	message("vision", HIY "\n��������е��������죬�ɻ�Ķ������ˣ����ϲ���ϲ�ã���\n" NOR, room);
	message("vision", HIC "\nֻ���ú�����һ��Ų�����ʮ����������������·���������Ů�����������ܽ�����\n"
		"ߴߴ�����������ţ��ַ�ͷ�ܿ��ˣ�ʱ��ʱ��Ц�ſ�һ��" + me->name() + "��" + obj->name() + "��\n\n" NOR, 
		room);
	say("�������λ����˵��������Ҫ�ż������Ƕ��Ǻ��о���ģ��ܿ�ͻ᲼�úõģ���\n"
   	    CYN "ֻ����ߵ���������ȥ��æ�ò����ˡ�\n"NOR);
	call_out("wait_marry", 1, ob, me, obj);
   	return 1;
}

int wait_marry(object ob, object me, object obj) 
{
	object room;
	object m_cloth, w_cloth;
	
	if (! (room = find_object("/d/suzhou/yinyuan-tang")))
		room = load_object("/d/suzhou/yinyuan-tang");
	
	switch (ob->query_temp("wait_time"))
	{
   	case 0:
    		say(RED "\nһ��С�һ��ܹ������е�����������ֽ��Ǯ�����ˣ�������Ͻ�����һЩǮ��\n\n" NOR);
	   	ob->set_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
	   	break;
      	case 1:
     		say(MAG "\nͻȻ���Ǳߵ�С����е����������ԧ���������������������һ�������ұ�����ȥ�㣡��\n\n" NOR);
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
      	case 2:
     		say(CYN "\n�ĸ��һ��Ӵ��Ӵ��̧��һֻ�����Ӵ�����������߹������ﶣ����������Щ����㣡��\n\n" NOR);
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
	case 3:
      		say("\n����һ����ס����ܹ���һ��С���ӣ���ϲ���õ�ϲ�綩���𣿿�ȥ����\n\n" NOR);
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
      	case 4:
     		say(YEL "\n�Ǳߵ��˽е��������û��������������������������\n\n" NOR);
      		ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob, me, obj);
	   	break;
	case 5:
     		say("\n�Ǳ��ֽ����������������Ǯ���ͻ����İɣ��������ˣ�������Ͻ��ܹ�ȥ��\n\n");
      		ob->add_temp("wait_time",1);
	 	call_out("wait_marry", 1, ob, me, obj);
      		break;
	case 6:
     		say(CYN "\n����һ·С�ܹ��������������������ģ����ͷ��ͷ�У����죬������׼��ϲװ����\n\n" NOR);
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
	case 7:
	  	say(WHT "\nһ�������ְ˽ŵ�̧���˼��Ŵ����ӣ��������Ϲ���һ������\n" HIR
"			       ��      ��\n"
"			    ����������������\n"
"			    ����������������\n"
"			     ������  ������\n"
"			     ������  ������\n"
"			      ����    ����\n"
"			    ����������������\n"
"			     ������  ������\n"
"			     ������  ������\n\n" NOR);
                ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
   	case 8:
     		say(YEL "\n�������ֿ�ʼ���Ի������������������������ʶ����ʶ���ˣ��׷׹�����أ�����ϲ��ϲ����\n\n" NOR);
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
      		break;
	case 9:
  	  	say("\n����С����Ц������һ�߲������Σ�һ�߻���ҧ�Ŷ��䣬��ʱ��͵�ۿ������ˡ�\n\n");
      		ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob, me, obj);
		break;
	case 10:
  	  	say("\n��λ������Ů������һ�״���߹����۵ݸ����ɣ�һ����ߴ���ˮ���佻����������������������ﴩϲװ����\n\n");
  	  	m_cloth = new("/d/suzhou/npc/obj/longpao");
  	  	w_cloth = new("/d/suzhou/npc/obj/yunxiu");
  	  	if(me->query("gender")=="����")
  	  	{
  	  		m_cloth->move(me);
  	  		w_cloth->move(obj);
  	  	}
  	  	else
  	  	{
  	  		m_cloth->move(obj);
  	  		w_cloth->move(me);
  	  	}
                ob->add_temp("wait_time", 1);
	  	call_out("wait_marry", 1, ob,me,obj);
		break;		
	case 11:
		message("vision", HIY "\n�����������һ��������׼�������𣿡�����Ӧ���������ˣ���\n"
      			"���������ϳ��������������������������ֻ��񡭡�����\n"
      			HIM "��ʱ���������������ڴ��������ɰ���ӵ���������ְ˽Ÿ����ɡ����ﻻ�����£�\n"
      			"׺ӵ�������������ȥ��\n" NOR, room);
      		call_out("start_marry", 1, ob, me, obj);
      		break;
   	}
   	return 1;
}

int start_marry(object ob, object me, object obj) 
{
	object moon, room;

	if (! (room = find_object("/d/suzhou/yinyuan-tang")))
		room = load_object("/d/suzhou/yinyuan-tang");
	moon = new("/d/suzhou/npc/yuelao");
   	moon->move(room);
	message("vision", "\n����һ�������Ц��һλ�����������ߣ��첽������У��ڳ���������Ů��������ݣ�\n"
   		"����������үү�������ϰڰ��֣�Ц�Ǻǵؿ���" + me->name() + "��" + obj->name() + "�����ͷ����\n"
      		"���ã��ã��ɲ�Ůò������֮�ϣ�����֮��ѽ����\n"
   		HIY "\n����һ���֣�ϲ���ָ���ֻ�������ϸ��������������ɡ�����ݡ���ء�������\n" NOR, room, moon);
   	say("������С���ض���������˵������˳�����롮�� ��ء��� ���úͰ� �Է������֡�����\n");
   	CHANNEL_D->do_channel(moon, "mudnews",
	   		      sprintf("����%s��%sϲ����Ե�����ô���ʱ��ʼ��\n", me->name(), obj->name()));
	me->set_temp("pending/bai", 1);
   	obj->set_temp("pending/bai", 1);
	return 1;
}

int do_back(object ob)
{
   	ob->delete_temp("wait_time");
   	ob->delete_temp("marry/money");
	say("�������������ϣ���һŤһŤ����������ȥ��\n");
   	ob->move("/d/suzhou/hongniang-zhuang");
	return 1;
}

int do_bai(string arg)
{
	object me, ob, obj;

	me = this_player();
   	ob = this_object();
	if (me->is_busy())
		return notify_fail("����˵�����������ڲ�����æ����æ����˵����\n");

	if (me->is_fighting(this_object()))
	{
		if (! this_object()->is_killing(me))
			this_object()->kill_ob(me);
		return notify_fail("����˵������������ĸ������£���Ҷ��䣬����ȥ����ɻ�ɣ���\n");
	}

	if (this_object()->is_fighting())
		return notify_fail("����˵����û����������˵�����\n");

	if (! living(this_object()))
		return notify_fail("�㻹������취�Ѻ�����Ѱɡ�\n");

	if (me->is_fighting())
		return notify_fail("����˵�������ٺ٣����Ȼ������������������˵�ɣ���\n");

	if (! environment() || base_name(environment()) != ("/d/suzhou/yinyuan-tang"))
		return notify_fail("����˵���������������ǵģ�������Ҫ����Ե�ò��е�ѽ����\n");

	if (! me->query_temp("pending/bai"))
		return notify_fail("����Ц�������������㷸ʲôɵѽ����\n");

	if (! objectp(obj = present((string)me->query("couple/id"), environment(me)))
	||  ! find_player(me->query("couple/id")))
	{
   		message_vision("����ת��һ�������ȵ�˵��������ѽ����İ�����ôͻȻ���ˣ�������ô���У����ɢ̯�ɡ���\n"
      			       "��һƬ��ϧ������ҷ׷��볡��ϲ���ϵĶ���Ҳ��һ�ն��ա�\n", me);
      		call_out("do_back", 1, ob);
      		return 1;
   	}

   	if (arg == " ���" || arg == " ����" || arg == " " + (string)me->query("couple/name"))
		return notify_fail("���ݡ������Ĵ�֮�����ð�ǿո�\n");

	if (! arg || (me->query_temp("pending/bai") == 1 && arg != "���")
	||  (me->query_temp("pending/bai") == 2 && arg != "����")
	||  (me->query_temp("pending/bai") == 3 && arg != (string)me->query("couple/name")))
		return notify_fail("����Ц���������Ұ�ʲôѽ��һ����أ����ݸ��ã�������İ��ˣ��ɱ��ٴ��ˣ���\n");

	if ((string)obj->query_temp("pending/act") != arg )
	{
      		if ((int)me->query_temp("pending/bai") != 3)
      		{
			tell_object(obj, MAG "��İ��������ź���� " + arg + " ��...\n" NOR);
			write(MAG "���������ȴ�����İ���...\n" NOR);
			me->set_temp("pending/act", arg);
      		}
      		else
      		{
			tell_object(obj, MAG "��İ��������ź��㻥�ݣ����������֣���...\n" NOR);
			write(MAG "���������ȴ�����İ���...\n" NOR);
			me->set_temp("pending/act", me->name());
      		}
		return 1;
	}
	else if ((int)me->query_temp("pending/bai") == 1)
   	{
  		message_vision("��һ�ݡ��졭�ء�����$N��$n�������������ӯӯ����......\n", me, obj);
      		me->add_temp("pending/bai", 1);
      		obj->add_temp("pending/bai", 1);
      		return 1;
   	}
	else if ((int)me->query_temp("pending/bai") == 2)
   	{
  		message_vision("�����ݡ��ߡ��á�����$N��$n��վ��������һЦ���ֻ�������......\n", me, obj);
      		me->add_temp("pending/bai", 1);
      		obj->add_temp("pending/bai", 1);
      		return 1;
   	}
	else if ((int)me->query_temp("pending/bai") == 3)
   	{
  		message_vision("�����ޡ��ԡ��ݡ�����$N��$n���໥�������һ��......\n", me, obj);
		message_vision(HIY "����Ц�Ǻǵ�˵�������ã�$N��$n��������ʽ��Ϊ����! \n" NOR, obj, me);
		CHANNEL_D->do_channel(this_object(), "chat",
                        sprintf("��ϲ%s��%s��һ�����ϲ����Ե��\n            ��λ������ѣ���Я������ϲ���òμ����ǵĻ��磡\n",
				me->name(), obj->name()));
				
      		me->set_temp("married_party", 1);     // ���ϼǺţ�ϲ�����ϰ忴���ͻ�ͬ�⿪��ϯ
      		obj->set_temp("married_party", 1);    // ���˶�������ֻ�����Բ�����

      		me->delete_temp("pending/bai");
      		obj->delete_temp("pending/bai");
      		me->delete_temp("pending/act");
      		obj->delete_temp("pending/act");

	   	call_out("last_marry", 1, ob, me, obj);
		return 1;
   	}
}

int last_marry(object ob, object me, object obj)
{
	object moon, room;
	if (! (room = find_object("/d/suzhou/yinyuan-tang")))
		room = load_object("/d/suzhou/yinyuan-tang");
	moon = present("yue lao", room);
	moon->move("/u/lonely/workroom");
   	ob->delete_temp("wait_time");
   	ob->delete_temp("marry/money");
	say("���ﺰ�������η򣡿콫�����͵�ϲ���þ��л��磬�Һ����ϾͲ�ȥ�ˣ��Ǻǣ���\n˵��һŤһŤ����������ȥ��\n");
   	ob->move("/d/suzhou/hongniang-zhuang");
	message_vision(HIR "���ɰ���ӵ����λ���ˣ������ſڵ�������컨�Σ�ֻ���η���һ������Σ���\n"
   		       "һ���˴������ر���ϲ����......\n" NOR, me, obj);
   	me->move("/d/suzhou/jiao1");
   	obj->move("/d/suzhou/jiao2");
        call_out("go_lou", 8, ob, me, obj);
        call_out("do_back", 10, ob);
	return 1;
}

int go_lou(object ob,object me,object obj)//����¥
{
	object room, npc;
	
	if (! (room = find_object("/d/suzhou/xifu-tang")))
		room = load_object("/d/suzhou/xifu-tang");
		
	message_vision("\n    ���˺ó�һ�����ֻ���η���һ����������������������һ�������䵽�˵��ϣ�\n"
   		"$N��$n�ӽ���������һ����ԭ���Ѿ�����ϲ���á������ֱ�ӵ����һֱ���˶�¥�����á�\n"
      		"ֻ����һ��Ǻ�Ц����ϲ�����ϰ�ϲ����Ц�������ӭ����������ϲ��λ���ˣ���ϲ��ϲ��\n��", me, obj);
      		
   	npc = new("/d/suzhou/npc/xi-laifu");
   	npc->set("name1", me->name());
   	npc->set("name2", obj->name());//˫������
   	npc->move(room);
   	me->move(room);
   	obj->move(room);
   	return 1;
}

int do_witness(object me, object ob)
{
        message_vision("$N��������������$n������������ˮ���������òŶ�" +
                       name() + "������λС�����ܷ�Ϊ����֤�飿\n\n",
                       me, ob);
                       
        if (! living(ob))
        {
                message_vision(name() + "�ԳԵ������Ц����$N������"
                               "���㻹���Ȱ���λŪ����˵�ɡ�\n", me);
                return 1;
        }

        if (! userp(ob))
        {
                message_vision(name() + "�������ǿ�Ц��Цɶ"
                               "�أ���Ҳ�Ǻǵĸ���ɵЦ��\n", me);
                return 1;
        }

        message_vision(name() + "�������������ܺð����õúܣ���"
                       "��˵��������ԸΪ�������ڵ�Ը������֦����\n" +
                       "�ٳ���Ե���������£���" + name() + "��Ը���ˣ���������λ" +
                       RANK_D->query_respect(ob) + "ҲԸ���𣿡�\n\n", me);

	tell_object(ob, YEL + name() + "�������㣺" + me->name(1) +
                        "����������أ����Ӧ(right)���ǲ���Ӧ(refuse)��\n" NOR);
	ob->set_temp("pending/answer/" + me->query("id") + "/right",
                     bind((: call_other, __FILE__, "do_right", ob, me :), ob));
	ob->set_temp("pending/answer/" + me->query("id") + "/refuse",
	             bind((: call_other, __FILE__, "do_refuse", ob, me :), ob));
	me->set_temp("pending/engage", ob);
        return 1;
}

int do_right(object me, object ob)
{
        string fn;
        string fc;
        object ring;

        message_vision("$N͵͵���˿�$n��ʹ���ĵ�ͷ������Ը�⣬Ը�⼫�ˣ�\n" + name() +
                       "���ˣ�Ц����������������Ը����������ý�ˣ��ǻ����ð��𣿡�\n\n",
                       me, ob);
        command("chat ��ϲ" + me->name(1) + "��" + ob->name(1) +
                 "��Ϊ����֮�ã�");
        message("visoin", name() + "Ц�ŶԶ���˵���������������"
                "��ϲ�����ӣ���û��ʲô���ֻ���͸���"
                "���������һ�Խ���ָ�ɣ���\n\n", environment(me));

        fc = read_file(MARRY_RING);
        fc = replace_string(fc, "LONG_DESCRIPTION",
                            "����" + me->name(1) + "��" +
                            ob->name(1) + "�Ľ���ָ�������˵Ķ���֮�\n");

        // give ring to me
        fn = RING_DIR + me->query("id");
        if (file_size(fn + ".c") > 0)
        {
                if (ring = find_object(fn)) destruct(ring);
                rm(fn + ".c");
        }
        assure_file(fn);
        write_file(fn + ".c", fc);
        VERSION_D->append_sn(fn + ".c");
        ring = load_object(fn);
        ring->move(me, 1);
        tell_object(me, HIY "������һ������ָ��\n" NOR);
        me->set("can_summon/" + "wedding ring", fn);

        // give ring to ob
        fn = RING_DIR + ob->query("id");
        if (file_size(fn + ".c") > 0)
        {
                if (ring = find_object(fn)) destruct(ring);
                rm(fn + ".c");
        }
        assure_file(fn);
        write_file(fn + ".c", fc);
        VERSION_D->append_sn(fn + ".c");
        ring = load_object(fn);
        ring->move(ob, 1);
        tell_object(ob, HIY "������һ������ָ��\n" NOR);
        ob->set("can_summon/" + "wedding ring", fn);
        
        // record
	me->set("couple/id", ob->query("id"));
	me->set("couple/name", ob->name(1));
        me->set("couple/witness", name());
	me->save();
	ob->set("couple/id", me->query("id"));
	ob->set("couple/name", me->name(1));
        ob->set("couple/witness", name());
	ob->save();
	me->set_temp("ask_money", 1);
	ob->set_temp("ask_money", 1);
	tell_object(me, HIR "������������ν���ķ��㣬��ֻҪ���� 1000 gold���ҿ��԰������������е����顣\n" NOR);
	tell_object(ob, HIR "������������ν���ķ��㣬��ֻҪ���� 1000 gold���ҿ��԰������������е����顣\n" NOR);
        return 1;
}

int do_refuse(object me, object ob)
{
        message_vision("$NƳ��$nһ�ۣ�ת��ͷȥ���ٿ���������"
                       "���ڣ����ޡ��ޡ��������ޣ���\n" +
                       name() + "���εĶ�$n��������Ҳ�����ˣ�"
                       "�׻�˵ǿŤ�Ĺϲ���...��\n", me, ob);
        return 1;
}

int do_divorce(object me)
{
        object ob;

        if (me->query("couple/witness") != name())
        {
                message_vision(name() + "ҡҡͷ����$N�������ҿ�"
                               "�������ǵ�ý�ˣ�����Ҫ����룬�������ң���\n", me);
                return 1;
        }

        ob = find_player(me->query("couple/id"));
        if (! ob || environment(ob) != environment(me))
        {
                message_vision(name() + "�Ծ��Ŀ���$N��������ô����"
                               "���ˣ��������ް��պð�������Ҫ������"
                               "ôҲ�ð��˼�����һ��̸̸������\n", me);
                return 1;
        }

        if (! living(ob))
        {
                message_vision(name() + "ҡҡͷ����$N��������˵��λ" +
                               RANK_D->query_respect(me) +
                               "����ôҲ�õ��˼��ѹ�����˵�ɣ���\n", me);
                return 1;
        }

        if (me->query_temp("pending/submit_divorce"))
        {
                message_vision(name() + "ҡҡͷ����$N����������"
                               "ʲô����Ҳ�������˼ҵ���˼����\n",
                               me);
                return 1;
        }

        if (! ob->query_temp("pending/submit_divorce"))
        {
                message_vision(name() + "����̾�˿�����һ�����ɵ�����Ҳ"
                               "������Щ��ɣ����ͷ���˿�$n���ʵ�������"
                               "Ҳ�������Ĳ���" + ob->name() + "���ˣ���\n\n", me, ob);
                tell_object(ob, YEL + name() + "���ĵĸ����㣺Ҫ���������������("
                                "divorce " + me->query("id") + ")��ʾ�����Ѷ���\n");
                me->set_temp("pending/submit_divorce", 1);
                return 1;
        }

        message_vision(name() + "ʹ�ĵĶ�$N��$n������������Ϊ����"
                       "������ý��ʱ�򣬿���û�뵽������ôһ�죡��\n\n", me, ob);
        command("chat �ӽ�����" + me->name(1) + "��" + ob->name(1) +
                "�����ˣ��Ժ�ɾ͸��߸���·����");
        UPDATE_D->clear_user_data(me->query("id"), "couple");
        return 1;
}

int accept_fight()
{
        command("fear");
        command("say �������Һ����µġ�");
        return notify_fail("�㻹�����˰ɣ�\n");
}

int accept_hit()
{
        command("say ��Ҫ������Ҫ�Ҷ��֣�");
        return notify_fail("�㻹�����˰ɣ�\n");
}

int accept_kill()
{
        command("say ѽ�������ʲô��");
        return 1;
}

void unconcious()
{
        die();
}

void die()
{
        command("chat �����ˣ��������ˣ�");
        message_vision("$N��Ҳ�Ƶ������ˡ�\n", this_object());
        destruct(this_object());
}

int return_home(object home) // ��ֹ�����и��£�����ؼ�
{
        if (! environment() || environment() == home) 
                return 1;
	if (! living(this_object()) ||  is_fighting()) 
	        return 0;
	if (this_object()->query_temp("wait_time")) 
	        return 0; // �н��Ĳ����Ͳ���ȥ

        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
    	        environment(), this_object());
        return move(home);
}
