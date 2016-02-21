// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_QUESTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
string ask_me();
string ask_book();
int ask_job();
int ask_fail();

void create()
{
        set_name("���Ǻ�", ({"su xinghe", "su", "xinghe"}));
        set("gender", "����" );
        set("nickname", HIW "�ϱ�����" NOR);
        set("long", @LONG
���˾��Ǻųƴϱ����˵����Ǻӣ���˵������
�Ʊ磬����������Ϊ�����һλ���ߣ�������
�书Ҳ��������֪��
LONG );
        set("class", "scholar");
        set("age", 60);
        set("str", 29);
        set("con", 30);
        set("int", 45);
        set("dex", 37);
        set("level", 20);
        set("combat_exp", 2000000);
        set("attitude", "peaceful");

        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 120);

        set_skill("force", 260);
        set_skill("xiaowuxiang", 240);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
        set_skill("strike", 240);
        // set_skill("panyang-zhang", 240);
        set_skill("liuyang-zhang", 240);
        set_skill("hand", 240);
        set_skill("qingyun-shou", 240);
        set_skill("zhemei-shou", 240);
        set_skill("parry", 240);
        set_skill("blade", 240);
        set_skill("ruyi-dao", 240);
        set_skill("literate", 280);
        set_skill("medical", 260);
        set_skill("xiaoyao-qixue", 260);
        set_skill("mathematics", 240);
        set_skill("qimen-wuxing", 240);
        set_skill("drawing",   240);
        set_skill("chuixiao-jifa", 240);
        set_skill("tanqin-jifa", 240);
        set_skill("chess", 280);
        set_skill("calligraphy", 240);
        set_skill("martial-cognize", 240);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("hand", "zhemei-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("parry", "zhemei-jian");
        map_skill("blade", "ruyi-dao");
        map_skill("medical", "xiaoyao-qixue");

        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");

        set("no_teach", ([
                "zhemei-shou"   : "��ң��÷���˱����񹦣�ֻ���������˴��ڡ�",
                // "liuyang-zhang" : "����ɽ����������ֻ������ң�����Ŵ������Ҳ�����ڡ�",
        ]));

        create_family("��ң��", 2, "���ŵ���");

        set("inquiry", ([
                "����׽Ӱ" : (: ask_skill1 :),
                // "��������" : (: ask_skill2 :),
                "��������" : (: ask_skill3 :),
                "���ܵص�" : (: ask_me :),
                "�ؼ�"     : (: ask_book :),
                "����" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhe" :),
                (: perform_action, "hand.hai" :),
                (: perform_action, "strike.huan" :),
                (: perform_action, "strike.zhong" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

        set("coagents", ({
                ([ "startroom" : "/d/xiaoyao/shishi",
                   "id"        : "wuya zi" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�������������˴��˱��Ž��أ�����"
                                "�������ڡ�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "��������ʲô�ˣ����������ҷ���"
                                "��" NOR,
        ]));

        set("master_ob", 4);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 30)
        {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ����ѧ"
                        "���϶��µ㹦�򣬱��˿���ң���ˣ�");
                return;
        }

        if ((int)ob->query("combat_exp") < 200000)
        {
                command("say �����ھ�����ǳ��������������书���ȶ���Ҫ����");
                return;
        }

        if (ob->query_skill("force", 1) < 100)
        {
                command("sigh");
                command("say ������ң�ɵ��书��Ҫ���ڹ�Ϊ���������Ȱ�"
                        "�����ڹ�ѧ��ʵ�ɡ�");
                return;
        }

        if (ob->query_skill("xiaowuxiang", 1) < 100)
        {
                command("sigh");
                command("say �������ŵ������ķ���û��ѧ�ã�����ѧ����"
                        "���ϳ���ѧ��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
        command("recruit " + ob->query("id"));
}

int permit_pass(object me, string dir)
{
        if (! ::permit_pass(me, dir))
                return 0;

       if (me->query("family/master_id") == "wuya zi")
                return 1;

        if (me->query("combat_exp") < 300000)
        {
                command("say ���������ֲ�Ҫȥ����ú�ѧ������ң���书��");
                return 0;
        }

        if (me->query_skill("xiaowuxiang", 1) < 120)
        {
                command("say ��������ң�ķ���ѧ���ã�����ʲô��");
                return 0;
        }

        command("sigh");
        command("say ȥ�ɣ�ȥ�ɣ���Ե���¾��ɡ�");
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qingyun-shou/zhuo"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qingyun-shou", 1) < 1)
                return "���������ֶ�δ��ѧ�����������У�";

        if (me->query("family/gongji") < 50)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("qingyun-shou", 1) < 50)
                return "��������ֻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ֽ�$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "��"
                       "���\n�ĵ�һЦ��������������\n" NOR, me,
                       this_object());

        command("nod");
        command("say �����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ�����׽Ӱ����\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("qingyun-shou"))
                me->improve_skill("qingyun-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qingyun-shou/zhuo", 1);
        me->add("family/gongji", -50);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/panyang-zhang/pan"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("panyang-zhang", 1) < 1)
                return "���������ƶ�δ��ѧ�����������У�";

        if (me->query("family/gongji") < 100)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("panyang-zhang", 1) < 60)
                return "��������ƻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ��˵�������Ҹ�����ʾ"
                      "һ�飬������ϸ�ˣ����漴\nһ����Х��˫�Ʒ׷ɹ�"
                      "������Ӱ���ص�����ʵ�ѱ棬ȫȫ����$N" HIY "ȫ��"
                      "��\n" NOR, me, this_object());

        command("nod");
        command("say ������˾��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������¡���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("panyang-zhang"))
                me->improve_skill("panyang-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/panyang-zhang/pan", 1);
        me->add("family/gongji", -100);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/ruyi-dao/ruyi"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("ruyi-dao", 1) < 1)
                return "�������⵶����δ��ѧ�����������У�";

        if (me->query("family/gongji") < 200)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("ruyi-dao", 1) < 100)
                return "������⵶�����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���ͷ��΢Ц��ʾ���������ֽ�$N"
                       HIY "�е���ǰ��������$N" HIY "������\n���˰���"
                       "����ʱ���γ��������輸�£��ƺ���һ����Ϊ�����"
                       "������\n" NOR, me, this_object());

        command("smile");
        command("say ���кܼ򵥣�ֻ���Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("ruyi-dao"))
                me->improve_skill("ruyi-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/ruyi-dao/ruyi", 1);
        me->add("family/gongji", -200);
        return 1;
}

string ask_book()
{
        object me,ob;
        mapping fam; 
        
        ob = this_player();
        if (! (fam = ob->query("family")) 
                || fam["family_name"] != "��ң��")
        {
                return "��Ҫ�ؼ��͵ü�����ң�ɡ�";
        }
        
        command("sigh");
        return "���ɵ��书�ؼ�����һ�������ܵĵط�����Ҳûȥ����";
}
string ask_me()
{
        object me,ob;
        mapping fam; 
        
        ob = this_player();
        if (! (fam = ob->query("family")) 
                || fam["family_name"] != "��ң��")
        {
                return "��Ҫ֪���ܵ��͵ü�����ң�ɡ�";
        }
        
        command("sigh");
        return "���ɵ��ܵ��ڻ�ɽ֮�ϣ����Ǽ��ա�������Ȥ����ȥ������";
}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/d/xiaoyao/npc/lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;


        if( me->query("family/family_name") != "��ң��")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�ұ��ɵ����������Ǻ��ѵģ��㻹�����߾���������");
                return 1;
}
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ�ұ��ɵ��������");
                return 1;
        }

        if (me->query("kill_xiaoyao") == 1) {

                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ��ң�ɳ���������̫���ˡ�");
                command("say " + me->query("id") + " �߱�ָ�����ڡ�" + quest["short"]             + "�����֣���ȥ�ɣ�\n" NOR);
                me->set("kill_xiaoyao", 1);
                me->set("task_time", time() + 300);
                ob = new("/d/xiaoyao/npc/qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new("/d/xiaoyao/npc/qiangdao2",1);
                }
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
/*
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
*/
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}


