// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhou.c �ܲ�ͨ

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

#define ZHENJING    "/clone/book/jiuyin1"

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        object ob;
        set_name("�ܲ�ͨ", ({"zhou botong", "zhou"}));
        set("gender", "����");
        set("age", 62);
        set("class", "taoist");
        set("nickname",HIY "����ͯ" NOR);
        set("long", "������ȥ��ü�԰ף�һ���õ�ģ����Ȼ������ȴ͸¶��һ�ɽ��\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 31);
        set("int", 36);
        set("con", 32);
        set("dex", 29);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        }));

        set("qi", 6200);
        set("max_qi", 6200);
        set("jing", 3100);
        set("max_jing", 3100);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 50);
        set("level", 60);
        set("combat_exp", 2800000);

        set_skill("force", 280);
        set_skill("quanzhen-xinfa", 280);
        set_skill("xiantian-gong", 280);
        set_skill("sword", 250);
        set_skill("quanzhen-jian",250);
        set_skill("dodge", 260);
        set_skill("jinyan-gong", 260);
        set_skill("parry", 270);
        set_skill("unarmed", 270);
        set_skill("kongming-quan", 270);
        set_skill("strike", 250);
        set_skill("chongyang-shenzhang", 250);
        set_skill("haotian-zhang", 250);
        set_skill("literate", 120);
        set_skill("finger", 250);
        set_skill("taoism", 220);
        set_skill("finger", 260);
        set_skill("zhongnan-zhi", 270);
        set_skill("zuoyou-hubo", 400);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "kongming-quan");
        map_skill("finger","zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        map_skill("unarmed", "kongming-quan");
        // prepare_skill("cuff", "kongming-quan");

        create_family("ȫ���", 1, "�ƽ�");
        set("title", "ȫ��̵�һ������");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "�����澭" : "�ٺٺٺ�...",
                "�λ�ү" : "��... �λ�ү���˼��ǻ�ү���Ҳ���ʶ��",
                "����"   : "�㣬��˵ɶ��",
                "����"   : "��...��...�ţ�",
                "��������" : (: ask_skill1 :),
                "�տ���Ҳ" : (: ask_skill2 :),
        ]));

        set("master_ob",4);
	setup();

        if (clonep())
        {
                ob = find_object(ZHENJING);
                if (! ob) ob = load_object(ZHENJING);

                if (! environment(ob) && random(30) == 1)
                        ob->move(this_object());
        }
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (count_lt(ob->query("combat_exp"),400000))
        {
                command("say �㾭����ô�����ȥ�����Ǽ���ʦֶ����ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 50000)
        {
                command("say ������Ʒ�в��ã�����һ��϶�������ʲô���¡�");
                return;
        }

        command("smile");
        command("say �������Ҳûɶ�¸ɣ�������������ɡ�");
        command("recruit " + ob->query("id"));
}

/*
int recognize_apprentice(object ob, string skill)
{
        if (! ob->query("can_learn/zhou"))
        {
                message_vision("$Nգգ�۾�������$n������Ц����ͣ��\n",
                               this_object(), ob);
                return -1;
        }

        if (skill != "kongming-quan" &&
            skill != "zuoyou-hubo")
        {
                command("say ��...�����û��ʲô�ý���ģ�");
                return -1;
        }

        return 1;
}
*/

int accept_fight(object ob)
{
        if (count_lt(ob->query("combat_exp"), 500000))
        {
                message_vision("$N����һЦ����$n�������㻹��"
                               "�ѹ�����������˵�ɣ���\n",
                               this_object(), ob);
                return -1;
        }

        if (is_fighting())
        {
                message_vision("$N��$n�е��������ȱ𼱣��Ҵ�����"
                               "�ܾ��������ģ���\n",
                               this_object(), ob);
                return -1;
        }

        if (query("qi") < 4000 ||
            query("jing") < 2000 ||
            query("neili") < 4000)
        {
                message_vision("$Nҡҡͷ��$n������������"
                               "̫���ˣ��Ȼ����˵�ɣ���\n",
                               this_object(), ob);
                return -1;
        }

        if (ob->query("can_learn/zhou"))
        {
                message_vision("$N��$n�������ã������Ǿ����棡��\n",
                               this_object(), ob);
                return 1;
        }

        message_vision("$N��ϲ������...�ã��������������������Ȼ��Ȼ���\n",
                       this_object(), ob);

        competition_with(ob);
        return -1;
}

void win()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision("$N���˿�$n���ٺ�Ц���������ˮƽ����"
                       "����������Ҫ�ú��������ú���������\n",
                       this_object(), ob);
        ::win();
}

