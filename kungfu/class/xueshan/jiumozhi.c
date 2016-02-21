// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// /kungfu/class/xueshan/jiumozhi.c �Ħ��

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include <ansi.h>
#include "xueshan.h"

mixed ask_me();
mixed ask_skill();

void create()
{
        set_name("�Ħ��", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "��������" NOR);
        set("long",@LONG
�����Ǵ����µ����ţ��˳ƴ����������Ħ�ǡ����Է��о�����о���
��һ��������ģ�ͷ��ɮñ��
LONG
        );
        set("title","����������");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 32);
        set("int", 40);
        set("con", 31);
        set("dex", 31);

        set("max_qi", 5800);
        set("max_jing", 2900);
        set("neili", 7100);
        set("max_neili", 7100);
        set("jiali", 100);
        set("level", 40);
        set("combat_exp", 2500000);

        set_skill("force", 470);
        set_skill("xiaowuxiang", 470);
        set_skill("mizong-neigong", 470);
        set_skill("dodge", 440);
        set_skill("shenkong-xing", 440);
        set_skill("parry", 470);
        set_skill("sword", 420);
        set_skill("mingwang-jian", 420);
        set_skill("lamaism", 450);
        set_skill("literate", 420);
        set_skill("strike", 470 );
        set_skill("huoyan-dao", 470);
	set_skill("cuff", 460);
	set_skill("yujiamu-quan", 460);
	set_skill("hand", 470);
	set_skill("dashou-yin", 470);
	set_skill("martial-cognize", 300);
        set_skill("longxiang-gong", 420); 

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("strike","huoyan-dao");
	map_skill("cuff", "yujiamu-quan");

        prepare_skill("strike", "huoyan-dao");
	prepare_skill("hand", "dashou-yin");

        create_family("������", 1, "����");
        set("class", "bonze");

        set("inquiry", ([
                "����" : (: ask_me :),
                "����" : (: ask_me :),
                "����" : (: ask_me :),
                "�������" : (: ask_skill :),
        ]));

        set("master_ob", 5);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/huoyan-dao/fen"))
                return "�������Ѿ�ѧ���ˣ�ʣ�µľ�Ҫ�����Լ�����ϰ�ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��Ȼ�������Ǵ�����֮�ˣ���ʲô��̸�ġ�";

        if (me->query_skill("huoyan-dao", 1) < 120)
                return "��Ļ��浶����Ϊ��������������������˵�ɣ�";

        if (me->query("family/gongji") < 300)
                return "��Ϊ������Ч��������������ʱ�����ܴ��㡣";                

        message_vision(HIC "$n" HIC "����һ������·���ε���Ϯ����$N"
                       HIC "��$N" HIC "��æ���ָ񵲣���������$n"
                       HIC "���������ÿ�ν�ǰ������\n" NOR,
                       me, this_object());
        command("simle");
        tell_object(me, HIG "��ͨ���˷���İ��\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("huoyan-dao"))
                me->improve_skill("huoyan-dao", 1500000);        
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 90000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huoyan-dao/fen", 1);
        me->add("family/gongji", -300);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;
 
        if ((string)ob->query("gender") != "����")
	{
        	command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
	}

	if ((string)ob->query("class") != "bonze")
	{
        	command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
	}

        if ((string)ob->query("family/family_name") != "������")
	{
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
	}

        if ((int)ob->query_skill("lamaism", 1) < 150) {
                command("say ���Ҵ����£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("recruit " + ob->query("id"));
	ob->set("title", HIY "����" NOR);
}

mixed ask_skill()
{
        object me;

        me = this_player();

        if (me->query("can_perform/huoyan-dao/yan"))
                return "��������ʲô���Լ���ȥ������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ���ʶ�㣬���������ʲô��";

        if (me->query_skill("huoyan-dao", 1) < 1)
                return "�������ϻ��浶��ûѧ�����������У�";

        if (me->query("family/gongji") < 400)
                return "��Ϊ������Ч��������������ʱ�����ܴ��㡣";

        if (me->query("shen") > -3000)
                return "��Ϊ��̫������������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���㣬��ѧ������һ�С�";

        if (me->query("max_neili") < 800)
                return "���������Ϊ���㣬���������ߵ������ɡ�";

        if (me->query_skill("huoyan-dao", 1) < 80)
                return "����ѻ��浶�������������ҡ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "���˵�ͷ���ȵ���������"
                     "ϸ�ˡ����������䣬ֻ��$n" HIY "�߾����еĸյ�����"
                     "���л�����̣����ƾ��ˣ����ڴ�ʱ���Ǳ��յ���Я��"
                     "������ײ��֮����Ȼ���䡣ֱ��$N" HIY "����Ŀ�ɿڴ�"
                     "��\n\n" NOR, me, this_object());

        command("nod");
        command("say �������˾��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ס���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("huoyan-dao"))
                me->improve_skill("huoyan-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huoyan-dao/yan", 1);
        me->add("family/gongji", -400);

        return 1;
}
