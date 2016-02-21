// ������� 
// Created by Lonely Nitan@Mud
// ���������ɵģΣУ�
// ����������ѽ�����������һ��ָ��
// ����Ϊ������ҵķǳ�������ˣ���
// �Ծ������ˡ�

#include <ansi.h>
inherit NPC;
#define MAX_EXP 10000000

int check_name(string str, object me);
int create_banghui(string str);

void create()
{
        set_name("���", ({"ni cai", "ni", "cai"}));
        set("long", "���Ϳ���֮һ���������ְ��(banghui)�Ľ�����\n");
        set("nickname", RED"����"NOR);
        set("gender", "����");
        set("age", 21);
        set("per", 2100);

        set_skill("unarmed", 500);
        set_skill("dodge",   500);
        set_skill("parry",   500);
        set_temp("apply/attack",  100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage",  50);

        set("inquiry", ([
                "banghui"       :"Ҫ���������create <�����>\n",
                "bangpai"       :"Ҫ���������create <�����>\n",
                "bunch"         :"Ҫ���������create <�����>\n",
                "���"          :"Ҫ���������create <�����>\n",
                "����"          :"Ҫ���������create <�����>\n",
        ]) );

        set("combat_exp", 21000000);
        set("max_jingli", 21000);
        set("jingli", 21000);
        set("max_neili", 21000);
        set("neili", 21000);
        set("max_qi", 21000);
        set("qi", 21000);
        set("max_jing", 21000);
        set("jing", 21000);
        set("no_suck", 1);
        setup();
}

int check_name(string name, object me)
{
        int i;

        i = strlen(name);

        if ((strlen(name) < 4) || (strlen(name) > 12 )) 
        {
                tell_object(me, "��������붨�ڶ��������֡�\n");
                return 0;
        }
        
        while (i--) 
        {
                if (name[i] <= ' ') 
                {
                        tell_object(me, "�Բ�����İ�����в����ÿ����ַ���\n");
                        return 0;
                }
                
                if (i%2 == 0 && ! is_chinese(name[i..<0])) 
                {
                        tell_object(me, "���á����ġ�������İ�ᡣ\n");
                        return 0;
                }
        }
        return 1;
}


void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("create_banghui", "create");
}

int create_banghui(string str)
{
        object me, lingpai, lp;
        int count;
        int base = 10000; 

        me = this_player();
        
        if ((string)me->query("bunch/name"))        
        {
                tell_object(me, "���Ѿ���" + me->query("bunch/name") + "�����ˣ���������ᡣ\n");
                return 1;
        }
        
        if (me->query("combat_exp") < MAX_EXP)    
        {
                tell_object(me, RANK_D->query_respect(me) + "��ʵս���黹��" +
                	    (string)(MAX_EXP - me->query("combat_exp")) + "�㣬��ʱ�޷��������ᡣ\n");
                return 1;
        }
        
     	if (me->query("weiwang") < 100)
     	{
        	tell_object(me, RANK_D->query_respect(me) + "������������Ҫһ�ٵ㽭��������"
                    	    + "������������˭����İ���\n");
        	return 1;
    	}
    	
        if (! count = me->query("lonely/have_create")) 
        	count = 0;
        	
        if (count >= 2)    
        {
                tell_object(me, "���ŭ��������Ϊ����Ǵ����������ٽ���ᣬ�±��Ӱɣ�\n");
                return 1;
        }
        
        if (! str)       
        {
                tell_object(me, "��Ҫ����ʲô���ֵİ�᣿\n");
                return 1;
        }
        
        if (! check_name(str, me)) return 1;

        if (file_size("/data/guild/" + str + ".o") != -1) 
        {
                tell_object(me, "�ǳ���Ǹ������İ�����������ˡ�\n");
                return 1;
        }
        
        lingpai = new("/clone/misc/lingpai");
        lingpai->create(str);
        lingpai->set("bangzhu", me->query("name"));
        lingpai->set("bangzhu_id", me->query("id"));
        lingpai->set("player", ([me->query("id") : me->query("name")]));
        lingpai->set("npc", ([]));
        lingpai->set("area", ([]));
        lingpai->set("money", 0);
        lingpai->save();
        destruct(lingpai);

        BUNCH_D->create_bunch(str, base); 
        me->set("bunch/name", str);
        me->set("bunch/rank", "����");
        me->set("bunch/level", 7);
        count++;
        me->set("lonely/have_create", count);
        me->save();
        command("chat ��ϲ" + me->query("name") + "�İ�ᡸ" + str + "�������ɹ���\n");
        return 1;
}

