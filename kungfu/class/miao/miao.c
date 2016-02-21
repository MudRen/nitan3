// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h> 
#include "miao.h" 

inherit NPC; 
inherit F_MASTER; 
inherit F_COAGENT; 

mixed ask_skill1(); 
mixed ask_skill2(); 
mixed ask_skill3(); 
mixed ask_skill4(); 
mixed ask_skill5(); 

void create() 
{ 
       // object ob; 
        set_name("���˷�", ({ "miao renfeng", "miao", "renfeng" })); 
        set("gender", "����"); 
        set("nickname", YEL "�����" NOR); 
        set("title", "��������޵���"); 
        set("age", 48); 
        set("long", @LONG 
�����Ǻųƴ�������޵��ֵġ���������� 
�ֻ������ɫ͸�ƣ��ƺ�������һ�㵭���� 
��ֽ������ĸߴ���࣬��֫�޳���ȴ��ȫȻ 
����ƪ�������˳��档 
LONG ); 
        set("attitude", "friendly"); 
        set("shen_type", 1); 
        set("str", 32); 
        set("int", 31); 
        set("con", 33); 
        set("dex", 31); 
        
        set("qi", 5500); 
        set("max_qi", 5500); 
        set("jing", 4000); 
        set("max_jing", 4000); 
        set("neili", 6800); 
        set("max_neili", 6800); 
        set("jiali", 200); 
        set("level", 50);
        set("combat_exp", 4500000); 
        set("score", 20000); 
        
        set_skill("force", 460); 
        set_skill("lengyue-shengong", 460); 
        set_skill("dodge", 440); 
        set_skill("taxue-wuhen", 440); 
        set_skill("sword", 460); 
        set_skill("miaojia-jian", 460); 
        set_skill("blade", 440); 
        set_skill("hujia-daofa", 440); 
        set_skill("strike", 460); 
        set_skill("tianchang-zhang", 460); 
        set_skill("parry", 460); 
        set_skill("literate", 440); 
        set_skill("martial-cognize", 260); 
        
        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "taxue-wuhen"); 
        map_skill("sword", "miaojia-jian"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-zhang"); 
        
        prepare_skill("strike", "tianchang-zhang"); 
           
        set("no_teach", ([ 
                "hujia-daofa"     : "���ҵ��������ҵ���Ӻ����ִ�ϰ�ã������⴫��", 
        ])); 
         
        create_family("��ԭ���", 6, "����"); 
        
        set("inquiry", ([ 
                "�Ʊ�ժ��" : (: ask_skill1 :), 
                "��������" : (: ask_skill2 :), 
                "����ǧ��" : (: ask_skill3 :), 
                "���Ǹ���" : (: ask_skill4 :), 
                "��������" : (: ask_skill5 :),
                "���ҵ���" : "���ҵ��������ҵ���Ӻ����ִ�ϰ�ã����澫���ޱȡ�", 
                "��һ��"   : "���������˼��˶���ɱ�������������ź�������", 
        ])); 
        
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.zhai" :), 
                (: perform_action, "sword.zhu" :), 
                (: perform_action, "sword.jian" :), 
                (: perform_action, "sword.gan" :), 
                (: perform_action, "strike.zhan" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
        
        set("master_ob",5);
	setup(); 
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear(); 
} 
        
void attempt_apprentice(object ob) 
{
        command("say ��ԭ����ݲ����ţ�"); 
        return;
        
        if (! permit_recruit(ob)) 
                return; 
        
        if (ob->name(1) == "���˷�") 
        { 
                command("hmm"); 
                command("say ����ôҲȡ������֣�"); 
                return; 
        } 
        
        if (ob->name(1) == "������") 
        { 
                command("hmm"); 
                command("say ��Ͳ��ܻ���������֣�"); 
                return; 
        } 
        
        if (ob->name(1) == "����" || ob->name(1) == "������") 
        { 
                command("hmm"); 
                command("say �㰲��Ҫ���������ǲ��ǣ�"); 
                return; 
        } 
        
        command("sigh"); 
        command("recruit " + ob->query("id")); 
        command("say �ұ��Ѵ��㲻��ͽ�ܣ��������������硢�����ҵķ�������ƽϢ��"); 
        command("say �������洫��ʮ������ҽ������Ҵ�ʧ����δ��̫����Т��"); 
        return; 
} 
 
int recognize_apprentice(object me, string skill) 
{
        if (me->query("family/family_name") != "�������") 
        {
                command("say ����˭����������"); 
                return -1; 
        }
        
        if ((int)me->query("shen") < 0) 
        {
                command("sigh"); 
                command("say ����������а·���ҿɲ��ܽ�����ҽ���"); 
                return -1; 
        }
        
        if (count_lt(me->query("combat_exp"), 400000))
        {
                command("say ���ʱ����̫ǳ�������ȴ�û�����˵�ɡ�");
                return -1;
        }

        if (skill != "miaojia-jian" && skill != "sword")
        {
                command("say ��ֻ���������������ҽ�������ľͲ�Ҫ�������ˣ�"); 
                return -1;
        }

        if (me->query_skill(skill, 1) >= 400) 
        {
               command("say ���ˣ��Ҿͽ��㵽����ɣ��书����" 
                       "Ҫ���Լ����о����ǣ�"); 
               return -1; 
        }
        
        command("say ���ڵ��������˼��˶���ɱ���˺�һ���������ź����������ϣ��Ҿʹ�����ҽ�����"); 
        return 1;
}
        
mixed ask_skill1() 
{ 
        object me; 
   
        me = this_player(); 
        
        if (me->query("can_perform/miaojia-jian/zhai")) 
                return "�Լ���ȥ��������˵ʲô��"; 
        
        if (me->query_skill("miaojia-jian", 1) < 1) 
                return "������ҽ�����δѧ����̸���п��ԣ�"; 
        
        if (me->query("family/gongji") < 400) 
                return "���ں���������Ϊ���������Ȳ�æ���㡣"; 
        
        if (me->query("shen") < 13000) 
                return "�������������ò������������Ȳ�æ���㡣"; 
        
        if (me->query_skill("force") < 120) 
                return "����ڹ�����㣬ѧ�������С�"; 
        
        if (me->query("max_neili") < 800) 
                return "���������Ϊ���㣬ѧ�������С�"; 
        
        if (me->query_skill("miaojia-jian", 1) < 100) 
                return "�����ҽ������δ�������ö���ϰ��ϰ��"; 
        
        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ�����ִ�����" 
                       "����һ�����ӣ�������\n��ʾ���С�$N" HIY "ֻ��" 
                       "$n" HIY "�������ţ����²�����˲ʱ֮��\n������" 
                       "���ֽ��ƣ�����֮�������ǰ��δ�š�\n" NOR, 
                       me, this_object()); 
        
        command("nod"); 
        command("say ���п��Ƹ��ӣ���ʵ��������������ȥ���Լ����ɡ�"); 
        tell_object(me, HIC "��ѧ���ˡ��Ʊ�ժ�¡���\n" NOR); 
        
        if (me->can_improve_skill("sword")) 
                me->improve_skill("sword", 1500000); 
        if (me->can_improve_skill("miaojia-jian")) 
                me->improve_skill("miaojia-jian", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->set("can_perform/miaojia-jian/zhai", 1); 
        me->add("family/gongji", -400); 
        return 1; 
} 
          
mixed ask_skill2() 
{ 
        object me; 
        
        me = this_player(); 
        
        if (me->query("can_perform/miaojia-jian/zhu")) 
                return "�Լ���ȥ��������˵ʲô��"; 
        
        if (me->query_skill("miaojia-jian", 1) < 1) 
                return "������ҽ�����δѧ����̸���п��ԣ�"; 
        
        if (me->query("family/gongji") < 600) 
                return "���ں���������Ϊ���������Ȳ�æ���㡣"; 
        
        if (me->query("shen") < 15000) 
                return "�������������ò������������Ȳ�æ���㡣"; 
        
        if (me->query_skill("force") < 150) 
                return "����ڹ�����㣬ѧ�������С�"; 
        
        if (me->query("max_neili") < 1200) 
                return "���������Ϊ���㣬ѧ�������С�"; 
        
        if (me->query_skill("miaojia-jian", 1) < 120) 
                return "�����ҽ������δ�������ö���ϰ��ϰ��"; 
        
        message_vision(HIY "$n" HIY "��$N" HIY "Ц��Ц���漴������֣�" 
                       "��ʳ��ָ��£������\n���������͡���һ���յ����" 
                       "����ʱ�ƿ�֮�����죬һ��\n������ָ��ŷ�����$N" 
                       HIY "���Ե�ľ����͸��һ��С�ס�\n" NOR, me, 
                       this_object()); 
        
        command("nod"); 
        command("say ���в�������Խ���ý���������ˡ�"); 
        tell_object(me, HIC "��ѧ���ˡ��������项��\n" NOR); 
        
        if (me->can_improve_skill("sword")) 
                me->improve_skill("sword", 1500000); 
        if (me->can_improve_skill("miaojia-jian")) 
                me->improve_skill("miaojia-jian", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->set("can_perform/miaojia-jian/zhu", 1); 
        me->add("family/gongji", -600); 
        return 1; 
} 
        
mixed ask_skill3()
{ 
        object me; 
        
        me = this_player(); 
        
        if (me->query("can_perform/miaojia-jian/qian")) 
                return "�Լ���ȥ��������˵ʲô��"; 
         
        if (me->query_skill("miaojia-jian", 1) < 1) 
                return "������ҽ�����δѧ����̸���п��ԣ�"; 
        
        if (me->query("family/gongji") < 1000) 
                return "�����Һ���������Ϊ���������Ȳ�æ���㡣"; 
        
        if (me->query("shen") < 18000) 
                return "�������������ò������������Ȳ�æ���㡣"; 
        
        if (me->query_skill("force") < 220) 
                return "����ڹ�����㣬ѧ�������С�"; 
        
        if (me->query("max_neili") < 1800) 
                return "���������Ϊ���㣬ѧ�������С�"; 
        
        if (me->query_skill("miaojia-jian", 1) < 160) 
                return "�����ҽ������δ�������ö���ϰ��ϰ��"; 
        
        message_vision(HIY "$n" HIY "��̾һ��������Ҳ���𻰣���$N" HIY 
                       "���ӹ��佣������\nʮ������ҽ�����ʩ������ʱ��" 
                       "����ˣ���â�ݺᣬ����\n��ֹ��ֻ��$n" HIY "��" 
                       "ʩ����ʮ���ƽ�������һ�ƣ�������\n����һ���ǳ�" 
                       "�������κ�������$N" HIY "ֻ����Ŀ�ɿڴ���\n" 
                       NOR, me, this_object()); 

        command("nod"); 
        command("say ���Լ���ȥ��ϰ�ɡ�"); 
        tell_object(me, HIC "��ѧ���ˡ�����ǧ���\n" NOR); 
        
        if (me->can_improve_skill("sword")) 
                me->improve_skill("sword", 1500000); 
        if (me->can_improve_skill("miaojia-jian")) 
                me->improve_skill("miaojia-jian", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->set("can_perform/miaojia-jian/qian", 1); 
        me->add("family/gongji", -1000); 
        return 1; 
} 
        
mixed ask_skill4()
{ 
        object me; 
        
        me = this_player(); 
            
        if (me->query("can_perform/miaojia-jian/gan")) 
                return "�Լ���ȥ��������˵ʲô��"; 

        if (me->query_skill("miaojia-jian", 1) < 1) 
                return "������ҽ�����δѧ����̸���п��ԣ�"; 
        
        if (me->query("family/gongji") < 2200) 
                return "���ں���������Ϊ���������Ȳ�æ���㡣"; 
        
        if (me->query("shen") < 35000) 
                return "�������������ò������������Ȳ�æ���㡣"; 

        if (me->query_skill("force", 1) < 100)
                return "����ڹ�����㣬ѧ�������С�"; 

        if (me->query("max_neili") < 3000) 
                return "���������Ϊ���㣬ѧ�������С�"; 
         
        if (me->query_skill("miaojia-jian", 1) < 200) 
                return "�����ҽ������δ�������ö���ϰ��ϰ��"; 
        
        message_vision(HIY "$n" HIY "������$N" HIY "���죬�����ص���" 
                       "��ͷ�����°γ�������\n�����������ߣ��׹����" 
                       "�����ش���ɽ��Ρ�ţ����鴦��\n����޼�����" 
                       "֮������������Ѳ⡣�赽������$n" HIY "\nһ��" 
                       "��ȣ������佣��Ȼ�������������һ�����ǣ�ֱ" 
                       "û\n��������$N" HIY "�����ǽ���С�\n" NOR, 
                       me, this_object()); 
         
        command("nod"); 
        command("say ����������ҽ����ľ��裬��Ҫ�ڼ���ϰ��"); 
        tell_object(me, HIC "��ѧ���ˡ����Ǹ��¡���\n" NOR); 
        
        if (me->can_improve_skill("force")) 
                me->improve_skill("force", 1500000); 

        if (me->can_improve_skill("parry")) 
                me->improve_skill("parry", 1500000); 
                
        if (me->can_improve_skill("sword")) 
                me->improve_skill("sword", 1500000); 
                
        if (me->can_improve_skill("miaojia-jian")) 
                me->improve_skill("miaojia-jian", 1500000); 
                
        me->improve_skill("martial-cognize", 1500000); 
        me->set("can_perform/miaojia-jian/gan", 1); 
        me->add("family/gongji", -2200); 
        return 1; 
} 

mixed ask_skill5()
{ 
        object me; 
        
        me = this_player(); 
        
        if (me->query("can_perform/miaojia-jian/lian")) 
                return "�Լ���ȥ��������˵ʲô��"; 
         
        if (me->query_skill("miaojia-jian", 1) < 1) 
                return "������ҽ�����δѧ����̸���п��ԣ�"; 
        
        if (me->query("family/gongji") < 1000) 
                return "�����Һ���������Ϊ���������Ȳ�æ���㡣"; 
        
        if (me->query("shen") < 18000) 
                return "�������������ò������������Ȳ�æ���㡣"; 
        
        if (me->query_skill("force") < 220) 
                return "����ڹ�����㣬ѧ�������С�"; 
        
        if (me->query("max_neili") < 1800) 
                return "���������Ϊ���㣬ѧ�������С�"; 
        
        if (me->query_skill("miaojia-jian", 1) < 160) 
                return "�����ҽ������δ�������ö���ϰ��ϰ��"; 
        
        message_sort(HIY "$n����һЦ����$N" HIY "�޵�����" 
                     "������������������ҽ��������裬"
                     "�ұ㴫��������������кη���˵���ֻ"
                     "��$n�ӻ�������һ����Ϊ�žɵ�С���ӣ�"
                     "ָ������һ�ζ�$N" HIY "��ϸ���⡣$N" 
                     HIY "�����˼���ã���������" NOR, 
                     me, this_object()); 

        command("nod"); 
        command("say ���Լ���ȥ��ϰ�ɡ�"); 
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR); 
        
        if (me->can_improve_skill("sword")) 
                me->improve_skill("sword", 1500000); 
        if (me->can_improve_skill("miaojia-jian")) 
                me->improve_skill("miaojia-jian", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->set("can_perform/miaojia-jian/lian", 1); 
        me->add("family/gongji", -1000); 
        return 1; 
} 
