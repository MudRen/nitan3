// magic-beast.h

/************************************************************
 * ħ���������������Ϊ�����ڡ������ڡ��ɳ��ڡ���̬�ںͳ����ڡ�
 * �����ڣ�����������ħ�������ԣ���ľˮ��������ʱ��һ���£�
 * �ɳ��ڣ����޻���帽�����������ϣ������������˵�����������
 *         �ṩ����������Խ�࣬���޳ɳ�Խ�죬ͬʱ�����ҲԽǿ��
 *         ������ħ��ֵ��ʱ��ʮ���£�
 * ��̬�ڣ���̬�ڵĻ����ǻ���һ�����������ʱ�ڣ���һʱ�ڵĻ�
 *         �޻����ɳɳ����������˹�����������ʱ��һ���£�
 * �����ڣ��������Ľ׶γ����ھ���ʵ���ڣ���������Ϊ���߸���
 *         ���������ϣ��������ˡ�
 * ���������ľ�������ˮ�����䡢������ȡ����ĺ�ʵ��
 ************************************************************/
 
#include <ansi.h>
#include <name.h>
#include <command.h>
#include <combat.h>

inherit NPC;
inherit F_NOCLONE;
inherit F_OBSAVE;

int is_item_make() { return 1; }
int is_magic_beast() { return 1; }
int is_stay_in_room() { return 1; }

mapping types = ([
        "gold"  : "�������",
        "wood"  : "ľ�����",
        "water" : "ˮ������",
        "fire"  : "�������",
        "soil"  : "���ĺ�ʵ",
]);

string chinese_s(mixed arg)
{
      if (! stringp(arg)) return "��";
      if (arg == "gold")  return HIY "��";
      if (arg == "wood")  return WHT "ľ";
      if (arg == "water") return HIG "ˮ";
      if (arg == "fire")  return HIR "��";
      if (arg == "soil")  return YEL "��";
}

nosave int last_age_set = 0;

void create()
{
        set_name("ħ����", ({ "magic beast" }));
        set("long", "��ҿ���������ȥָ���ĵط�(rideto)��\n");	
        set("race", "Ұ��");
        set("unit", "ֻ"); 
        set("str", 30);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("dex", 30);
        set("no_sell", "����ҲҪ���������ǵ���������Ѫ֮��Լ��"); 
        set("owner", "lonely");
        set("owner_name", "�ߴ���ʤ��");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ", "β��" }) );
        set("verbs", ({ "bite", "hoof" }) );
        
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);    
        set("jingli", 100);
        set("max_jingli", 100);                 
        set("shen_type", 0);
        set("combat_exp", 50000);
        set("attitude", "peaceful"); 
        set("obedience", 2);   

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defence",100);
        set_temp("apply/armor", 100);
        
        if (! check_clone()) return 0;
        
        setup();
        ::restore();
        keep_heart_beat(); 
}

string long()
{
        string result;
        string level;
        
        result = query("long");

        if (! query("magic/owner"))
        {
                result += HIW "��Ŀǰ�����������ڣ�˿��������������ħ�����ԡ�\n" NOR;
                return result;
        } else
        {
                if (! query("magic/growup"))
                        result += HIW "��Ŀǰ�����ڳɳ��ڣ����ĸ���ħ������Ϊ��\n" NOR;
                else
                if (! query("magic/become"))
                        result += HIW "��Ŀǰ�Ѵ��ڱ�̬�ڣ����ĸ���ħ������Ϊ��\n" NOR;
                else
                if (! query("magic/beast"))
                        result += HIW "��Ŀǰ�Ѵ��ڳ����ڣ����ĸ���ħ������Ϊ��\n" NOR;
                else
                        result += HIW "��Ŀǰ�����Ϲ����ޣ����ĸ���ħ������Ϊ��\n" NOR;
                
                if (! query("magic/beast"))
                        level = query("magic/level") + "��" + query("magic/lvl") + "��";
                else
                {
                        if (query("magic/king1"))
                                level = HIY "����̫ʼ";
                        else
                        if (query("magic/king2"))
                                level = HIY "����̫��";
                        else
                                level = HIM "�Ϲ�����";
                }
        }

        result += "-------------------------------------\n";
        result += HIW "���޵ȼ���" + level + "\n" NOR;
        result += HIW "����������" + query("magic/armor") + "\n" NOR;
        result += HIW "ħ�����ԣ�" + chinese_s(query("magic/type")) + "\n" NOR;
        result += HIW "ħ����ֵ��" + query("magic/power")  + "\n" NOR;
        result += HIW "�� �� �ȣ�" + query("magic/blood") + "\n" NOR;
        result += "-------------------------------------\n";

        return result;
}

