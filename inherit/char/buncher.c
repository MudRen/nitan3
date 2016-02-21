// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

int is_bunch_npc() { return 1; }

int init_area_npc(object ob);
int do_join_bunch(object who);

void setup() 
{

        set("bunch/zhengzhao", 1 + random(3));
        ::setup(); 

        call_out("init_area_npc", 0, this_object()); 
} 

string long()
{
        string desc;
        
        desc = query("long");
        if (! stringp(desc)) desc = "";

        if (query("bunch/bunch_name")) 
                return desc;
        
        desc += HIW + (query("gender") == "����" ? "��" : "��") + 
                "����Ѱ����������ıӻ��������������ɡ�\n" NOR;

        return desc;
}

int init_area_npc(object ob)
{
        mapping areas, data;
        object room;
        
        if (! objectp(ob) || 
            ! room = environment(ob)) 
                return 0;
        
        areas = BUNCH_D->query_all_areas();        
        // �������û�м��ص�ϵͳ�У���õ���û�б�����ռ��                 
        if (undefinedp(areas[base_name(room)])) 
                return 0;
        
        if (areas[base_name(room)]["bunch_name"] == "������")
                return 0;
                
        data = ([ "bunch_name"     : areas[base_name(room)]["bunch_name"],
                  "max_zhongcheng" : 100,
                  "zhongcheng"     : areas[base_name(room)]["zhongcheng"],
                  "zhengzhao"      : query("bunch/zhengzhao"),
        ]);
                           
        set("bunch", data);
        
        return 1;        
}

int accept_object(object who, object ob)
{
        int r; 
        mapping data;
        string  *obj;
        string  stuffid, stuffname;

        if (r = ::accept_object(who, ob))   
                return r;   
           
        if (! who->query("bunch/bunch_name"))  
        {
                command("say ��Ȼ" + RANK_D->query_respect(who) +
                	"��˿��������Ҿ������ˡ�\n");
                return 1;
        }

        if (who->query("bunch/bunch_name") == query("bunch/bunch_name")) 
        {
                command("say ���ǰ����ֵܣ��α���˿�����\n");
                return 0;
        }  

        if (query("startroom") != base_name(environment(this_object())))
        {
                command("say �������е㲻�ʣ������µ��һ�ȥ��˵�ɡ�\n");
                return 0;
        }
                                                          
        if (query("bunch/zhengzhao") == 1)       
        {
                command("say " + RANK_D->query_self(this_object()) +
                	"ֻ���书����Ȥ������һ����̸��\n");
                return 0;
        }        

        if (query("bunch/zhengzhao") == 2)       
        {
                if (query_temp("invite/target") != who) 
                {
                        command("say �޹�����»����֪" + 
                        	RANK_D->query_respect(who) + "����" + ob->name() + 
                        	"�к����⣿\n");
                        return 0;
		}       
		
                if (! ob->query("money_id"))     
                {
                        command("say " + RANK_D->query_self_rude(this_object()) +
                         	"ֻ��Ǯ����Ȥ������������Լ����Űɡ�\n");
                        return 0;
                }       

                if (ob->value() < query_temp("invite/money") * 10) 
                {
                        command("say �Ҳ���˵������" +
                        	chinese_number(query_temp("invite/money") / 1000) +
                        	"���ƽ���һ����Ҳ���У�\n");
                        return 0;
                }
                
                if (query("bunch/bunch_name") && 
                    query("bunch/zhongcheng") > who->query_kar())   
                {
                        command("say �����������Ǯ������ζԵ�������������֣�\n");
                        return 0;
                }
                
                return do_join_bunch(who);
        }
        
        if (query("bunch/zhengzhao") == 3)       
        {
                data = query_temp("invite/target");
                
                if (! mapp(data)) data = ([]);
                
                obj = keys(data);
                
                if (member_array(who->query("id"), obj) == -1)        
                {
                        command("say �����ز���ʶ��Ϊ�θ�" +
                        	RANK_D->query_self(this_object()) + ob->name() +
                        	"��\n");
                        return 0;
                }
                
                sscanf (data[who->query("id")], "%s:%s", stuffid, stuffname);
                
                if (stuffname != ob->query("name") 
                ||  stuffid != ob->query("id"))    
                {
                        command("say " + RANK_D->query_respect(who) +
                        	"������Ҫ����" + stuffname + "(" +
                        	stuffid + ")������" + ob->query("name") +
                        	"(" + ob->query("id") + ")��\n");
                        return 0;
                }
                
                if (query("bunch/bunch_name") && 
                    query("bunch/zhongcheng") > who->query("meili"))     
                {
                        command("say ����������Ķ���������ζԵ�������������֣�\n");
                        return 0;
                }
                
                return do_join_bunch(who);
        }
}

int do_join_bunch(object who)
{
        string bunch, area;
        
        if (! stringp(bunch = who->query("bunch/bunch_name")))      
        {
                command("say �ף���û�м����ᣬ������μ����أ�\n");
                return 0;
        }
        
        if (bunch == query("bunch/bunch_name"))        
        {
                command("say ���Ƕ���ͬ����֣����º������\n");
                return 0;
        }
         
        area = base_name(environment(this_object()));
        
        command("say ��Ȼ" + RANK_D->query_respect(who) +
                "��˿�����" + RANK_D->query_self(this_object()) +
                "������Ҳ���ܶԲ����㰡��\n");
        message_vision("$N���������ᡸ" + bunch + "����\n",
                this_object());

        BUNCH_D->add_area_into_bunch(bunch, area, environment(this_object())->short(), this_object());
        
        if (query_temp("invite/target"))
               delete_temp("invite/target");
        
        set("no_clean_up", 1);
                       
        return 1;
}

void die()
{      
        mapping areas;
        object room; 
        int kaifa, zhongcheng;

        room = environment(this_object());

        areas = BUNCH_D->query_all_areas();        
        // �������û�м��ص�ϵͳ�У���õ���û�б�����ռ��                 
        if (undefinedp(areas[base_name(room)])) 
                return ::die();
                        
        if (query("bunch/bunch_name") == "������")
                return ::die();                

        kaifa = areas[base_name(room)]["kaifa"];
        kaifa -= (random(10) + 1); 
        zhongcheng = areas[base_name(room)]["zhongcheng"];
        zhongcheng -= random(2);
        
        if (kaifa < 20) kaifa = 20;
        if (zhongcheng < 10) zhongcheng = 10;
        
        BUNCH_D->set_area_info(base_name(room), "kaifa", kaifa);
        BUNCH_D->set_area_info(base_name(room), "zhongcheng", zhongcheng);
        
        set("bunch/zhongcheng", zhongcheng);
        
        message("channel:rumor", HIM "��ҥ������ĳ�ˣ�����" + query("name") + "��ɱ��" + 
                                 room->short() + "�Ŀ����Ƚ�Ϊ" + kaifa + "��\n" NOR, users());
                
        return ::die();
}
