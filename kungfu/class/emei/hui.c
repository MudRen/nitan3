// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hui.c ����ʦ̫

#include <command.h>
#include <ansi.h>
#include "tobebonze.h"
#include "emei.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ʦ̫", ({ "jinghui shitai","jinghui","shitai"}));
        set("long",
           "���Ƕ�������ʦ�㣬ֻ��������˸˸���񣬲�ͣ��ɨ�������ܡ���\n");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");
        set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
        ]));

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("level", 10);
        set("combat_exp", 250000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("throwing", 60);
        set_skill("force", 100);
        set_skill("dodge", 90);
        set_skill("finger", 100);
        set_skill("parry", 90);
        set_skill("strike", 100);
        set_skill("sword", 95);
        set_skill("literate", 90);
        set_skill("mahayana", 100);
        set_skill("emei-xinfa", 100);
        set_skill("jinding-zhang", 100);
        set_skill("tiangang-zhi", 90);
        set_skill("huifeng-jian", 90);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        create_family("������", 4, "����");

        set("master_ob", 3);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
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

	message("vision", "����ʦ̫����"+me->name()+"���˼��仰��\n", environment(me), ({me}) );

        switch(random(2)) {
		case 0:
		write("����ʦ̫˵�����ݴ��ţ���������������ʦ��
	    ��һ��һ����Ա�����������л�������𣿡����ݴ��Ŵ������Ͼ��롣
	    �ǹ�Ա����Щ�����ֻ���˵������֪ʶΪʲô��������أ�
	    ���ݴ����������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
			write("���Ȼ������һ�������������������¡�\n");
			write("��˵�����ݴ��Żش��������Ҳ��������˭ȥ�̻��㣿\n\n");
			message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
				environment(me), ({me}) );

                	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("��������ã�Ҳ���������еĵ���\n");
			command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
		break;

		case 1:
                write("����ʦ̫˵�����ݴ��ţ���������������ʦ��
	    ��һ��һ��ɮ�����������ӻ��з���û�У�������˵���ޡ���
	    ɮ��˵����������������ϣ����з��ԣ�Ϊʲô����ȴû�У�
            ���ݴ����������ش������أ�\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
                        write("�����һ�������������ʡ�\n");
                        write("��˵�����ݴ��Żش������Ϊ����ҵʶ����ʶ��֮ҵ���ڡ�\n\n");
                        message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
                                environment(me), ({me}) );

                        command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                        command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ� �ö�������\n");
                        command("recruit " + me->query("id"));
                }
		else {
                	write("��������ã�Ҳ���������еĵ���\n");
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

        command("say �����ӷ����գ����գ��ڱ������У���Ҫ�ȿ�����ķ𷨡�");
        ob->set_temp("pending/kao", 1);
        command("say ��Ҫ׼�����ˣ��͸���(nod)�Ұɡ�\n");
        add_action("do_nod", "nod");
        return; 
}