int heal_up()
{
        object ob;
        string type;
        
        if (present("energy stone", this_object()))
                command("eat energy stone");

        if (! environment() || ! objectp(ob = find_player(query("owner"))))
        {
                save();
                message_vision("$Nһ���Ͳ����ˡ�\n", this_object());
                destruct(this_object());
                return 1;
        }
        
        if (query("mud_age") >= 3600 && ! query("magic/owner"))
        {
                if (! query("magic/level"))
                        set("magic/level", 1);
                if (! query("magic/lvl"))
                        set("magic/lvl", 1);
                                        
                if (environment(ob) != environment())
                        tell_object(ob, HIW "�����������ԼԼ�ĸ�Ӧ�����ħ����(" + name() + HIW ")Ŀǰ����������\n" NOR);
                else
                {
                        message_sort(HIW "ԭ����ѱ��$N" HIW "ͻ���Դ󷢣��ݺݵ�ҧ��$n�����ֱ�һ�ڣ���"
                                "�һ�����һ���Ѫ��������ȥ��Ȼ������$n�Ļ��У������˹���ĺ������ڹ�"
                                "��֮�󣬾������������Ľ��ߣ�һ�����ˣ�ȫ���ֽ⡱����ס$n����������"
                                "�����⴦���������ֲ�����䣬Ȼ��Ť���ۺϱ仯���ָ�ԭ�Ρ�\n" NOR, this_object(), ob);
                        
                        tell_object(ob, HIY + name() + HIY "���ڴ�ʱ����Ϊ���ˣ���ͬʱ����ɳ��ڡ�\n" NOR);        
                        set("magic/owner", ob->query("id"));                       
                        set("magic/armor", 1);
                        set("magic/power", 1);
                        set("magic/blood", 1);
                        set("ridable", 1); // ���ʱ��ſ�����Ϊ����Ĺ���
                        
                        switch(random(5))
                        {
                                case 0 : type = "gold"; break;
                                case 1 : type = "wood"; break;
                                case 2 : type = "water"; break;
                                case 3 : type = "fire"; break;
                                case 4 : type = "soil"; break;
                        }
                
                        set("magic/type", type);
                        tell_object(ob, HIY + name() + HIY "�����ɲ�ǣ���о���һ��" + types[type] + "��\n" NOR);
                        save();
                }
        } else       
        if (query("mud_age") > 3600 && query("mud_age") <= 39600)
        {
                /*
	        if (! query_condition("need_upgrade"))
                        apply_condition("need_upgrade", 1);
                */
                        
                if (random(10) == 1)   
                tell_object(ob, HIW "�����������ԼԼ�ĸ�Ӧ�����ħ����(" + name() + HIW 
                        ")��Ҫ�������������䣨upgrade��������\n" NOR);  
        } else
        if (query("mud_age") > 39600 && query("mud_age") < 43200)  
        {
                if (! query("magic/growup"))
                {
                        set("magic/growup", 1);    
                        tell_object(ob, HIY + name() + HIY "�ɹ������̬�ڣ����ʱ�����Ƚϴ�������Ҫ��ı�����\n" NOR);    
                }      

                /*
	        if (! query_condition("need_upgrade"))
                        apply_condition("need_upgrade", 1);
                */
		
                if (random(10) == 1)   
                tell_object(ob, HIW "�����������ԼԼ�ĸ�Ӧ�����ħ����(" + name() + HIW 
                        ")��Ҫ�������������䣨upgrade��������\n" NOR);     
        } else
        if (query("mud_age") >= 43200)
        {
                if (! query("magic/become"))
                {
                        set("magic/become", 1);                             
                        tell_object(ob, HIY + name() + HIY "�ɹ���������ڣ�����ӵ���������Ĺ��ܡ�\n" NOR);     
                }
        }  
        
        if (environment() && environment()->is_chat_room())
                last_age_set = time(); 
        if (! last_age_set) 
                last_age_set = time();               
    	
        add("mud_age", time() - last_age_set);
    	last_age_set = time();
    	set("age", (int)query("mud_age") / 43200);
        
        /*
        if (query("food") <= 0 || query("water") <= 0)
        {
	        if (environment() &&
		    ! environment()->is_chat_room() &&
                    ! query_condition("need_energy"))
		{
			// born & enter the world
                        apply_condition("need_energy", 1);
		}
        }
        */  
        save();  	
        
        // return ::heal_up() ;
        return 1;
}

