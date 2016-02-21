// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

string ask_me();
mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("����һ", ({"wang chuyi", "wang"}));
        set("gender", "����");
        set("age", 35);
        set("class", "taoist");
        set("nickname",RED"������"NOR);
        set("long",
                "������ȫ������֮������һ�����ˡ�������޳����������࣬\n"
                "��縺���Ʈ����ǰ����̬������\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 32);
        set("dex", 30);

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

        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2100);
        set("max_jing", 2100);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);

        set("combat_exp", 1200000);

        set_skill("force", 170);
        set_skill("quanzhen-xinfa", 170);
        set_skill("sword", 160);
        set_skill("quanzhen-jian",160);
        set_skill("dodge", 150);
        set_skill("jinyan-gong", 150);
        set_skill("parry", 170);
        set_skill("strike", 170);
        set_skill("chongyang-shenzhang", 170);
        set_skill("haotian-zhang", 170);
        set_skill("literate",100);
        set_skill("finger",150);
        set_skill("zhongnan-zhi", 170);
        set_skill("taoism",100);
	set_skill("medical", 180);
	set_skill("liandan-shu", 180);
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
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "�ϵ�"   : (: ask_me :),
                "�λ�ү" : (: ask_me :),
                "���־�" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
        ]) );

        set("master_ob",3);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("quanzhen-xinfa",1) < 90 )
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
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

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string ask_me()
{
        object me=this_player();

        if (me->query_temp("tmark/ָ") == 1)
        {
                me->add_temp("tmark/ָ",1);
                return("ȥ��ʦ��ȥ���λ�ү�����˵�λ�ү������������һ��ָ�����ڸ���ʦ���ˡ�\n");
        } else
        {
                me->set_temp("tmark/ָ",0);
                return("�λ�ү������һ���������£����ڳ������˺����ˣ�����");
        }
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/chan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "����ȫ�潣����ûѧ����̸���п��ԣ�";

        if (me->query("family/gongji") < 200)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 10000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("quanzhen-jian", 1) < 80)
                return "���ȫ�潣��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 100)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "΢Ц�ŵ��˵�ͷ��˵�����������ˡ���˵"
                     "�ռ�������䳤����������ʾ������ֻ��$n" HIY "���н�"
                     "��Բ�������಻������������ϸ˿��ӳ�������͸��������"
                     "���������ֱ����$N" HIY "Ŀ�ɿڴ���\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say �����޷����Խ����Ի���֣����޸���֮�١�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/chan", 1);
        me->add("family/gongji", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/ding"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "����ȫ�潣����ûѧ����̸���п��ԣ�";

        if (me->query("family/gongji") < 400)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 12000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("quanzhen-jian", 1) < 100)
                return "���ȫ�潣��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���ȵ���������ϸ�ˡ���������"
                     "�䣬ֻ��$n" HIY "�������Ҽ�����������һ����������"
                     "��������������������ʯ��һ��бб�̳�����ʱֻ���á�"
                     "�ꡱ��һ����$N" HIY "���µķ�ש��ȻӦ�����飬�ѳ���"
                     "���顣\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ���еľ�Ҫ�޷��������ݽ�����������������");
        tell_object(me, HIC "��ѧ���ˡ������롹��\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/ding", 1);
        me->add("family/gongji", -400);

        return 1;
}

