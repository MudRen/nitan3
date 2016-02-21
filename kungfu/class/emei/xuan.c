// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <command.h>
#include <ansi.h>
#include "tobebonze.h"
#include "emei.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ʦ̫", ({ "jingxuan shitai","jingxuan","shitai"}));
        set("long", "���Ƕ����ɴ�ʦ�㣬�������ʦ̫��ʮ���أ�"
                    "�����ɵĹ����Ѿ���������\n");
        set("gender", "Ů��");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
                "����"  : "���ҵ��ӣ����ܻ��ס���������ʦ̫�ɡ�",
        ]));

        set("str", 22);
        set("int", 20);
        set("con", 24);
        set("dex", 23);

        set("max_qi", 3100);
        set("max_jing", 1600);
        set("neili", 3300);
        set("max_neili", 3300);
        set("level", 20);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("emei-xinfa", 180);
        set_skill("linji-zhuang", 150);
        set_skill("dodge", 160);
        set_skill("zhutian-bu", 160);
        set_skill("strike", 160);
        // set_skill("sixiang-zhang", 160);
        set_skill("jinding-zhang", 160);
        set_skill("finger", 160);
        set_skill("tiangang-zhi", 160);
        set_skill("hand", 160);
        // set_skill("jieshou-jiushi", 160);
        set_skill("parry", 160);
        set_skill("sword", 180);
        set_skill("huifeng-jian", 180);
        set_skill("blade", 180);
        set_skill("yanxing-dao", 180);
        set_skill("literate", 200);
        set_skill("mahayana", 200);
        set_skill("buddhism", 200);
        set_skill("martial-cognize", 100);

        map_skill("force","emei-xinfa");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        // map_skill("hand", "jieshou-jiushi");
        map_skill("sword", "huifeng-jian");
        map_skill("strike", "jinding-zhang");
        map_skill("blade", "yanxing-dao");
        map_skill("parry","yanxing-dao");

        // prepare_skill("hand", "jieshou-jiushi");
        prepare_skill("finger", "tiangang-zhi");

        set("no_teach", ([
                "linji-zhuang" : "�ټ�ʮ��ׯ�����ʦ�����ʦ̫���Դ��ڡ�",
        ]));

        create_family("������", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.jie" :),
                (: perform_action, "finger.ling" :),
                (: perform_action, "blade.huan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("master_ob", 4);
	setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

/*
void init()
{       
        ::init();
        add_action("do_nod","nod");
}
*/

int do_nod(string arg)
{
        object me = this_player();

        if( !me->query_temp("pending/kao") )
                return 0;

	command("smile");
	command("say �ҽ�������������\n");

	message("vision", "����ʦ̫����"+me->name()+"���˼��仰��\n",
                        environment(me), ({me}) );

        switch(random(2)) {
		case 0:
                write("����ʦ̫˵���޺�������ס�ڶ���ɽ�Ӹ�Ժ�
            ��ɮ��������ʲô���������⣿����˵�����к��棬���︡Ž��
            ɮ���ʣ�����ô��᣿���޺������������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
			write("��������һ����������������ʡ�\n");
			write("��˵��ңָ��ɣ���Ǳߡ�\n\n");
			message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
				environment(me), ({me}) );

                	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("��������ã�Ҳ�ⲻ�������е�����\n");
			command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
		break;

		case 1:
                write("����ʦ̫˵����ӡ�������ڻ����¿�����
            ��ӡ������һ�������ɮԲ��ʲô�ǹŷ�δ�ң�
            Բ��˵��ͥǰ�����ӡ���ӡ����������˵��ʲô��\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
                        write("��������һ������������������ʡ�\n");
                        write("����������˵��һ��Ͷ�ھ��֡����ⲻ֪��ҲͶ��һ�Σ���\n\n");
                        message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
                                environment(me), ({me}) );

                        command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                        command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                        command("recruit " + me->query("id"));
                }
		else {
                        write("��������ã�Ҳ�ⲻ�������е�����\n");
                	command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
               	break;
	}
        return 1;

} 

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 1000)
        {
                command("say " + RANK_D->query_respect(ob) +
                        "����������֮�»����Ĳ�����");
                return;
        }

        if ((int)ob->query_skill("mahayana",1) < 50)
        {
                command("say �������͹�����Ϊ�����������Щ�����ɡ�");
                return;
        }

        command("say �����ӷ����գ����գ��ڱ������У���Ҫ�ȿ�����ķ𷨡�");
        ob->set_temp("pending/kao", 1);
        command("say ��Ҫ׼�����ˣ��͸���(nod)�Ұɡ�\n");
        add_action("do_nod", "nod");
        return; 
}