void init()
{
        if (this_player()->query("id") == query("owner"))
        {
                add_action("do_modify", "modify");
                add_action("do_teach", "teach");
                add_action("do_shape", "shape");
                add_action("do_upgrade", "shengji");
        }

}


int do_modify(string arg)
{
        string item, msg;
        object me = this_player();
        if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
        return notify_fail("SYNTAX: modify ���� ����\n");
        if(item == "flee")
        {
                set("env/wimpy", atoi(msg));
                write("�ϣ�\n");
                save();
                return 1;
        }

        if(CHINESE_D->check_control(msg))
                return notify_fail("���������п��Ʒ���\n");
        if(CHINESE_D->check_space(msg))
                return notify_fail("�������費���ո�\n");
        if(CHINESE_D->check_return(msg))
                return notify_fail("�������費���س�����\n");

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);
        switch(item)
        {
        case "desc":
                if(CHINESE_D->check_length(msg) > 100)
                return notify_fail("����̫����\n"); 
                set("long",msg+ NOR"\n");
                write("�ϣ�\n");
                save();
                return 1;
        case "nickname" :
                if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("����̫����\n");
                set("nickname",msg+NOR);
                write("�ϣ�\n");
                save();
                return 1;
        case "title" :
                if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("����̫����\n");
                set("title",msg+NOR);
                write("�ϣ�\n");
                save();
                return 1;
        case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 60)
                return notify_fail("����̫����\n");
                set("arrive_msg",msg+NOR);
                write("�ϣ�\n");
                save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 60)
                return notify_fail("����̫����\n");
                set("leave_msg",msg+NOR);
                write("�ϣ�\n");
                save();
                return 1;

        }
        return notify_fail("��Ҫ�޸�ʲô��\n");

}

