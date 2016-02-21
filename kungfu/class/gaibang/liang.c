// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// liang.c ������

#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_GUARDER;

#include "fight.h"

mixed  ask_skill1();
string ask_baicao();
string ask_xhwan();

void create()
{
        set_name("������", ({ "liang zhanglao", "liang", "zhanglao" }));
        set("long", @LONG
��������ؤ�������ã��书��ߵĳ��ϣ���
�����������Ѿá�ؤ���书������ǿ��������
����һ�����٣������������ϡ�
LONG);
        set("nickname", HIR "��������" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4200);
        set("max_jing", 3200);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 200);
        set("combat_exp", 2200000);
        set("level", 20);
        set("score", 350000);
        set("shen_type", 1);
	set("baicao", 10);
	set("xhwan", 10);
        
        set_skill("force", 240);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
        set_skill("unarmed", 240);
	set_skill("changquan", 240);
        set_skill("hand", 240);
        set_skill("shexing-diaoshou", 240);
        set_skill("strike", 240);
        set_skill("xiaoyaoyou", 240);
        set_skill("parry", 240);
        set_skill("staff", 240);
        set_skill("fengmo-zhang", 240);
        set_skill("jiaohua-bangfa", 240);
        set_skill("blade", 240);
        set_skill("liuhe-dao", 240);
        set_skill("begging", 280);
        set_skill("checking", 280);
        set_skill("literate", 220);
        set_skill("martial-cognize", 240);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("unarmed", "changquan");
        map_skill("strike", "xiaoyaoyou");
        map_skill("blade", "liuhe-dao");
        map_skill("parry", "liuhe-dao");
        map_skill("staff", "fengmo-zhang");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("strike", "xiaoyaoyou");

        create_family("ؤ��", 18, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.lianhuan" :),
                (: perform_action, "blade.shan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
        
        set("inquiry", ([
                "������" : (: ask_skill1 :),
                // "�ۻ���" : (: ask_xhwan :),
	        // "�ٲݵ�" : (: ask_baicao :),
        ]));
        
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("master_ob",4);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && ! is_fighting()
        &&  file_name(environment(this_object())) == "/d/city/gbandao") 
	{
		myfam = (mapping)ob->query("family");
		if (! myfam || myfam["family_name"] != "ؤ��")
		{
			remove_call_out("saying");
			call_out("saying", 1, ob);
		}
        }
}

void saying(object ob)
{
        if (! ob || environment(ob) != environment()) 
                return;

	message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (! ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +
		"��С������˳�����\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("level") < 5)
        {
                command("say ��Ľ������鲻�������������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query("family/beggarlvl") < 4)
        {
                command("say ���ڱ���ĵ�λ̫�ͣ�������������ʦ��ѧϰ�ɡ�");
                return;
        }

        if (ob->query_skill("force") < 90)
        {
                command("say ����ڹ���򻹲�����������������ʦ��ѧϰ�ɡ�");
                return;
        }
        command("grin");
        command("say �����Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuhe-dao/shan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("liuhe-dao", 1) < 1)
                return "�������ϵ���ûѧ����̸���п��ԣ�";

        if (me->query("family/gongji") < 400)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query_skill("liuhe-dao", 1) < 120)
                return "������ϵ���򻹲�����������ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����$N" HIY "˵��������"
                     "�ҿ�����ˡ���ͻȻ����$n" HIY "һ�����ȣ����и�"
                     "��һ�����裬���ƺ������������������Ӱ������"
                     "���ȣ������ɵ����������ϵ��ľ�Ҫ���ڡ�\n\n" NOR,
                     me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("liuhe-dao"))
                me->improve_skill("liuhe-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuhe-dao/shan", 1);
        me->add("family/gongji", -400);

        return 1;
}

string ask_xhwan()
{
	object me = this_object(), ob = this_player(), wan;

	if (! ob->query("family") || ob->query("family/family_name") != "ؤ��") 
	{
		return "��Ǳ�����ӣ�������ȡ������ҩ��\n\n";
	}

	if (! ob->query_condition("xx_poison") || ! ob->query_condition("snake_poison")
	||  ! ob->query_condition("insect_poison")) 
	{
		message_vision("$N��$n������ϸ�ش�����һ�󣬱�����üͷ��\n", me, ob);
		return "�㲢δ�ж���Ҫ�ۻ������\n\n";
	}

	message_vision("$N��$n������ϸ�ش�����һ��ץ��$n���������\n", me, ob);

	if (me->query("xhwan") < 1) 
	{
		message_vision("Ȼ��$N�����뻳�����������ã��ƺ�û���š�\n", me);
		return "�����ϴ˿�û���ۻ��裬�㻹�ǿ쵽����ȥ�Ҵ��ɣ�\n\n";
	}

	me->add("xhwan", -1);
	wan = new(DRUG_D("xh-wan"));
	wan->move(ob);

	message_vision("Ȼ��$N�����뻳��ȡ��һ���ۻ����$n��\n", me, ob);
	return "����ۻ�����£���Ҫ�ö��������ڸ���\n\n";
}

string ask_baicao()
{
	object me = this_object(), ob = this_player(), wan;

	if (! ob->query("family") || ob->query("family/family_name") != "ؤ��") 
	{
		return "��Ǳ�����ӣ�������ȡ������ҩ��\n\n";
	}

	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")
	&&  (int)ob->query("eff_jing") == (int)ob->query("max_jing")) 
	{
		message_vision("$N��$n������ϸ�ش�����һ�󣬱�����üͷ��\n", me, ob);
		return "�㲢δ���ˣ�Ҫ�ٲݵ�����\n\n";
	}

	message_vision("$N��$n������ϸ�ش�����һ��ץ��$n���������\n", me, ob);

	if (me->query("baicao") < 1) 
	{
		message_vision("Ȼ��$N�����뻳�����������ã��ƺ�û���š�\n", me);
		return "�����ϴ˿�û�аٲݵ����㻹�ǿ쵽����ȥ�Ҵ��ɣ�\n\n";
	}

	me->add("baicao", -1);
	wan = new(DRUG_D("baicao-dan"));
	wan->move(ob);

	message_vision("Ȼ��$N�����뻳��ȡ��һ�Űٲݵ���$n��\n", me, ob);
	return "��Ѱٲݵ����£���Ҫ�����Ƽ������أ�\n\n";
}
