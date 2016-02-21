// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit BABY;
inherit F_NOCLONE;  

void consider();
void provide(); 
int  is_baby(){ return 1; }

void create()
{
        set_name("����", ({"xiao baobao","baby"}) );
        set("gender", "Ů��");
        set("age", 10);
        set("mud_age", 864000);
        set("attitude", "friendly");
        set("long","һ���װ����ֵĹԱ�������֪����˭�ҵĺ��ӡ�\n");
        set("no_clean_up", 1); 
        set("combat_exp", 10000);
        set("accept", 1);   

        setup();
        carry_object("/clone/cloth/cloth")->wear();

        call_out("check_me", 2, this_object());
}

void check_me(object me)
{
   	if (me && ! mapp(me->query("parents")))
   	        destruct(me);
   	return;
}

int load_baby(object me)
{   
     	string file, info, name, id;   

     	if (! userp(me)) return 0;

     	if (me->query("gender") == "Ů��")
         	file = "/data/baby/" + me->query("id") + ".o";
     	else if (me->query("couple/id"))
         	file = "/data/baby/" + me->query("couple/id") + ".o";

     	if (stringp(read_file(file)))
     	{
         	restore_object(file);
         	reset_action();

         	set("max_neili", query_skill("force") * 20 + query("combat_exp") / 1000);
         	set("neili", query("max_neili"));
         	set("max_jingli", query_skill("magic") * 10 + query_skill("taoism") * 10 + query("combat_exp") / 3000); 
         	set("jingli", query("max_jingli"));
         	set("max_qi", 150 + query("max_neili") / 2 + query("age") * query("con"));
         	set("eff_qi", query("max_qi"));
         	set("qi", query("max_qi"));
         	set("max_jing", 100 + query("max_jingli") / 3 + query("age") * query("con"));
         	set("eff_jing", query("max_jing"));
         	set("jing", query("max_jing"));
         	set_name(query("name"), ({query("id"), "baby"})); 

         	set("chat_chance", query("int") / 10);
         	set("chat_chance_combat", query("con") / 5 * 10); 

         	set("chat_msg", ({
                    	(: consider :),
                    	(: provide :), 
         	}));
         	set("perform_skills", 0); 

         	setup();

         	UPDATE_D->check_user(this_object());
         	call_out("consider", 10); 
     	} else 
     	return 0;
} 

void init()
{
       	add_action("do_kill", ({"kill", "fight", "hit", "steal"}));
       	add_action("do_get", "get");
       	add_action("do_drop", "drop");
       	add_action("do_home", "go_home");       
}