int do_teach(string arg)
{
        object me;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
        if(!myskill = me->query_skill(arg,1))
                return notify_fail("���������󻹲����أ�\n");
        if(arg != "unarmed" && arg != "move" && arg != "dodge")
                return notify_fail("��ѧ��������ܵģ�\n");
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
                return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");
        if(count_lt(count_sub(me->query("potential"), me->query("learned_points")), 1))
                return notify_fail("���Ǳ�ܲ�����\n");
        gin_cost = 100/ (int) query_int();
        if((int)me->query("jing") < gin_cost)
                return notify_fail("����Ȼ̫����û�а취�̣�\n");
        me->receive_damage("jing",gin_cost);
        me->add("potential",-1);
        amount = (int)me->query_int() * (int) query_int();
        message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());
        if(random(100) < query("obedience") )
                command("emote �ܲ���Ը�غ���һ����");
        else 
        {
                improve_skill(arg,amount);
                message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(arg)),this_object());
        }
        return 1;

}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
                else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int do_shape(string arg)
{        
        mapping my;
        string shape;
        mixed at_pt, pa_pt, do_pt;
        
        my = query_entire_dbase();
        
        printf("������ %s%3d/ %3d %s(%3d%%)"NOR"  ��Ѫ�� %s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]
        );    
        printf("ʳ� %d\t\t��ˮ�� %d\n", 
        my["food"], my["water"]);            
        printf("���ˣ� %s\n", my["owner"]);
        printf("���飺 %s\t\tɱ���� %d\n",
        count_add(my["combat_exp"], 0),my["bellicosity"]
        );
        printf("�ǻۣ� %d\t\t���ʣ� %d\n",
        query_int(), query_con()
        );
        printf("��̬�� %d\t\t������ %d\n",
        query_per(), query_str()
        );
        printf("�ٶȣ� %d\n",
        query_dex()
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf("������ %s\t\t������ %s\n\n",
//        at_pt+1, pa_pt/2+do_pt/2+1
        count_add(at_pt, 1), count_add(count_add(count_div(pa_pt, 2), count_div(do_pt, 2)), 1)
        );
        return 1;
}


int do_upgrade(string arg)
{
        object me;
        int b_en, b_lv, b_level;
    
        me = this_player();
    
        if (! arg || ! id(arg))
                return notify_fail("��Ҫ���������������ʲô��\n");
        
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
                
        if (! query("magic/owner"))
                return notify_fail("���ħ������ʱ������Ҫ���������\n");
                
        if (environment(me) != environment())
                return notify_fail("���ħ���޲������㴦��һ�����䡣\n");

        if (me->query("neili") < me->query("max_neili") * 9 / 10)
                return notify_fail("�����������������棬����óȻ���ã�\n");

        if (me->query("jingli") < me->query("max_jingli") * 9 / 10)
                return notify_fail("�����ھ������ã�����óȻ���ã�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����������ʵ������óȻ�����ħ���ޡ�\n");

        if (me->query("max_neili") < 8000)
                return notify_fail("�㳢������һ���������޷�˳"
                                   "������һ�����죬����ʩչ���������\n");

        if (me->query("max_jingli") < 1000)
                return notify_fail("����ͼ�������þ��������Ǹо�����Ƿȱ��\n");                                
                
        if (me->query("experience") < me->query("learned_experience") + 100) 
                return notify_fail("�����ڻ��۵�ʵս��ỹ̫�٣��޷�����������ħ���ޣ�\n");
                
        message_sort(HIR "$N���о�����ָħ���޼���ͬʱ��ת������������"
                "���澭����ԴԴ������������ע��ħ����($n" HIR ")���ڡ�\n" NOR, 
                me, this_object());

        if (me->query("max_neili") < me->query_neili_limit() - 400)
        {
                if (random(2) == 1)
                {
                        // ����δ������
                        message_vision(HIR "$N" HIR "��ɫ��Ȼ���˱䡣\n" NOR,
                                       me);
                        tell_object(me, HIC "���Ȼ���õ�����Ϣ��Щ���ҡ�\n" NOR);
                } else
                {
                        message_vision(HIR "$N" HIR "��Ȼ�ƺ�һ������"
                                       "��ɲʱ�����죡\n" NOR, me);
                        tell_object(me, HIC "��е����������������δ����"
                                    "���������������������ڹ�������\n" NOR);
                        tell_object(me, HIC "��Ļ����ڹ��½��ˡ�\n");
                        me->set_skill("force", me->query_skillo("force", 1) - 10 - random(5));
                        return 1;
                }
        }
                
        me->start_busy(1);
        
        me->add("max_neili", -100);
        me->set("neili", (int)me->query("max_neili"));
        me->add("max_jingli", -100);
        me->set("jingli", (int)me->query("max_jingli"));        
        me->add("learned_experience", 100);
        
        tell_object(me, HIW "������Ƭ�̣�����" + name() +
                        HIW "�ƺ��������ԣ���Ծ���ݣ�����΢΢һЦ��\n" NOR);
                        
        // apply_condition("need_upgrade", 0);
        
        if (query("magic/owner") && ! query("magic/growup"))
        {
                add("magic/power", 5);
                add("magic/blood", 1);
                add("magic/armor", 2);
                message_vision(RED "$N��ħ����($n" RED ")ħ�������ˣ�\n" NOR, me, this_object());
                save();
                return 1;
        } else  
        if (query("magic/growup") && ! query("magic/become"))
        {
                add("magic/blood", 1);
                add("magic/armor", 5);
                add("magic/power", 2);  
                message_vision(RED "$N��ħ����($n" RED ")ħ�������ˣ�\n" NOR, me, this_object());
                save();
                return 1; 
        } else                        
        if (query("magic/become"))
        {
                b_en = (int)query("magic/energy");
                b_en++;
        
                set("magic/energy", b_en);
                add("magic/blood", 1);
                
                b_lv = (int)query("magic/lvl");
                
                // if ( b_en >= ((b_lv + 1) * (b_lv + 1) + 10)) 
                if (b_en >= (b_lv * 2))
                {
                        b_lv++;
                        set("magic/lvl", b_lv);
                
                        message_vision(HIY "ħ���������һ����һ���������$N�����壬�����ˣ�\n" NOR, me);
                        message_vision(HIG "$N��ħ���޵������ˣ�\n" NOR, me);
                        
                        add("magic/power", 10);
                        add("magic/armor", 10);
                        set("magic/energy", 0);
                
                        b_lv = (int)query("magic/lvl");
                        b_level = (int)query("magic/level");       
                        if (b_level <= 9 && b_lv % 9 == 0)
                        {
                                add("magic/power", 200);
                                add("magic/armor", 200);
                                add("magic/level", 1);
                                set("magic/lvl", 1);
                                message_vision(HIY "ħ��������ķ����⣬�������Ϲ�����$N�����壬�����ˣ�\n" NOR, me);
                                message_vision(HIG "$N��ħ���޵������ˣ�\n" NOR, me);
                        }                       
                        
                        if (b_level > 9 && ! query("magic/beast"))
                        {
                                set("magic/beast", 1); 
                                add("magic/power", 800);
                                add("magic/armor", 800);       
                                message_vision(HIY "ͻȻ��ճ���һ��������ħ��������ĺ����ӣ�ħ����ȫ��ͨ�죡\n" NOR, me);  
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                        "��˵�Ϲ�����" + name() + HIM + "�������˼䡣");
                        }
                             
                        save();
                        return 1;
                }       
                message_vision(RED "$N��ħ����($n" RED ")ħ�������ˣ�\n" NOR, me, this_object());
                save();
                return 1;
        }
}