void lost()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision("$N��ѽһ����Ĩ��Ĩͷ�ϵĺ���ϲ��������λ" +
                       RANK_D->query_respect(ob) + "������书��������\n"
                       "�����ɣ��Ұ���Ϊʦ���ˣ�����ҵ㹦����������һ��"
                       "����ȭ�������һ���\n��С������������ȤҲ����ѧѧ����ô������\n",
                       this_object(), ob);
        ob->set("can_learn/zhou", 1);
        ::lost();
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/ruo"))
                return "�����������������������档";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����˭������ô����ʶ�㣿";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "�ٺ٣������ҵĿ���ȭ��ûѧ������ôѧ���У�";

        if (me->query("family/gongji") < 200)
                return "��Ͷ����ȫ��̣�ȴ��Ŭ�����£���ΪʲôҪ���㣿";

        if (me->query("shen") < 50000)
                return "�������ĵػ������ã���ʱ�һ����ܽ��㡣";

        if (me->query_skill("kongming-quan", 1) < 100)
                return "��Ŀ���ȭ�����ò����ã��´���˵�ɡ�";

        if (me->query("max_neili") < 1000)
                return "�����������������治֪��������ô�����ġ�";

        message_sort(HIY "\n$n" HIY "ץ��ץͷ��������Ը���ֹ������䣬��"
                     "��˵������С�ӣ��Ұѿھ�˵��������Ȼ������Լ���ȥ"
                     "���������������ˡ���˵���һ�ѽ�$N" HIY "鱵����"
                     "����$N" HIY "�������󹾹�˵�˰��졣\n\n" NOR, me,
                     this_object()); 

        command("bite");
        command("say ���ˣ����ˣ�����߰ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/ruo", 1);
        me->add("family/gongji", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/kong"))
                return "����������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����˭������ô����ʶ�㣿";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "�ٺ٣������ҵĿ���ȭ��ûѧ������ôѧ���У�";

        if (me->query("family/gongji") < 500)
                return "��Ͷ����ȫ��̣�ȴ��Ŭ�����£���ΪʲôҪ���㣿";

        if (me->query("shen") < 60000)
                return "�������ĵػ������ã���ʱ�һ����ܽ��㡣";

        if (me->query_skill("kongming-quan", 1) < 150)
                return "��Ŀ���ȭ�����ò����ã��´���˵�ɡ�";

        if (me->query("max_neili") < 2000)
                return "�����������������治֪��������ô�����ġ�";

        message_sort(HIY "\n$n" HIY "˫Ŀһ�ɣ���$N" HIY "˵����������ô"
                     "��ô����û�������������𣿡�����$n" HIY "ҡ��ҡͷ��"
                     "�ֵ��������Ǻ�ڵ��������㣬�����ˣ���˵��������һ"
                     "������ƮƮ�ӳ�һȭ��ȭ����ʵ�Ѳ⣬��Χ��ʱ�����ó�"
                     "�����\n\n" NOR, me, this_object()); 

        command("angry");
        command("say ���ߣ����ߣ��Ժ�����������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��տ���Ҳ����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/kong", 1);
        me->add("family/gongji", -500);

        return 1;
}
/*
void die()
{
        recover();
        return;
}

*/