void greeting(object ob)
{
        string banghui;
        object lingpai;
        if (! ob || environment(ob) != environment()) return;
        if ((string)(banghui = ob->query("bunch/name")))      
        {
                lingpai = new("/clone/misc/lingpai");
                lingpai->create(banghui);
                
                if (lingpai->query("no_use"))    
                {
                        tell_object(ob, "��ɵ���" + ob->query("name") + "����İ���ļ������⣬������ʦ��ϵ�ɡ�\n");
                }
                else if (lingpai->query("bangzhu_id") != "???")    
                {
                        if (lingpai->query("bangzhu_id") == ob->query("id") 
                        &&  lingpai->query("bangzhu") == ob->query("name"))
                        	tell_object(ob, "���һ��ȭ������λ" + ob->query("bunch/name") +
                        		    ob->query("bunch/rank") + "�����������Σ�\n");
                        		    
                        else    tell_object(ob, "��ɵ���" + ob->query("name") +
                        "������������ɺã�\n");
                }
                else    tell_object(ob, "���͵͵������ߵ��������ʧ�ٶ��գ�" +
                        	    RANK_D->query_respect(ob) +
                        	    "ֻ�軨һǧ���ƽ�Ϳ������°���֮λ��\n");
                destruct(lingpai);
        }
        else    tell_object(ob, "��ɶ���һ��ȭ������λ" + RANK_D->query_respect(ob) + "��������������\n");
}

int accept_object(object who, object obj)
{
        string banghui;
        object lingpai;
        
        if (! banghui = who->query("bunch/name"))     
        {
                tell_object(who, "���Ц�����ҿɲ���ƽ���޹ʽ�����Ķ�����\n");
                return 0;
        }
        
        lingpai = new("/clone/misc/lingpai");
        lingpai->create(banghui);
        
        if (lingpai->query("no_use"))    
        {
                tell_object(who, "���̾����" + who->query("name") + "����İ���ļ������⣬������ʦ��ϵ�ɡ�\n");
                destruct(lingpai);
                return 0;
        }
        
        if (lingpai->query("bangzhu_id") != "???")       
        {
                tell_object(who, "���ʮ�־��ȣ�˵��������������ĺúõģ��ҿɲ��İѰ���֮λ����" +
                	    RANK_D->query_respect(who) + "����\n");
                destruct(lingpai);
                return 0;
        }
        
        if (! obj->query("money_id"))    
        {
                tell_object(who, "�����ü������Щ������û��Ȥ��\n");
                destruct(lingpai);
                return 0;
        }
        
        if(obj->value() < MAX_EXP)       
        {
                tell_object(who, "��ɵ�������һǧ���ƽ𣬲�Ȼ����������潻����\n");
                destruct(lingpai);
                return 0;
        }
        
        lingpai->set("bangzhu", who->query("name"));
        lingpai->set("bangzhu_id", who->query("id"));
        lingpai->save();
        destruct(lingpai);
        who->set("bunch/level", 7);
        who->set("bunch/rank", "����");
        who->save();
        
        command("chat " + who->query("name") +
        	"����һǧ���ƽ�������" + banghui + "����֮λ��\n");
        return 1;
}