// �ٻ��ӿ�
int receive_whistle(object me)
{
        object env;
        int    period; 

        if ((env = environment()) && env == me)
        {
                if (me->query_temp("is_changing") &&
                    me->query_temp("is_changing") == this_object())
                        write(name() + "�Ѿ���������������ˣ����ٻ���ʲô����\n");
                else
                        write(name() + "�㲻�������������ٻ���ʲô����\n");
                return 1;
        }
        if (env == environment(me))
        {
                if (is_fighting())
                        remove_all_enemy(1);                                     
                message_vision(name() + "һ���Ͳ����ˡ�\n", me);
                period = time() - ((int) query("last_save"));
                if (period < 0 || period > 900)
                {
                        set("last_save", time());
                        save(); 
                }
                destruct(this_object());
                return 1;
        } else
        {
                if (env)
                {
                        if (env->is_character() && environment(env))
                                env = environment(env);

                        message("vision", HIG "ͻȻ" + name() + HIG "����һ����â��"
                                HIG "˲����ʧ�ˣ�\n\n" NOR, env);

                        if (interactive(env = environment()))
                        {
                                env->delete_temp("is_riding"); 
                                delete_temp("is_rided_by");
                                tell_object(env, HIM + name() +
                                        HIM "��Ȼ�����ȥ�ˣ�\n" NOR);
                        }
                }
                message_vision(HIG "$n" HIG "��֪������ܵ�$N" HIG "��ǰ��\n\n" NOR,
                        me, this_object());
        }
        set_temp("apply/armor", query("magic/armor"));
        
        move(environment(me));

        if (environment() != environment(me))
                return 0;

        return 1;
}

