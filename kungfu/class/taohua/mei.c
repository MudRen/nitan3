// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// mei.c ÷����

#include <ansi.h>;
inherit NPC;
inherit F_NOCLONE; 

#define YINJIAO    "/clone/lonely/yinjiaobian"

mixed ask_skill();

void create()
{
        //object ob;
        set_name("÷����", ({ "mei chaofeng", "mei", "chaofeng" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", WHT "��ʬ" NOR);
        set("gender", "Ů��");
        set("age", 32);
        set("long", "÷�����ǻ�ҩʦΨһ��Ů���ӣ��������ܻ�ҩʦ�۰�����\n"
                    "ϧ����ʦ�ֳ����簵����㺣�����͵�ˡ������澭��˽����\n"
                    "����ɫ�����Ϊ�þӺ����Ե���ڣ�ģ��ȴ��Ϊ��������\n"
                    "���һ��������Ⱦ�ͨ�޷���\n");
        set("attitude", "aggressive");
        set("str", 29);
        set("int", 32);
        set("con", 35);
        set("dex", 31);
        set("max_qi", 4500);
        set("max_jing",3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        set("level", 20);
        set("combat_exp", 1800000);

        set_skill("claw", 200);
        set_skill("strike", 200);
        set_skill("force", 200);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("cuixin-zhang", 200);
        set_skill("jiuyin-zhao", 200);
        set_skill("luoying-shenfa", 200);
        set_skill("whip", 220);
        set_skill("canglang-bian", 220);
        set_skill("martial-cognize", 200);

        map_skill("force", "luoying-xinfa");
        map_skill("whip", "canglang-bian");
        map_skill("parry", "yinlong-bian");
        map_skill("dodge", "luoying-shenfa");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("strike", "cuixin-zhang");

        prepare_skill("claw", "jiuyin-zhao");
        prepare_skill("strike", "cuixin-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.duo" :),
                (: perform_action, "claw.sha" :),
                (: perform_action, "strike.cui" :),
                (: perform_action, "whip.julang" :),
                (: exert_function, "recover" :),
        }));

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
                "ͭʬ" : "�����ϵ��˶���ô���ҵģ����²��£�����������",
                "��а" : "������ʦ���Ĵºš�",
                "����" : "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
                "�ϵ�" : "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
                "��ؤ" : "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
                "����" : "������ʦ���Ķ�Ů�����ǵ������ԡ�",
                "���߹�" : "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
                "÷����" : "��������ô�����ǰ׳հ���",
                "������" : "�����ҵ�ʦ�磬Ҳ���ҵķ������ϧ��������С�������ˡ�",
                "��ҩʦ" : "������ʦ����",
                "�����澭" : "������ʦ�����ؼ�����ɱ��ע�⣡",
                 "������צ" : (: ask_skill :),
        ]));
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
/*
        if (clonep())
        {
                ob = find_object(YINJIAO);
                if (! ob) ob = load_object(YINJIAO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/changbian");
                        ob->move(this_object());
                        ob->wield();
                }
        }
*/
        carry_object("/clone/cloth/bupao")->wear();
        carry_object("/clone/unique/dulong-bian")->wear();
        set("startroom", "/d/huanghe/shidong"); 
        check_clone();         
}

void attempt_apprentice(object ob)
{
        command("������");
}

int accept_fight(object me)
{
        command("say ���ҹ�����");
        return 0;
}

int accept_hit(object me)
{
        command("say ������");
        kill_ob(me);
        return 1;
}

void kill_ob (object ob)
{
        object me = this_object();
        object where = environment(me);
        object guard = present("chen xuanfeng", where);

        set_temp("my_killer", ob);
        ::kill_ob(ob);

        if (guard && ! guard->is_fighting())
        {
                message_vision(HIW "\n$N" HIW "��ŭ������Ȼ�۸������Ǻڷ�˫ɷ"
                               "ͷ�����ˣ����ɣ�\n\n" NOR, guard);
                guard->kill_ob(ob);
        }
}

mixed ask_skill()
{      
        object me = this_player();

        if (me->query("can_perform/jiuyin-baiguzhao/zhua"))
                return "�㲻���Ѿ�������";

        if (! me->query("can_learn/jiuyin-baiguzhao/zhua"))
        {
               tell_object(me, HIG "��ȥ���������澭�²᡹�������ң��ұ㴫�����У�\n" NOR);
               command("heihei");
               return 1;
        }

        if (me->query_skill("jiuyin-baiguzhao", 1) < 240)
        {
               command("shake");
               return "������׹�צ��򲻹����һ����ܴ������У�";
        }

        if (me->query_skill("claw", 1) < 240)
               return "�����צ��������죬�Ҳ��ܴ������У�";        
 
        if (me->query_skill("force", 1) < 260)
               return "���ڹ���Ϊ�������Ҳ��ܴ������У�";

        if (me->query_skill("martial-cognize", 1) < 240)
               return "����ѧ�����������Ҳ��ܴ�����У�";

        if (me->query("max_neili") < 5500)
               return "��������Ϊ���㣬�һ����ܴ�����У�";

        command("heihei");
        command("say С��~~��");
        message_sort(HIM "÷�������ֳ�צ����Хһ������Ȼ��ץ��$N" HIM "�ļ��$N" HIM 
                     "΢΢һЦ�������мܣ�ֻ��÷�������ֺ�Ȼ�ջأ�����ȴ�͵�ץ�����ٶ�֮"
                     "�죬��λ֮׼��ֱϮ$N" HIM "̴�д�Ѩ��$N" HIM "ֻ����һ������Ϯ����"
                     "���������мܣ�÷����ȴͻȻ���У�����ȴͣ������̴��Ѩ�ϣ�ֻ��Ҫ����"
                     "һ������$N" HIM "����ʱ������\n" NOR, me);
        command("haha");

        command("say ��������");
        if (me->can_improve_skill("claw"))
                me->improve_skill("claw", 1500000);
        if (me->can_improve_skill("jiuyin-baiguzhao"))
                me->improve_skill("jiuyin-baiguzhao", 1500000);
        if (me->can_improve_skill("martial-cognize"))
                me->improve_skill("martial-cognize", 1500000);

        me->set("can_perform/jiuyin-baiguzhao/zhua", 1);
        tell_object(me, HIG "��ѧ���ˡ�������צ����\n" NOR);
       
        return 1;
}

int accept_object(object me, object ob) 
{
        if (base_name(ob) != "/clone/book/jiuyin2")
          
        {
               command("say ��������ֶ�����ʲô��");               
               return 0;
        } 

        command("heihei");        
        command("say �ðɣ���Ȼ�������Ҿʹ�����У��������ʱ�����ң�"); 
        tell_object(me, HIG "÷����������㡸������ץ����\n" NOR);
        destruct(ob);
        me->set("can_learn/jiuyin-baiguzhao/zhua", 1);
 
        return 1;        
}

void die()
{
	object obj, me;
	//int i, flag;
	int flag;

	flag = 0;
	
	me = this_object();
	if (objectp(obj = query_last_damage_from()))
		obj->set_temp("kill_chaofeng", 1);
	else 
		return;
        
	if (obj->query_temp("kill_xuanfeng")) 
	{
		obj->set("kill_th_traitor", 1);
		flag = 1;
	}
	
	if (flag) 
	        message_vision(HIR "÷����ҽ�һ�������������ӣ����������ˣ�����\n" NOR, this_object());
	else 
	        message_vision(HIR "÷����ҽ�һ�������������ӣ����ұ��𣡣���\n" NOR, this_object());

        ::die();
}