int do_home(string arg)
{
      	object me = this_object(), who = this_player();

      	if (! arg) return 0;
      	if (! this_object()->id(arg)) return 0;

      	if ((who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        &&  who->query("couple/child"))
      	{                           
       		message_vision("$N����$n����˵������������Щ���飬���Ȼؼ�ȥ�ɡ�\n", who, me);
       		me->save();
       		destruct(me);
       		return 1;
      	} else
      	command("say ����˭����ΪʲôҪ����Ļ���\n");
      	return 1;
}

int do_drop(string arg)
{
      	object me = this_object(), who = this_player();
      	if (! arg || ! this_object()->id(arg)) return 0;

      	if (me->move(environment(who)))
      	{
             	message_vision("$N��$n�ӻ������������\n", who, me);
             	return 1;
      	}
      	return 0;
}

int do_get(string arg)
{
      	object me = this_object(), who = this_player();

      	if (! arg) return 0;
      	if (! this_object()->id(arg)) return 0;   

      	if ((who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        &&  who->query("couple/child")) 
      	{
             	if (query("age") < 15 && me->move(who))
             	{
                   	message_vision("$N��������$n����������§�ڻ��\n", who, me);
             	}
             	else
             	{
                   	message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n", who, me);
             	}
      	}
      	else
      	{
             	message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
      	}
      	return 1;
}

int do_kill(string arg)
{       
      	object me, who;
      	string name, verb, what, obj;
      	
      	if (! arg) return 0;
      	
      	verb = query_verb();
      	me = this_player();
   
      	if (verb == "steal")
      	{
             	if (sscanf(arg, "%s from %s", what, obj) != 2) 
             		return 0;
      	}
      	else obj = arg;

      	if (! objectp(who = present(obj, environment(me))) 
        ||  ! living(who)) 
        	return 0;
        	
      	if (who == this_object())
      	{
             	switch(verb)
             	{
                case "kill":
			// command("chat* " +
                    	tell_object(environment(this_object()),
                         	    who->query("name") + "ƴ���ؿ����������������������" +
                                    me->query("name") + "Ҫɱ�ң����������ѽ��\n");
                       	break;
                case "hit":
			//  command("chat* " +
                        tell_object(environment(this_object()),
                         	    who->query("name") + "������������������������" +
                             	    me->query("name") + "�۸��ң����������ѽ��\n");
                        break;
              	case "fight":
			// command("chat* " +
                        tell_object(environment(this_object()),
                         	    who->query("name") + "�����������������������" +
                             	    me->query("name") + "Ҫ���ҵ��ǳԣ����������ѽ��\n");
                        break;
                case "steal":
			// command("chat* " +
                        tell_object(environment(this_object()),
                         	    who->query("name") + "�����������������������" +
                             	    me->query("name") + "Ҫ͵���ҵ��ǣ�\n");
                        break;
                case "beg":
			// command("chat* " +
                        tell_object(environment(this_object()),
                          	    who->query("name") + "С��һ������������������������" +
                             	    me->query("name") + "Ҫƭ�ҵ��ǳԣ�\n");
                        break;
             	}
      	}
      	command(verb);
      	return 0;
}

void relay_emote(object ob, string verb)
{
      	if (! userp(ob)) return;

      	switch(verb)
      	{
        case "kick":
                command("say �������������"  + ob->query("name") + "����Ү��");
                command("kick " + ob->query("id"));
                 break;
        case "slap":
                command("say �������������"  + ob->query("name") + "����Ү����ʹ����������");
                command("slap " + ob->query("id"));
                break;
        case "hit":
                command("pain " + ob->query("id"));
                break;
        case "bite":
                command("face " + ob->query("id"));
                break;  
        case "papaya":
                command("angry");
                break;  
      	}
}

void relay_whisper(object me, string msg)
{
      	if ((me->query("id") != query("parents/father")
        &&  me->query("id") != query("parents/mother"))
        ||  ! me->query("couple/child"))   
      	{
            	message_vision((string)this_object()->query("name") + "�ɻ�ؿ���$N��\n", me);
            	return;
      	}

        /*
      	// note, do not allow the order contain "chat", "tell"...
      	// may need disable more later...
      	if (strsrch(msg, "chat") != -1 ||
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "sos")  != -1 ||
            strsrch(msg, "recruit") != -1)
            	return;
        */

      	if (msg)
      	{
            	remove_call_out ("relaying");
            	call_out ("relaying", random(2), msg);
      	}
}

void relaying (string msg)
{
	// execute the order.
      	if (command (msg)) 
      	        command("say ��֪���ˡ����� \n");
      	else 
      	        command("say ������ѽ������\n");
      	return;        

}

void consider()
{
   	string *basic = ({"unarmed", "strike", "finger", "cuff", "claw", "hand",
          		  "blade", "sword", "whip", "throwing", "club", "staff", "hammer", "axe",
          		  "parry", "force", "dodge", "magic", "poison", "poison", "taoism",
          		});     
   	string skill;
   	string *chat_chance_combat_here = ({(: exert_function, "powerup" :)}), *my_skill,
               *basic_skill = ({}), *use_skill = ({}), dir;
   	mapping skills;
   	int i, j, k;
   	object ob = this_object();
   	mixed *file;

   	if (! environment())  return;   
   	skills = ob->query_skills();        
   	if (sizeof(skills) && (sizeof(skills)>query("skills_learned") || query("no_load")))
   	{
    		my_skill = keys(skills);
    		for (i = 0; i < sizeof(basic); i++)
    			if (member_array(basic[i], my_skill) != -1)
          			basic_skill += ({basic[i]});

    		for (i = 0; i < sizeof(my_skill); i++)   
    			if (SKILL_D(my_skill[i])->type() != "knowledge" 
        		&&  member_array(my_skill[i], basic) == -1)
          			use_skill += ({my_skill[i]});

    		for (i = 0; i < sizeof(basic_skill); i++)
    		for (j = 0; j < sizeof(use_skill); j++)
    			if (SKILL_D(use_skill[j])->valid_enable(basic_skill[i]) 
        		&&  ! stringp(query_skill_mapped(basic_skill[i])))
    			{
     				map_skill(basic_skill[i], use_skill[j]);
     				if (sizeof(ob->query_skill_prepare()) < 2)
     					if (basic_skill[i] == "finger" 
     					||  basic_skill[i] == "strike" 
         				||  basic_skill[i] == "hand" 
         				||  basic_skill[i] == "cuff" 
         				||  basic_skill[i] == "claw" 
         				||  basic_skill[i] == "unarmed")
     						prepare_skill(basic_skill[i], use_skill[j]);
     						
    			} else continue;

    			if (sizeof(skills) > query("skills_learned"))
    				set("perform_skills", 0);

    			if (! query("perform_skills"));  
    			{
      				for (i = 0; i < sizeof(basic_skill); i++ )
      				if (basic_skill[i] != "magic" && basic_skill[i] != "taoism" 
         			&&  stringp(query_skill_mapped(basic_skill[i])))
      				{
         			dir = "/kungfu/skill/" + query_skill_mapped(basic_skill[i]) + "/";
         			file = get_dir(dir, -1);

         			if (sizeof(file) > 0)
         			for (k = 0; k < sizeof(file); k++)
         			{
           				if (file[k][0][strlen(file[k][0])-2..strlen(file[k][0])] != ".c")
           					continue;
           				file[k][0] = replace_string(file[k][0], ".c", "");
           				if (file[k][0] == "powerup" || file[k][0] == "roar" || 
               				    file[k][0] == "hou" || file[k][0] == "huadu" || 
               				    file[k][0] == "du" || file[k][0] == "judu" ||
               				    file[k][0] == "force" || file[k][0] == "bx_arrow" || 
               				    file[k][0] == "jingang" || file[k][0] == "liaodu" ||
               				    file[k][0] == "qudu" || file[k][0] == "nizhuan" || 
               				    file[k][0] == "bidu" || file[k][0] == "other" ||
               				    file[k][0] == "heal" || file[k][0] == "lifeheal" || 
               				    file[k][0] == "jingheal" || file[k][0] == "jing" ||
               				    file[k][0] == "recoverjing" || file[k][0] == "revive" ||
               				    file[k][0] == "shield" || file[k][0] == "suck" || 
               				    file[k][0] == "qisuck" || file[k][0] == "jingsuck" ||
               				    file[k][0] == "jinglisuck" || file[k][0] == "neilisuck" || 
               				    file[k][0] == "maxsuck" || file[k][0] == "zongjue" ||
               				    file[k][0] == "lianquan")
           					continue;
           				chat_chance_combat_here += ({( : perform_action, basic_skill[i] + "." + file[k][0]: )}); 
         			}
      			} else continue;     

     			set("chat_msg_combat", chat_chance_combat_here);                        
    	 		set("perform_skills", 1); 
    		}

    		set("chat_msg_combat", chat_chance_combat_here);
    		reset_action();
    		set("skills_learned", sizeof(skills));  
    		command("say ��������֪���ˣ��һ����ˣ�\n");  
   	}

   	set("jiali", query_skill("force") / 2 + 10);
   	save();

   	command("say ����������ס�ˣ������ˣ�\n");
   	return;
}

int accept_object(object who, object ob)
{
      	if ((who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        &&  who->query("couple/child")) 
      	{
        	remove_call_out("provide");
        	call_out("provide", 2);
        	return 1;
      	} else return 0;
}

void provide()
{
    	object *ilist, ob;
    	object weapon, armor;
    	int i;

    	if (! environment()) return;
    	ilist = all_inventory(this_object());
    	if (sizeof(ilist) < 1) return;

    	for (i = 0; i < sizeof(ilist); i++)
    	{
      		ob = ilist[i];
      		if (ob->query("weapon_prop/damage"))
      		{
        		if (objectp(weapon = query_temp("weapon")) && weapon != ob 
            		&&  ob->query("weapon_prop/damage") > 
                            weapon->query("weapon_prop/damage"))
         			weapon->unequip();
         		command("wield " + ob->query("id"));
      		}

      		if (ob->query("armor_prop/armor"))
      		{ 
         		if (objectp(armor = query_temp("armor/" + ob->query("armor_type")))
             		&&  armor != ob 
             		&&  ob->query("armor_prop/armor") > 
                            armor->query("armor_prop/armor"))
         			armor->unequip();
         		command("wear " + ob->query("id")); 
      		}    

      		if (ob->query("food_remaining"))
         		command("eat "+ob->query("id"));
      		else if (ob->query("liquid/remaining"))
         		command("drink " + ob->query("id"));
   	}

   	set("jiali", query_skill("force") / 2 + 10);    
   	command("sweat");
   	return;
}