int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_xiaoyao") == 1) {
                command("sigh");
                command("say ��������Ҳ���ұ��ɵ��߱�ָ��,����50��POT.");
                me->add("potential",-50);
               me->delete("kill_xiaoyao");
                me->apply_condition("menpai_busy",10);
//                call_out("delete", 1);
                return 1;
                }
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
   if(obj->query("id") == "zhihuan" && me->query("kill_xiaoyao") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say �ɵúã�\n");
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }

   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
   if(me->query("kill_xiaoyao") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say �������������û����ɰ���");
       return 1;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot, gj;
   kar = random(me->query("kar")) * 15;
   exp = 100 + kar;
   pot = random(exp)-80;
   gj = random(8)+4;

   if(obj) destruct(obj);

   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ����һ��߱�ָ������������\n"
                + chinese_number(exp / 3) + "��ʵս���飬\n"
               + chinese_number(pot / 2) + "��Ǳ�ܣ�\n"
                + chinese_number(gj) + "�㹦����Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp / 3);
                me->add("family/gongji",gj);
                if (me->query("potential") > me->query_potential_limit())
                me->add("potential", pot / 2);
                else
                me->add("potential", 1);
                me->delete("kill_xiaoyao");
   return;      
}



/*
void unconcious()
{
        die();
}
*/