// �����ӿ�
int receive_change(object me)
{
        object ob;
        object env;
        
        ob = this_object();

        if (! query("magic/owner"))
                return 0;
                
        if ((env = environment()) && env == me)
        {
                if (me->query_temp("is_changing") &&
                    me->query_temp("is_changing") == ob)
                        write(name() + "�Ѿ���������������ˣ��㻹������ʲô����\n");
                else
                        write(name() + "�㲻���������������Ļ�����Ҫ��������������\n");
                return 1;
        }
                                
        set_weight(1); 
        move(me);
        set("no_put", "ħ�����Ѿ����������޷��ֿ���");
        set("no_give", "ħ�����Ѿ����������޷��ֿ���");
        set("no_drop", "ħ�����Ѿ����������޷��ֿ���");
        set("no_steal", "ħ�����Ѿ����������޷��ֿ���");
        set("no_get", "ħ�����Ѿ����������޷��ֿ���");        
        set_temp("is_changed_by", me); 
        me->set_temp("is_changing", ob);
        
        if (! query("magic/become"))
        {
                message_sort(HIM "$n" HIM "һ����Х�����ϵ�����ͻ��ʢ������������"
                             "���Ľ��ߣ�һ�����ˣ�ȫ���ֽ⡱����ס$N" HIM "��������"
                             "�������⴦��\n" NOR, me, ob);
                return 1;
        } 
        me->set_temp("armor/beast", ob);
        me->add_temp("apply/armor", query("magic/armor"));
        message_sort(HIM "$n" HIM "һ����Х�����ϵ�����ͻ��ʢ������������������Ľ�"
                     "ɫ���ƣ�˲�䣬$n" HIM "����������̬����ʼ������$N" HIM "�����ϣ�$n"
                     HIM "��ϸ����֯���ϵ���$N" HIM "���ϸ���λ��ͣ�ĔJ���������ģ�ÿ"
                     "һ�����ֶ���ʼ�𽥵ĳ��Σ���״����һ��飬�����������һ��$N"
                     HIM "�����˼�����ȫ����$n" HIM "��̬��������С�\n" NOR, me, ob);
        tell_object(me, sort_msg(HIC "�㿴���Լ����������������һ����ȫ����һ����ҫ���ĺ�"
                        "ʵ�����У�����������ǽ����Ŀ��ף�������ȴ���Ըо���Ƥ��Ħ"
                        "�ĵĸо����ͺ�����һ�����ԭ�����������һ���ݣ��������Ƥ��"
                        "һ�������������Ըе�����������΢�磬�Լ�����ɹ�������ϵ����ȡ�\n" 
                        NOR), me, ob);       
        return 1;
}        
        
// �������
int receive_recover(object me)
{
        object env;

        if (! (env = environment()) || env != me)
                return 0; 
       
        message_sort(HIM "$N���ϵ�ħ����ϸ��������䣬�����Ϸ�����������һ"
                     "�����$NԼһ�������ң����ڵ��ϣ�Ȼ���ڵ��Ͽ�ʼŤ����"
                     "�ϱ仯�������ģ�����һ�����ޱ���Ϥ�����壭" + name() + 
                     HIM "��\n" NOR, me);
       
        tell_object(me, sort_msg(HIC "��о����Լ������屻������һ���Ƶģ����ָо�"
                "�޷����ݣ���ʹ����������ȥ��һ��Ƥ�ĸо�ȴ����˵�������"
                "��̡�\n" NOR));
                
        move(environment(me));
        delete("no_put");
        delete("no_give");
        delete("no_drop");
        delete("no_steal");
        delete("no_get");               
        delete_temp("is_changed_by"); 
        me->delete_temp("is_changing");   
        
        if (me->query_temp("armor/beast")&&
            me->query_temp("armor/beast") == this_object())
        {
                me->delete_temp("armor/beast"); 
                me->add_temp("apply/armor", - query("magic/armor"));
        }
        
        if (environment() != environment(me))
                return 0;
                
        return 1;      
}

