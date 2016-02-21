// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tan.c ̷����

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
string ask_me();

void create()
{
        set_name("̷����", ({"tan chuduan", "tan"}));
        set("gender", "����");
        set("age", 40);
        set("class", "taoist");
        set("nickname",HIY"������"NOR);
        set("long",
                "������ȫ���ͽ̷����̷���ˣ�����Ŀ��࣬Ũü���ۣ�ɤ��\n"
                "����������������Ϊʦǰ������������\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 34);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("title","ȫ������֮��");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 100);
        set("level", 20);
        set("combat_exp", 1200000);

        set_skill("force", 150);
        set_skill("quanzhen-xinfa", 160);
        set_skill("sword", 150);
        set_skill("quanzhen-jian",160);
        set_skill("dodge", 140);
        set_skill("jinyan-gong", 140);
        set_skill("parry", 150);
        set_skill("strike", 150);
        set_skill("chongyang-shenzhang", 150);
        set_skill("haotian-zhang", 150);
        set_skill("literate",80);
        set_skill("finger",140);
        set_skill("zhongnan-zhi", 140);
        set_skill("taoism",100);
	set_skill("cuff",150);
	set_skill("chunyang-quan",150);
        set_skill("array",150);
	set_skill("beidou-zhenfa", 150);
	
        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���"   :  "��ȫ��������µ����������ڡ�\n",
                "�����۶�" : (: ask_skill1 :),
                "�ؼ�" : (: ask_me :),                
        ]) );
        set("book_count", 1);
        set("master_ob",3);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("quanzhen-xinfa",1) < 80 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 8000)
        {
                command("say �ҿ��㻹�Ƕ���һЩ����֮�°ɡ�\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/haotian-zhang/ju"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("haotian-zhang", 1) < 1)
                return "��������ƶ�ûѧ����̸���п��ԣ�";

        if (me->query("family/gongji") < 250)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("haotian-zhang", 1) < 120)
                return "�������Ʋ�����죬���ߵ������ɡ�";

        if (me->query_skill("force") < 180)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "üͷһ�壬���´�����$N" HIY "һ��"
                     "�����¸����𻰣���������һ������Ȼ���һ������ʱ"
                     "˫�Ʒ׷ɣ��ƾ�������˷��ƹ���������ƻֺ�֮����"
                     "\n\n" NOR, me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ������۶�����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("haotian-zhang"))
                me->improve_skill("haotian-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/haotian-zhang/ju", 1);
        me->add("family/gongji", -250);

        return 1;
}

string ask_me()
{
        mapping fam;
        object ob, *obs,ob2 ;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
           obs = filter_array(children("/d/quanzhen/obj/qz_force"), (: clonep :));
                  if (sizeof(obs) > 20)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        ob=new("/d/quanzhen/obj/qz_force");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"Ū����һ�������ڹ��ķ���");
        return "�ðɣ��Ȿ�������ڹ��ķ������û�ȥ�ú����С�";
}

