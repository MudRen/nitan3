// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xie.c лѷ

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_dao();
string ask_boat();

void create()
{
        object ob;
        set_name("лѷ",({"xie xun","xie","xun"}));
	set("title", HIG "����" HIY "��ëʨ��" NOR);
	
        set("long", "���������̵��Ĵ󻤷�֮һ�Ľ�ëʨ����\n"+
                    "����Ŀ�ΰ�쳣����ͷ��ɢ����ͷ����˫Ŀ��Ϲ��\n"+
                    "������ǰһվ���������ݣ���������һ�㡣\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -13000);
        set("str", 30);
        set("per", 16);
        set("int", 29);
        set("con", 35);
        set("dex", 27);        
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 70);
        set("combat_exp", 1350000);
        set("level", 40);

        set_skill("cuff",460); 
        set_skill("dodge",460);
        set_skill("force", 460);
        set_skill("blade",460);
        set_skill("hand", 460);
        set_skill("literate",410);
        set_skill("qingfu-shenfa", 460);
        set_skill("qishang-quan",480);
        set_skill("shenghuo-shengong", 460);
        set_skill("pili-shou", 460);
        set_skill("parry", 460);
        set_skill("lieyan-dao",460);    
        set_skill("martial-cognize", 300);   
                    
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "qishang-quan");
        map_skill("blade", "lieyan-dao");
        map_skill("hand", "pili-shou");
        
        prepare_skill("cuff","qishang-quan");
        
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform cuff.shang") :),
                (: command("perform cuff.fei") :),
	}) );

        set("inquiry", ([
                 "���޼�"  : "�����ҵ����ӣ����Ѻܾ�û�м������ˡ�",
                 "����ȭ��": (: ask_me :),
                 "������": (: ask_dao :),
                 "��"    : (: ask_boat :),
                 "����"  : (: ask_boat :),
                 "�촬"  : (: ask_boat :),
                 "��ԭ"  : (: ask_boat :),
                 "����"  : "���������ǹ���ʦ������ɱ����һ���Ŀڣ��˳𲻹����죡",
        ]));

        create_family("����", 36, "��������");
        
        set("master_ob",5);
	setup();
        
        // carry_object("/d/mingjiao/obj/tulong-dao")->wield();
        carry_object("/clone/weapon/tulongdao")->wield();
        carry_object("/d/mingjiao/obj/xiongpi")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say �Ϸ��յ��ӡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("can_learn/xiexun/qishang-quan") &&
            skill == "qishang-quan")
                return 1;

        if (ob->query("can_learn/xiexun/qishang-quan") &&
            skill == "cuff")
                return 1;

        if (ob->query("can_learn/xiexun/qishang-quan") &&
            skill == "hand")
                return 1;

        if (ob->query("can_learn/xiexun/qishang-quan") &&
            skill == "pili-shou")
                return 1;
                                        
        if (! ob->query("can_learn/xiexun/qishang-quan"))
                return -1;
                
        command("say �㵽��ѧ��ѧ�ҵ�����ȭ������ѧ�Ϳ����");
        return -1;
}

string ask_me()
{
        mapping fam; 
        object me = this_player();
        
        if (! (fam = me->query("family")) || fam["family_name"] != "����")
                return "����ȭ����û��˵����";
                
        if (fam["master_name"] != "���޼�")
                return RANK_D->query_respect(me) + "������ذɣ���˵��������ɵľ���������ô��֪����";
                
        if (me->query("can_lean/xiexun/qishang-quan"))
                return "�Ҳ��Ǵ�Ӧ��������ȭ��������ô��Ҫ�ʣ�";
                
        if (! me->query_temp("marks/����"))
                return "��������ȭ�����������ӣ��������ˣ�";
                
        command("consider");
        command("say �޼��⺢�ӣ���ô�ɽ�����ȭ���������أ�");
        command("say Ҳ�գ��޼ɼ�Ȼ������������Ҿʹ�����ɡ�");
        me->set("can_learn/xiexun/qishang-quan", 1);
        me->delete_temp("marks/����");
        command("whisper " + me->query("id") + " ����֮���������������˷δݸγ������뾫ʧ���㱣�������������Ƿ��");
        return "��ѧ���˾Ϳ��Ի�ȥ�ɡ�";
}

string ask_boat()
{ 
        object me = this_player();
        
        if (! me->query("can_learn/xiexun/qishang-quan")) 
                return "�����⼫�������뿪��ԭ��������Ĵ�����";
                
        command("say �����Ұ�������������ں�ɽ�����п���(chop)��ľ��Ȼ��Űᵽ�����촬(make)��");
        return "Ҳ��֪���������Ǻ������޼ɺ�������ô���ˡ�";
}

string ask_dao()
{
        mapping fam;
         
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
                
        if (present("tulong dao", this_object()))
        {
                command("wield dao");
                command("say �������𣬱����������������£�Ī�Ҳ��ӣ����첻����˭�����档");
                write("\nлѷ����������������ͷڤ˼����֮�ء�\n\n");
                this_player()->set_temp("xie_tld", 1);
                return "��Ѱ��������֮�أ���֮�����εñ�����......";
        } else 
                return "�������𣬱����������������£�Ī�Ҳ��ӣ�";
}

int accept_object(object who, object ob)
{
        object obj;
        object me = this_object();
       
        if ((! ob->is_head() && ! ob->is_corpse()) || 
            ! stringp(ob->query("owner_id")) ||  
            ob->query("owner_id") != "cheng kun")
        {
                command("say �Ϸ����������ûʲô��Ȥ����");
                return 0;
        }                  
            
        command("say ��������������ͷ�� ��������ͷ��");
        command("chat ��������������������ͷ�� ��������ͷ��");
        call_out("destroy", 1, ob);
       
        if (ob->query("killed_by") != who->query("id"))
        {
                command("say ������������ɱ�İɣ�������ô�õ������ͷ�ģ�");
                return 1;
        }     
        if (who->query_temp("xie_tld") && present("tulong dao", me))
        {
                command("say �����Ҵ��ñ�����ѵ������ҵ�л��ֻ��ϧ�����������Ƕ�����");   
                command("unwield dao");        
                command("give tulong dao to "+who->query("id"));
                who->delete_temp("xie_tld");
                return 1;
        } else
        {
                command("say �����Ҵ��ñ���������ֻ���ҵĽ�ë�͸����ˣ�ֻ��ϧ�����������Ƕ�����");
                obj = new ("/d/mingjiao/obj/jinmao");
                obj->move(this_player());
                return 1;
        }
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "���Ƿ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qishang-quan/fei",
                           "name"    : "���Ƿ���",
                           "sk1"     : "qishang-quan",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qishang-quan/shang",
                           "name"    : "���־�",
                           "sk1"     : "qishang-quan",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "��ػ�Ԫ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pili-shou/hun",
                           "name"    : "��ػ�Ԫ",
                           "sk1"     : "pili-shou",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;
                
        default:
                return 0;
        }
}