int accept_object(object me, object ob)
{
        if (me->query("id") == query("owner")) 
        {
                if (ob->query("id") == "energy stone")
                {
                        command("eat energy stone");                        
                        return 1;
                }
        }
        return 0;
}

void die()
{        
        int i;
        object owner, *enemy;
        int jing, qi;
        mixed exp;

        
        owner = UPDATE_D->global_find_player(query("owner")); 
        
        if (! objectp(owner)) 
                return ::die();
        
        if (query_temp("is_changed_by")) 
        {
                delete("no_put");
                delete("no_give");
                delete("no_drop");
                delete("no_steal");
                delete("no_get");               
                delete_temp("is_changed_by"); 
                
                if (owner->query_temp("is_changing") &&
                    owner->query_temp("is_changing") == this_object()) 
                        owner->delete_temp("is_changing");
                
                if (owner->query_temp("armor/beast") &&
                    owner->query_temp("armor/beast") == this_object())
                {
                        owner->delete_temp("armor/beast"); 
                        owner->add_temp("apply/armor", - query("magic/armor"));
                }
        }  
        // owner->set("beastdied", 1);
        
        UPDATE_D->global_destruct_player(owner, 1); 

        exp = query("combat_exp");
        jing = (int) query("max_jing");
        qi = (int) query("max_qi");
        if (! environment()->query("no_death_penalty"))
        // set("combat_exp", count_mul(count_div(exp, 10), 9));
        set("eff_qi", qi);
        set("eff_jing", jing);
        set("qi", qi);
        set("jing", jing);

        save();        
        return ::die();
}

void unconcious()
{
        die();
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result; 

        if (! query("magic/owner") || 
            (query("magic/growup") && 
            ! query("magic/become")))
                return 0;
        
                        
        result = ([ "damage": -query("magic/armor") ]);  

        result += (["msg" :   HIC "$N" HIC "�Ĺ�������$n" 
                              HIC "��ʵ�Ļ����ϡ�\n" NOR ]); 

        return result; 
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        if (! query("magic/owner") || 
            (query("magic/growup") && 
            ! query("magic/become")))
                return 0;
                
        ob->receive_wound("qi", 200 + query("magic/power"), me);
               
        return sort_msg(HIR "$N" HIR "���쳯��$n��" HIR "�����΢"
               "΢������â��һ��Լʮ���ִ�С�Ļ�����$N"
               HIR "����������ɿ�Ļ���$n" HIR "���ؿڣ�"
               "$n" HIR "�ŵŵŵĵ����˼���������������\n" NOR);
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{
        if (! mapp(data))
                return 0;

        if (mapp(data["magic"]))
                set("magic", data["magic"]);
        
        if (intp(data["ridable"]))
                set("ridable", 1);
        
        if (intp(data["age"]))
                set("age", data["age"]);    

        if (intp(data["mud_age"]))
                set("mud_age", data["mud_age"]);        

        if (stringp(data["owner"]))
                set("owner", data["owner"]);
                
        return 1;
}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;
        object  user;

        data = ([ ]);
        
        if (mapp(query("magic")))
                data += ([ "magic" : query("magic") ]);

        if (intp(data["ridable"]))
                data += ([ "ridable" : query("ridable") ]);
                
        if (intp(data["age"]))
                data += ([ "age" : query("age") ]);

        if (intp(data["mud_age"]))
                data += ([ "mud_age" : query("mud_age") ]);                

        if (stringp(data["owner"]))
                data += ([ "owner" : query("owner") ]);  
                
        return data;
}
