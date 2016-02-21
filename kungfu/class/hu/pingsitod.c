#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

int ask_job();
int ask_fail();
mixed ask_me();

void create()
{
        set_name("ƽ��", ({ "ping si", "ping", "si" }));
        set("gender", "����");
        set("age", 65);
        set("title", "������Ӷ");
        set("long", "���Ǻ������Ĺ��������ۡ�\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 4000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 150000);

        set_skill("force", 40);
        set_skill("blade", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("unarmed", 40);

        create_family("�������", 0, "��Ӷ");

        set("inquiry",([
        	"�ֻ�"   : "�ֻ����ߡ����������",
                "��һ��" : "�ǡ������������ˣ�����",
                "���˷�" : "������ɲ��ǻ��ˡ�",
                "�԰�ɽ" : "�����Ҽ����˵Ľ�������û��˵�ġ�",
                "����"   : (: ask_me :),
                "����"   : (: ask_me :),
                "��ȥ"   : (: ask_me :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
        ]));
        set("coagents", ({
                ([ "startroom" : "/d/guanwai/xiaowu",
                   "id"        : "hu fei" ]),
        }));

        setup();
        set("startroom", "/d/guanwai/xiaoyuan");
        carry_object("/clone/cloth/cloth")->wear();
}

mixed ask_me()
{
        object ob, me;
        me = this_player();

        if ((string)me->query("family/family_name") != "�������")
                return "���Լ�û����ô��";

        if (find_object(query("startroom")) != environment())
                return "�����ﻹ���£�����Լ��߻�ȥ�ɡ�";

        command("nod");
        command("say Ҫ��ȥ����ô�����ҽм�����������һ�̰ɡ�");

        message_sort(HIC "\nƽ�ĳ�Զ��һ���֣���ʱ�����ο͸�����ʻ��"
                     "������ƽ��Ц�����Ҽ�С����Ҫ���ذ���£����˾���"
                     "���������͡����ο�������æ��Ц�Ŵ�Ӧ��$N" HIC "��"
                     "״��æ������У�ֻ��һ�����ı��죬��������ȥ"
                     "��\n\n" NOR, me);

        ob = load_object("/d/beijing/majiu");
        ob = find_object("/d/beijing/majiu");
        me->move("/d/beijing/majiu");

        message("vision", HIC "\nԶ��һ������ʻ����������һ��" +
                          me->query("name") + HIC "���������˳�"
                          "����\n\n" NOR, environment(me), ({me}));

        tell_object(me, CYN "\n�ο�Ц������λ" + RANK_D->query_respect(me) +
                        CYN "�Ѿ����ˣ����³��ɡ�\n�ο�˵������Ҫ"
                        "�������Щ���飬�������" HIC "���" NOR +
                        CYN "�Ļ����һ������������㡣\n\n" NOR);
        return 1;

}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/d/guanwai/npc/lagjob")->query_quest();

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

        if( me->query("family/family_name") != "�������")

           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (count_lt(me->query("combat_exp"), 100000)) {
                command("say " + RANK_D->query_respect(me) + "�ȷ�����ʿ����û��ô���ף��㻹�����߾���������");
                return 1;
}
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (count_lt(me->query("potential"), 200) || count_gt(me->query("combat_exp"), 300)) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }

        if (me->query("kill_yunlong") == 1) {

                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "���帴������Ҫ����־ʿ����ȥ��!");
                command("say " + me->query("id") + " ��һ��������ʿ��ץ�ˣ�Ҫ�������ǣ�Ҫ�ڡ�" + quest["short"]             + "��·������ȥ���˰ɣ�\n" NOR);
                me->set("kill_yunlong", 1);
                me->set("task_time", time() + 300);
                ob = new("/d/guanwai/npc/shangdui",1);
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));

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
        
        if (me->query("kill_yunlong") == 1) {
                command("pk1");
                command("say �ҿ������ˣ���ֻ���ɱ���ȥ�ȷ�����ʿ,����50��POT.");
                me->add("potential",-50);
                me->apply_condition("menpai_busy",10);

                call_out("delete", 1);
                return 1;
                }
}

int delete()
{
        this_player()->delete("kill_yunlong");
        return 1;
}

